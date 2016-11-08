#!/bin/bash
# This script takes a source file as a CLI argument. The program is transformed
# in order to extract task loops and instrument memory accesses. The program is
# then ran.
#
# This script automatically detects whether the program is a C or C++ program
# and invokes clang or clang++ respectively.

CFLAGS="-g -O3"
CXXFLAGS="$CFLAGS -std=c++0x -stdlib=libc++"

cache_source_name() {
  echo "INFO: Caching source name."
  if [ -z "$1" ] ; then
    echo "ERROR: Please provide the test source file as first argument."
    exit 1
  fi

  SRC_FILE=$1
  shift
  ARGS=$@
}

init_vars() {
  echo "INFO: Initializing vars."
# Set in order to call `time` and suppress stderr from final runs.
# TIME_IT=

  SELF_DIR=$(dirname $0)
  PROJECT_ROOT=${PWD}/${SELF_DIR}/..
}


verify_source_name() {
  echo "INFO: Verifying source name."
  if [ ${SRC_FILE: -2} == ".c" ] ; then
    COMPILER=clang
    FLAGS=$CFLAGS

    TEST_NAME=${SRC_FILE%".c"}
  elif [ ${SRC_FILE: -4} == ".cpp" ] ; then
    COMPILER=clang++
    FLAGS=$CXXFLAGS

    TEST_NAME=${SRC_FILE%".cpp"}
  else
    echo "ERROR: File extension of selected file ($SRC_FILE) not recognized."
  fi
}

# setup different file names

setup_file_names() {
  echo "INFO: Setting up file names."
  BC_FILE=$TEST_NAME.bc
  NO_FILE=$TEST_NAME-no.bc
  TE_FILE=$TEST_NAME-te.bc
  DI_FILE=$TEST_NAME-te-di.bc
  FP_FILE=$TEST_NAME-te-di.bc

  DI_EXE_FILE=$TEST_NAME-te-di.exe
  FP_EXE_FILE=$TEST_NAME-te-di-fp.exe
  EXE_FILE=$TEST_NAME.exe
}

# verify configuration

check_profiler_root() {
  if [ -z "$PROFILER_ROOT" ] ; then
    echo "ERROR: Please set PROFILER_ROOT to the location of graph lib."
    exit 1
  fi
}

check_boost_root() {
  if [ -z "$BOOST_ROOT" ] ; then
    echo "ERROR: Please set BOOST_ROOT to the location of boost." exit 1
  fi
}

check_decouple_loops_root() {
  if [ -z "$DECOUPLE_LOOPS_ROOT" ] ; then
    echo "ERROR: Please set DECOUPLE_LOOPS_ROOT to the location of icsa-dswp."
    exit 1
  fi
}

# functions start

do_vanilla() {
  echo "INFO: Compiling vanilla program"
  $COMPILER $FLAGS $SRC_FILE -o $EXE_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Compiling vanilla program failed."
    exit $?
  fi

  echo "INFO: Running vanilla program"
  time ./$EXE_FILE $ARGS
  RC=$?
  if [ $RC -ne 0 ] ; then
    echo "ERROR: Running vanilla program failed with return code $RC."
    exit $RC
  fi
}

prepare() {
  echo "INFO: Compiling to bit-code"
  $COMPILER $FLAGS -c -emit-llvm $SRC_FILE -o $BC_FILE -DMEASURE_MEMPROF 
  if [ $? -ne 0 ] ; then
    echo "ERROR: Compiling to bit-code failed."
    exit $?
  fi

  echo "INFO: Normalizing bit-code"
  opt                                                                          \
    -mem2reg                                                                   \
    -simplifycfg                                                               \
    -loop-simplify                                                             \
    $BC_FILE -o $NO_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Normalizing bit-code failed."
    exit $?
  fi
}

