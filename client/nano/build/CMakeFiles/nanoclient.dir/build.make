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
CMAKE_SOURCE_DIR = /home/ace/文档/aceMQTT/client/nano

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/文档/aceMQTT/client/nano/build

# Include any dependencies generated for this target.
include CMakeFiles/nanoclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nanoclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nanoclient.dir/flags.make

CMakeFiles/nanoclient.dir/nanoclient.c.o: CMakeFiles/nanoclient.dir/flags.make
CMakeFiles/nanoclient.dir/nanoclient.c.o: ../nanoclient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/nano/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nanoclient.dir/nanoclient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nanoclient.dir/nanoclient.c.o   -c /home/ace/文档/aceMQTT/client/nano/nanoclient.c

CMakeFiles/nanoclient.dir/nanoclient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nanoclient.dir/nanoclient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ace/文档/aceMQTT/client/nano/nanoclient.c > CMakeFiles/nanoclient.dir/nanoclient.c.i

CMakeFiles/nanoclient.dir/nanoclient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nanoclient.dir/nanoclient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ace/文档/aceMQTT/client/nano/nanoclient.c -o CMakeFiles/nanoclient.dir/nanoclient.c.s

# Object files for target nanoclient
nanoclient_OBJECTS = \
"CMakeFiles/nanoclient.dir/nanoclient.c.o"

# External object files for target nanoclient
nanoclient_EXTERNAL_OBJECTS =

nanoclient: CMakeFiles/nanoclient.dir/nanoclient.c.o
nanoclient: CMakeFiles/nanoclient.dir/build.make
nanoclient: CMakeFiles/nanoclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/nano/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable nanoclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nanoclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nanoclient.dir/build: nanoclient

.PHONY : CMakeFiles/nanoclient.dir/build

CMakeFiles/nanoclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nanoclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nanoclient.dir/clean

CMakeFiles/nanoclient.dir/depend:
	cd /home/ace/文档/aceMQTT/client/nano/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/nano /home/ace/文档/aceMQTT/client/nano /home/ace/文档/aceMQTT/client/nano/build /home/ace/文档/aceMQTT/client/nano/build /home/ace/文档/aceMQTT/client/nano/build/CMakeFiles/nanoclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nanoclient.dir/depend

