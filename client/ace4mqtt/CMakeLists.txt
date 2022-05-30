
cmake_minimum_required(VERSION 3.5)

project(MAIN VERSION 1.0 LANGUAGES CXX C)

add_library(${PROJECT_NAME} INTERFACE)
# add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11 c_std_99)

# build options
option(EXAMPLES "Build examples?" ON)

# Build examples
if(EXAMPLES)
    find_package(Threads REQUIRED)

    add_executable(MQTTClient_subscribe src/MQTTClient_subscribe.c)
    target_link_libraries(MQTTClient_subscribe Threads::Threads paho-mqtt3c)

    add_executable(MQTTClient_publish src/MQTTClient_publish.c)
    target_link_libraries(MQTTClient_publish Threads::Threads paho-mqtt3c)

    add_executable(test_client src/test_client.cpp)
    target_link_libraries(test_client Threads::Threads paho-mqtt3a)

endif()
