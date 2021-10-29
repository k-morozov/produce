cmake_minimum_required(VERSION 3.20)
project(produce)

find_package (Threads REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(produce main.cpp consumer/Consumer.cpp consumer/Consumer.h produser/Producer.cpp produser/Producer.h middleware/Middleware.cpp middleware/Middleware.h)

target_link_libraries(produce
        ${CMAKE_THREAD_LIBS_INIT}
        )