TimerLib
========

A simple cross-platform C++ timer library for benchmarking and profiling.

---
Requirements
=========
CMake

a c++ compiler(duh)

Features
--------
- Lightweight and dependency-free
- Uses C++11 `<chrono>`
- Easy to integrate via CPM.cmake or find_package()
- Includes both wall clock and scoped timing utilities


Installation
---------------

### Option 1: RECOMMENDED Use via CPM.cmake

example CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.14)
project(my_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1 Download CPM.cmake into build dir
file(DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
)

# 2 Include and initialize CPM
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# 3 Fetch TimerLib
CPMAddPackage(
  NAME        TimerLib
  GITHUB_REPOSITORY EmeraldDev52/TimerLib
  GIT_TAG     main
  OPTIONS     "BUILD_TESTS OFF"
)

# 4 Link to your executable
add_executable(my_app src/main.cpp)
target_link_libraries(my_app PRIVATE Timers::TimerLib)
```
### Option 2: Add as a subdirectory
clone the github and add this to your cmake

```cmake
add_subdirectory(path/to/TimerLib)
target_link_libraries(MyApp PRIVATE TimerLib)
```

### Option 3: Use installed package

After installing:
```bash
cmake -S . -B build
cmake --install build --prefix /your/install/path
```
Then in your project:
```cmake
find_package(TimerLib CONFIG REQUIRED)
target_link_libraries(MyApp PRIVATE TimerLib::TimerLib)
```
---
### Usage Example
```cpp
#include <TimerLib/timer.h>

void myFunction() {
    Timers::Timer timer;
    // ... do work ...
    std::cout << "Elapsed time: " << timer.elapsedMilliseconds() << " ms\n";
}
```
or
```cpp
#include <TimerLib/timer.h>

void myFunction() {
    Timers::ScopedTimer timer;
    // ... do work ...
} 
```
This will output the duration after it gets destroyed (hence being scope based) 
or
```cpp
void myFunction() {
    double someDouble;

    if(something){
	    Timers::ScopedTimer timer(&someDouble);
			//... do work ...        
    }
    std::cout << "if statement took" << someDouble << "to execute"
    
} 
```
or even
```cpp
void myFunction() {
    double someDouble;
    Timers::ScopedTimer timer = new Timers::ScopedTimer(&someDouble);
    //something
    delete timer; 
    //something
} 
