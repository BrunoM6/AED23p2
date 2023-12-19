//
// Created by brunow on 19-12-2023.
//
/**
 * @class FlightManager
 * @brief Represents a flight manager object.
 *
 * The flight manager class deals with the manipulation of the graphs created by the parser.
 */
#ifndef PROJETO2_FLIGHTMANAGER_H
#define PROJETO2_FLIGHTMANAGER_H

#include "parser.h"
#include "unordered_set"
class flightmanager {
private:
    parser parser;
public:
    int number_of_airports();
    int number_of_airlines();
    int number_of_flights_available();
    int number_of_flights_out(Airport airport);
    int number_of_flights_out(Airport airport, int jumps);
    int number_of_flights_in(Airport airport);
    int number_of_flights_airline(Airline airline);
    int number_of_countries(Airport airport);
    int number_of_cities(Airport airport);
    int ranking_airport(int rank);
    int essential_airports();
};
#endif //PROJETO2_FLIGHTMANAGER_H
