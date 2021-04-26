cmake_minimum_required(VERSION 3.19)
project(lazy_foo)

set(CMAKE_CXX_STANDARD 14)

add_executable(lazy_foo
        01_hello_SDL/01_hello_SDL.cpp
        02_getting_an_image_on_the_screen/02_getting_an_image_on_the_screen.cpp
        main.cpp
        )
