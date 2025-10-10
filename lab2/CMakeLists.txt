cmake_minimum_required(VERSION 3.14)
project(OctalCalculator)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_DIR "${CMAKE_SOURCE_DIR}/../googletest")
na
if(EXISTS ${GTEST_DIR}/CMakeLists.txt)
    message(STATUS "Found GoogleTest at: ${GTEST_DIR}")
    add_subdirectory(${GTEST_DIR} googletest-build)
else()
    message(FATAL_ERROR "GoogleTest not found at: ${GTEST_DIR}. Please check the path.")
endif()

add_executable(octal_calculator 
    main.cpp          
    src/octal.cpp      
)
target_include_directories(octal_calculator PRIVATE includes)

add_executable(octal_tests
    tests/tests.cpp    
    src/octal.cpp      
)
target_include_directories(octal_tests PRIVATE includes)
target_link_libraries(octal_tests gtest gtest_main)

add_custom_target(run_tests
    COMMAND octal_tests
    DEPENDS octal_tests
    COMMENT "Running Octal tests"
)