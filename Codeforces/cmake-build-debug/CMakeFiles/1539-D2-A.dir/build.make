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
include CMakeFiles/1539-D2-A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1539-D2-A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1539-D2-A.dir/flags.make

CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o: CMakeFiles/1539-D2-A.dir/flags.make
CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o: ../1539-D2-A.cpp
CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o -c /Users/shiftyblock/CLionProjects/Codeforces/1539-D2-A.cpp

CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/Codeforces/1539-D2-A.cpp > CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.i

CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/Codeforces/1539-D2-A.cpp -o CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.s

# Object files for target 1539-D2-A
1539__D2__A_OBJECTS = \
"CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o"

# External object files for target 1539-D2-A
1539__D2__A_EXTERNAL_OBJECTS =

1539-D2-A: CMakeFiles/1539-D2-A.dir/1539-D2-A.cpp.o
1539-D2-A: CMakeFiles/1539-D2-A.dir/build.make
1539-D2-A: CMakeFiles/1539-D2-A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1539-D2-A"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1539-D2-A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1539-D2-A.dir/build: 1539-D2-A

.PHONY : CMakeFiles/1539-D2-A.dir/build

CMakeFiles/1539-D2-A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1539-D2-A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1539-D2-A.dir/clean

CMakeFiles/1539-D2-A.dir/depend:
	cd /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/Codeforces /Users/shiftyblock/CLionProjects/Codeforces /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/1539-D2-A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1539-D2-A.dir/depend

