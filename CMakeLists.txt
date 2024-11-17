cmake_minimum_required(VERSION 3.28)
project(logger)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    set(CMAKE_CXX_FLAGS "/EHsc /Wall /W4 /WX")
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi /D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else ()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-inline -fno-elide-constructors")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif ()

find_package(spdlog REQUIRED)

add_executable(logger
        src/ILogger.h
        src/main.cpp
        src/SpdlogLogger.h
        src/SpdlogLogger.cpp
)

target_compile_definitions(logger PRIVATE SPDLOG_COMPILED_LIB)

target_link_libraries(logger spdlog::spdlog)