do_terrace() {

  check_decouple_loops_root

  echo "INFO: Applying Terrace transformation"
  LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DECOUPLE_LOOPS_ROOT/lib
  opt                                                                          \
    -load $PROJECT_ROOT/build/libLLVMTerracePass.so -terrace                   \
    $NO_FILE -o $TE_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Terrace transformation failed."
    exit $?
  fi
}

do_poolpar() {

  check_profiler_root
  check_boost_root

  echo "INFO: Instrumenting memory"
  GRAPH_LIB=$PROFILER_ROOT/lib
  BOOST_LIB=$BOOST_ROOT/lib
  LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(llvm-config --libdir):$GRAPH_LIB:$BOOST_LIB
  opt                                                                          \
    -load $POOLPAR_LIB_DIR/poolpar.so                                          \
    -memprof                                                                   \
    -memprof-instrument-control=false                                          \
    $TE_FILE -o $DI_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Instrumenting memory failed."
    exit $?
  fi
}

do_fullprof() {

  check_profiler_root
  check_boost_root

  if [ -z "$FULLPROF_BUILD_DIR" ] ; then
    echo "ERROR: Please set FULLPROF_BUILD_DIR to the location of fullprof."
    exit 1
  fi

  echo "INFO: Applying fullprof transform"
  GRAPH_LIB=$PROFILER_ROOT/lib
  BOOST_LIB=$BOOST_ROOT/lib
  LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(llvm-config --libdir):$GRAPH_LIB:$BOOST_LIB
  opt                                                                          \
    -load $FULLPROF_BUILD_DIR/pass/libfullprof.so \
    -fullprof \
    $DI_FILE -o $FP_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Applying fullprof transform failed."
    exit $?
  fi

  echo "INFO: Compiling fullprof program"
  $COMPILER                                                                    \
    -stdlib=libc++ -lc++abi -lc++                                              \
    -lbz2                                                                      \
    -lsnappy                                                                   \
    -L$GRAPH_LIB -lcommprofilerrt-fullprof                                     \
    $FP_FILE \
    $FULLPROF_BUILD_DIR/runtime/libfullprof-rt.a \
    -o $FP_EXE_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Compiling fullprof program failed."
    exit $?
  fi
}

do_final_compile() {
  echo "INFO: Compiling transformed program"
  $COMPILER                                                                    \
    -stdlib=libc++ -lc++abi -lc++                                              \
    -lbz2                                                                      \
    -lsnappy                                                                   \
    -L$GRAPH_LIB -lcommprofilerrt                                              \
    $DI_FILE -o $DI_EXE_FILE
  if [ $? -ne 0 ] ; then
    echo "ERROR: Compiling transformed program failed."
    exit $?
  fi
}

do_profiling_run() {
  EXE=$1
  echo "INFO: Profile memory"
  if [ -z "$TIME_IT" ] ; then
    COMM_TEST=0 COMM_DEPTH=0 COMM_FAST=1 ./$EXE $ARGS
  else
    time { COMM_TEST=0 COMM_DEPTH=0 COMM_FAST=1 ./$EXE $ARGS 2>/dev/null ; }
  fi
  if [ $? -ne 0 ] ; then
    echo "ERROR: Profiling memory failed."
    exit $?
  fi
}

do_commutativity_test() {
  EXE=$1
  echo "INFO: Perform commutativity test"
  if [ -z "$TIME_IT" ] ; then
    COMM_TEST=1 COMM_DEPTH=0 COMM_FAST=1 ./$EXE $ARGS
  else
    time { COMM_TEST=1 COMM_DEPTH=0 COMM_FAST=1 ./$EXE $ARGS 2>/dev/null ; }
  fi

  echo "INFO: Done!"
}

# functions end

cache_source_name $@
init_vars
verify_source_name
setup_file_names

do_vanilla
prepare
do_terrace
do_poolpar
do_final_compile
# do_fullprof
do_profiling_run $DI_EXE_FILE
do_commutativity_test $DI_EXE_FILE
