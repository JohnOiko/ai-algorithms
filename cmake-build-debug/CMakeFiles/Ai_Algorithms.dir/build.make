# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\JetBrains\Toolbox\Apps\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\JetBrains\Toolbox\Apps\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Ai_Algorithms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ai_Algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ai_Algorithms.dir/flags.make

CMakeFiles/Ai_Algorithms.dir/main.cpp.obj: CMakeFiles/Ai_Algorithms.dir/flags.make
CMakeFiles/Ai_Algorithms.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ai_Algorithms.dir/main.cpp.obj"
	"D:\Code Blocks\CodeBlocks\MinGW\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ai_Algorithms.dir\main.cpp.obj -c "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\main.cpp"

CMakeFiles/Ai_Algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ai_Algorithms.dir/main.cpp.i"
	"D:\Code Blocks\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\main.cpp" > CMakeFiles\Ai_Algorithms.dir\main.cpp.i

CMakeFiles/Ai_Algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ai_Algorithms.dir/main.cpp.s"
	"D:\Code Blocks\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\main.cpp" -o CMakeFiles\Ai_Algorithms.dir\main.cpp.s

CMakeFiles/Ai_Algorithms.dir/Board.cpp.obj: CMakeFiles/Ai_Algorithms.dir/flags.make
CMakeFiles/Ai_Algorithms.dir/Board.cpp.obj: ../Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ai_Algorithms.dir/Board.cpp.obj"
	"D:\Code Blocks\CodeBlocks\MinGW\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ai_Algorithms.dir\Board.cpp.obj -c "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\Board.cpp"

CMakeFiles/Ai_Algorithms.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ai_Algorithms.dir/Board.cpp.i"
	"D:\Code Blocks\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\Board.cpp" > CMakeFiles\Ai_Algorithms.dir\Board.cpp.i

CMakeFiles/Ai_Algorithms.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ai_Algorithms.dir/Board.cpp.s"
	"D:\Code Blocks\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\Board.cpp" -o CMakeFiles\Ai_Algorithms.dir\Board.cpp.s

# Object files for target Ai_Algorithms
Ai_Algorithms_OBJECTS = \
"CMakeFiles/Ai_Algorithms.dir/main.cpp.obj" \
"CMakeFiles/Ai_Algorithms.dir/Board.cpp.obj"

# External object files for target Ai_Algorithms
Ai_Algorithms_EXTERNAL_OBJECTS =

Ai_Algorithms.exe: CMakeFiles/Ai_Algorithms.dir/main.cpp.obj
Ai_Algorithms.exe: CMakeFiles/Ai_Algorithms.dir/Board.cpp.obj
Ai_Algorithms.exe: CMakeFiles/Ai_Algorithms.dir/build.make
Ai_Algorithms.exe: CMakeFiles/Ai_Algorithms.dir/linklibs.rsp
Ai_Algorithms.exe: CMakeFiles/Ai_Algorithms.dir/objects1.rsp
Ai_Algorithms.exe: CMakeFiles/Ai_Algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Ai_Algorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ai_Algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ai_Algorithms.dir/build: Ai_Algorithms.exe

.PHONY : CMakeFiles/Ai_Algorithms.dir/build

CMakeFiles/Ai_Algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ai_Algorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ai_Algorithms.dir/clean

CMakeFiles/Ai_Algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms" "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms" "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug" "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug" "D:\JetBrains\IdeaProjects\CLionProjects\Artificial Intelligence\AI Project 1\Ai_Algorithms\cmake-build-debug\CMakeFiles\Ai_Algorithms.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ai_Algorithms.dir/depend

