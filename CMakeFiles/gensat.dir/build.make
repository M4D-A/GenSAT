# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam/STUFF/GenSAT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/STUFF/GenSAT

# Include any dependencies generated for this target.
include CMakeFiles/gensat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gensat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gensat.dir/flags.make

CMakeFiles/gensat.dir/main.c.o: CMakeFiles/gensat.dir/flags.make
CMakeFiles/gensat.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/STUFF/GenSAT/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gensat.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gensat.dir/main.c.o   -c /home/adam/STUFF/GenSAT/main.c

CMakeFiles/gensat.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gensat.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adam/STUFF/GenSAT/main.c > CMakeFiles/gensat.dir/main.c.i

CMakeFiles/gensat.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gensat.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adam/STUFF/GenSAT/main.c -o CMakeFiles/gensat.dir/main.c.s

# Object files for target gensat
gensat_OBJECTS = \
"CMakeFiles/gensat.dir/main.c.o"

# External object files for target gensat
gensat_EXTERNAL_OBJECTS =

gensat: CMakeFiles/gensat.dir/main.c.o
gensat: CMakeFiles/gensat.dir/build.make
gensat: libraries/libdimacs.a
gensat: CMakeFiles/gensat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam/STUFF/GenSAT/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable gensat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gensat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gensat.dir/build: gensat

.PHONY : CMakeFiles/gensat.dir/build

CMakeFiles/gensat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gensat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gensat.dir/clean

CMakeFiles/gensat.dir/depend:
	cd /home/adam/STUFF/GenSAT && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/STUFF/GenSAT /home/adam/STUFF/GenSAT /home/adam/STUFF/GenSAT /home/adam/STUFF/GenSAT /home/adam/STUFF/GenSAT/CMakeFiles/gensat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gensat.dir/depend

