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
include CMakeFiles/ccw.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ccw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ccw.dir/flags.make

CMakeFiles/ccw.dir/ccw.cpp.o: CMakeFiles/ccw.dir/flags.make
CMakeFiles/ccw.dir/ccw.cpp.o: ../ccw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ccw.dir/ccw.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ccw.dir/ccw.cpp.o -c /Users/shiftyblock/CLionProjects/USACO/ccw.cpp

CMakeFiles/ccw.dir/ccw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccw.dir/ccw.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shiftyblock/CLionProjects/USACO/ccw.cpp > CMakeFiles/ccw.dir/ccw.cpp.i

CMakeFiles/ccw.dir/ccw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccw.dir/ccw.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shiftyblock/CLionProjects/USACO/ccw.cpp -o CMakeFiles/ccw.dir/ccw.cpp.s

# Object files for target ccw
ccw_OBJECTS = \
"CMakeFiles/ccw.dir/ccw.cpp.o"

# External object files for target ccw
ccw_EXTERNAL_OBJECTS =

ccw: CMakeFiles/ccw.dir/ccw.cpp.o
ccw: CMakeFiles/ccw.dir/build.make
ccw: CMakeFiles/ccw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ccw"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ccw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ccw.dir/build: ccw

.PHONY : CMakeFiles/ccw.dir/build

CMakeFiles/ccw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ccw.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ccw.dir/clean

CMakeFiles/ccw.dir/depend:
	cd /Users/shiftyblock/CLionProjects/USACO/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO/cmake-build-default /Users/shiftyblock/CLionProjects/USACO/cmake-build-default /Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles/ccw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ccw.dir/depend
