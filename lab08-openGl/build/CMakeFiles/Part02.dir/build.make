# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cshome/m/mismith/COSC342/lab08-openGl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cshome/m/mismith/COSC342/lab08-openGl/build

# Include any dependencies generated for this target.
include CMakeFiles/Part02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Part02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Part02.dir/flags.make

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o: ../Part02/redTriangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o -c /home/cshome/m/mismith/COSC342/lab08-openGl/Part02/redTriangle.cpp

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/Part02/redTriangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/m/mismith/COSC342/lab08-openGl/Part02/redTriangle.cpp > CMakeFiles/Part02.dir/Part02/redTriangle.cpp.i

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/Part02/redTriangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/m/mismith/COSC342/lab08-openGl/Part02/redTriangle.cpp -o CMakeFiles/Part02.dir/Part02/redTriangle.cpp.s

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.requires:

.PHONY : CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.requires

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.provides: CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part02.dir/build.make CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.provides.build
.PHONY : CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.provides

CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.provides.build: CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o


CMakeFiles/Part02.dir/common/Shader.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Shader.cpp.o: ../common/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Part02.dir/common/Shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part02.dir/common/Shader.cpp.o -c /home/cshome/m/mismith/COSC342/lab08-openGl/common/Shader.cpp

CMakeFiles/Part02.dir/common/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/m/mismith/COSC342/lab08-openGl/common/Shader.cpp > CMakeFiles/Part02.dir/common/Shader.cpp.i

CMakeFiles/Part02.dir/common/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/m/mismith/COSC342/lab08-openGl/common/Shader.cpp -o CMakeFiles/Part02.dir/common/Shader.cpp.s

CMakeFiles/Part02.dir/common/Shader.cpp.o.requires:

.PHONY : CMakeFiles/Part02.dir/common/Shader.cpp.o.requires

CMakeFiles/Part02.dir/common/Shader.cpp.o.provides: CMakeFiles/Part02.dir/common/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part02.dir/build.make CMakeFiles/Part02.dir/common/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/Part02.dir/common/Shader.cpp.o.provides

CMakeFiles/Part02.dir/common/Shader.cpp.o.provides.build: CMakeFiles/Part02.dir/common/Shader.cpp.o


CMakeFiles/Part02.dir/common/Camera.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Camera.cpp.o: ../common/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Part02.dir/common/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part02.dir/common/Camera.cpp.o -c /home/cshome/m/mismith/COSC342/lab08-openGl/common/Camera.cpp

CMakeFiles/Part02.dir/common/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/m/mismith/COSC342/lab08-openGl/common/Camera.cpp > CMakeFiles/Part02.dir/common/Camera.cpp.i

CMakeFiles/Part02.dir/common/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/m/mismith/COSC342/lab08-openGl/common/Camera.cpp -o CMakeFiles/Part02.dir/common/Camera.cpp.s

CMakeFiles/Part02.dir/common/Camera.cpp.o.requires:

.PHONY : CMakeFiles/Part02.dir/common/Camera.cpp.o.requires

CMakeFiles/Part02.dir/common/Camera.cpp.o.provides: CMakeFiles/Part02.dir/common/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part02.dir/build.make CMakeFiles/Part02.dir/common/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/Part02.dir/common/Camera.cpp.o.provides

CMakeFiles/Part02.dir/common/Camera.cpp.o.provides.build: CMakeFiles/Part02.dir/common/Camera.cpp.o


CMakeFiles/Part02.dir/common/Scene.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Scene.cpp.o: ../common/Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Part02.dir/common/Scene.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part02.dir/common/Scene.cpp.o -c /home/cshome/m/mismith/COSC342/lab08-openGl/common/Scene.cpp

CMakeFiles/Part02.dir/common/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Scene.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/m/mismith/COSC342/lab08-openGl/common/Scene.cpp > CMakeFiles/Part02.dir/common/Scene.cpp.i

CMakeFiles/Part02.dir/common/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Scene.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/m/mismith/COSC342/lab08-openGl/common/Scene.cpp -o CMakeFiles/Part02.dir/common/Scene.cpp.s

CMakeFiles/Part02.dir/common/Scene.cpp.o.requires:

.PHONY : CMakeFiles/Part02.dir/common/Scene.cpp.o.requires

CMakeFiles/Part02.dir/common/Scene.cpp.o.provides: CMakeFiles/Part02.dir/common/Scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part02.dir/build.make CMakeFiles/Part02.dir/common/Scene.cpp.o.provides.build
.PHONY : CMakeFiles/Part02.dir/common/Scene.cpp.o.provides

CMakeFiles/Part02.dir/common/Scene.cpp.o.provides.build: CMakeFiles/Part02.dir/common/Scene.cpp.o


CMakeFiles/Part02.dir/common/Object.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Object.cpp.o: ../common/Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Part02.dir/common/Object.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part02.dir/common/Object.cpp.o -c /home/cshome/m/mismith/COSC342/lab08-openGl/common/Object.cpp

CMakeFiles/Part02.dir/common/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Object.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/m/mismith/COSC342/lab08-openGl/common/Object.cpp > CMakeFiles/Part02.dir/common/Object.cpp.i

