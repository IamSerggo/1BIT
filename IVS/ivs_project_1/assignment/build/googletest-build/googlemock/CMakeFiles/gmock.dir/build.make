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

# Include any dependencies generated for this target.
include googletest-build/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include googletest-build/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make

googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make
googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest-master/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/radovan/Downloads/ivs_project_1/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-master/googlemock/src/gmock-all.cc

googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-master/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-master/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f googletest-build/googlemock/CMakeFiles/gmock.dir/build.make googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

googletest-build/googlemock/libgmock.a: googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
googletest-build/googlemock/libgmock.a: googletest-build/googlemock/CMakeFiles/gmock.dir/build.make
googletest-build/googlemock/libgmock.a: googletest-build/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/radovan/Downloads/ivs_project_1/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgmock.a"
	cd /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-build/googlemock/CMakeFiles/gmock.dir/build: googletest-build/googlemock/libgmock.a

.PHONY : googletest-build/googlemock/CMakeFiles/gmock.dir/build

googletest-build/googlemock/CMakeFiles/gmock.dir/requires: googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : googletest-build/googlemock/CMakeFiles/gmock.dir/requires

googletest-build/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : googletest-build/googlemock/CMakeFiles/gmock.dir/clean

googletest-build/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/radovan/Downloads/ivs_project_1/assignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/radovan/Downloads/ivs_project_1/assignment /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-master/googlemock /home/radovan/Downloads/ivs_project_1/assignment/build /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock /home/radovan/Downloads/ivs_project_1/assignment/build/googletest-build/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest-build/googlemock/CMakeFiles/gmock.dir/depend

