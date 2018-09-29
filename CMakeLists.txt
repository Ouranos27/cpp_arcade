cmake_minimum_required(VERSION 3.9)
project(cpp_arcade)

include_directories(include lib/interfaces)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_arcade
        lib/interfaces/IGraphicalLibrary.hpp
        lib/sfml/sfml.cpp
        include/handler.hpp
        include/sfml.hpp
        src/main.cpp
        src/handler.cpp
        games/pacman/pacman.cpp
        include/pacman.hpp
        lib/interfaces/IGameLibrary.hpp
        include/ncurses.hpp
        lib/ncurses/ncurses.cpp
        lib/sdl/sdl.cpp
        include/sdl.hpp)
