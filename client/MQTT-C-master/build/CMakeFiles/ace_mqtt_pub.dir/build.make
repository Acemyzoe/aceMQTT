# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ace/文档/aceMQTT/client/MQTT-C-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/文档/aceMQTT/client/MQTT-C-master/build

# Include any dependencies generated for this target.
include CMakeFiles/ace_mqtt_pub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ace_mqtt_pub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ace_mqtt_pub.dir/flags.make

CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.o: CMakeFiles/ace_mqtt_pub.dir/flags.make
CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.o: ../examples/ace_mqtt_pub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/MQTT-C-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.o   -c /home/ace/文档/aceMQTT/client/MQTT-C-master/examples/ace_mqtt_pub.c

CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ace/文档/aceMQTT/client/MQTT-C-master/examples/ace_mqtt_pub.c > CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.i

CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ace/文档/aceMQTT/client/MQTT-C-master/examples/ace_mqtt_pub.c -o CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.s

# Object files for target ace_mqtt_pub
ace_mqtt_pub_OBJECTS = \
"CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.o"

# External object files for target ace_mqtt_pub
ace_mqtt_pub_EXTERNAL_OBJECTS =

ace_mqtt_pub: CMakeFiles/ace_mqtt_pub.dir/examples/ace_mqtt_pub.c.o
ace_mqtt_pub: CMakeFiles/ace_mqtt_pub.dir/build.make
ace_mqtt_pub: libmqttc.a
ace_mqtt_pub: CMakeFiles/ace_mqtt_pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/MQTT-C-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ace_mqtt_pub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ace_mqtt_pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ace_mqtt_pub.dir/build: ace_mqtt_pub

.PHONY : CMakeFiles/ace_mqtt_pub.dir/build

CMakeFiles/ace_mqtt_pub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ace_mqtt_pub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ace_mqtt_pub.dir/clean

CMakeFiles/ace_mqtt_pub.dir/depend:
	cd /home/ace/文档/aceMQTT/client/MQTT-C-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/MQTT-C-master /home/ace/文档/aceMQTT/client/MQTT-C-master /home/ace/文档/aceMQTT/client/MQTT-C-master/build /home/ace/文档/aceMQTT/client/MQTT-C-master/build /home/ace/文档/aceMQTT/client/MQTT-C-master/build/CMakeFiles/ace_mqtt_pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ace_mqtt_pub.dir/depend

