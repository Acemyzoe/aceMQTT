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
CMAKE_SOURCE_DIR = /home/ace/文档/aceMQTT/client/ace4mqtt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/文档/aceMQTT/client/ace4mqtt/build

# Include any dependencies generated for this target.
include CMakeFiles/test_cmqtt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_cmqtt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_cmqtt.dir/flags.make

CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.o: CMakeFiles/test_cmqtt.dir/flags.make
CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.o: ../src/test_cmqtt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/ace4mqtt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.o -c /home/ace/文档/aceMQTT/client/ace4mqtt/src/test_cmqtt.cpp

CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/文档/aceMQTT/client/ace4mqtt/src/test_cmqtt.cpp > CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.i

CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/文档/aceMQTT/client/ace4mqtt/src/test_cmqtt.cpp -o CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.s

# Object files for target test_cmqtt
test_cmqtt_OBJECTS = \
"CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.o"

# External object files for target test_cmqtt
test_cmqtt_EXTERNAL_OBJECTS =

test_cmqtt: CMakeFiles/test_cmqtt.dir/src/test_cmqtt.cpp.o
test_cmqtt: CMakeFiles/test_cmqtt.dir/build.make
test_cmqtt: CMakeFiles/test_cmqtt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/ace4mqtt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_cmqtt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_cmqtt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_cmqtt.dir/build: test_cmqtt

.PHONY : CMakeFiles/test_cmqtt.dir/build

CMakeFiles/test_cmqtt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_cmqtt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_cmqtt.dir/clean

CMakeFiles/test_cmqtt.dir/depend:
	cd /home/ace/文档/aceMQTT/client/ace4mqtt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/ace4mqtt /home/ace/文档/aceMQTT/client/ace4mqtt /home/ace/文档/aceMQTT/client/ace4mqtt/build /home/ace/文档/aceMQTT/client/ace4mqtt/build /home/ace/文档/aceMQTT/client/ace4mqtt/build/CMakeFiles/test_cmqtt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_cmqtt.dir/depend

