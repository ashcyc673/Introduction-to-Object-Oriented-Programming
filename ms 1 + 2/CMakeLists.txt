cmake_minimum_required(VERSION 3.15)
project(ms1)

set(CMAKE_CXX_STANDARD 11)

add_executable(ms1 Menu.cpp Menu.h Utils.cpp Utils.h ms2_ParkingApp.cpp Parking.cpp Parking.h)