
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

    add_executable(test_pub_sub test/test_pub_sub.cpp include/lib_mqtt.c)
    target_link_libraries(test_pub_sub Threads::Threads paho-mqtt3c)

    add_executable(test_thread test/test_thread.cpp include/lib_mqtt.c)
    target_link_libraries(test_thread Threads::Threads paho-mqtt3c)

endif()
