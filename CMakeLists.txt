cmake_minimum_required(VERSION 3.5)
project(autocomplete VERSION 0.0.1 LANGUAGES CXX)

include_directories(./autocomplete/)
add_executable(autocomplete
               ./autocomplete/main.cpp)
