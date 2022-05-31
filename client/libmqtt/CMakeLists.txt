
cmake_minimum_required(VERSION 3.5)

project(MAIN VERSION 1.0 LANGUAGES CXX C)

add_library(${PROJECT_NAME} INTERFACE)
# add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include_directories(${PROJECT_SOURCE_DIR}/mqtt_lib_test)
include_directories(${PROJECT_SOURCE_DIR}/mqtt_lib)
link_directories(${PROJECT_SOURCE_DIR}/mqtt_lib_test)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11 c_std_99)

# build options
option(EXAMPLES "Build examples?" ON)

# Build examples
if(EXAMPLES)
    find_package(Threads REQUIRED)

    add_executable(main mqtt_lib_test/main.c mqtt_lib/lib_mqtt.c)
    target_link_libraries(main Threads::Threads paho-mqtt3c)


endif()
