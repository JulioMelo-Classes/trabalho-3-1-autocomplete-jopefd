cmake_minimum_required(VERSION 3.5)
project(autocomplete VERSION 0.0.1 LANGUAGES CXX)

include_directories(./autocomplete/)
add_executable(autocomplete
               ./autocomplete/main.cpp
               ./autocomplete/database_controller.cpp
               ./autocomplete/io_controller.cpp
               ./autocomplete/query_controller.cpp)
