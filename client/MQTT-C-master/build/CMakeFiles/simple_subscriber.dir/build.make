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
include CMakeFiles/simple_subscriber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_subscriber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_subscriber.dir/flags.make

CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.o: CMakeFiles/simple_subscriber.dir/flags.make
CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.o: ../examples/simple_subscriber.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/MQTT-C-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.o   -c /home/ace/文档/aceMQTT/client/MQTT-C-master/examples/simple_subscriber.c

CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ace/文档/aceMQTT/client/MQTT-C-master/examples/simple_subscriber.c > CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.i

CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ace/文档/aceMQTT/client/MQTT-C-master/examples/simple_subscriber.c -o CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.s

# Object files for target simple_subscriber
simple_subscriber_OBJECTS = \
"CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.o"

# External object files for target simple_subscriber
simple_subscriber_EXTERNAL_OBJECTS =

simple_subscriber: CMakeFiles/simple_subscriber.dir/examples/simple_subscriber.c.o
simple_subscriber: CMakeFiles/simple_subscriber.dir/build.make
simple_subscriber: libmqttc.a
simple_subscriber: CMakeFiles/simple_subscriber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/MQTT-C-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable simple_subscriber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_subscriber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_subscriber.dir/build: simple_subscriber

.PHONY : CMakeFiles/simple_subscriber.dir/build

CMakeFiles/simple_subscriber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_subscriber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_subscriber.dir/clean

CMakeFiles/simple_subscriber.dir/depend:
	cd /home/ace/文档/aceMQTT/client/MQTT-C-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/MQTT-C-master /home/ace/文档/aceMQTT/client/MQTT-C-master /home/ace/文档/aceMQTT/client/MQTT-C-master/build /home/ace/文档/aceMQTT/client/MQTT-C-master/build /home/ace/文档/aceMQTT/client/MQTT-C-master/build/CMakeFiles/simple_subscriber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_subscriber.dir/depend

