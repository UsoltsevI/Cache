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
include problem_lc/CMakeFiles/lrulib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include problem_lc/CMakeFiles/lrulib.dir/compiler_depend.make

# Include the progress variables for this target.
include problem_lc/CMakeFiles/lrulib.dir/progress.make

# Include the compile flags for this target's objects.
include problem_lc/CMakeFiles/lrulib.dir/flags.make

problem_lc/CMakeFiles/lrulib.dir/source/cache.c.o: problem_lc/CMakeFiles/lrulib.dir/flags.make
problem_lc/CMakeFiles/lrulib.dir/source/cache.c.o: /home/daddy/Документы/C_projects/Cache/problem_lc/source/cache.c
problem_lc/CMakeFiles/lrulib.dir/source/cache.c.o: problem_lc/CMakeFiles/lrulib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object problem_lc/CMakeFiles/lrulib.dir/source/cache.c.o"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT problem_lc/CMakeFiles/lrulib.dir/source/cache.c.o -MF CMakeFiles/lrulib.dir/source/cache.c.o.d -o CMakeFiles/lrulib.dir/source/cache.c.o -c /home/daddy/Документы/C_projects/Cache/problem_lc/source/cache.c

problem_lc/CMakeFiles/lrulib.dir/source/cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lrulib.dir/source/cache.c.i"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/problem_lc/source/cache.c > CMakeFiles/lrulib.dir/source/cache.c.i

problem_lc/CMakeFiles/lrulib.dir/source/cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lrulib.dir/source/cache.c.s"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/problem_lc/source/cache.c -o CMakeFiles/lrulib.dir/source/cache.c.s

problem_lc/CMakeFiles/lrulib.dir/source/hash.c.o: problem_lc/CMakeFiles/lrulib.dir/flags.make
problem_lc/CMakeFiles/lrulib.dir/source/hash.c.o: /home/daddy/Документы/C_projects/Cache/problem_lc/source/hash.c
problem_lc/CMakeFiles/lrulib.dir/source/hash.c.o: problem_lc/CMakeFiles/lrulib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object problem_lc/CMakeFiles/lrulib.dir/source/hash.c.o"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT problem_lc/CMakeFiles/lrulib.dir/source/hash.c.o -MF CMakeFiles/lrulib.dir/source/hash.c.o.d -o CMakeFiles/lrulib.dir/source/hash.c.o -c /home/daddy/Документы/C_projects/Cache/problem_lc/source/hash.c

problem_lc/CMakeFiles/lrulib.dir/source/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lrulib.dir/source/hash.c.i"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/problem_lc/source/hash.c > CMakeFiles/lrulib.dir/source/hash.c.i

problem_lc/CMakeFiles/lrulib.dir/source/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lrulib.dir/source/hash.c.s"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/problem_lc/source/hash.c -o CMakeFiles/lrulib.dir/source/hash.c.s

problem_lc/CMakeFiles/lrulib.dir/source/list.c.o: problem_lc/CMakeFiles/lrulib.dir/flags.make
problem_lc/CMakeFiles/lrulib.dir/source/list.c.o: /home/daddy/Документы/C_projects/Cache/problem_lc/source/list.c
problem_lc/CMakeFiles/lrulib.dir/source/list.c.o: problem_lc/CMakeFiles/lrulib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object problem_lc/CMakeFiles/lrulib.dir/source/list.c.o"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT problem_lc/CMakeFiles/lrulib.dir/source/list.c.o -MF CMakeFiles/lrulib.dir/source/list.c.o.d -o CMakeFiles/lrulib.dir/source/list.c.o -c /home/daddy/Документы/C_projects/Cache/problem_lc/source/list.c

problem_lc/CMakeFiles/lrulib.dir/source/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lrulib.dir/source/list.c.i"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/problem_lc/source/list.c > CMakeFiles/lrulib.dir/source/list.c.i

problem_lc/CMakeFiles/lrulib.dir/source/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lrulib.dir/source/list.c.s"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/problem_lc/source/list.c -o CMakeFiles/lrulib.dir/source/list.c.s

# Object files for target lrulib
lrulib_OBJECTS = \
"CMakeFiles/lrulib.dir/source/cache.c.o" \
"CMakeFiles/lrulib.dir/source/hash.c.o" \
"CMakeFiles/lrulib.dir/source/list.c.o"

# External object files for target lrulib
lrulib_EXTERNAL_OBJECTS =

problem_lc/liblrulib.a: problem_lc/CMakeFiles/lrulib.dir/source/cache.c.o
problem_lc/liblrulib.a: problem_lc/CMakeFiles/lrulib.dir/source/hash.c.o
problem_lc/liblrulib.a: problem_lc/CMakeFiles/lrulib.dir/source/list.c.o
problem_lc/liblrulib.a: problem_lc/CMakeFiles/lrulib.dir/build.make
problem_lc/liblrulib.a: problem_lc/CMakeFiles/lrulib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library liblrulib.a"
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && $(CMAKE_COMMAND) -P CMakeFiles/lrulib.dir/cmake_clean_target.cmake
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lrulib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
problem_lc/CMakeFiles/lrulib.dir/build: problem_lc/liblrulib.a
.PHONY : problem_lc/CMakeFiles/lrulib.dir/build

problem_lc/CMakeFiles/lrulib.dir/clean:
	cd /home/daddy/Документы/C_projects/Cache/build/problem_lc && $(CMAKE_COMMAND) -P CMakeFiles/lrulib.dir/cmake_clean.cmake
.PHONY : problem_lc/CMakeFiles/lrulib.dir/clean

problem_lc/CMakeFiles/lrulib.dir/depend:
	cd /home/daddy/Документы/C_projects/Cache/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daddy/Документы/C_projects/Cache /home/daddy/Документы/C_projects/Cache/problem_lc /home/daddy/Документы/C_projects/Cache/build /home/daddy/Документы/C_projects/Cache/build/problem_lc /home/daddy/Документы/C_projects/Cache/build/problem_lc/CMakeFiles/lrulib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : problem_lc/CMakeFiles/lrulib.dir/depend

