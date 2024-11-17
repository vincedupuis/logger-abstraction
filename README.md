# Usage

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

