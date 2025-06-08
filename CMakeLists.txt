cmake_minimum_required(VERSION 3.10)
project(lab005)

set(CMAKE_CXX_STANDARD 17)

add_library(banking STATIC
    src/Account.cpp
    src/Transaction.cpp
)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests
    tests/test_account.cpp
    tests/test_transaction.cpp
)

target_link_libraries(tests banking ${GTEST_LIBRARIES} pthread)

add_test(NAME banking_tests COMMAND tests)
