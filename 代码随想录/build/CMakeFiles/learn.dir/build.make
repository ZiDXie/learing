# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/xie/Others/Project/learing/代码随想录

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xie/Others/Project/learing/代码随想录/build

# Include any dependencies generated for this target.
include CMakeFiles/learn.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn.dir/flags.make

CMakeFiles/learn.dir/main.cpp.o: CMakeFiles/learn.dir/flags.make
CMakeFiles/learn.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xie/Others/Project/learing/代码随想录/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learn.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn.dir/main.cpp.o -c /home/xie/Others/Project/learing/代码随想录/main.cpp

CMakeFiles/learn.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xie/Others/Project/learing/代码随想录/main.cpp > CMakeFiles/learn.dir/main.cpp.i

CMakeFiles/learn.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xie/Others/Project/learing/代码随想录/main.cpp -o CMakeFiles/learn.dir/main.cpp.s

CMakeFiles/learn.dir/src/Array.cpp.o: CMakeFiles/learn.dir/flags.make
CMakeFiles/learn.dir/src/Array.cpp.o: ../src/Array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xie/Others/Project/learing/代码随想录/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/learn.dir/src/Array.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn.dir/src/Array.cpp.o -c /home/xie/Others/Project/learing/代码随想录/src/Array.cpp

CMakeFiles/learn.dir/src/Array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn.dir/src/Array.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xie/Others/Project/learing/代码随想录/src/Array.cpp > CMakeFiles/learn.dir/src/Array.cpp.i

CMakeFiles/learn.dir/src/Array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn.dir/src/Array.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xie/Others/Project/learing/代码随想录/src/Array.cpp -o CMakeFiles/learn.dir/src/Array.cpp.s

# Object files for target learn
learn_OBJECTS = \
"CMakeFiles/learn.dir/main.cpp.o" \
"CMakeFiles/learn.dir/src/Array.cpp.o"

# External object files for target learn
learn_EXTERNAL_OBJECTS =

learn: CMakeFiles/learn.dir/main.cpp.o
learn: CMakeFiles/learn.dir/src/Array.cpp.o
learn: CMakeFiles/learn.dir/build.make
learn: CMakeFiles/learn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xie/Others/Project/learing/代码随想录/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable learn"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn.dir/build: learn

.PHONY : CMakeFiles/learn.dir/build

CMakeFiles/learn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learn.dir/clean

CMakeFiles/learn.dir/depend:
	cd /home/xie/Others/Project/learing/代码随想录/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xie/Others/Project/learing/代码随想录 /home/xie/Others/Project/learing/代码随想录 /home/xie/Others/Project/learing/代码随想录/build /home/xie/Others/Project/learing/代码随想录/build /home/xie/Others/Project/learing/代码随想录/build/CMakeFiles/learn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn.dir/depend

