# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/daddy/Документы/C_projects/Cache

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daddy/Документы/C_projects/Cache/build

# Include any dependencies generated for this target.
include problem_lc/CMakeFiles/lru.x.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include problem_lc/CMakeFiles/lru.x.dir/compiler_depend.make

# Include the progress variables for this target.
include problem_lc/CMakeFiles/lru.x.dir/progress.make

# Include the compile flags for this target's objects.
include problem_lc/CMakeFiles/lru.x.dir/flags.make

problem_lc/CMakeFiles/lru.x.dir/LCmain.c.o: problem_lc/CMakeFiles/lru.x.dir/flags.make
problem_lc/CMakeFiles/lru.x.dir/LCmain.c.o: /home/daddy/Документы/C_projects/Cache/problem_lc/LCmain.c
problem_lc/CMakeFiles/lru.x.dir/LCmain.c.o: problem_lc/CMakeFiles/lru.x.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object problem_lc/CMakeFiles/lru.x.dir/LCmain.c.o"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT problem_lc/CMakeFiles/lru.x.dir/LCmain.c.o -MF CMakeFiles/lru.x.dir/LCmain.c.o.d -o CMakeFiles/lru.x.dir/LCmain.c.o -c /home/daddy/Документы/C_projects/Cache/problem_lc/LCmain.c

problem_lc/CMakeFiles/lru.x.dir/LCmain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lru.x.dir/LCmain.c.i"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/problem_lc/LCmain.c > CMakeFiles/lru.x.dir/LCmain.c.i

problem_lc/CMakeFiles/lru.x.dir/LCmain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lru.x.dir/LCmain.c.s"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/problem_lc/LCmain.c -o CMakeFiles/lru.x.dir/LCmain.c.s

# Object files for target lru.x
lru_x_OBJECTS = \
"CMakeFiles/lru.x.dir/LCmain.c.o"

# External object files for target lru.x
lru_x_EXTERNAL_OBJECTS =

problem_lc/lru.x: problem_lc/CMakeFiles/lru.x.dir/LCmain.c.o
problem_lc/lru.x: problem_lc/CMakeFiles/lru.x.dir/build.make
problem_lc/lru.x: problem_lc/liblrulib.a
problem_lc/lru.x: problem_lc/CMakeFiles/lru.x.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lru.x"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lru.x.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
problem_lc/CMakeFiles/lru.x.dir/build: problem_lc/lru.x
.PHONY : problem_lc/CMakeFiles/lru.x.dir/build

problem_lc/CMakeFiles/lru.x.dir/clean:
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && $(CMAKE_COMMAND) -P CMakeFiles/lru.x.dir/cmake_clean.cmake
.PHONY : problem_lc/CMakeFiles/lru.x.dir/clean

problem_lc/CMakeFiles/lru.x.dir/depend:
	cd /home/daddy/Документы/C_projects/Cache/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daddy/Документы/C_projects/Cache /home/daddy/Документы/C_projects/Cache/problem_lc /home/daddy/Документы/C_projects/Cache/build /home/daddy/Документы/C_projects/Cache/build/problem_lc /home/daddy/Документы/C_projects/Cache/build/problem_lc/CMakeFiles/lru.x.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : problem_lc/CMakeFiles/lru.x.dir/depend

