# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Users/ggrimes/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/ggrimes/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ggrimes/projects/fillit_cl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ggrimes/projects/fillit_cl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/fillit.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/fillit.c.o: ../fillit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ggrimes/projects/fillit_cl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/fillit.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/fillit.c.o   -c /Users/ggrimes/projects/fillit_cl/fillit.c

CMakeFiles/main.dir/fillit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/fillit.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ggrimes/projects/fillit_cl/fillit.c > CMakeFiles/main.dir/fillit.c.i

CMakeFiles/main.dir/fillit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/fillit.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ggrimes/projects/fillit_cl/fillit.c -o CMakeFiles/main.dir/fillit.c.s

CMakeFiles/main.dir/read_and_validate.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/read_and_validate.c.o: ../read_and_validate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ggrimes/projects/fillit_cl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/read_and_validate.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/read_and_validate.c.o   -c /Users/ggrimes/projects/fillit_cl/read_and_validate.c

CMakeFiles/main.dir/read_and_validate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/read_and_validate.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ggrimes/projects/fillit_cl/read_and_validate.c > CMakeFiles/main.dir/read_and_validate.c.i

CMakeFiles/main.dir/read_and_validate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/read_and_validate.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ggrimes/projects/fillit_cl/read_and_validate.c -o CMakeFiles/main.dir/read_and_validate.c.s

CMakeFiles/main.dir/inscribe_shapes.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/inscribe_shapes.c.o: ../inscribe_shapes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ggrimes/projects/fillit_cl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/inscribe_shapes.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/inscribe_shapes.c.o   -c /Users/ggrimes/projects/fillit_cl/inscribe_shapes.c

CMakeFiles/main.dir/inscribe_shapes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/inscribe_shapes.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ggrimes/projects/fillit_cl/inscribe_shapes.c > CMakeFiles/main.dir/inscribe_shapes.c.i

CMakeFiles/main.dir/inscribe_shapes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/inscribe_shapes.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ggrimes/projects/fillit_cl/inscribe_shapes.c -o CMakeFiles/main.dir/inscribe_shapes.c.s

CMakeFiles/main.dir/print.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/print.c.o: ../print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ggrimes/projects/fillit_cl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/print.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/print.c.o   -c /Users/ggrimes/projects/fillit_cl/print.c

CMakeFiles/main.dir/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/print.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ggrimes/projects/fillit_cl/print.c > CMakeFiles/main.dir/print.c.i

CMakeFiles/main.dir/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/print.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ggrimes/projects/fillit_cl/print.c -o CMakeFiles/main.dir/print.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/fillit.c.o" \
"CMakeFiles/main.dir/read_and_validate.c.o" \
"CMakeFiles/main.dir/inscribe_shapes.c.o" \
"CMakeFiles/main.dir/print.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/fillit.c.o
main: CMakeFiles/main.dir/read_and_validate.c.o
main: CMakeFiles/main.dir/inscribe_shapes.c.o
main: CMakeFiles/main.dir/print.c.o
main: CMakeFiles/main.dir/build.make
main: ../libft/libft.a
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ggrimes/projects/fillit_cl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/ggrimes/projects/fillit_cl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ggrimes/projects/fillit_cl /Users/ggrimes/projects/fillit_cl /Users/ggrimes/projects/fillit_cl/cmake-build-debug /Users/ggrimes/projects/fillit_cl/cmake-build-debug /Users/ggrimes/projects/fillit_cl/cmake-build-debug/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
