# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build"

# Utility rule file for NightlySubmit.

# Include the progress variables for this target.
include tests/CMakeFiles/NightlySubmit.dir/progress.make

tests/CMakeFiles/NightlySubmit:
	cd "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build/tests" && /usr/bin/ctest -D NightlySubmit

NightlySubmit: tests/CMakeFiles/NightlySubmit
NightlySubmit: tests/CMakeFiles/NightlySubmit.dir/build.make

.PHONY : NightlySubmit

# Rule to build all files generated by this target.
tests/CMakeFiles/NightlySubmit.dir/build: NightlySubmit

.PHONY : tests/CMakeFiles/NightlySubmit.dir/build

tests/CMakeFiles/NightlySubmit.dir/clean:
	cd "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/NightlySubmit.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/NightlySubmit.dir/clean

tests/CMakeFiles/NightlySubmit.dir/depend:
	cd "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image" "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/tests" "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build" "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build/tests" "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/build/tests/CMakeFiles/NightlySubmit.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/NightlySubmit.dir/depend

