# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aleksandrazieba/Documents/grafika/3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aleksandrazieba/Documents/grafika/3d/build

# Include any dependencies generated for this target.
include src/Assignments/Colors/CMakeFiles/Colors.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Assignments/Colors/CMakeFiles/Colors.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Assignments/Colors/CMakeFiles/Colors.dir/progress.make

# Include the compile flags for this target's objects.
include src/Assignments/Colors/CMakeFiles/Colors.dir/flags.make

src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.o: src/Assignments/Colors/CMakeFiles/Colors.dir/flags.make
src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.o: /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/main.cpp
src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.o: src/Assignments/Colors/CMakeFiles/Colors.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aleksandrazieba/Documents/grafika/3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.o"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.o -MF CMakeFiles/Colors.dir/main.cpp.o.d -o CMakeFiles/Colors.dir/main.cpp.o -c /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/main.cpp

src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Colors.dir/main.cpp.i"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/main.cpp > CMakeFiles/Colors.dir/main.cpp.i

src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Colors.dir/main.cpp.s"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/main.cpp -o CMakeFiles/Colors.dir/main.cpp.s

src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.o: src/Assignments/Colors/CMakeFiles/Colors.dir/flags.make
src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.o: /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/app.cpp
src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.o: src/Assignments/Colors/CMakeFiles/Colors.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/aleksandrazieba/Documents/grafika/3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.o"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.o -MF CMakeFiles/Colors.dir/app.cpp.o.d -o CMakeFiles/Colors.dir/app.cpp.o -c /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/app.cpp

src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Colors.dir/app.cpp.i"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/app.cpp > CMakeFiles/Colors.dir/app.cpp.i

src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Colors.dir/app.cpp.s"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors/app.cpp -o CMakeFiles/Colors.dir/app.cpp.s

# Object files for target Colors
Colors_OBJECTS = \
"CMakeFiles/Colors.dir/main.cpp.o" \
"CMakeFiles/Colors.dir/app.cpp.o"

# External object files for target Colors
Colors_EXTERNAL_OBJECTS = \
"/Users/aleksandrazieba/Documents/grafika/3d/build/CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o"

src/Assignments/Colors/Colors: src/Assignments/Colors/CMakeFiles/Colors.dir/main.cpp.o
src/Assignments/Colors/Colors: src/Assignments/Colors/CMakeFiles/Colors.dir/app.cpp.o
src/Assignments/Colors/Colors: CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o
src/Assignments/Colors/Colors: src/Assignments/Colors/CMakeFiles/Colors.dir/build.make
src/Assignments/Colors/Colors: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.0.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
src/Assignments/Colors/Colors: _deps/glfw-build/src/libglfw3.a
src/Assignments/Colors/Colors: src/Application/libapplication.a
src/Assignments/Colors/Colors: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.0.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
src/Assignments/Colors/Colors: _deps/glfw-build/src/libglfw3.a
src/Assignments/Colors/Colors: src/Assignments/Colors/CMakeFiles/Colors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/aleksandrazieba/Documents/grafika/3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Colors"
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Colors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Assignments/Colors/CMakeFiles/Colors.dir/build: src/Assignments/Colors/Colors
.PHONY : src/Assignments/Colors/CMakeFiles/Colors.dir/build

src/Assignments/Colors/CMakeFiles/Colors.dir/clean:
	cd /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors && $(CMAKE_COMMAND) -P CMakeFiles/Colors.dir/cmake_clean.cmake
.PHONY : src/Assignments/Colors/CMakeFiles/Colors.dir/clean

src/Assignments/Colors/CMakeFiles/Colors.dir/depend:
	cd /Users/aleksandrazieba/Documents/grafika/3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aleksandrazieba/Documents/grafika/3d /Users/aleksandrazieba/Documents/grafika/3d/src/Assignments/Colors /Users/aleksandrazieba/Documents/grafika/3d/build /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors /Users/aleksandrazieba/Documents/grafika/3d/build/src/Assignments/Colors/CMakeFiles/Colors.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/Assignments/Colors/CMakeFiles/Colors.dir/depend

