# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DiagramDynamic.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DiagramDynamic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiagramDynamic.dir/flags.make

CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.obj: CMakeFiles/DiagramDynamic.dir/flags.make
CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.obj: ../src/Diagram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DiagramDynamic.dir\src\Diagram.cpp.obj -c C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\src\Diagram.cpp

CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\src\Diagram.cpp > CMakeFiles\DiagramDynamic.dir\src\Diagram.cpp.i

CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\src\Diagram.cpp -o CMakeFiles\DiagramDynamic.dir\src\Diagram.cpp.s

CMakeFiles/DiagramDynamic.dir/src/func.cpp.obj: CMakeFiles/DiagramDynamic.dir/flags.make
CMakeFiles/DiagramDynamic.dir/src/func.cpp.obj: ../src/func.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DiagramDynamic.dir/src/func.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DiagramDynamic.dir\src\func.cpp.obj -c C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\src\func.cpp

CMakeFiles/DiagramDynamic.dir/src/func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiagramDynamic.dir/src/func.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\src\func.cpp > CMakeFiles\DiagramDynamic.dir\src\func.cpp.i

CMakeFiles/DiagramDynamic.dir/src/func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiagramDynamic.dir/src/func.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\src\func.cpp -o CMakeFiles\DiagramDynamic.dir\src\func.cpp.s

# Object files for target DiagramDynamic
DiagramDynamic_OBJECTS = \
"CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.obj" \
"CMakeFiles/DiagramDynamic.dir/src/func.cpp.obj"

# External object files for target DiagramDynamic
DiagramDynamic_EXTERNAL_OBJECTS =

libDiagramDynamic.a: CMakeFiles/DiagramDynamic.dir/src/Diagram.cpp.obj
libDiagramDynamic.a: CMakeFiles/DiagramDynamic.dir/src/func.cpp.obj
libDiagramDynamic.a: CMakeFiles/DiagramDynamic.dir/build.make
libDiagramDynamic.a: CMakeFiles/DiagramDynamic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libDiagramDynamic.a"
	$(CMAKE_COMMAND) -P CMakeFiles\DiagramDynamic.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DiagramDynamic.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiagramDynamic.dir/build: libDiagramDynamic.a
.PHONY : CMakeFiles/DiagramDynamic.dir/build

CMakeFiles/DiagramDynamic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DiagramDynamic.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DiagramDynamic.dir/clean

CMakeFiles/DiagramDynamic.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug C:\Users\Ivan\CLionProjects\DiagramDynamic\Lib\cmake-build-debug\CMakeFiles\DiagramDynamic.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiagramDynamic.dir/depend

