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
CMAKE_SOURCE_DIR = /Users/shiftyblock/CLionProjects/Codeforces

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hacktest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hacktest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hacktest.dir/flags.make

CMakeFiles/hacktest.dir/hacktest.cpp.o: CMakeFiles/hacktest.dir/flags.make
CMakeFiles/hacktest.dir/hacktest.cpp.o: ../hacktest.cpp
CMakeFiles/hacktest.dir/hacktest.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/hacktest.dir/hacktest.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hacktest.dir/hacktest.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/hacktest.dir/hacktest.cpp.o -c /Users/shiftyblock/CLionProjects/Codeforces/hacktest.cpp

CMakeFiles/hacktest.dir/hacktest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hacktest.dir/hacktest.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/Codeforces/hacktest.cpp > CMakeFiles/hacktest.dir/hacktest.cpp.i

CMakeFiles/hacktest.dir/hacktest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hacktest.dir/hacktest.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/Codeforces/hacktest.cpp -o CMakeFiles/hacktest.dir/hacktest.cpp.s

# Object files for target hacktest
hacktest_OBJECTS = \
"CMakeFiles/hacktest.dir/hacktest.cpp.o"

# External object files for target hacktest
hacktest_EXTERNAL_OBJECTS =

hacktest: CMakeFiles/hacktest.dir/hacktest.cpp.o
hacktest: CMakeFiles/hacktest.dir/build.make
hacktest: CMakeFiles/hacktest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hacktest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hacktest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hacktest.dir/build: hacktest

.PHONY : CMakeFiles/hacktest.dir/build

CMakeFiles/hacktest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hacktest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hacktest.dir/clean

CMakeFiles/hacktest.dir/depend:
	cd /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/Codeforces /Users/shiftyblock/CLionProjects/Codeforces /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/hacktest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hacktest.dir/depend

