# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/radovan/Downloads/ivs_project_1/assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/radovan/Downloads/ivs_project_1/assignment/build

# Utility rule file for tdd_test_coverage.

# Include the progress variables for this target.
include CMakeFiles/tdd_test_coverage.dir/progress.make

CMakeFiles/tdd_test_coverage:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/radovan/Downloads/ivs_project_1/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Resetting code coverage counters to zero."
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Processing code coverage counters and generating report."
	/home/radovan/Downloads/ivs_project_1/assignment/lcov/bin/lcov --directory . --zerocounters
	/home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test
	/home/radovan/Downloads/ivs_project_1/assignment/lcov/bin/lcov --directory . --capture --output-file /home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test_coverage.info
	/home/radovan/Downloads/ivs_project_1/assignment/lcov/bin/lcov --remove /home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test_coverage.info 'tests/*' '/usr/*' '*/googletest-master/*' --output-file /home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test_coverage.info.cleaned
	/home/radovan/Downloads/ivs_project_1/assignment/lcov/bin/genhtml -o tdd_test_coverage /home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test_coverage.info.cleaned
	/usr/bin/cmake -E remove /home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test_coverage.info /home/radovan/Downloads/ivs_project_1/assignment/build/tdd_test_coverage.info.cleaned

tdd_test_coverage: CMakeFiles/tdd_test_coverage
tdd_test_coverage: CMakeFiles/tdd_test_coverage.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Open ./tdd_test_coverage/index.html in your browser to view the coverage report."
.PHONY : tdd_test_coverage

# Rule to build all files generated by this target.
CMakeFiles/tdd_test_coverage.dir/build: tdd_test_coverage

.PHONY : CMakeFiles/tdd_test_coverage.dir/build

CMakeFiles/tdd_test_coverage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tdd_test_coverage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tdd_test_coverage.dir/clean

CMakeFiles/tdd_test_coverage.dir/depend:
	cd /home/radovan/Downloads/ivs_project_1/assignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/radovan/Downloads/ivs_project_1/assignment /home/radovan/Downloads/ivs_project_1/assignment /home/radovan/Downloads/ivs_project_1/assignment/build /home/radovan/Downloads/ivs_project_1/assignment/build /home/radovan/Downloads/ivs_project_1/assignment/build/CMakeFiles/tdd_test_coverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tdd_test_coverage.dir/depend

