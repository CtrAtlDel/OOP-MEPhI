# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/ivankvasov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6461.46/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/ivankvasov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6461.46/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug

# Include any dependencies generated for this target.
include Main/CMakeFiles/Main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Main/CMakeFiles/Main.dir/compiler_depend.make

# Include the progress variables for this target.
include Main/CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include Main/CMakeFiles/Main.dir/flags.make

Main/CMakeFiles/Main.dir/main.cpp.o: Main/CMakeFiles/Main.dir/flags.make
Main/CMakeFiles/Main.dir/main.cpp.o: ../Main/main.cpp
Main/CMakeFiles/Main.dir/main.cpp.o: Main/CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Main/CMakeFiles/Main.dir/main.cpp.o"
	cd /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Main/CMakeFiles/Main.dir/main.cpp.o -MF CMakeFiles/Main.dir/main.cpp.o.d -o CMakeFiles/Main.dir/main.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/Main/main.cpp

Main/CMakeFiles/Main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/main.cpp.i"
	cd /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/Main/main.cpp > CMakeFiles/Main.dir/main.cpp.i

Main/CMakeFiles/Main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/main.cpp.s"
	cd /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/Main/main.cpp -o CMakeFiles/Main.dir/main.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main/Main: Main/CMakeFiles/Main.dir/main.cpp.o
Main/Main: Main/CMakeFiles/Main.dir/build.make
Main/Main: Lib/libDiagramDynamic.a
Main/Main: Main/CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main"
	cd /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Main/CMakeFiles/Main.dir/build: Main/Main
.PHONY : Main/CMakeFiles/Main.dir/build

Main/CMakeFiles/Main.dir/clean:
	cd /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main && $(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : Main/CMakeFiles/Main.dir/clean

Main/CMakeFiles/Main.dir/depend:
	cd /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/Main /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main /Users/ivankvasov/OOP/OOP-MEPhI/DiagramDynamic/cmake-build-debug/Main/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Main/CMakeFiles/Main.dir/depend
