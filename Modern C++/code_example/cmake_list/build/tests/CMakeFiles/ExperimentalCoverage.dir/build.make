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
CMAKE_SOURCE_DIR = "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build"

# Utility rule file for ExperimentalCoverage.

# Include the progress variables for this target.
include tests/CMakeFiles/ExperimentalCoverage.dir/progress.make

tests/CMakeFiles/ExperimentalCoverage:
	cd "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build/tests" && /usr/bin/ctest -D ExperimentalCoverage

ExperimentalCoverage: tests/CMakeFiles/ExperimentalCoverage
ExperimentalCoverage: tests/CMakeFiles/ExperimentalCoverage.dir/build.make

.PHONY : ExperimentalCoverage

# Rule to build all files generated by this target.
tests/CMakeFiles/ExperimentalCoverage.dir/build: ExperimentalCoverage

.PHONY : tests/CMakeFiles/ExperimentalCoverage.dir/build

tests/CMakeFiles/ExperimentalCoverage.dir/clean:
	cd "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalCoverage.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ExperimentalCoverage.dir/clean

tests/CMakeFiles/ExperimentalCoverage.dir/depend:
	cd "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list" "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/tests" "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build" "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build/tests" "/media/marzan/data storage/C++/Modern C++/code_example/cmake_list/build/tests/CMakeFiles/ExperimentalCoverage.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/ExperimentalCoverage.dir/depend

