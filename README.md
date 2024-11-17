# Logger Abstraction

A lightweight C++ logging abstraction library designed to seamlessly integrate with various logging frameworks. The library provides a flexible and extensible interface, allowing you to easily switch between different logging backends (e.g., spdlog, Boost.Log, custom implementations) without modifying your core code.

## Features
- **Plug-and-Play Design**: Quickly integrate with existing logging solutions.
- **Flexible Interface**: Consistent API for different logging backends.
- **Minimal Overhead**: Lightweight and efficient, ideal for performance-critical applications.
- **Extensible**: Easily add support for additional logging libraries.

## Example
```cpp
#include "ILogger.h"

int main()
{
    logINFO("Hello, {}. Are you {} years old only?!?", "Vincent", 50);

    return 0;
}
```

# Demo

## Using dev container
```
Should work out of the box
```

## Using conan
[Install conan version 2.0.0 or higher](https://conan.io/downloads)
```
conan profile new default --detect
```

### MSVC

````
conan install . --build missing --settings build_type=Debug
cmake --preset conan-default
cmake --build --preset conan-debug
.\build\Debug\logger.exe
````

### gcc

```
conan install . --build missing --settings "&:build_type=Debug" --settings build_type=Release
cmake --preset conan-debug
cmake --build --preset conan-debug
.\build\Debug\logger.exe
```

