# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build

# Include any dependencies generated for this target.
include CMakeFiles/ByteBuffer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ByteBuffer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ByteBuffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ByteBuffer.dir/flags.make

CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o: CMakeFiles/ByteBuffer.dir/flags.make
CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o: /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/src/ByteBuffer.cpp
CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o: CMakeFiles/ByteBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o -MF CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o.d -o CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o -c /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/src/ByteBuffer.cpp

CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/src/ByteBuffer.cpp > CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.i

CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/src/ByteBuffer.cpp -o CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.s

# Object files for target ByteBuffer
ByteBuffer_OBJECTS = \
"CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o"

# External object files for target ByteBuffer
ByteBuffer_EXTERNAL_OBJECTS =

libByteBuffer.a: CMakeFiles/ByteBuffer.dir/src/ByteBuffer.cpp.o
libByteBuffer.a: CMakeFiles/ByteBuffer.dir/build.make
libByteBuffer.a: CMakeFiles/ByteBuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libByteBuffer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ByteBuffer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ByteBuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ByteBuffer.dir/build: libByteBuffer.a
.PHONY : CMakeFiles/ByteBuffer.dir/build

CMakeFiles/ByteBuffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ByteBuffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ByteBuffer.dir/clean

CMakeFiles/ByteBuffer.dir/depend:
	cd /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build /home/rafael/Escritorio/Proyectos_CPP/ByteBuffer/build/CMakeFiles/ByteBuffer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ByteBuffer.dir/depend

