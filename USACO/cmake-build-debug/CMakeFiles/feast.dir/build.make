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
CMAKE_BINARY_DIR = /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/feast.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/feast.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/feast.dir/flags.make

CMakeFiles/feast.dir/feast.cpp.o: CMakeFiles/feast.dir/flags.make
CMakeFiles/feast.dir/feast.cpp.o: ../feast.cpp
CMakeFiles/feast.dir/feast.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/feast.dir/feast.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/feast.dir/feast.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/feast.dir/feast.cpp.o -c /Users/shiftyblock/CLionProjects/USACO/feast.cpp

CMakeFiles/feast.dir/feast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feast.dir/feast.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/USACO/feast.cpp > CMakeFiles/feast.dir/feast.cpp.i

CMakeFiles/feast.dir/feast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feast.dir/feast.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/USACO/feast.cpp -o CMakeFiles/feast.dir/feast.cpp.s

# Object files for target feast
feast_OBJECTS = \
"CMakeFiles/feast.dir/feast.cpp.o"

# External object files for target feast
feast_EXTERNAL_OBJECTS =

feast: CMakeFiles/feast.dir/feast.cpp.o
feast: CMakeFiles/feast.dir/build.make
feast: CMakeFiles/feast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable feast"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/feast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/feast.dir/build: feast

.PHONY : CMakeFiles/feast.dir/build

CMakeFiles/feast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/feast.dir/cmake_clean.cmake
.PHONY : CMakeFiles/feast.dir/clean

CMakeFiles/feast.dir/depend:
	cd /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/feast.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/feast.dir/depend
