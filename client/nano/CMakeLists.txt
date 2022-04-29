cmake_minimum_required(VERSION 3.16)

project(nanoclient C)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
set(CMAKE_C_STANDARD 99)
add_executable(nanoclient nanoclient.c)
target_link_libraries(nanoclient paho-mqtt3c)