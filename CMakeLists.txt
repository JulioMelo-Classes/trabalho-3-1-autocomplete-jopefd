cmake_minimum_required(VERSION 3.5)
project(autocomplete VERSION 0.0.1 LANGUAGES CXX)

include_directories(./autocomplete/)
add_executable(autocomplete
  ./autocomplete/database.cpp
  ./autocomplete/io.cpp
  ./autocomplete/main.cpp
  ./autocomplete/query.cpp
)
