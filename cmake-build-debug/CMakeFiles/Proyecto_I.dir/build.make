# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/67/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/67/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/malavassi/Escritorio/Scrabble

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malavassi/Escritorio/Scrabble/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Proyecto_I.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proyecto_I.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proyecto_I.dir/flags.make

CMakeFiles/Proyecto_I.dir/main.cpp.o: CMakeFiles/Proyecto_I.dir/flags.make
CMakeFiles/Proyecto_I.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proyecto_I.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_I.dir/main.cpp.o -c /home/malavassi/Escritorio/Scrabble/main.cpp

CMakeFiles/Proyecto_I.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_I.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malavassi/Escritorio/Scrabble/main.cpp > CMakeFiles/Proyecto_I.dir/main.cpp.i

CMakeFiles/Proyecto_I.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_I.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malavassi/Escritorio/Scrabble/main.cpp -o CMakeFiles/Proyecto_I.dir/main.cpp.s

CMakeFiles/Proyecto_I.dir/Ficha.cpp.o: CMakeFiles/Proyecto_I.dir/flags.make
CMakeFiles/Proyecto_I.dir/Ficha.cpp.o: ../Ficha.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Proyecto_I.dir/Ficha.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_I.dir/Ficha.cpp.o -c /home/malavassi/Escritorio/Scrabble/Ficha.cpp

CMakeFiles/Proyecto_I.dir/Ficha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_I.dir/Ficha.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malavassi/Escritorio/Scrabble/Ficha.cpp > CMakeFiles/Proyecto_I.dir/Ficha.cpp.i

CMakeFiles/Proyecto_I.dir/Ficha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_I.dir/Ficha.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malavassi/Escritorio/Scrabble/Ficha.cpp -o CMakeFiles/Proyecto_I.dir/Ficha.cpp.s

CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.o: CMakeFiles/Proyecto_I.dir/flags.make
CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.o: ../ListaFichas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.o -c /home/malavassi/Escritorio/Scrabble/ListaFichas.cpp

CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malavassi/Escritorio/Scrabble/ListaFichas.cpp > CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.i

CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malavassi/Escritorio/Scrabble/ListaFichas.cpp -o CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.s

CMakeFiles/Proyecto_I.dir/Jugador.cpp.o: CMakeFiles/Proyecto_I.dir/flags.make
CMakeFiles/Proyecto_I.dir/Jugador.cpp.o: ../Jugador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Proyecto_I.dir/Jugador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_I.dir/Jugador.cpp.o -c /home/malavassi/Escritorio/Scrabble/Jugador.cpp

CMakeFiles/Proyecto_I.dir/Jugador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_I.dir/Jugador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malavassi/Escritorio/Scrabble/Jugador.cpp > CMakeFiles/Proyecto_I.dir/Jugador.cpp.i

CMakeFiles/Proyecto_I.dir/Jugador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_I.dir/Jugador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malavassi/Escritorio/Scrabble/Jugador.cpp -o CMakeFiles/Proyecto_I.dir/Jugador.cpp.s

CMakeFiles/Proyecto_I.dir/Juego.cpp.o: CMakeFiles/Proyecto_I.dir/flags.make
CMakeFiles/Proyecto_I.dir/Juego.cpp.o: ../Juego.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Proyecto_I.dir/Juego.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_I.dir/Juego.cpp.o -c /home/malavassi/Escritorio/Scrabble/Juego.cpp

CMakeFiles/Proyecto_I.dir/Juego.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_I.dir/Juego.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malavassi/Escritorio/Scrabble/Juego.cpp > CMakeFiles/Proyecto_I.dir/Juego.cpp.i

CMakeFiles/Proyecto_I.dir/Juego.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_I.dir/Juego.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malavassi/Escritorio/Scrabble/Juego.cpp -o CMakeFiles/Proyecto_I.dir/Juego.cpp.s

# Object files for target Proyecto_I
Proyecto_I_OBJECTS = \
"CMakeFiles/Proyecto_I.dir/main.cpp.o" \
"CMakeFiles/Proyecto_I.dir/Ficha.cpp.o" \
"CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.o" \
"CMakeFiles/Proyecto_I.dir/Jugador.cpp.o" \
"CMakeFiles/Proyecto_I.dir/Juego.cpp.o"

# External object files for target Proyecto_I
Proyecto_I_EXTERNAL_OBJECTS =

Proyecto_I: CMakeFiles/Proyecto_I.dir/main.cpp.o
Proyecto_I: CMakeFiles/Proyecto_I.dir/Ficha.cpp.o
Proyecto_I: CMakeFiles/Proyecto_I.dir/ListaFichas.cpp.o
Proyecto_I: CMakeFiles/Proyecto_I.dir/Jugador.cpp.o
Proyecto_I: CMakeFiles/Proyecto_I.dir/Juego.cpp.o
Proyecto_I: CMakeFiles/Proyecto_I.dir/build.make
Proyecto_I: CMakeFiles/Proyecto_I.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Proyecto_I"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Proyecto_I.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proyecto_I.dir/build: Proyecto_I

.PHONY : CMakeFiles/Proyecto_I.dir/build

CMakeFiles/Proyecto_I.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Proyecto_I.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Proyecto_I.dir/clean

CMakeFiles/Proyecto_I.dir/depend:
	cd /home/malavassi/Escritorio/Scrabble/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malavassi/Escritorio/Scrabble /home/malavassi/Escritorio/Scrabble /home/malavassi/Escritorio/Scrabble/cmake-build-debug /home/malavassi/Escritorio/Scrabble/cmake-build-debug /home/malavassi/Escritorio/Scrabble/cmake-build-debug/CMakeFiles/Proyecto_I.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Proyecto_I.dir/depend

