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
CMAKE_SOURCE_DIR = /Users/shiftyblock/CLionProjects/NekoHW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ModularArithmetic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ModularArithmetic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ModularArithmetic.dir/flags.make

CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o: CMakeFiles/ModularArithmetic.dir/flags.make
CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o: ../ModularArithmetic.cpp
CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o -c /Users/shiftyblock/CLionProjects/NekoHW/ModularArithmetic.cpp

CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/NekoHW/ModularArithmetic.cpp > CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.i

CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/NekoHW/ModularArithmetic.cpp -o CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.s

# Object files for target ModularArithmetic
ModularArithmetic_OBJECTS = \
"CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o"

# External object files for target ModularArithmetic
ModularArithmetic_EXTERNAL_OBJECTS =

ModularArithmetic: CMakeFiles/ModularArithmetic.dir/ModularArithmetic.cpp.o
ModularArithmetic: CMakeFiles/ModularArithmetic.dir/build.make
ModularArithmetic: CMakeFiles/ModularArithmetic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ModularArithmetic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ModularArithmetic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ModularArithmetic.dir/build: ModularArithmetic

.PHONY : CMakeFiles/ModularArithmetic.dir/build

CMakeFiles/ModularArithmetic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ModularArithmetic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ModularArithmetic.dir/clean

CMakeFiles/ModularArithmetic.dir/depend:
	cd /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/NekoHW /Users/shiftyblock/CLionProjects/NekoHW /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/ModularArithmetic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ModularArithmetic.dir/depend

