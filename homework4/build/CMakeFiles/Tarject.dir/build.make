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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chenrenhao/cpp/homework/homework4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chenrenhao/cpp/homework/homework4/build

# Include any dependencies generated for this target.
include CMakeFiles/Tarject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tarject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tarject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tarject.dir/flags.make

CMakeFiles/Tarject.dir/src/main.cpp.o: CMakeFiles/Tarject.dir/flags.make
CMakeFiles/Tarject.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Tarject.dir/src/main.cpp.o: CMakeFiles/Tarject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenrenhao/cpp/homework/homework4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tarject.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tarject.dir/src/main.cpp.o -MF CMakeFiles/Tarject.dir/src/main.cpp.o.d -o CMakeFiles/Tarject.dir/src/main.cpp.o -c /home/chenrenhao/cpp/homework/homework4/src/main.cpp

CMakeFiles/Tarject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tarject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenrenhao/cpp/homework/homework4/src/main.cpp > CMakeFiles/Tarject.dir/src/main.cpp.i

CMakeFiles/Tarject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tarject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenrenhao/cpp/homework/homework4/src/main.cpp -o CMakeFiles/Tarject.dir/src/main.cpp.s

# Object files for target Tarject
Tarject_OBJECTS = \
"CMakeFiles/Tarject.dir/src/main.cpp.o"

# External object files for target Tarject
Tarject_EXTERNAL_OBJECTS =

Tarject: CMakeFiles/Tarject.dir/src/main.cpp.o
Tarject: CMakeFiles/Tarject.dir/build.make
Tarject: CMakeFiles/Tarject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chenrenhao/cpp/homework/homework4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tarject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tarject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tarject.dir/build: Tarject
.PHONY : CMakeFiles/Tarject.dir/build

CMakeFiles/Tarject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tarject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tarject.dir/clean

CMakeFiles/Tarject.dir/depend:
	cd /home/chenrenhao/cpp/homework/homework4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenrenhao/cpp/homework/homework4 /home/chenrenhao/cpp/homework/homework4 /home/chenrenhao/cpp/homework/homework4/build /home/chenrenhao/cpp/homework/homework4/build /home/chenrenhao/cpp/homework/homework4/build/CMakeFiles/Tarject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tarject.dir/depend

