cmake_minimum_required(VERSION 3.10)
project(BookingConflictChecker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BookingConflictChecker 
    src/IntervalTree.cpp 
    src/BookingManager.cpp)

target_include_directories(BookingConflictChecker PUBLIC include)

add_executable(test_interval_tree tests/test_interval_tree.cpp)
target_link_libraries(test_interval_tree PRIVATE BookingConflictLogger)

add_executable(example examples/example_usage.cpp)
target_link_libraries(example PRIVATE BookingConflictLogger)
