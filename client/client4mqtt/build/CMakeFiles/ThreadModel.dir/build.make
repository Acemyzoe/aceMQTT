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
CMAKE_SOURCE_DIR = /home/ace/文档/aceMQTT/client/client4mqtt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/文档/aceMQTT/client/client4mqtt/build

# Include any dependencies generated for this target.
include CMakeFiles/ThreadModel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ThreadModel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ThreadModel.dir/flags.make

CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.o: CMakeFiles/ThreadModel.dir/flags.make
CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.o: ../include/ThreadModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ace/文档/aceMQTT/client/client4mqtt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.o -c /home/ace/文档/aceMQTT/client/client4mqtt/include/ThreadModel.cpp

CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ace/文档/aceMQTT/client/client4mqtt/include/ThreadModel.cpp > CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.i

CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ace/文档/aceMQTT/client/client4mqtt/include/ThreadModel.cpp -o CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.s

# Object files for target ThreadModel
ThreadModel_OBJECTS = \
"CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.o"

# External object files for target ThreadModel
ThreadModel_EXTERNAL_OBJECTS =

libThreadModel.a: CMakeFiles/ThreadModel.dir/include/ThreadModel.cpp.o
libThreadModel.a: CMakeFiles/ThreadModel.dir/build.make
libThreadModel.a: CMakeFiles/ThreadModel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ace/文档/aceMQTT/client/client4mqtt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libThreadModel.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ThreadModel.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ThreadModel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ThreadModel.dir/build: libThreadModel.a

.PHONY : CMakeFiles/ThreadModel.dir/build

CMakeFiles/ThreadModel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ThreadModel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ThreadModel.dir/clean

CMakeFiles/ThreadModel.dir/depend:
	cd /home/ace/文档/aceMQTT/client/client4mqtt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/文档/aceMQTT/client/client4mqtt /home/ace/文档/aceMQTT/client/client4mqtt /home/ace/文档/aceMQTT/client/client4mqtt/build /home/ace/文档/aceMQTT/client/client4mqtt/build /home/ace/文档/aceMQTT/client/client4mqtt/build/CMakeFiles/ThreadModel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ThreadModel.dir/depend

