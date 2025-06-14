cmake_minimum_required(VERSION 3.10)
project(banking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы библиотеки
set(SOURCES
    src/Transaction.cpp
    src/Account.cpp
)

# Создаём статическую библиотеку
add_library(banking STATIC ${SOURCES})

# Находим GoogleTest (и GoogleMock, который входит в GTest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

# Тестовые файлы (создай test/main.cpp с main из GoogleTest)
set(TEST_SOURCES
    test/main.cpp
    test/TransactionTest.cpp
    test/AccountTest.cpp
)

# Исполняемый файл для тестов
add_executable(runTests
    test/AccountTest.cpp
    test/TransactionTest.cpp
)

# Линкуем runTests с библиотекой banking, GTest и pthread (для Linux)
target_link_libraries(runTests PRIVATE banking ${GTEST_LIBRARIES} gtest_main pthread)
target_include_directories(runTests PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Включаем поддержку тестирования через CTest
enable_testing()
add_test(NAME runTests COMMAND runTests)

# Опция для покрытия кода
option(CODE_COVERAGE "Enable coverage reporting" ON)

if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # Флаги для библиотеки
        target_compile_options(banking PRIVATE --coverage -O0 -g)
        target_link_libraries(banking PRIVATE --coverage)

        # Флаги для тестов
        target_compile_options(runTests PRIVATE --coverage -O0 -g)
        target_link_libraries(runTests PRIVATE --coverage)
    endif()
endif()
