# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/cmake-3.26.5-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.26.5-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rishi/Documents/C/DoomDepthsC-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rishi/Documents/C/DoomDepthsC-main

# Include any dependencies generated for this target.
include CMakeFiles/DoomDepthsC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DoomDepthsC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DoomDepthsC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DoomDepthsC.dir/flags.make

CMakeFiles/DoomDepthsC.dir/main.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/main.c.o: main.c
CMakeFiles/DoomDepthsC.dir/main.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DoomDepthsC.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/main.c.o -MF CMakeFiles/DoomDepthsC.dir/main.c.o.d -o CMakeFiles/DoomDepthsC.dir/main.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/main.c

CMakeFiles/DoomDepthsC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/main.c > CMakeFiles/DoomDepthsC.dir/main.c.i

CMakeFiles/DoomDepthsC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/main.c -o CMakeFiles/DoomDepthsC.dir/main.c.s

CMakeFiles/DoomDepthsC.dir/creationmap.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/creationmap.c.o: creationmap.c
CMakeFiles/DoomDepthsC.dir/creationmap.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DoomDepthsC.dir/creationmap.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/creationmap.c.o -MF CMakeFiles/DoomDepthsC.dir/creationmap.c.o.d -o CMakeFiles/DoomDepthsC.dir/creationmap.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/creationmap.c

CMakeFiles/DoomDepthsC.dir/creationmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/creationmap.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/creationmap.c > CMakeFiles/DoomDepthsC.dir/creationmap.c.i

CMakeFiles/DoomDepthsC.dir/creationmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/creationmap.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/creationmap.c -o CMakeFiles/DoomDepthsC.dir/creationmap.c.s

CMakeFiles/DoomDepthsC.dir/CaseAction.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/CaseAction.c.o: CaseAction.c
CMakeFiles/DoomDepthsC.dir/CaseAction.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/DoomDepthsC.dir/CaseAction.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/CaseAction.c.o -MF CMakeFiles/DoomDepthsC.dir/CaseAction.c.o.d -o CMakeFiles/DoomDepthsC.dir/CaseAction.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/CaseAction.c

CMakeFiles/DoomDepthsC.dir/CaseAction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/CaseAction.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/CaseAction.c > CMakeFiles/DoomDepthsC.dir/CaseAction.c.i

CMakeFiles/DoomDepthsC.dir/CaseAction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/CaseAction.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/CaseAction.c -o CMakeFiles/DoomDepthsC.dir/CaseAction.c.s

CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o: shopInventaire.c
CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o -MF CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o.d -o CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/shopInventaire.c

CMakeFiles/DoomDepthsC.dir/shopInventaire.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/shopInventaire.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/shopInventaire.c > CMakeFiles/DoomDepthsC.dir/shopInventaire.c.i

CMakeFiles/DoomDepthsC.dir/shopInventaire.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/shopInventaire.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/shopInventaire.c -o CMakeFiles/DoomDepthsC.dir/shopInventaire.c.s

CMakeFiles/DoomDepthsC.dir/combat.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/combat.c.o: combat.c
CMakeFiles/DoomDepthsC.dir/combat.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/DoomDepthsC.dir/combat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/combat.c.o -MF CMakeFiles/DoomDepthsC.dir/combat.c.o.d -o CMakeFiles/DoomDepthsC.dir/combat.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/combat.c

CMakeFiles/DoomDepthsC.dir/combat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/combat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/combat.c > CMakeFiles/DoomDepthsC.dir/combat.c.i

CMakeFiles/DoomDepthsC.dir/combat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/combat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/combat.c -o CMakeFiles/DoomDepthsC.dir/combat.c.s

CMakeFiles/DoomDepthsC.dir/Player.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/Player.c.o: Player.c
CMakeFiles/DoomDepthsC.dir/Player.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/DoomDepthsC.dir/Player.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/Player.c.o -MF CMakeFiles/DoomDepthsC.dir/Player.c.o.d -o CMakeFiles/DoomDepthsC.dir/Player.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/Player.c

