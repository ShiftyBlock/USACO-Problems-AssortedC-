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
CMAKE_SOURCE_DIR = /Users/shiftyblock/CLionProjects/USACO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shiftyblock/CLionProjects/USACO/cmake-build-default

# Include any dependencies generated for this target.
include CMakeFiles/piggy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/piggy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/piggy.dir/flags.make

CMakeFiles/piggy.dir/piggy.cpp.o: CMakeFiles/piggy.dir/flags.make
CMakeFiles/piggy.dir/piggy.cpp.o: ../piggy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/piggy.dir/piggy.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/piggy.dir/piggy.cpp.o -c /Users/shiftyblock/CLionProjects/USACO/piggy.cpp

CMakeFiles/piggy.dir/piggy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/piggy.dir/piggy.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shiftyblock/CLionProjects/USACO/piggy.cpp > CMakeFiles/piggy.dir/piggy.cpp.i

CMakeFiles/piggy.dir/piggy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/piggy.dir/piggy.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shiftyblock/CLionProjects/USACO/piggy.cpp -o CMakeFiles/piggy.dir/piggy.cpp.s

# Object files for target piggy
piggy_OBJECTS = \
"CMakeFiles/piggy.dir/piggy.cpp.o"

# External object files for target piggy
piggy_EXTERNAL_OBJECTS =

piggy: CMakeFiles/piggy.dir/piggy.cpp.o
piggy: CMakeFiles/piggy.dir/build.make
piggy: CMakeFiles/piggy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable piggy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/piggy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/piggy.dir/build: piggy

.PHONY : CMakeFiles/piggy.dir/build

CMakeFiles/piggy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/piggy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/piggy.dir/clean

CMakeFiles/piggy.dir/depend:
	cd /Users/shiftyblock/CLionProjects/USACO/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO/cmake-build-default /Users/shiftyblock/CLionProjects/USACO/cmake-build-default /Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles/piggy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/piggy.dir/depend

