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
CMAKE_SOURCE_DIR = /Users/shiftyblock/CLionProjects/FHC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stuckrut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stuckrut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stuckrut.dir/flags.make

CMakeFiles/stuckrut.dir/stuckrut.cpp.o: CMakeFiles/stuckrut.dir/flags.make
CMakeFiles/stuckrut.dir/stuckrut.cpp.o: ../stuckrut.cpp
CMakeFiles/stuckrut.dir/stuckrut.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/stuckrut.dir/stuckrut.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stuckrut.dir/stuckrut.cpp.o"
	/usr/local/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/stuckrut.dir/stuckrut.cpp.o -c /Users/shiftyblock/CLionProjects/FHC/stuckrut.cpp

CMakeFiles/stuckrut.dir/stuckrut.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stuckrut.dir/stuckrut.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/FHC/stuckrut.cpp > CMakeFiles/stuckrut.dir/stuckrut.cpp.i

CMakeFiles/stuckrut.dir/stuckrut.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stuckrut.dir/stuckrut.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/FHC/stuckrut.cpp -o CMakeFiles/stuckrut.dir/stuckrut.cpp.s

# Object files for target stuckrut
stuckrut_OBJECTS = \
"CMakeFiles/stuckrut.dir/stuckrut.cpp.o"

# External object files for target stuckrut
stuckrut_EXTERNAL_OBJECTS =

stuckrut: CMakeFiles/stuckrut.dir/stuckrut.cpp.o
stuckrut: CMakeFiles/stuckrut.dir/build.make
stuckrut: CMakeFiles/stuckrut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stuckrut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stuckrut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stuckrut.dir/build: stuckrut

.PHONY : CMakeFiles/stuckrut.dir/build

CMakeFiles/stuckrut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stuckrut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stuckrut.dir/clean

CMakeFiles/stuckrut.dir/depend:
	cd /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/FHC /Users/shiftyblock/CLionProjects/FHC /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/stuckrut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stuckrut.dir/depend

