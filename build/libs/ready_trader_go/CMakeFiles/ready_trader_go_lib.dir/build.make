# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /mnt/c/Users/tavod/PycharmProjects/readytradergo/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /mnt/c/Users/tavod/PycharmProjects/readytradergo/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build

# Include any dependencies generated for this target.
include libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/progress.make

# Include the compile flags for this target's objects.
include libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/flags.make

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/flags.make
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.o: /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/application.cc
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.o"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.o -MF CMakeFiles/ready_trader_go_lib.dir/application.cc.o.d -o CMakeFiles/ready_trader_go_lib.dir/application.cc.o -c /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/application.cc

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ready_trader_go_lib.dir/application.cc.i"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/application.cc > CMakeFiles/ready_trader_go_lib.dir/application.cc.i

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ready_trader_go_lib.dir/application.cc.s"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/application.cc -o CMakeFiles/ready_trader_go_lib.dir/application.cc.s

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/flags.make
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o: /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/autotraderapphandler.cc
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o -MF CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o.d -o CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o -c /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/autotraderapphandler.cc

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.i"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/autotraderapphandler.cc > CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.i

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.s"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/autotraderapphandler.cc -o CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.s

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/flags.make
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o: /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/baseautotrader.cc
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o -MF CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o.d -o CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o -c /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/baseautotrader.cc

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.i"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/baseautotrader.cc > CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.i

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.s"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/baseautotrader.cc -o CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.s

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/flags.make
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o: /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/connectivity.cc
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o -MF CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o.d -o CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o -c /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/connectivity.cc

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.i"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/connectivity.cc > CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.i

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.s"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/connectivity.cc -o CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.s

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/flags.make
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o: /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/protocol.cc
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o -MF CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o.d -o CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o -c /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/protocol.cc

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ready_trader_go_lib.dir/protocol.cc.i"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/protocol.cc > CMakeFiles/ready_trader_go_lib.dir/protocol.cc.i

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ready_trader_go_lib.dir/protocol.cc.s"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go/protocol.cc -o CMakeFiles/ready_trader_go_lib.dir/protocol.cc.s

# Object files for target ready_trader_go_lib
ready_trader_go_lib_OBJECTS = \
"CMakeFiles/ready_trader_go_lib.dir/application.cc.o" \
"CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o" \
"CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o" \
"CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o" \
"CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o"

# External object files for target ready_trader_go_lib
ready_trader_go_lib_EXTERNAL_OBJECTS =

libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/application.cc.o
libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/autotraderapphandler.cc.o
libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/baseautotrader.cc.o
libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/connectivity.cc.o
libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/protocol.cc.o
libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/build.make
libs/ready_trader_go/libready_trader_go_lib.a: libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libready_trader_go_lib.a"
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && $(CMAKE_COMMAND) -P CMakeFiles/ready_trader_go_lib.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ready_trader_go_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/build: libs/ready_trader_go/libready_trader_go_lib.a
.PHONY : libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/build

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/clean:
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go && $(CMAKE_COMMAND) -P CMakeFiles/ready_trader_go_lib.dir/cmake_clean.cmake
.PHONY : libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/clean

libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/depend:
	cd /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/libs/ready_trader_go /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go /mnt/c/Users/tavod/PycharmProjects/readytradergo/bin/build/libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/ready_trader_go/CMakeFiles/ready_trader_go_lib.dir/depend

