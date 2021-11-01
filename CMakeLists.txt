cmake_minimum_required(VERSION 3.20)
project(produce)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
SET(CONAN_DISABLE_CHECK_COMPILER TRUE)
conan_basic_setup()

find_package (Threads REQUIRED)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})
add_executable(produce main.cpp
        consumer/Consumer.cpp
        producer/Producer.cpp
        middleware/Middleware.cpp
        utils/Utils.h)

target_link_libraries(produce
#        ${CMAKE_THREAD_LIBS_INIT}
        ${CONAN_LIBS}
        )