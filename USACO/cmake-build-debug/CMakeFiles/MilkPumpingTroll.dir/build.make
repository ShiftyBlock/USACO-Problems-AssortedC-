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
include CMakeFiles/MilkPumpingTroll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MilkPumpingTroll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MilkPumpingTroll.dir/flags.make

CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o: CMakeFiles/MilkPumpingTroll.dir/flags.make
CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o: ../MilkPumpingTroll.cpp
CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o -c /Users/shiftyblock/CLionProjects/USACO/MilkPumpingTroll.cpp

CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/USACO/MilkPumpingTroll.cpp > CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.i

CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/USACO/MilkPumpingTroll.cpp -o CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.s

# Object files for target MilkPumpingTroll
MilkPumpingTroll_OBJECTS = \
"CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o"

# External object files for target MilkPumpingTroll
MilkPumpingTroll_EXTERNAL_OBJECTS =

MilkPumpingTroll: CMakeFiles/MilkPumpingTroll.dir/MilkPumpingTroll.cpp.o
MilkPumpingTroll: CMakeFiles/MilkPumpingTroll.dir/build.make
MilkPumpingTroll: CMakeFiles/MilkPumpingTroll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MilkPumpingTroll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MilkPumpingTroll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MilkPumpingTroll.dir/build: MilkPumpingTroll

.PHONY : CMakeFiles/MilkPumpingTroll.dir/build

CMakeFiles/MilkPumpingTroll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MilkPumpingTroll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MilkPumpingTroll.dir/clean

CMakeFiles/MilkPumpingTroll.dir/depend:
	cd /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug /Users/shiftyblock/CLionProjects/USACO/cmake-build-debug/CMakeFiles/MilkPumpingTroll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MilkPumpingTroll.dir/depend

