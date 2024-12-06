cmake_minimum_required(VERSION 3.14)

# Change "projectName" to whatever you want
set(this final)

# Defines the project and the language we are using
project(${this} CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable testing
enable_testing()

# Find libcurl
find_package(CURL REQUIRED)

# Allows us to include the Google Test framework
add_subdirectory(googletest)

# Change foo.h and huh.h to the headers in your project
# Do not delete "Headers"; this is the name of a variable
set(Headers
    wikiladder.h
)

# Change foo.cpp and huh.cpp to the sources in your project
# Do not delete "Sources"; this is the name of a variable
# Make sure to not include a main function in any of these files
set(Sources
    wikiladder.cpp
)

# Creates a library from the source code we provided in "Sources" and "Headers"
add_library(${this} SHARED ${Sources} ${Headers})

# Link libcurl to the library
target_link_libraries(${this} PRIVATE CURL::libcurl)

# Sets the name of the testing executable we are creating
# You can rename "testingExample" to whatever you want
set(test testingExample)

# Change test.cpp to the name of your testing file
# Your testing file should not include a main file
set(testSources
    test.cpp
)

# Creates the testing executable and links it to our project and
# the Google Test framework
add_executable(${test} ${testSources})
target_link_libraries(${test} PUBLIC
    gtest_main # When testing, gtest provides the main function
    ${this}
)

# Allows us to use ctest
add_test(
    NAME ${test}
    COMMAND ${test}
)
