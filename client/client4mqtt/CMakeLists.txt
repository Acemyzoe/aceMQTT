
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

    add_library(ThreadModel
    STATIC 
    ${PROJECT_SOURCE_DIR}/include/ThreadModel.cpp
    ${PROJECT_SOURCE_DIR}/include/ThreadModel.h
  )

      add_library(Client4MQTT
    STATIC 
    ${PROJECT_SOURCE_DIR}/include/Client4MQTT.cpp
    ${PROJECT_SOURCE_DIR}/include/Client4MQTT.h
  )

    add_executable(test_tm test/test_tm.cpp)
    target_link_libraries(test_tm Threads::Threads ThreadModel)

    add_executable(test_c4q test/test_c4q.cpp)
    target_link_libraries(test_c4q Threads::Threads Client4MQTT ThreadModel)
    target_link_libraries(test_c4q paho-mqtt3c)

endif()
