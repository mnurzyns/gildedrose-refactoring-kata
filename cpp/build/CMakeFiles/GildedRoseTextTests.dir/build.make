# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/paro/Pulpit/gildedrose-refactoring-kata/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/GildedRoseTextTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GildedRoseTextTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GildedRoseTextTests.dir/flags.make

CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.o: CMakeFiles/GildedRoseTextTests.dir/flags.make
CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.o: ../GildedRose.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.o -c /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/GildedRose.cc

CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/GildedRose.cc > CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.i

CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/GildedRose.cc -o CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.s

CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.o: CMakeFiles/GildedRoseTextTests.dir/flags.make
CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.o: ../GildedRoseTextTests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.o -c /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/GildedRoseTextTests.cc

CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/GildedRoseTextTests.cc > CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.i

CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/GildedRoseTextTests.cc -o CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.s

# Object files for target GildedRoseTextTests
GildedRoseTextTests_OBJECTS = \
"CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.o" \
"CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.o"

# External object files for target GildedRoseTextTests
GildedRoseTextTests_EXTERNAL_OBJECTS =

GildedRoseTextTests: CMakeFiles/GildedRoseTextTests.dir/GildedRose.cc.o
GildedRoseTextTests: CMakeFiles/GildedRoseTextTests.dir/GildedRoseTextTests.cc.o
GildedRoseTextTests: CMakeFiles/GildedRoseTextTests.dir/build.make
GildedRoseTextTests: googletest-prefix/src/googletest-build/lib/libgtest_main.a
GildedRoseTextTests: googletest-prefix/src/googletest-build/lib/libgtest.a
GildedRoseTextTests: googletest-prefix/src/googletest-build/lib/libgmock_main.a
GildedRoseTextTests: googletest-prefix/src/googletest-build/lib/libgmock.a
GildedRoseTextTests: CMakeFiles/GildedRoseTextTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GildedRoseTextTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GildedRoseTextTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GildedRoseTextTests.dir/build: GildedRoseTextTests

.PHONY : CMakeFiles/GildedRoseTextTests.dir/build

CMakeFiles/GildedRoseTextTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GildedRoseTextTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GildedRoseTextTests.dir/clean

CMakeFiles/GildedRoseTextTests.dir/depend:
	cd /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paro/Pulpit/gildedrose-refactoring-kata/cpp /home/paro/Pulpit/gildedrose-refactoring-kata/cpp /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build /home/paro/Pulpit/gildedrose-refactoring-kata/cpp/build/CMakeFiles/GildedRoseTextTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GildedRoseTextTests.dir/depend

