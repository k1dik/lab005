# CMake generated Testfile for 
# Source directory: /home/ch1psik/lab005
# Build directory: /home/ch1psik/lab005/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_account "/home/ch1psik/lab005/build/test_account")
set_tests_properties(test_account PROPERTIES  _BACKTRACE_TRIPLES "/home/ch1psik/lab005/CMakeLists.txt;39;add_test;/home/ch1psik/lab005/CMakeLists.txt;0;")
add_test(test_transaction "/home/ch1psik/lab005/build/test_transaction")
set_tests_properties(test_transaction PROPERTIES  _BACKTRACE_TRIPLES "/home/ch1psik/lab005/CMakeLists.txt;40;add_test;/home/ch1psik/lab005/CMakeLists.txt;0;")
subdirs("external/googletest")
