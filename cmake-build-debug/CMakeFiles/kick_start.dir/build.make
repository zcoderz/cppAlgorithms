# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/usman/work/cppAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usman/work/cppAlgorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kick_start.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/kick_start.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kick_start.dir/flags.make

CMakeFiles/kick_start.dir/main.cpp.o: CMakeFiles/kick_start.dir/flags.make
CMakeFiles/kick_start.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usman/work/cppAlgorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kick_start.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kick_start.dir/main.cpp.o -c /home/usman/work/cppAlgorithms/main.cpp

CMakeFiles/kick_start.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kick_start.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usman/work/cppAlgorithms/main.cpp > CMakeFiles/kick_start.dir/main.cpp.i

CMakeFiles/kick_start.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kick_start.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usman/work/cppAlgorithms/main.cpp -o CMakeFiles/kick_start.dir/main.cpp.s

CMakeFiles/kick_start.dir/sort/SortChecks.cpp.o: CMakeFiles/kick_start.dir/flags.make
CMakeFiles/kick_start.dir/sort/SortChecks.cpp.o: ../sort/SortChecks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usman/work/cppAlgorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kick_start.dir/sort/SortChecks.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kick_start.dir/sort/SortChecks.cpp.o -c /home/usman/work/cppAlgorithms/sort/SortChecks.cpp

CMakeFiles/kick_start.dir/sort/SortChecks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kick_start.dir/sort/SortChecks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usman/work/cppAlgorithms/sort/SortChecks.cpp > CMakeFiles/kick_start.dir/sort/SortChecks.cpp.i

CMakeFiles/kick_start.dir/sort/SortChecks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kick_start.dir/sort/SortChecks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usman/work/cppAlgorithms/sort/SortChecks.cpp -o CMakeFiles/kick_start.dir/sort/SortChecks.cpp.s

CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.o: CMakeFiles/kick_start.dir/flags.make
CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.o: ../priorityqueue/PriorityQueueTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usman/work/cppAlgorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.o -c /home/usman/work/cppAlgorithms/priorityqueue/PriorityQueueTest.cpp

CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usman/work/cppAlgorithms/priorityqueue/PriorityQueueTest.cpp > CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.i

CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usman/work/cppAlgorithms/priorityqueue/PriorityQueueTest.cpp -o CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.s

# Object files for target kick_start
kick_start_OBJECTS = \
"CMakeFiles/kick_start.dir/main.cpp.o" \
"CMakeFiles/kick_start.dir/sort/SortChecks.cpp.o" \
"CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.o"

# External object files for target kick_start
kick_start_EXTERNAL_OBJECTS =

kick_start: CMakeFiles/kick_start.dir/main.cpp.o
kick_start: CMakeFiles/kick_start.dir/sort/SortChecks.cpp.o
kick_start: CMakeFiles/kick_start.dir/priorityqueue/PriorityQueueTest.cpp.o
kick_start: CMakeFiles/kick_start.dir/build.make
kick_start: CMakeFiles/kick_start.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usman/work/cppAlgorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable kick_start"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kick_start.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kick_start.dir/build: kick_start
.PHONY : CMakeFiles/kick_start.dir/build

CMakeFiles/kick_start.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kick_start.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kick_start.dir/clean

CMakeFiles/kick_start.dir/depend:
	cd /home/usman/work/cppAlgorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usman/work/cppAlgorithms /home/usman/work/cppAlgorithms /home/usman/work/cppAlgorithms/cmake-build-debug /home/usman/work/cppAlgorithms/cmake-build-debug /home/usman/work/cppAlgorithms/cmake-build-debug/CMakeFiles/kick_start.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kick_start.dir/depend

