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
CMAKE_SOURCE_DIR = /home/pi/Pi3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Pi3

# Include any dependencies generated for this target.
include CMakeFiles/Bike.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bike.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bike.dir/flags.make

CMakeFiles/Bike.dir/src/AD_HOC.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/AD_HOC.c.o: src/AD_HOC.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Bike.dir/src/AD_HOC.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/AD_HOC.c.o   -c /home/pi/Pi3/src/AD_HOC.c

CMakeFiles/Bike.dir/src/AD_HOC.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/AD_HOC.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/AD_HOC.c > CMakeFiles/Bike.dir/src/AD_HOC.c.i

CMakeFiles/Bike.dir/src/AD_HOC.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/AD_HOC.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/AD_HOC.c -o CMakeFiles/Bike.dir/src/AD_HOC.c.s

CMakeFiles/Bike.dir/src/AD_HOC.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/AD_HOC.c.o.requires

CMakeFiles/Bike.dir/src/AD_HOC.c.o.provides: CMakeFiles/Bike.dir/src/AD_HOC.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/AD_HOC.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/AD_HOC.c.o.provides

CMakeFiles/Bike.dir/src/AD_HOC.c.o.provides.build: CMakeFiles/Bike.dir/src/AD_HOC.c.o


CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o: src/Bluetooth_Phone.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o   -c /home/pi/Pi3/src/Bluetooth_Phone.c

CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/Bluetooth_Phone.c > CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.i

CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/Bluetooth_Phone.c -o CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.s

CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.requires

CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.provides: CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.provides

CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.provides.build: CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o


CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o: src/Bluetooth_Pi0W.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o   -c /home/pi/Pi3/src/Bluetooth_Pi0W.c

CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/Bluetooth_Pi0W.c > CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.i

CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/Bluetooth_Pi0W.c -o CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.s

CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.requires

CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.provides: CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.provides

CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.provides.build: CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o


CMakeFiles/Bike.dir/src/Button_ISR.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/Button_ISR.c.o: src/Button_ISR.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Bike.dir/src/Button_ISR.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/Button_ISR.c.o   -c /home/pi/Pi3/src/Button_ISR.c

CMakeFiles/Bike.dir/src/Button_ISR.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/Button_ISR.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/Button_ISR.c > CMakeFiles/Bike.dir/src/Button_ISR.c.i

CMakeFiles/Bike.dir/src/Button_ISR.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/Button_ISR.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/Button_ISR.c -o CMakeFiles/Bike.dir/src/Button_ISR.c.s

CMakeFiles/Bike.dir/src/Button_ISR.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/Button_ISR.c.o.requires

CMakeFiles/Bike.dir/src/Button_ISR.c.o.provides: CMakeFiles/Bike.dir/src/Button_ISR.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/Button_ISR.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/Button_ISR.c.o.provides

CMakeFiles/Bike.dir/src/Button_ISR.c.o.provides.build: CMakeFiles/Bike.dir/src/Button_ISR.c.o


CMakeFiles/Bike.dir/src/OBDII.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/OBDII.c.o: src/OBDII.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Bike.dir/src/OBDII.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/OBDII.c.o   -c /home/pi/Pi3/src/OBDII.c

CMakeFiles/Bike.dir/src/OBDII.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/OBDII.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/OBDII.c > CMakeFiles/Bike.dir/src/OBDII.c.i

CMakeFiles/Bike.dir/src/OBDII.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/OBDII.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/OBDII.c -o CMakeFiles/Bike.dir/src/OBDII.c.s

CMakeFiles/Bike.dir/src/OBDII.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/OBDII.c.o.requires

CMakeFiles/Bike.dir/src/OBDII.c.o.provides: CMakeFiles/Bike.dir/src/OBDII.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/OBDII.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/OBDII.c.o.provides

CMakeFiles/Bike.dir/src/OBDII.c.o.provides.build: CMakeFiles/Bike.dir/src/OBDII.c.o


CMakeFiles/Bike.dir/src/SerialDriver.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/SerialDriver.c.o: src/SerialDriver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Bike.dir/src/SerialDriver.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/SerialDriver.c.o   -c /home/pi/Pi3/src/SerialDriver.c

CMakeFiles/Bike.dir/src/SerialDriver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/SerialDriver.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/SerialDriver.c > CMakeFiles/Bike.dir/src/SerialDriver.c.i

CMakeFiles/Bike.dir/src/SerialDriver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/SerialDriver.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/SerialDriver.c -o CMakeFiles/Bike.dir/src/SerialDriver.c.s

