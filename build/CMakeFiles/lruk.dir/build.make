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
include CMakeFiles/lruk.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lruk.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lruk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lruk.dir/flags.make

CMakeFiles/lruk.dir/source/cache.c.o: CMakeFiles/lruk.dir/flags.make
CMakeFiles/lruk.dir/source/cache.c.o: /home/daddy/Документы/C_projects/Cache/source/cache.c
CMakeFiles/lruk.dir/source/cache.c.o: CMakeFiles/lruk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lruk.dir/source/cache.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lruk.dir/source/cache.c.o -MF CMakeFiles/lruk.dir/source/cache.c.o.d -o CMakeFiles/lruk.dir/source/cache.c.o -c /home/daddy/Документы/C_projects/Cache/source/cache.c

CMakeFiles/lruk.dir/source/cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lruk.dir/source/cache.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/source/cache.c > CMakeFiles/lruk.dir/source/cache.c.i

CMakeFiles/lruk.dir/source/cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lruk.dir/source/cache.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/source/cache.c -o CMakeFiles/lruk.dir/source/cache.c.s

CMakeFiles/lruk.dir/source/hash.c.o: CMakeFiles/lruk.dir/flags.make
CMakeFiles/lruk.dir/source/hash.c.o: /home/daddy/Документы/C_projects/Cache/source/hash.c
CMakeFiles/lruk.dir/source/hash.c.o: CMakeFiles/lruk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lruk.dir/source/hash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lruk.dir/source/hash.c.o -MF CMakeFiles/lruk.dir/source/hash.c.o.d -o CMakeFiles/lruk.dir/source/hash.c.o -c /home/daddy/Документы/C_projects/Cache/source/hash.c

CMakeFiles/lruk.dir/source/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lruk.dir/source/hash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/source/hash.c > CMakeFiles/lruk.dir/source/hash.c.i

CMakeFiles/lruk.dir/source/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lruk.dir/source/hash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/source/hash.c -o CMakeFiles/lruk.dir/source/hash.c.s

CMakeFiles/lruk.dir/source/queue.c.o: CMakeFiles/lruk.dir/flags.make
CMakeFiles/lruk.dir/source/queue.c.o: /home/daddy/Документы/C_projects/Cache/source/queue.c
CMakeFiles/lruk.dir/source/queue.c.o: CMakeFiles/lruk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lruk.dir/source/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lruk.dir/source/queue.c.o -MF CMakeFiles/lruk.dir/source/queue.c.o.d -o CMakeFiles/lruk.dir/source/queue.c.o -c /home/daddy/Документы/C_projects/Cache/source/queue.c

CMakeFiles/lruk.dir/source/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lruk.dir/source/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/source/queue.c > CMakeFiles/lruk.dir/source/queue.c.i

CMakeFiles/lruk.dir/source/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lruk.dir/source/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/source/queue.c -o CMakeFiles/lruk.dir/source/queue.c.s

CMakeFiles/lruk.dir/source/tree.c.o: CMakeFiles/lruk.dir/flags.make
CMakeFiles/lruk.dir/source/tree.c.o: /home/daddy/Документы/C_projects/Cache/source/tree.c
CMakeFiles/lruk.dir/source/tree.c.o: CMakeFiles/lruk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lruk.dir/source/tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lruk.dir/source/tree.c.o -MF CMakeFiles/lruk.dir/source/tree.c.o.d -o CMakeFiles/lruk.dir/source/tree.c.o -c /home/daddy/Документы/C_projects/Cache/source/tree.c

CMakeFiles/lruk.dir/source/tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lruk.dir/source/tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/source/tree.c > CMakeFiles/lruk.dir/source/tree.c.i

CMakeFiles/lruk.dir/source/tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lruk.dir/source/tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/source/tree.c -o CMakeFiles/lruk.dir/source/tree.c.s

CMakeFiles/lruk.dir/source/list.c.o: CMakeFiles/lruk.dir/flags.make
CMakeFiles/lruk.dir/source/list.c.o: /home/daddy/Документы/C_projects/Cache/source/list.c
CMakeFiles/lruk.dir/source/list.c.o: CMakeFiles/lruk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lruk.dir/source/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lruk.dir/source/list.c.o -MF CMakeFiles/lruk.dir/source/list.c.o.d -o CMakeFiles/lruk.dir/source/list.c.o -c /home/daddy/Документы/C_projects/Cache/source/list.c

CMakeFiles/lruk.dir/source/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lruk.dir/source/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daddy/Документы/C_projects/Cache/source/list.c > CMakeFiles/lruk.dir/source/list.c.i

CMakeFiles/lruk.dir/source/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lruk.dir/source/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daddy/Документы/C_projects/Cache/source/list.c -o CMakeFiles/lruk.dir/source/list.c.s

# Object files for target lruk
lruk_OBJECTS = \
"CMakeFiles/lruk.dir/source/cache.c.o" \
"CMakeFiles/lruk.dir/source/hash.c.o" \
"CMakeFiles/lruk.dir/source/queue.c.o" \
"CMakeFiles/lruk.dir/source/tree.c.o" \
"CMakeFiles/lruk.dir/source/list.c.o"

# External object files for target lruk
lruk_EXTERNAL_OBJECTS =

liblruk.a: CMakeFiles/lruk.dir/source/cache.c.o
liblruk.a: CMakeFiles/lruk.dir/source/hash.c.o
liblruk.a: CMakeFiles/lruk.dir/source/queue.c.o
liblruk.a: CMakeFiles/lruk.dir/source/tree.c.o
liblruk.a: CMakeFiles/lruk.dir/source/list.c.o
liblruk.a: CMakeFiles/lruk.dir/build.make
liblruk.a: CMakeFiles/lruk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/daddy/Документы/C_projects/Cache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library liblruk.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lruk.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lruk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lruk.dir/build: liblruk.a
.PHONY : CMakeFiles/lruk.dir/build

CMakeFiles/lruk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lruk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lruk.dir/clean

CMakeFiles/lruk.dir/depend:
	cd /home/daddy/Документы/C_projects/Cache/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daddy/Документы/C_projects/Cache /home/daddy/Документы/C_projects/Cache /home/daddy/Документы/C_projects/Cache/build /home/daddy/Документы/C_projects/Cache/build /home/daddy/Документы/C_projects/Cache/build/CMakeFiles/lruk.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lruk.dir/depend

