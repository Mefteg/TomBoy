# TomBoy - Mac

## Setup
- Copy the content of ./SFML-2.3.2/Frameworks to ~/Library/Frameworks
- Copy the content of ./SFML-2.3.2/extlibs to ~/Library/Frameworks (SFML depends on a few external libraries)
- Create folder "build"
- Run CMake
-- Configure as Unix Makefiles
-- Generate

## Build
- Execute `make` in your build folder

## Run
- Execute `./tomboy` in your build folder

## Profiler
- To enable the profiler, set cmake variable MICROPROFILE_ENABLED to ON (disable by default).
