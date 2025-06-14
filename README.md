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

add this to your CMakeLists.txt
```cmake
file(DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
)

include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage(
  NAME TimerLib
  GITHUB_REPOSITORY EmeraldDev52/TimerLib
  GIT_TAG main
)


# LINK IT TO YOUR PEOJECT WITH SOMETHING LIKE
add_executable(MyProject source.cpp)
target_link_libraries(MyProject PRIVATE TimerLib)
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
    TimerLib::Timer timer;
    // ... do work ...
    std::cout << "Elapsed time: " << timer.elapsedMilliseconds() << " ms\n";
}
```
or
```cpp
#include <TimerLib/timer.h>

void myFunction() {
    TimerLib::ScopedTimer timer;
    // ... do work ...
} 
```
This will output the duration after it gets destroyed (hence being scope based) 
or even
```cpp
void myFunction() {
	double someDouble;

    if(something){
	    TimerLib::ScopedTimer timer(&someDouble);
			//... do work ...        
    }
    std::cout << "if statement took" << someDouble << "to execute"
    
} 
```
