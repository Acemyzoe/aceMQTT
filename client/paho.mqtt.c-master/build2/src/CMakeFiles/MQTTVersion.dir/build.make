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
CMAKE_SOURCE_DIR = /home/ace/文档/aceMQTT/client/paho.mqtt.c-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2

# Include any dependencies generated for this target.
include src/CMakeFiles/MQTTVersion.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MQTTVersion.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MQTTVersion.dir/flags.make

src/CMakeFiles/MQTTVersion.dir/MQTTVersion.c.o: src/CMakeFiles/MQTTVersion.dir/flags.make
src/CMakeFiles/MQTTVersion.dir/MQTTVersion.c.o: ../src/MQTTVersion.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/MQTTVersion.dir/MQTTVersion.c.o"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MQTTVersion.dir/MQTTVersion.c.o   -c /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/MQTTVersion.c

src/CMakeFiles/MQTTVersion.dir/MQTTVersion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MQTTVersion.dir/MQTTVersion.c.i"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/MQTTVersion.c > CMakeFiles/MQTTVersion.dir/MQTTVersion.c.i

src/CMakeFiles/MQTTVersion.dir/MQTTVersion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MQTTVersion.dir/MQTTVersion.c.s"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/MQTTVersion.c -o CMakeFiles/MQTTVersion.dir/MQTTVersion.c.s

# Object files for target MQTTVersion
MQTTVersion_OBJECTS = \
"CMakeFiles/MQTTVersion.dir/MQTTVersion.c.o"

# External object files for target MQTTVersion
MQTTVersion_EXTERNAL_OBJECTS =

src/MQTTVersion: src/CMakeFiles/MQTTVersion.dir/MQTTVersion.c.o
src/MQTTVersion: src/CMakeFiles/MQTTVersion.dir/build.make
src/MQTTVersion: src/libpaho-mqtt3a.so.1.3.10
src/MQTTVersion: src/libpaho-mqtt3c.so.1.3.10
src/MQTTVersion: src/CMakeFiles/MQTTVersion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MQTTVersion"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MQTTVersion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MQTTVersion.dir/build: src/MQTTVersion

.PHONY : src/CMakeFiles/MQTTVersion.dir/build

src/CMakeFiles/MQTTVersion.dir/clean:
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src && $(CMAKE_COMMAND) -P CMakeFiles/MQTTVersion.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MQTTVersion.dir/clean

src/CMakeFiles/MQTTVersion.dir/depend:
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/paho.mqtt.c-master /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2 /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/CMakeFiles/MQTTVersion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MQTTVersion.dir/depend

