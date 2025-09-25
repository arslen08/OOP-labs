cmake_minimum_required(VERSION 3.14)
project(VowelCounter)

set(CMAKE_CXX_STANDARD 11)

# GoogleTest находится в той же папке проекта - ./googletest
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/googletest" CACHE PATH "Path to Google Test")

# Проверяем существование GoogleTest
if(EXISTS ${GTEST_DIR}/CMakeLists.txt)
    message(STATUS "Found GoogleTest at: ${GTEST_DIR}")
    add_subdirectory(${GTEST_DIR} googletest-build)
else()
    message(FATAL_ERROR "GoogleTest not found at: ${GTEST_DIR}. Please check the path.")
endif()

# Основная программа
add_executable(vowel_counter 
    src/main.cpp 
    src/function.cpp
)
target_include_directories(vowel_counter PRIVATE headers)

# Тесты
add_subdirectory(tests)