CMakeFiles/Part02.dir/common/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Object.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/m/mismith/COSC342/lab08-openGl/common/Object.cpp -o CMakeFiles/Part02.dir/common/Object.cpp.s

CMakeFiles/Part02.dir/common/Object.cpp.o.requires:

.PHONY : CMakeFiles/Part02.dir/common/Object.cpp.o.requires

CMakeFiles/Part02.dir/common/Object.cpp.o.provides: CMakeFiles/Part02.dir/common/Object.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part02.dir/build.make CMakeFiles/Part02.dir/common/Object.cpp.o.provides.build
.PHONY : CMakeFiles/Part02.dir/common/Object.cpp.o.provides

CMakeFiles/Part02.dir/common/Object.cpp.o.provides.build: CMakeFiles/Part02.dir/common/Object.cpp.o


CMakeFiles/Part02.dir/common/Triangle.cpp.o: CMakeFiles/Part02.dir/flags.make
CMakeFiles/Part02.dir/common/Triangle.cpp.o: ../common/Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Part02.dir/common/Triangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part02.dir/common/Triangle.cpp.o -c /home/cshome/m/mismith/COSC342/lab08-openGl/common/Triangle.cpp

CMakeFiles/Part02.dir/common/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part02.dir/common/Triangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/m/mismith/COSC342/lab08-openGl/common/Triangle.cpp > CMakeFiles/Part02.dir/common/Triangle.cpp.i

CMakeFiles/Part02.dir/common/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part02.dir/common/Triangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/m/mismith/COSC342/lab08-openGl/common/Triangle.cpp -o CMakeFiles/Part02.dir/common/Triangle.cpp.s

CMakeFiles/Part02.dir/common/Triangle.cpp.o.requires:

.PHONY : CMakeFiles/Part02.dir/common/Triangle.cpp.o.requires

CMakeFiles/Part02.dir/common/Triangle.cpp.o.provides: CMakeFiles/Part02.dir/common/Triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part02.dir/build.make CMakeFiles/Part02.dir/common/Triangle.cpp.o.provides.build
.PHONY : CMakeFiles/Part02.dir/common/Triangle.cpp.o.provides

CMakeFiles/Part02.dir/common/Triangle.cpp.o.provides.build: CMakeFiles/Part02.dir/common/Triangle.cpp.o


# Object files for target Part02
Part02_OBJECTS = \
"CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o" \
"CMakeFiles/Part02.dir/common/Shader.cpp.o" \
"CMakeFiles/Part02.dir/common/Camera.cpp.o" \
"CMakeFiles/Part02.dir/common/Scene.cpp.o" \
"CMakeFiles/Part02.dir/common/Object.cpp.o" \
"CMakeFiles/Part02.dir/common/Triangle.cpp.o"

# External object files for target Part02
Part02_EXTERNAL_OBJECTS =

Part02: CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o
Part02: CMakeFiles/Part02.dir/common/Shader.cpp.o
Part02: CMakeFiles/Part02.dir/common/Camera.cpp.o
Part02: CMakeFiles/Part02.dir/common/Scene.cpp.o
Part02: CMakeFiles/Part02.dir/common/Object.cpp.o
Part02: CMakeFiles/Part02.dir/common/Triangle.cpp.o
Part02: CMakeFiles/Part02.dir/build.make
Part02: external/glfw-3.1.2/src/libglfw3.a
Part02: external/libGLEW_1130.a
Part02: CMakeFiles/Part02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Part02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Part02.dir/link.txt --verbose=$(VERBOSE)
	/Applications/CMake.app/Contents/bin/cmake -E copy /home/cshome/m/mismith/COSC342/lab08-openGl/build/./Part02 /home/cshome/m/mismith/COSC342/lab08-openGl/Part02/

# Rule to build all files generated by this target.
CMakeFiles/Part02.dir/build: Part02

.PHONY : CMakeFiles/Part02.dir/build

CMakeFiles/Part02.dir/requires: CMakeFiles/Part02.dir/Part02/redTriangle.cpp.o.requires
CMakeFiles/Part02.dir/requires: CMakeFiles/Part02.dir/common/Shader.cpp.o.requires
CMakeFiles/Part02.dir/requires: CMakeFiles/Part02.dir/common/Camera.cpp.o.requires
CMakeFiles/Part02.dir/requires: CMakeFiles/Part02.dir/common/Scene.cpp.o.requires
CMakeFiles/Part02.dir/requires: CMakeFiles/Part02.dir/common/Object.cpp.o.requires
CMakeFiles/Part02.dir/requires: CMakeFiles/Part02.dir/common/Triangle.cpp.o.requires

.PHONY : CMakeFiles/Part02.dir/requires

CMakeFiles/Part02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Part02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Part02.dir/clean

CMakeFiles/Part02.dir/depend:
	cd /home/cshome/m/mismith/COSC342/lab08-openGl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cshome/m/mismith/COSC342/lab08-openGl /home/cshome/m/mismith/COSC342/lab08-openGl /home/cshome/m/mismith/COSC342/lab08-openGl/build /home/cshome/m/mismith/COSC342/lab08-openGl/build /home/cshome/m/mismith/COSC342/lab08-openGl/build/CMakeFiles/Part02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Part02.dir/depend

