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
CMAKE_COMMAND = "/Users/ivankvasov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6461.75/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/ivankvasov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6461.75/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Controlv2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Controlv2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Controlv2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Controlv2.dir/flags.make

CMakeFiles/Controlv2.dir/main.cpp.o: CMakeFiles/Controlv2.dir/flags.make
CMakeFiles/Controlv2.dir/main.cpp.o: ../main.cpp
CMakeFiles/Controlv2.dir/main.cpp.o: CMakeFiles/Controlv2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Controlv2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Controlv2.dir/main.cpp.o -MF CMakeFiles/Controlv2.dir/main.cpp.o.d -o CMakeFiles/Controlv2.dir/main.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/main.cpp

CMakeFiles/Controlv2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controlv2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/main.cpp > CMakeFiles/Controlv2.dir/main.cpp.i

CMakeFiles/Controlv2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controlv2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/main.cpp -o CMakeFiles/Controlv2.dir/main.cpp.s

CMakeFiles/Controlv2.dir/Junior.cpp.o: CMakeFiles/Controlv2.dir/flags.make
CMakeFiles/Controlv2.dir/Junior.cpp.o: ../Junior.cpp
CMakeFiles/Controlv2.dir/Junior.cpp.o: CMakeFiles/Controlv2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Controlv2.dir/Junior.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Controlv2.dir/Junior.cpp.o -MF CMakeFiles/Controlv2.dir/Junior.cpp.o.d -o CMakeFiles/Controlv2.dir/Junior.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Junior.cpp

CMakeFiles/Controlv2.dir/Junior.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controlv2.dir/Junior.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Junior.cpp > CMakeFiles/Controlv2.dir/Junior.cpp.i

CMakeFiles/Controlv2.dir/Junior.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controlv2.dir/Junior.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Junior.cpp -o CMakeFiles/Controlv2.dir/Junior.cpp.s

CMakeFiles/Controlv2.dir/Senior.cpp.o: CMakeFiles/Controlv2.dir/flags.make
CMakeFiles/Controlv2.dir/Senior.cpp.o: ../Senior.cpp
CMakeFiles/Controlv2.dir/Senior.cpp.o: CMakeFiles/Controlv2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Controlv2.dir/Senior.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Controlv2.dir/Senior.cpp.o -MF CMakeFiles/Controlv2.dir/Senior.cpp.o.d -o CMakeFiles/Controlv2.dir/Senior.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Senior.cpp

CMakeFiles/Controlv2.dir/Senior.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controlv2.dir/Senior.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Senior.cpp > CMakeFiles/Controlv2.dir/Senior.cpp.i

CMakeFiles/Controlv2.dir/Senior.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controlv2.dir/Senior.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Senior.cpp -o CMakeFiles/Controlv2.dir/Senior.cpp.s

CMakeFiles/Controlv2.dir/TableStudents.cpp.o: CMakeFiles/Controlv2.dir/flags.make
CMakeFiles/Controlv2.dir/TableStudents.cpp.o: ../TableStudents.cpp
CMakeFiles/Controlv2.dir/TableStudents.cpp.o: CMakeFiles/Controlv2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Controlv2.dir/TableStudents.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Controlv2.dir/TableStudents.cpp.o -MF CMakeFiles/Controlv2.dir/TableStudents.cpp.o.d -o CMakeFiles/Controlv2.dir/TableStudents.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/TableStudents.cpp

CMakeFiles/Controlv2.dir/TableStudents.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controlv2.dir/TableStudents.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/TableStudents.cpp > CMakeFiles/Controlv2.dir/TableStudents.cpp.i

CMakeFiles/Controlv2.dir/TableStudents.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controlv2.dir/TableStudents.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/TableStudents.cpp -o CMakeFiles/Controlv2.dir/TableStudents.cpp.s

CMakeFiles/Controlv2.dir/TableGroup.cpp.o: CMakeFiles/Controlv2.dir/flags.make
CMakeFiles/Controlv2.dir/TableGroup.cpp.o: ../TableGroup.cpp
CMakeFiles/Controlv2.dir/TableGroup.cpp.o: CMakeFiles/Controlv2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Controlv2.dir/TableGroup.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Controlv2.dir/TableGroup.cpp.o -MF CMakeFiles/Controlv2.dir/TableGroup.cpp.o.d -o CMakeFiles/Controlv2.dir/TableGroup.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/TableGroup.cpp

CMakeFiles/Controlv2.dir/TableGroup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controlv2.dir/TableGroup.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/TableGroup.cpp > CMakeFiles/Controlv2.dir/TableGroup.cpp.i

CMakeFiles/Controlv2.dir/TableGroup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controlv2.dir/TableGroup.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/TableGroup.cpp -o CMakeFiles/Controlv2.dir/TableGroup.cpp.s

CMakeFiles/Controlv2.dir/Console.cpp.o: CMakeFiles/Controlv2.dir/flags.make
CMakeFiles/Controlv2.dir/Console.cpp.o: ../Console.cpp
CMakeFiles/Controlv2.dir/Console.cpp.o: CMakeFiles/Controlv2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Controlv2.dir/Console.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Controlv2.dir/Console.cpp.o -MF CMakeFiles/Controlv2.dir/Console.cpp.o.d -o CMakeFiles/Controlv2.dir/Console.cpp.o -c /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Console.cpp

CMakeFiles/Controlv2.dir/Console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Controlv2.dir/Console.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Console.cpp > CMakeFiles/Controlv2.dir/Console.cpp.i

CMakeFiles/Controlv2.dir/Console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Controlv2.dir/Console.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/Console.cpp -o CMakeFiles/Controlv2.dir/Console.cpp.s

# Object files for target Controlv2
Controlv2_OBJECTS = \
"CMakeFiles/Controlv2.dir/main.cpp.o" \
"CMakeFiles/Controlv2.dir/Junior.cpp.o" \
"CMakeFiles/Controlv2.dir/Senior.cpp.o" \
"CMakeFiles/Controlv2.dir/TableStudents.cpp.o" \
"CMakeFiles/Controlv2.dir/TableGroup.cpp.o" \
"CMakeFiles/Controlv2.dir/Console.cpp.o"

# External object files for target Controlv2
Controlv2_EXTERNAL_OBJECTS =

Controlv2: CMakeFiles/Controlv2.dir/main.cpp.o
Controlv2: CMakeFiles/Controlv2.dir/Junior.cpp.o
Controlv2: CMakeFiles/Controlv2.dir/Senior.cpp.o
Controlv2: CMakeFiles/Controlv2.dir/TableStudents.cpp.o
Controlv2: CMakeFiles/Controlv2.dir/TableGroup.cpp.o
Controlv2: CMakeFiles/Controlv2.dir/Console.cpp.o
Controlv2: CMakeFiles/Controlv2.dir/build.make
Controlv2: CMakeFiles/Controlv2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Controlv2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Controlv2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Controlv2.dir/build: Controlv2
.PHONY : CMakeFiles/Controlv2.dir/build

CMakeFiles/Controlv2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Controlv2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Controlv2.dir/clean

CMakeFiles/Controlv2.dir/depend:
	cd /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2 /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2 /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug /Users/ivankvasov/OOP/OOP-MEPhI/Controlv2/cmake-build-debug/CMakeFiles/Controlv2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Controlv2.dir/depend