CMakeFiles/DoomDepthsC.dir/Player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/Player.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/Player.c > CMakeFiles/DoomDepthsC.dir/Player.c.i

CMakeFiles/DoomDepthsC.dir/Player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/Player.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/Player.c -o CMakeFiles/DoomDepthsC.dir/Player.c.s

CMakeFiles/DoomDepthsC.dir/monster.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/monster.c.o: monster.c
CMakeFiles/DoomDepthsC.dir/monster.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/DoomDepthsC.dir/monster.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/monster.c.o -MF CMakeFiles/DoomDepthsC.dir/monster.c.o.d -o CMakeFiles/DoomDepthsC.dir/monster.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/monster.c

CMakeFiles/DoomDepthsC.dir/monster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/monster.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/monster.c > CMakeFiles/DoomDepthsC.dir/monster.c.i

CMakeFiles/DoomDepthsC.dir/monster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/monster.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/monster.c -o CMakeFiles/DoomDepthsC.dir/monster.c.s

CMakeFiles/DoomDepthsC.dir/affichage.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/affichage.c.o: affichage.c
CMakeFiles/DoomDepthsC.dir/affichage.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/DoomDepthsC.dir/affichage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/affichage.c.o -MF CMakeFiles/DoomDepthsC.dir/affichage.c.o.d -o CMakeFiles/DoomDepthsC.dir/affichage.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/affichage.c

CMakeFiles/DoomDepthsC.dir/affichage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/affichage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/affichage.c > CMakeFiles/DoomDepthsC.dir/affichage.c.i

CMakeFiles/DoomDepthsC.dir/affichage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/affichage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/affichage.c -o CMakeFiles/DoomDepthsC.dir/affichage.c.s

CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o: CMakeFiles/DoomDepthsC.dir/flags.make
CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o: sauvegarde_player.c
CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o: CMakeFiles/DoomDepthsC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o -MF CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o.d -o CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o -c /home/rishi/Documents/C/DoomDepthsC-main/sauvegarde_player.c

CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rishi/Documents/C/DoomDepthsC-main/sauvegarde_player.c > CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.i

CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rishi/Documents/C/DoomDepthsC-main/sauvegarde_player.c -o CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.s

# Object files for target DoomDepthsC
DoomDepthsC_OBJECTS = \
"CMakeFiles/DoomDepthsC.dir/main.c.o" \
"CMakeFiles/DoomDepthsC.dir/creationmap.c.o" \
"CMakeFiles/DoomDepthsC.dir/CaseAction.c.o" \
"CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o" \
"CMakeFiles/DoomDepthsC.dir/combat.c.o" \
"CMakeFiles/DoomDepthsC.dir/Player.c.o" \
"CMakeFiles/DoomDepthsC.dir/monster.c.o" \
"CMakeFiles/DoomDepthsC.dir/affichage.c.o" \
"CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o"

# External object files for target DoomDepthsC
DoomDepthsC_EXTERNAL_OBJECTS =

DoomDepthsC: CMakeFiles/DoomDepthsC.dir/main.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/creationmap.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/CaseAction.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/combat.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/Player.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/monster.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/affichage.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/build.make
DoomDepthsC: CMakeFiles/DoomDepthsC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable DoomDepthsC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DoomDepthsC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DoomDepthsC.dir/build: DoomDepthsC
.PHONY : CMakeFiles/DoomDepthsC.dir/build

CMakeFiles/DoomDepthsC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DoomDepthsC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DoomDepthsC.dir/clean

CMakeFiles/DoomDepthsC.dir/depend:
	cd /home/rishi/Documents/C/DoomDepthsC-main && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rishi/Documents/C/DoomDepthsC-main /home/rishi/Documents/C/DoomDepthsC-main /home/rishi/Documents/C/DoomDepthsC-main /home/rishi/Documents/C/DoomDepthsC-main /home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles/DoomDepthsC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DoomDepthsC.dir/depend