CMakeFiles/Bike.dir/src/SerialDriver.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/SerialDriver.c.o.requires

CMakeFiles/Bike.dir/src/SerialDriver.c.o.provides: CMakeFiles/Bike.dir/src/SerialDriver.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/SerialDriver.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/SerialDriver.c.o.provides

CMakeFiles/Bike.dir/src/SerialDriver.c.o.provides.build: CMakeFiles/Bike.dir/src/SerialDriver.c.o


CMakeFiles/Bike.dir/src/VoiceCommands.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/VoiceCommands.c.o: src/VoiceCommands.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Bike.dir/src/VoiceCommands.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/VoiceCommands.c.o   -c /home/pi/Pi3/src/VoiceCommands.c

CMakeFiles/Bike.dir/src/VoiceCommands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/VoiceCommands.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/VoiceCommands.c > CMakeFiles/Bike.dir/src/VoiceCommands.c.i

CMakeFiles/Bike.dir/src/VoiceCommands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/VoiceCommands.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/VoiceCommands.c -o CMakeFiles/Bike.dir/src/VoiceCommands.c.s

CMakeFiles/Bike.dir/src/VoiceCommands.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/VoiceCommands.c.o.requires

CMakeFiles/Bike.dir/src/VoiceCommands.c.o.provides: CMakeFiles/Bike.dir/src/VoiceCommands.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/VoiceCommands.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/VoiceCommands.c.o.provides

CMakeFiles/Bike.dir/src/VoiceCommands.c.o.provides.build: CMakeFiles/Bike.dir/src/VoiceCommands.c.o


CMakeFiles/Bike.dir/src/main.c.o: CMakeFiles/Bike.dir/flags.make
CMakeFiles/Bike.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Bike.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bike.dir/src/main.c.o   -c /home/pi/Pi3/src/main.c

CMakeFiles/Bike.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bike.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Pi3/src/main.c > CMakeFiles/Bike.dir/src/main.c.i

CMakeFiles/Bike.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bike.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Pi3/src/main.c -o CMakeFiles/Bike.dir/src/main.c.s

CMakeFiles/Bike.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/Bike.dir/src/main.c.o.requires

CMakeFiles/Bike.dir/src/main.c.o.provides: CMakeFiles/Bike.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/Bike.dir/build.make CMakeFiles/Bike.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/Bike.dir/src/main.c.o.provides

CMakeFiles/Bike.dir/src/main.c.o.provides.build: CMakeFiles/Bike.dir/src/main.c.o


# Object files for target Bike
Bike_OBJECTS = \
"CMakeFiles/Bike.dir/src/AD_HOC.c.o" \
"CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o" \
"CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o" \
"CMakeFiles/Bike.dir/src/Button_ISR.c.o" \
"CMakeFiles/Bike.dir/src/OBDII.c.o" \
"CMakeFiles/Bike.dir/src/SerialDriver.c.o" \
"CMakeFiles/Bike.dir/src/VoiceCommands.c.o" \
"CMakeFiles/Bike.dir/src/main.c.o"

# External object files for target Bike
Bike_EXTERNAL_OBJECTS =

Bike: CMakeFiles/Bike.dir/src/AD_HOC.c.o
Bike: CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o
Bike: CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o
Bike: CMakeFiles/Bike.dir/src/Button_ISR.c.o
Bike: CMakeFiles/Bike.dir/src/OBDII.c.o
Bike: CMakeFiles/Bike.dir/src/SerialDriver.c.o
Bike: CMakeFiles/Bike.dir/src/VoiceCommands.c.o
Bike: CMakeFiles/Bike.dir/src/main.c.o
Bike: CMakeFiles/Bike.dir/build.make
Bike: CMakeFiles/Bike.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Pi3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable Bike"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bike.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bike.dir/build: Bike

.PHONY : CMakeFiles/Bike.dir/build

CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/AD_HOC.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/Bluetooth_Phone.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/Bluetooth_Pi0W.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/Button_ISR.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/OBDII.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/SerialDriver.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/VoiceCommands.c.o.requires
CMakeFiles/Bike.dir/requires: CMakeFiles/Bike.dir/src/main.c.o.requires

.PHONY : CMakeFiles/Bike.dir/requires

CMakeFiles/Bike.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bike.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bike.dir/clean

CMakeFiles/Bike.dir/depend:
	cd /home/pi/Pi3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Pi3 /home/pi/Pi3 /home/pi/Pi3 /home/pi/Pi3 /home/pi/Pi3/CMakeFiles/Bike.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bike.dir/depend

