# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/jhg/dev/ex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhg/dev/ex/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/util.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/util.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/util.dir/flags.make

lib/CMakeFiles/util.dir/util.cpp.o: lib/CMakeFiles/util.dir/flags.make
lib/CMakeFiles/util.dir/util.cpp.o: ../lib/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhg/dev/ex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/util.dir/util.cpp.o"
	cd /home/jhg/dev/ex/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/util.dir/util.cpp.o -c /home/jhg/dev/ex/lib/util.cpp

lib/CMakeFiles/util.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/util.cpp.i"
	cd /home/jhg/dev/ex/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhg/dev/ex/lib/util.cpp > CMakeFiles/util.dir/util.cpp.i

lib/CMakeFiles/util.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/util.cpp.s"
	cd /home/jhg/dev/ex/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhg/dev/ex/lib/util.cpp -o CMakeFiles/util.dir/util.cpp.s

lib/CMakeFiles/util.dir/util.cpp.o.requires:

.PHONY : lib/CMakeFiles/util.dir/util.cpp.o.requires

lib/CMakeFiles/util.dir/util.cpp.o.provides: lib/CMakeFiles/util.dir/util.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/util.dir/build.make lib/CMakeFiles/util.dir/util.cpp.o.provides.build
.PHONY : lib/CMakeFiles/util.dir/util.cpp.o.provides

lib/CMakeFiles/util.dir/util.cpp.o.provides.build: lib/CMakeFiles/util.dir/util.cpp.o


# Object files for target util
util_OBJECTS = \
"CMakeFiles/util.dir/util.cpp.o"

# External object files for target util
util_EXTERNAL_OBJECTS =

lib/libutil.a: lib/CMakeFiles/util.dir/util.cpp.o
lib/libutil.a: lib/CMakeFiles/util.dir/build.make
lib/libutil.a: lib/CMakeFiles/util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jhg/dev/ex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutil.a"
	cd /home/jhg/dev/ex/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean_target.cmake
	cd /home/jhg/dev/ex/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/util.dir/build: lib/libutil.a

.PHONY : lib/CMakeFiles/util.dir/build

lib/CMakeFiles/util.dir/requires: lib/CMakeFiles/util.dir/util.cpp.o.requires

.PHONY : lib/CMakeFiles/util.dir/requires

lib/CMakeFiles/util.dir/clean:
	cd /home/jhg/dev/ex/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/util.dir/clean

lib/CMakeFiles/util.dir/depend:
	cd /home/jhg/dev/ex/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jhg/dev/ex /home/jhg/dev/ex/lib /home/jhg/dev/ex/build /home/jhg/dev/ex/build/lib /home/jhg/dev/ex/build/lib/CMakeFiles/util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/util.dir/depend

