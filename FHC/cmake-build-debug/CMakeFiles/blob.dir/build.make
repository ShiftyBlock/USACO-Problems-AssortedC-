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
include CMakeFiles/blob.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/blob.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/blob.dir/flags.make

CMakeFiles/blob.dir/blob.cpp.o: CMakeFiles/blob.dir/flags.make
CMakeFiles/blob.dir/blob.cpp.o: ../blob.cpp
CMakeFiles/blob.dir/blob.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/blob.dir/blob.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/blob.dir/blob.cpp.o"
	/usr/local/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/blob.dir/blob.cpp.o -c /Users/shiftyblock/CLionProjects/FHC/blob.cpp

CMakeFiles/blob.dir/blob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blob.dir/blob.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/FHC/blob.cpp > CMakeFiles/blob.dir/blob.cpp.i

CMakeFiles/blob.dir/blob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blob.dir/blob.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/FHC/blob.cpp -o CMakeFiles/blob.dir/blob.cpp.s

# Object files for target blob
blob_OBJECTS = \
"CMakeFiles/blob.dir/blob.cpp.o"

# External object files for target blob
blob_EXTERNAL_OBJECTS =

blob: CMakeFiles/blob.dir/blob.cpp.o
blob: CMakeFiles/blob.dir/build.make
blob: CMakeFiles/blob.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable blob"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blob.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/blob.dir/build: blob

.PHONY : CMakeFiles/blob.dir/build

CMakeFiles/blob.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/blob.dir/cmake_clean.cmake
.PHONY : CMakeFiles/blob.dir/clean

CMakeFiles/blob.dir/depend:
	cd /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/FHC /Users/shiftyblock/CLionProjects/FHC /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug /Users/shiftyblock/CLionProjects/FHC/cmake-build-debug/CMakeFiles/blob.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/blob.dir/depend

