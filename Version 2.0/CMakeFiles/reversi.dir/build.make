# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2

# Include any dependencies generated for this target.
include CMakeFiles/reversi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reversi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reversi.dir/flags.make

CMakeFiles/reversi.dir/matriz.cpp.o: CMakeFiles/reversi.dir/flags.make
CMakeFiles/reversi.dir/matriz.cpp.o: matriz.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reversi.dir/matriz.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reversi.dir/matriz.cpp.o -c /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/matriz.cpp

CMakeFiles/reversi.dir/matriz.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reversi.dir/matriz.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/matriz.cpp > CMakeFiles/reversi.dir/matriz.cpp.i

CMakeFiles/reversi.dir/matriz.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reversi.dir/matriz.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/matriz.cpp -o CMakeFiles/reversi.dir/matriz.cpp.s

CMakeFiles/reversi.dir/matriz.cpp.o.requires:

.PHONY : CMakeFiles/reversi.dir/matriz.cpp.o.requires

CMakeFiles/reversi.dir/matriz.cpp.o.provides: CMakeFiles/reversi.dir/matriz.cpp.o.requires
	$(MAKE) -f CMakeFiles/reversi.dir/build.make CMakeFiles/reversi.dir/matriz.cpp.o.provides.build
.PHONY : CMakeFiles/reversi.dir/matriz.cpp.o.provides

CMakeFiles/reversi.dir/matriz.cpp.o.provides.build: CMakeFiles/reversi.dir/matriz.cpp.o


CMakeFiles/reversi.dir/tablero.cpp.o: CMakeFiles/reversi.dir/flags.make
CMakeFiles/reversi.dir/tablero.cpp.o: tablero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reversi.dir/tablero.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reversi.dir/tablero.cpp.o -c /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/tablero.cpp

CMakeFiles/reversi.dir/tablero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reversi.dir/tablero.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/tablero.cpp > CMakeFiles/reversi.dir/tablero.cpp.i

CMakeFiles/reversi.dir/tablero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reversi.dir/tablero.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/tablero.cpp -o CMakeFiles/reversi.dir/tablero.cpp.s

CMakeFiles/reversi.dir/tablero.cpp.o.requires:

.PHONY : CMakeFiles/reversi.dir/tablero.cpp.o.requires

CMakeFiles/reversi.dir/tablero.cpp.o.provides: CMakeFiles/reversi.dir/tablero.cpp.o.requires
	$(MAKE) -f CMakeFiles/reversi.dir/build.make CMakeFiles/reversi.dir/tablero.cpp.o.provides.build
.PHONY : CMakeFiles/reversi.dir/tablero.cpp.o.provides

CMakeFiles/reversi.dir/tablero.cpp.o.provides.build: CMakeFiles/reversi.dir/tablero.cpp.o


CMakeFiles/reversi.dir/jugador.cpp.o: CMakeFiles/reversi.dir/flags.make
CMakeFiles/reversi.dir/jugador.cpp.o: jugador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/reversi.dir/jugador.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reversi.dir/jugador.cpp.o -c /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/jugador.cpp

CMakeFiles/reversi.dir/jugador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reversi.dir/jugador.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/jugador.cpp > CMakeFiles/reversi.dir/jugador.cpp.i

CMakeFiles/reversi.dir/jugador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reversi.dir/jugador.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/jugador.cpp -o CMakeFiles/reversi.dir/jugador.cpp.s

CMakeFiles/reversi.dir/jugador.cpp.o.requires:

.PHONY : CMakeFiles/reversi.dir/jugador.cpp.o.requires

CMakeFiles/reversi.dir/jugador.cpp.o.provides: CMakeFiles/reversi.dir/jugador.cpp.o.requires
	$(MAKE) -f CMakeFiles/reversi.dir/build.make CMakeFiles/reversi.dir/jugador.cpp.o.provides.build
.PHONY : CMakeFiles/reversi.dir/jugador.cpp.o.provides

CMakeFiles/reversi.dir/jugador.cpp.o.provides.build: CMakeFiles/reversi.dir/jugador.cpp.o


CMakeFiles/reversi.dir/reversi.cpp.o: CMakeFiles/reversi.dir/flags.make
CMakeFiles/reversi.dir/reversi.cpp.o: reversi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/reversi.dir/reversi.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reversi.dir/reversi.cpp.o -c /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/reversi.cpp

CMakeFiles/reversi.dir/reversi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reversi.dir/reversi.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/reversi.cpp > CMakeFiles/reversi.dir/reversi.cpp.i

CMakeFiles/reversi.dir/reversi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reversi.dir/reversi.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/reversi.cpp -o CMakeFiles/reversi.dir/reversi.cpp.s

CMakeFiles/reversi.dir/reversi.cpp.o.requires:

.PHONY : CMakeFiles/reversi.dir/reversi.cpp.o.requires

CMakeFiles/reversi.dir/reversi.cpp.o.provides: CMakeFiles/reversi.dir/reversi.cpp.o.requires
	$(MAKE) -f CMakeFiles/reversi.dir/build.make CMakeFiles/reversi.dir/reversi.cpp.o.provides.build
.PHONY : CMakeFiles/reversi.dir/reversi.cpp.o.provides

CMakeFiles/reversi.dir/reversi.cpp.o.provides.build: CMakeFiles/reversi.dir/reversi.cpp.o


# Object files for target reversi
reversi_OBJECTS = \
"CMakeFiles/reversi.dir/matriz.cpp.o" \
"CMakeFiles/reversi.dir/tablero.cpp.o" \
"CMakeFiles/reversi.dir/jugador.cpp.o" \
"CMakeFiles/reversi.dir/reversi.cpp.o"

# External object files for target reversi
reversi_EXTERNAL_OBJECTS =

reversi: CMakeFiles/reversi.dir/matriz.cpp.o
reversi: CMakeFiles/reversi.dir/tablero.cpp.o
reversi: CMakeFiles/reversi.dir/jugador.cpp.o
reversi: CMakeFiles/reversi.dir/reversi.cpp.o
reversi: CMakeFiles/reversi.dir/build.make
reversi: CMakeFiles/reversi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable reversi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reversi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reversi.dir/build: reversi

.PHONY : CMakeFiles/reversi.dir/build

CMakeFiles/reversi.dir/requires: CMakeFiles/reversi.dir/matriz.cpp.o.requires
CMakeFiles/reversi.dir/requires: CMakeFiles/reversi.dir/tablero.cpp.o.requires
CMakeFiles/reversi.dir/requires: CMakeFiles/reversi.dir/jugador.cpp.o.requires
CMakeFiles/reversi.dir/requires: CMakeFiles/reversi.dir/reversi.cpp.o.requires

.PHONY : CMakeFiles/reversi.dir/requires

CMakeFiles/reversi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reversi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reversi.dir/clean

CMakeFiles/reversi.dir/depend:
	cd /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2 /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2 /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2 /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2 /home/pablo/Escritorio/PracticasConCppMetProg17/reversi/version2/CMakeFiles/reversi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reversi.dir/depend

