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
include CMakeFiles/RectangularPasture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RectangularPasture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RectangularPasture.dir/flags.make

CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o: CMakeFiles/RectangularPasture.dir/flags.make
CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o: ../RectangularPasture.cpp
CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o -c /Users/shiftyblock/CLionProjects/USACO/RectangularPasture.cpp

CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/USACO/RectangularPasture.cpp > CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.i

CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/USACO/RectangularPasture.cpp -o CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.s

# Object files for target RectangularPasture
RectangularPasture_OBJECTS = \
"CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o"

# External object files for target RectangularPasture
RectangularPasture_EXTERNAL_OBJECTS =

RectangularPasture: CMakeFiles/RectangularPasture.dir/RectangularPasture.cpp.o
RectangularPasture: CMakeFiles/RectangularPasture.dir/build.make
RectangularPasture: CMakeFiles/RectangularPasture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RectangularPasture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RectangularPasture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RectangularPasture.dir/build: RectangularPasture

.PHONY : CMakeFiles/RectangularPasture.dir/build

CMakeFiles/RectangularPasture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RectangularPasture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RectangularPasture.dir/clean

CMakeFiles/RectangularPasture.dir/depend:
	cd /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/RectangularPasture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RectangularPasture.dir/depend

