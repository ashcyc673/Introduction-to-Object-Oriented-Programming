cmake_minimum_required(VERSION 3.15)
project(ms3)

set(CMAKE_CXX_STANDARD 11)

add_executable(ms3 ReadWritable.cpp ReadWritable.h ParkingAppTester.cpp Vehicle.cpp Vehicle.h Utils.cpp Utils.h Car.cpp Car.h Motorcycle.cpp Motorcycle.h Menu.cpp Menu.h Parking.cpp Parking.h)