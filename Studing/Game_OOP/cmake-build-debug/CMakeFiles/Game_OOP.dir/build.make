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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game_OOP.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Game_OOP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game_OOP.dir/flags.make

CMakeFiles/Game_OOP.dir/main.cpp.o: CMakeFiles/Game_OOP.dir/flags.make
CMakeFiles/Game_OOP.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game_OOP.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_OOP.dir/main.cpp.o -c /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/main.cpp

CMakeFiles/Game_OOP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_OOP.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/main.cpp > CMakeFiles/Game_OOP.dir/main.cpp.i

CMakeFiles/Game_OOP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_OOP.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/main.cpp -o CMakeFiles/Game_OOP.dir/main.cpp.s

CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.o: CMakeFiles/Game_OOP.dir/flags.make
CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.o: ../Cell/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.o -c /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Cell/Cell.cpp

CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Cell/Cell.cpp > CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.i

CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Cell/Cell.cpp -o CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.s

CMakeFiles/Game_OOP.dir/Field/Field.cpp.o: CMakeFiles/Game_OOP.dir/flags.make
CMakeFiles/Game_OOP.dir/Field/Field.cpp.o: ../Field/Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game_OOP.dir/Field/Field.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_OOP.dir/Field/Field.cpp.o -c /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Field/Field.cpp

CMakeFiles/Game_OOP.dir/Field/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_OOP.dir/Field/Field.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Field/Field.cpp > CMakeFiles/Game_OOP.dir/Field/Field.cpp.i

CMakeFiles/Game_OOP.dir/Field/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_OOP.dir/Field/Field.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Field/Field.cpp -o CMakeFiles/Game_OOP.dir/Field/Field.cpp.s

CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.o: CMakeFiles/Game_OOP.dir/flags.make
CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.o: ../Iterator/Iterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.o -c /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Iterator/Iterator.cpp

CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Iterator/Iterator.cpp > CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.i

CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/Iterator/Iterator.cpp -o CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.s

# Object files for target Game_OOP
Game_OOP_OBJECTS = \
"CMakeFiles/Game_OOP.dir/main.cpp.o" \
"CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.o" \
"CMakeFiles/Game_OOP.dir/Field/Field.cpp.o" \
"CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.o"

# External object files for target Game_OOP
Game_OOP_EXTERNAL_OBJECTS =

Game_OOP: CMakeFiles/Game_OOP.dir/main.cpp.o
Game_OOP: CMakeFiles/Game_OOP.dir/Cell/Cell.cpp.o
Game_OOP: CMakeFiles/Game_OOP.dir/Field/Field.cpp.o
Game_OOP: CMakeFiles/Game_OOP.dir/Iterator/Iterator.cpp.o
Game_OOP: CMakeFiles/Game_OOP.dir/build.make
Game_OOP: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Game_OOP: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
Game_OOP: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Game_OOP: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Game_OOP: CMakeFiles/Game_OOP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Game_OOP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game_OOP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game_OOP.dir/build: Game_OOP
.PHONY : CMakeFiles/Game_OOP.dir/build

CMakeFiles/Game_OOP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game_OOP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game_OOP.dir/clean

CMakeFiles/Game_OOP.dir/depend:
	cd /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug /home/danil/Documents/Studing/OOP/Repo_Flint/Studing/Game_OOP/cmake-build-debug/CMakeFiles/Game_OOP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game_OOP.dir/depend

