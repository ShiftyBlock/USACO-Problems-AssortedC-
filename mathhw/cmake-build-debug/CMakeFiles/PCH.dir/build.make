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
include CMakeFiles/PCH.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PCH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PCH.dir/flags.make

CMakeFiles/PCH.dir/cmake_pch.hxx.gch: CMakeFiles/PCH.dir/flags.make
CMakeFiles/PCH.dir/cmake_pch.hxx.gch: CMakeFiles/PCH.dir/cmake_pch.hxx.cxx
CMakeFiles/PCH.dir/cmake_pch.hxx.gch: CMakeFiles/PCH.dir/cmake_pch.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PCH.dir/cmake_pch.hxx.gch"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/PCH.dir/cmake_pch.hxx.gch -c /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx.cxx

CMakeFiles/PCH.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCH.dir/cmake_pch.hxx.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx.cxx > CMakeFiles/PCH.dir/cmake_pch.hxx.i

CMakeFiles/PCH.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCH.dir/cmake_pch.hxx.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx.cxx -o CMakeFiles/PCH.dir/cmake_pch.hxx.s

CMakeFiles/PCH.dir/pch.cpp.o: CMakeFiles/PCH.dir/flags.make
CMakeFiles/PCH.dir/pch.cpp.o: pch.cpp
CMakeFiles/PCH.dir/pch.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx
CMakeFiles/PCH.dir/pch.cpp.o: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PCH.dir/pch.cpp.o"
	/usr/local/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -o CMakeFiles/PCH.dir/pch.cpp.o -c /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/pch.cpp

CMakeFiles/PCH.dir/pch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCH.dir/pch.cpp.i"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -E /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/pch.cpp > CMakeFiles/PCH.dir/pch.cpp.i

CMakeFiles/PCH.dir/pch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCH.dir/pch.cpp.s"
	/usr/local/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/cmake_pch.hxx -S /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/pch.cpp -o CMakeFiles/PCH.dir/pch.cpp.s

PCH: CMakeFiles/PCH.dir/cmake_pch.hxx.gch
PCH: CMakeFiles/PCH.dir/pch.cpp.o
PCH: CMakeFiles/PCH.dir/build.make

.PHONY : PCH

# Rule to build all files generated by this target.
CMakeFiles/PCH.dir/build: PCH

.PHONY : CMakeFiles/PCH.dir/build

CMakeFiles/PCH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PCH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PCH.dir/clean

CMakeFiles/PCH.dir/depend:
	cd /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shiftyblock/CLionProjects/NekoHW /Users/shiftyblock/CLionProjects/NekoHW /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug /Users/shiftyblock/CLionProjects/NekoHW/cmake-build-debug/CMakeFiles/PCH.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PCH.dir/depend

