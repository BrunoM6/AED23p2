cmake_minimum_required(VERSION 3.10)
project(AED23p2)

set(CMAKE_CXX_STANDARD 17)


add_executable(
        AED23p2
        Airline.cpp
        Airline.h
        Airport.cpp
        Airline.h
        FlightManager.cpp
        FlightManager.h
        Parser.h
        Parser.cpp
        main.cpp
        Graph.h
        Menu.h
        Menu.cpp
)
