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
CMAKE_COMMAND = /home/home/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/home/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/home/Рабочий стол/cub3d/my"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/home/Рабочий стол/cub3d/my/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/my.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my.dir/flags.make

CMakeFiles/my.dir/main.c.o: CMakeFiles/my.dir/flags.make
CMakeFiles/my.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/home/Рабочий стол/cub3d/my/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my.dir/main.c.o   -c "/home/home/Рабочий стол/cub3d/my/main.c"

CMakeFiles/my.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/home/Рабочий стол/cub3d/my/main.c" > CMakeFiles/my.dir/main.c.i

CMakeFiles/my.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/home/Рабочий стол/cub3d/my/main.c" -o CMakeFiles/my.dir/main.c.s

# Object files for target my
my_OBJECTS = \
"CMakeFiles/my.dir/main.c.o"

# External object files for target my
my_EXTERNAL_OBJECTS =

my: CMakeFiles/my.dir/main.c.o
my: CMakeFiles/my.dir/build.make
my: CMakeFiles/my.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/home/Рабочий стол/cub3d/my/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my.dir/build: my

.PHONY : CMakeFiles/my.dir/build

CMakeFiles/my.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my.dir/clean

CMakeFiles/my.dir/depend:
	cd "/home/home/Рабочий стол/cub3d/my/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/home/Рабочий стол/cub3d/my" "/home/home/Рабочий стол/cub3d/my" "/home/home/Рабочий стол/cub3d/my/cmake-build-debug" "/home/home/Рабочий стол/cub3d/my/cmake-build-debug" "/home/home/Рабочий стол/cub3d/my/cmake-build-debug/CMakeFiles/my.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/my.dir/depend

