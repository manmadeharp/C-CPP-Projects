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
CMAKE_COMMAND = "/home/Finbar/Desktop/ubuntu save/JetBrains CLion 2020.1 Build 201.6668.126 for Linux/clion-2020.1/bin/cmake/linux/bin/cmake"

# The command to remove a file.
RM = "/home/Finbar/Desktop/ubuntu save/JetBrains CLion 2020.1 Build 201.6668.126 for Linux/clion-2020.1/bin/cmake/linux/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/Finbar/CLionProjects/Bjarne C++ book"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bjarne_C___book.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bjarne_C___book.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bjarne_C___book.dir/flags.make

CMakeFiles/Bjarne_C___book.dir/main.cpp.o: CMakeFiles/Bjarne_C___book.dir/flags.make
CMakeFiles/Bjarne_C___book.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bjarne_C___book.dir/main.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bjarne_C___book.dir/main.cpp.o -c "/home/Finbar/CLionProjects/Bjarne C++ book/main.cpp"

CMakeFiles/Bjarne_C___book.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bjarne_C___book.dir/main.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/Finbar/CLionProjects/Bjarne C++ book/main.cpp" > CMakeFiles/Bjarne_C___book.dir/main.cpp.i

CMakeFiles/Bjarne_C___book.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bjarne_C___book.dir/main.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/Finbar/CLionProjects/Bjarne C++ book/main.cpp" -o CMakeFiles/Bjarne_C___book.dir/main.cpp.s

CMakeFiles/Bjarne_C___book.dir/test.cpp.o: CMakeFiles/Bjarne_C___book.dir/flags.make
CMakeFiles/Bjarne_C___book.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bjarne_C___book.dir/test.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bjarne_C___book.dir/test.cpp.o -c "/home/Finbar/CLionProjects/Bjarne C++ book/test.cpp"

CMakeFiles/Bjarne_C___book.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bjarne_C___book.dir/test.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/Finbar/CLionProjects/Bjarne C++ book/test.cpp" > CMakeFiles/Bjarne_C___book.dir/test.cpp.i

CMakeFiles/Bjarne_C___book.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bjarne_C___book.dir/test.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/Finbar/CLionProjects/Bjarne C++ book/test.cpp" -o CMakeFiles/Bjarne_C___book.dir/test.cpp.s

# Object files for target Bjarne_C___book
Bjarne_C___book_OBJECTS = \
"CMakeFiles/Bjarne_C___book.dir/main.cpp.o" \
"CMakeFiles/Bjarne_C___book.dir/test.cpp.o"

# External object files for target Bjarne_C___book
Bjarne_C___book_EXTERNAL_OBJECTS =

Bjarne_C___book: CMakeFiles/Bjarne_C___book.dir/main.cpp.o
Bjarne_C___book: CMakeFiles/Bjarne_C___book.dir/test.cpp.o
Bjarne_C___book: CMakeFiles/Bjarne_C___book.dir/build.make
Bjarne_C___book: CMakeFiles/Bjarne_C___book.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Bjarne_C___book"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bjarne_C___book.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bjarne_C___book.dir/build: Bjarne_C___book

.PHONY : CMakeFiles/Bjarne_C___book.dir/build

CMakeFiles/Bjarne_C___book.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bjarne_C___book.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bjarne_C___book.dir/clean

CMakeFiles/Bjarne_C___book.dir/depend:
	cd "/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/Finbar/CLionProjects/Bjarne C++ book" "/home/Finbar/CLionProjects/Bjarne C++ book" "/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug" "/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug" "/home/Finbar/CLionProjects/Bjarne C++ book/cmake-build-debug/CMakeFiles/Bjarne_C___book.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Bjarne_C___book.dir/depend

