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
include CMakeFiles/276-D2-D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/276-D2-D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/276-D2-D.dir/flags.make

CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o: CMakeFiles/276-D2-D.dir/flags.make
CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o: ../276-D2-D.cpp
CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o -c /Users/shiftyblock/CLionProjects/Codeforces/276-D2-D.cpp

CMakeFiles/276-D2-D.dir/276-D2-D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/276-D2-D.dir/276-D2-D.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/Codeforces/276-D2-D.cpp > CMakeFiles/276-D2-D.dir/276-D2-D.cpp.i

CMakeFiles/276-D2-D.dir/276-D2-D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/276-D2-D.dir/276-D2-D.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/Codeforces/276-D2-D.cpp -o CMakeFiles/276-D2-D.dir/276-D2-D.cpp.s

# Object files for target 276-D2-D
276__D2__D_OBJECTS = \
"CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o"

# External object files for target 276-D2-D
276__D2__D_EXTERNAL_OBJECTS =

276-D2-D: CMakeFiles/276-D2-D.dir/276-D2-D.cpp.o
276-D2-D: CMakeFiles/276-D2-D.dir/build.make
276-D2-D: CMakeFiles/276-D2-D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 276-D2-D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/276-D2-D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/276-D2-D.dir/build: 276-D2-D

.PHONY : CMakeFiles/276-D2-D.dir/build

CMakeFiles/276-D2-D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/276-D2-D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/276-D2-D.dir/clean

CMakeFiles/276-D2-D.dir/depend:
	cd /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/Codeforces /Users/shiftyblock/CLionProjects/Codeforces /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug /Users/shiftyblock/CLionProjects/Codeforces/cmake-build-debug/CMakeFiles/276-D2-D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/276-D2-D.dir/depend

