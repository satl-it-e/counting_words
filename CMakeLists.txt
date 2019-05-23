cmake_minimum_required(VERSION 3.8)
project(counting_words)



set(CMAKE_CXX_STANDARD 17)

#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)



#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

#find_package(Boost REQUIRED COMPONENTS system filesystem locale REQUIRED)

add_executable(counting_words main.cpp additionals.cpp config.cpp)

#target_link_libraries(counting_words
#        ${Boost_PROGRAM_OPTIONS_LIBRARY}
#        ${Boost_FILESYSTEM_LIBRARY}
#        ${Boost_SYSTEM_LIBRARY}
#        ${Boost_LOCALE_LIBRARY}
#        ${ICU_LIBRARIES}
#        )


