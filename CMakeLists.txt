cmake_minimum_required(VERSION 3.21)
project(SVC CXX)

find_package(geode REQUIRED)

add_geode_mod(SVC)

target_sources(SVC PRIVATE
    src/main.cpp
)
