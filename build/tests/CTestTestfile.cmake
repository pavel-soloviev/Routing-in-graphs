# CMake generated Testfile for 
# Source directory: /home/pavel/Routing-in-graphs/tests
# Build directory: /home/pavel/Routing-in-graphs/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AlgorithmTests "/home/pavel/Routing-in-graphs/build/tests/tests")
set_tests_properties(AlgorithmTests PROPERTIES  _BACKTRACE_TRIPLES "/home/pavel/Routing-in-graphs/tests/CMakeLists.txt;11;add_test;/home/pavel/Routing-in-graphs/tests/CMakeLists.txt;0;")
subdirs("googletest")
