# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/pi3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/pi3

# Include any dependencies generated for this target.
include sphinxbase/CMakeFiles/SphinxBase.dir/depend.make

# Include the progress variables for this target.
include sphinxbase/CMakeFiles/SphinxBase.dir/progress.make

# Include the compile flags for this target's objects.
include sphinxbase/CMakeFiles/SphinxBase.dir/flags.make

sphinxbase/sb.cpp:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating swig bindings"
	cd /home/pi/pi3/sphinxbase && swig -I/usr/local/share/sphinxbase/swig -javascript -node -DV8_VERSION=0x032872 -o sb.cpp /usr/local/share/sphinxbase/swig/sphinxbase.i

sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o: sphinxbase/CMakeFiles/SphinxBase.dir/flags.make
sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o: sphinxbase/sb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o"
	cd /home/pi/pi3/sphinxbase && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SphinxBase.dir/sb.cpp.o -c /home/pi/pi3/sphinxbase/sb.cpp

sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SphinxBase.dir/sb.cpp.i"
	cd /home/pi/pi3/sphinxbase && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/pi3/sphinxbase/sb.cpp > CMakeFiles/SphinxBase.dir/sb.cpp.i

sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SphinxBase.dir/sb.cpp.s"
	cd /home/pi/pi3/sphinxbase && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/pi3/sphinxbase/sb.cpp -o CMakeFiles/SphinxBase.dir/sb.cpp.s

sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.requires:

.PHONY : sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.requires

sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.provides: sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.requires
	$(MAKE) -f sphinxbase/CMakeFiles/SphinxBase.dir/build.make sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.provides.build
.PHONY : sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.provides

sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.provides.build: sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o


# Object files for target SphinxBase
SphinxBase_OBJECTS = \
"CMakeFiles/SphinxBase.dir/sb.cpp.o"

# External object files for target SphinxBase
SphinxBase_EXTERNAL_OBJECTS =

sphinxbase/SphinxBase.node: sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o
sphinxbase/SphinxBase.node: sphinxbase/CMakeFiles/SphinxBase.dir/build.make
sphinxbase/SphinxBase.node: sphinxbase/CMakeFiles/SphinxBase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library SphinxBase.node"
	cd /home/pi/pi3/sphinxbase && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SphinxBase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sphinxbase/CMakeFiles/SphinxBase.dir/build: sphinxbase/SphinxBase.node

.PHONY : sphinxbase/CMakeFiles/SphinxBase.dir/build

sphinxbase/CMakeFiles/SphinxBase.dir/requires: sphinxbase/CMakeFiles/SphinxBase.dir/sb.cpp.o.requires

.PHONY : sphinxbase/CMakeFiles/SphinxBase.dir/requires

sphinxbase/CMakeFiles/SphinxBase.dir/clean:
	cd /home/pi/pi3/sphinxbase && $(CMAKE_COMMAND) -P CMakeFiles/SphinxBase.dir/cmake_clean.cmake
.PHONY : sphinxbase/CMakeFiles/SphinxBase.dir/clean

sphinxbase/CMakeFiles/SphinxBase.dir/depend: sphinxbase/sb.cpp
	cd /home/pi/pi3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/pi3 /home/pi/pi3/sphinxbase /home/pi/pi3 /home/pi/pi3/sphinxbase /home/pi/pi3/sphinxbase/CMakeFiles/SphinxBase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sphinxbase/CMakeFiles/SphinxBase.dir/depend

