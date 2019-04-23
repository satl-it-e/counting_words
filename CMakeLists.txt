cmake_minimum_required(VERSION 3.8)
project(counting_words)

set(CMAKE_CXX_STANDARD 14)

set(ADDITIONAL_FILES additionals.cpp)

add_executable(counting_words_consistent ${ADDITIONAL_FILES} consistent_main.cpp)
add_executable(counting_words_parallel ${ADDITIONAL_FILES} parallel_main.cpp)