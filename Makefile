# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/cmake-3.26.5-linux-x86_64/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/cmake-3.26.5-linux-x86_64/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles /home/rishi/Documents/C/DoomDepthsC-main//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rishi/Documents/C/DoomDepthsC-main/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DoomDepthsC

# Build rule for target.
DoomDepthsC: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 DoomDepthsC
.PHONY : DoomDepthsC

# fast build rule for target.
DoomDepthsC/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/build
.PHONY : DoomDepthsC/fast

CaseAction.o: CaseAction.c.o
.PHONY : CaseAction.o

# target to build an object file
CaseAction.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/CaseAction.c.o
.PHONY : CaseAction.c.o

CaseAction.i: CaseAction.c.i
.PHONY : CaseAction.i

# target to preprocess a source file
CaseAction.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/CaseAction.c.i
.PHONY : CaseAction.c.i

CaseAction.s: CaseAction.c.s
.PHONY : CaseAction.s

# target to generate assembly for a file
CaseAction.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/CaseAction.c.s
.PHONY : CaseAction.c.s

Player.o: Player.c.o
.PHONY : Player.o

# target to build an object file
Player.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/Player.c.o
.PHONY : Player.c.o

Player.i: Player.c.i
.PHONY : Player.i

# target to preprocess a source file
Player.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/Player.c.i
.PHONY : Player.c.i

Player.s: Player.c.s
.PHONY : Player.s

# target to generate assembly for a file
Player.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/Player.c.s
.PHONY : Player.c.s

affichage.o: affichage.c.o
.PHONY : affichage.o

# target to build an object file
affichage.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/affichage.c.o
.PHONY : affichage.c.o

affichage.i: affichage.c.i
.PHONY : affichage.i

# target to preprocess a source file
affichage.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/affichage.c.i
.PHONY : affichage.c.i

affichage.s: affichage.c.s
.PHONY : affichage.s

# target to generate assembly for a file
affichage.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/affichage.c.s
.PHONY : affichage.c.s

combat.o: combat.c.o
.PHONY : combat.o

# target to build an object file
combat.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/combat.c.o
.PHONY : combat.c.o

combat.i: combat.c.i
.PHONY : combat.i

# target to preprocess a source file
combat.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/combat.c.i
.PHONY : combat.c.i

combat.s: combat.c.s
.PHONY : combat.s

# target to generate assembly for a file
combat.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/combat.c.s
.PHONY : combat.c.s

creationmap.o: creationmap.c.o
.PHONY : creationmap.o

# target to build an object file
creationmap.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/creationmap.c.o
.PHONY : creationmap.c.o

creationmap.i: creationmap.c.i
.PHONY : creationmap.i

# target to preprocess a source file
creationmap.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/creationmap.c.i
.PHONY : creationmap.c.i

creationmap.s: creationmap.c.s
.PHONY : creationmap.s

# target to generate assembly for a file
creationmap.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/creationmap.c.s
.PHONY : creationmap.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/main.c.s
.PHONY : main.c.s

monster.o: monster.c.o
.PHONY : monster.o

# target to build an object file
monster.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/monster.c.o
.PHONY : monster.c.o

monster.i: monster.c.i
.PHONY : monster.i

# target to preprocess a source file
monster.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/monster.c.i
.PHONY : monster.c.i

monster.s: monster.c.s
.PHONY : monster.s

# target to generate assembly for a file
monster.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/monster.c.s
.PHONY : monster.c.s

sauvegarde_player.o: sauvegarde_player.c.o
.PHONY : sauvegarde_player.o

# target to build an object file
sauvegarde_player.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.o
.PHONY : sauvegarde_player.c.o

sauvegarde_player.i: sauvegarde_player.c.i
.PHONY : sauvegarde_player.i

# target to preprocess a source file
sauvegarde_player.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.i
.PHONY : sauvegarde_player.c.i

sauvegarde_player.s: sauvegarde_player.c.s
.PHONY : sauvegarde_player.s

# target to generate assembly for a file
sauvegarde_player.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/sauvegarde_player.c.s
.PHONY : sauvegarde_player.c.s

shopInventaire.o: shopInventaire.c.o
.PHONY : shopInventaire.o

# target to build an object file
shopInventaire.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/shopInventaire.c.o
.PHONY : shopInventaire.c.o

shopInventaire.i: shopInventaire.c.i
.PHONY : shopInventaire.i

# target to preprocess a source file
shopInventaire.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/shopInventaire.c.i
.PHONY : shopInventaire.c.i

shopInventaire.s: shopInventaire.c.s
.PHONY : shopInventaire.s

# target to generate assembly for a file
shopInventaire.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DoomDepthsC.dir/build.make CMakeFiles/DoomDepthsC.dir/shopInventaire.c.s
.PHONY : shopInventaire.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... DoomDepthsC"
	@echo "... CaseAction.o"
	@echo "... CaseAction.i"
	@echo "... CaseAction.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
	@echo "... affichage.o"
	@echo "... affichage.i"
	@echo "... affichage.s"
	@echo "... combat.o"
	@echo "... combat.i"
	@echo "... combat.s"
	@echo "... creationmap.o"
	@echo "... creationmap.i"
	@echo "... creationmap.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... monster.o"
	@echo "... monster.i"
	@echo "... monster.s"
	@echo "... sauvegarde_player.o"
	@echo "... sauvegarde_player.i"
	@echo "... sauvegarde_player.s"
	@echo "... shopInventaire.o"
	@echo "... shopInventaire.i"
	@echo "... shopInventaire.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

