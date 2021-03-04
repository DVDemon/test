

cmake_minimum_required(VERSION 3.10)

# set the project name
project(MyProject)

set(EXE my_project)
set(LIB my_lib)
set(TESTS gtest)

find_package(Boost COMPONENTS filesystem system program_options regex REQUIRED)
find_package(GTest REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

# add tests
add_executable(${TESTS} tests.cpp)

# add library
add_library(${LIB} STATIC mylib.cpp)

# add the executable
add_executable(${EXE} tutorial.cpp)

set_target_properties(${EXE} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${EXE} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)


target_link_libraries(${EXE} ${LIB} 
                             ${Boost_LIBRARIES})

target_link_libraries(${TESTS} ${LIB}
                             ${GTEST_LIBRARIES}
                             ${CMAKE_THREAD_LIBS_INIT})

