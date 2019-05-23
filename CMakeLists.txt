cmake_minimum_required(VERSION 3.8)
project(counting_words)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(ICU_MAJOR_VER "57")
set(ICU_FULL_VERSION "${ICU_MAJOR_VER}.1")



find_package(Boost REQUIRED system)
find_package(Boost COMPONENTS system filesystem locale REQUIRED)
find_package(LibArchive REQUIRED)

add_executable(counting_words main.cpp config.cpp additionals.cpp)
add_executable(test_archive test_archive.cpp)

target_link_libraries(test_archive ${LibArchive_LIBRARIES})
target_link_libraries(counting_words ${LibArchive_LIBRARIES})
target_link_libraries(counting_words
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_LOCALE_LIBRARY}
        ${ICU_LIBRARIES}
        )
