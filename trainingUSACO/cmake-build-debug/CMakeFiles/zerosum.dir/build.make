# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shiftyblock/CLionProjects/trainingUSACO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zerosum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zerosum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zerosum.dir/flags.make

CMakeFiles/zerosum.dir/zerosum.cpp.o: CMakeFiles/zerosum.dir/flags.make
CMakeFiles/zerosum.dir/zerosum.cpp.o: ../zerosum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zerosum.dir/zerosum.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zerosum.dir/zerosum.cpp.o -c /Users/shiftyblock/CLionProjects/trainingUSACO/zerosum.cpp

CMakeFiles/zerosum.dir/zerosum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zerosum.dir/zerosum.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shiftyblock/CLionProjects/trainingUSACO/zerosum.cpp > CMakeFiles/zerosum.dir/zerosum.cpp.i

CMakeFiles/zerosum.dir/zerosum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zerosum.dir/zerosum.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shiftyblock/CLionProjects/trainingUSACO/zerosum.cpp -o CMakeFiles/zerosum.dir/zerosum.cpp.s

# Object files for target zerosum
zerosum_OBJECTS = \
"CMakeFiles/zerosum.dir/zerosum.cpp.o"

# External object files for target zerosum
zerosum_EXTERNAL_OBJECTS =

zerosum: CMakeFiles/zerosum.dir/zerosum.cpp.o
zerosum: CMakeFiles/zerosum.dir/build.make
zerosum: CMakeFiles/zerosum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zerosum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zerosum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zerosum.dir/build: zerosum

.PHONY : CMakeFiles/zerosum.dir/build

CMakeFiles/zerosum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zerosum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zerosum.dir/clean

CMakeFiles/zerosum.dir/depend:
	cd /Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/trainingUSACO /Users/shiftyblock/CLionProjects/trainingUSACO /Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug /Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug /Users/shiftyblock/CLionProjects/trainingUSACO/cmake-build-debug/CMakeFiles/zerosum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zerosum.dir/depend
