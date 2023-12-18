//
// Created by brunow on 18-12-2023.
//
/**
 * @class FlightManager
 * @brief Represents a flight manager object.
 *
 * The FlightManager class deals with the parsing of the files from the dataset and the creation of the graphs needed.
 */
#ifndef PROJETO2_FLIGHTMANAGER_H
#define PROJETO2_FLIGHTMANAGER_H

#include "airport.h"
#include "airline.h"
#include "graph.h"

class FlightManager {
private:
    Graph<Airport> airports;
    Graph<Airline> airlines;
    vector<Flights> flights;
public:
    void parseAirports();
    void parseAirlines();
    void parseFlights();
};
#endif //PROJETO2_FLIGHTMANAGER_H
