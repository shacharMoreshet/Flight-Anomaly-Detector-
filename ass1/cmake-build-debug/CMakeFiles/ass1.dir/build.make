# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\shach\git repos\advanced-programming\ass1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\ass1.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\ass1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ass1.dir\flags.make

CMakeFiles\ass1.dir\MainTrain.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\MainTrain.cpp.obj: ..\MainTrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ass1.dir/MainTrain.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\MainTrain.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\MainTrain.cpp"
<<

CMakeFiles\ass1.dir\MainTrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/MainTrain.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\MainTrain.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\MainTrain.cpp"
<<

CMakeFiles\ass1.dir\MainTrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/MainTrain.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\MainTrain.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\MainTrain.cpp"
<<

CMakeFiles\ass1.dir\anomaly_detection_util.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\anomaly_detection_util.cpp.obj: ..\anomaly_detection_util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ass1.dir/anomaly_detection_util.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\anomaly_detection_util.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\anomaly_detection_util.cpp"
<<

CMakeFiles\ass1.dir\anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/anomaly_detection_util.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\anomaly_detection_util.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\anomaly_detection_util.cpp"
<<

CMakeFiles\ass1.dir\anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/anomaly_detection_util.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\anomaly_detection_util.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\anomaly_detection_util.cpp"
<<

CMakeFiles\ass1.dir\timeseries.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\timeseries.cpp.obj: ..\timeseries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ass1.dir/timeseries.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\timeseries.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\timeseries.cpp"
<<

CMakeFiles\ass1.dir\timeseries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/timeseries.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\timeseries.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\timeseries.cpp"
<<

CMakeFiles\ass1.dir\timeseries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/timeseries.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\timeseries.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\timeseries.cpp"
<<

CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.obj: ..\TimeSeriesAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ass1.dir/TimeSeriesAnomalyDetector.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\TimeSeriesAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/TimeSeriesAnomalyDetector.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\TimeSeriesAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/TimeSeriesAnomalyDetector.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\TimeSeriesAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.obj: ..\SimpleAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ass1.dir/SimpleAnomalyDetector.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\SimpleAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/SimpleAnomalyDetector.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\SimpleAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/SimpleAnomalyDetector.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\SimpleAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\minCircle.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\minCircle.cpp.obj: ..\minCircle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ass1.dir/minCircle.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\minCircle.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\minCircle.cpp"
<<

CMakeFiles\ass1.dir\minCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/minCircle.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\minCircle.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\minCircle.cpp"
<<

CMakeFiles\ass1.dir\minCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/minCircle.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\minCircle.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\minCircle.cpp"
<<

CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.obj: ..\HybridAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ass1.dir/HybridAnomalyDetector.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\HybridAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/HybridAnomalyDetector.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\HybridAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/HybridAnomalyDetector.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\HybridAnomalyDetector.cpp"
<<

CMakeFiles\ass1.dir\CLI.cpp.obj: CMakeFiles\ass1.dir\flags.make
CMakeFiles\ass1.dir\CLI.cpp.obj: ..\CLI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ass1.dir/CLI.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ass1.dir\CLI.cpp.obj /FdCMakeFiles\ass1.dir\ /FS -c "C:\Users\shach\git repos\advanced-programming\ass1\CLI.cpp"
<<

CMakeFiles\ass1.dir\CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/CLI.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ass1.dir\CLI.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\shach\git repos\advanced-programming\ass1\CLI.cpp"
<<

CMakeFiles\ass1.dir\CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/CLI.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass1.dir\CLI.cpp.s /c "C:\Users\shach\git repos\advanced-programming\ass1\CLI.cpp"
<<

# Object files for target ass1
ass1_OBJECTS = \
"CMakeFiles\ass1.dir\MainTrain.cpp.obj" \
"CMakeFiles\ass1.dir\anomaly_detection_util.cpp.obj" \
"CMakeFiles\ass1.dir\timeseries.cpp.obj" \
"CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.obj" \
"CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.obj" \
"CMakeFiles\ass1.dir\minCircle.cpp.obj" \
"CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.obj" \
"CMakeFiles\ass1.dir\CLI.cpp.obj"

# External object files for target ass1
ass1_EXTERNAL_OBJECTS =

ass1.exe: CMakeFiles\ass1.dir\MainTrain.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\anomaly_detection_util.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\timeseries.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\TimeSeriesAnomalyDetector.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\SimpleAnomalyDetector.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\minCircle.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\HybridAnomalyDetector.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\CLI.cpp.obj
ass1.exe: CMakeFiles\ass1.dir\build.make
ass1.exe: CMakeFiles\ass1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ass1.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ass1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ass1.dir\objects1.rsp @<<
 /out:ass1.exe /implib:ass1.lib /pdb:"C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\ass1.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ass1.dir\build: ass1.exe
.PHONY : CMakeFiles\ass1.dir\build

CMakeFiles\ass1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ass1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ass1.dir\clean

CMakeFiles\ass1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\shach\git repos\advanced-programming\ass1" "C:\Users\shach\git repos\advanced-programming\ass1" "C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug" "C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug" "C:\Users\shach\git repos\advanced-programming\ass1\cmake-build-debug\CMakeFiles\ass1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\ass1.dir\depend

