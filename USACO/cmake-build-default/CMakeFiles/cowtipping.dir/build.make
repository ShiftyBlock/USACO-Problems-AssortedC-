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
include CMakeFiles/cowtipping.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cowtipping.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cowtipping.dir/flags.make

CMakeFiles/cowtipping.dir/cowtipping.cpp.o: CMakeFiles/cowtipping.dir/flags.make
CMakeFiles/cowtipping.dir/cowtipping.cpp.o: ../cowtipping.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cowtipping.dir/cowtipping.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cowtipping.dir/cowtipping.cpp.o -c /Users/shiftyblock/CLionProjects/USACO/cowtipping.cpp

CMakeFiles/cowtipping.dir/cowtipping.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cowtipping.dir/cowtipping.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shiftyblock/CLionProjects/USACO/cowtipping.cpp > CMakeFiles/cowtipping.dir/cowtipping.cpp.i

CMakeFiles/cowtipping.dir/cowtipping.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cowtipping.dir/cowtipping.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shiftyblock/CLionProjects/USACO/cowtipping.cpp -o CMakeFiles/cowtipping.dir/cowtipping.cpp.s

# Object files for target cowtipping
cowtipping_OBJECTS = \
"CMakeFiles/cowtipping.dir/cowtipping.cpp.o"

# External object files for target cowtipping
cowtipping_EXTERNAL_OBJECTS =

cowtipping: CMakeFiles/cowtipping.dir/cowtipping.cpp.o
cowtipping: CMakeFiles/cowtipping.dir/build.make
cowtipping: CMakeFiles/cowtipping.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cowtipping"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cowtipping.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cowtipping.dir/build: cowtipping

.PHONY : CMakeFiles/cowtipping.dir/build

CMakeFiles/cowtipping.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cowtipping.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cowtipping.dir/clean

CMakeFiles/cowtipping.dir/depend:
	cd /Users/shiftyblock/CLionProjects/USACO/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO/cmake-build-default /Users/shiftyblock/CLionProjects/USACO/cmake-build-default /Users/shiftyblock/CLionProjects/USACO/cmake-build-default/CMakeFiles/cowtipping.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cowtipping.dir/depend
