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
include src/samples/CMakeFiles/paho_cs_sub.dir/depend.make

# Include the progress variables for this target.
include src/samples/CMakeFiles/paho_cs_sub.dir/progress.make

# Include the compile flags for this target's objects.
include src/samples/CMakeFiles/paho_cs_sub.dir/flags.make

src/samples/CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.o: src/samples/CMakeFiles/paho_cs_sub.dir/flags.make
src/samples/CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.o: ../src/samples/paho_cs_sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/samples/CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.o"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.o   -c /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples/paho_cs_sub.c

src/samples/CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.i"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples/paho_cs_sub.c > CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.i

src/samples/CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.s"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples/paho_cs_sub.c -o CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.s

src/samples/CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.o: src/samples/CMakeFiles/paho_cs_sub.dir/flags.make
src/samples/CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.o: ../src/samples/pubsub_opts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/samples/CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.o"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.o   -c /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples/pubsub_opts.c

src/samples/CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.i"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples/pubsub_opts.c > CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.i

src/samples/CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.s"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples/pubsub_opts.c -o CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.s

# Object files for target paho_cs_sub
paho_cs_sub_OBJECTS = \
"CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.o" \
"CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.o"

# External object files for target paho_cs_sub
paho_cs_sub_EXTERNAL_OBJECTS =

src/samples/paho_cs_sub: src/samples/CMakeFiles/paho_cs_sub.dir/paho_cs_sub.c.o
src/samples/paho_cs_sub: src/samples/CMakeFiles/paho_cs_sub.dir/pubsub_opts.c.o
src/samples/paho_cs_sub: src/samples/CMakeFiles/paho_cs_sub.dir/build.make
src/samples/paho_cs_sub: src/samples/CMakeFiles/paho_cs_sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable paho_cs_sub"
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/paho_cs_sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/samples/CMakeFiles/paho_cs_sub.dir/build: src/samples/paho_cs_sub

.PHONY : src/samples/CMakeFiles/paho_cs_sub.dir/build

src/samples/CMakeFiles/paho_cs_sub.dir/clean:
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples && $(CMAKE_COMMAND) -P CMakeFiles/paho_cs_sub.dir/cmake_clean.cmake
.PHONY : src/samples/CMakeFiles/paho_cs_sub.dir/clean

src/samples/CMakeFiles/paho_cs_sub.dir/depend:
	cd /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/paho.mqtt.c-master /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/src/samples /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2 /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples /home/ace/文档/aceMQTT/client/paho.mqtt.c-master/build2/src/samples/CMakeFiles/paho_cs_sub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/samples/CMakeFiles/paho_cs_sub.dir/depend

