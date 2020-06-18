cmake_minimum_required(VERSION 3.1)
project(StateMachine VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
# add_library(MyLibExample simple_lib.cpp simple_lib.hpp)

add_executable(ST 
	src/main.cpp
	src/lightsource/lightsource.cpp
	src/lightsource/lightsourceStates.cpp
)
