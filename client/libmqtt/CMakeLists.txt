
cmake_minimum_required(VERSION 3.5)

project(MAIN VERSION 1.0 LANGUAGES CXX C)

add_library(${PROJECT_NAME} INTERFACE)
# add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11 c_std_99)

# build options
option(EXAMPLES "Build examples?" ON)

# Build examples
if(EXAMPLES)
    find_package(Threads REQUIRED)

    add_library(mqttLib
    STATIC 
    ${PROJECT_SOURCE_DIR}/include/mqttLib.c
    ${PROJECT_SOURCE_DIR}/include/mqttLib.h
  )

    add_executable(test_client test/test_client.cpp include/mqttLib.c)
    target_link_libraries(test_client Threads::Threads paho-mqtt3c)

    add_executable(test_async test/test_async.cpp)
    target_link_libraries(test_async mqttLib Threads::Threads paho-mqtt3a)

    add_executable(test_async2 test/test_async2.cpp include/mqttLibAsync.cpp)
    target_link_libraries(test_async2 Threads::Threads paho-mqtt3a)

endif()
