//
// Created by brunow on 19-12-2023.
//
/**
 * @class FlightManager
 * @brief Represents a flight manager object.
 *
 * The flight manager class deals with the manipulation of the graphs created by the Parser.
 */
#ifndef PROJETO2_FLIGHTMANAGER_H
#define PROJETO2_FLIGHTMANAGER_H

#include "Parser.h"
#include "unordered_set"
#include <iostream>
using namespace std;
class FlightManager {
private:
    Parser parser;
    set<Airport> airports;
    set<Airline> airlines;
    Graph<Airport> flights;
    void dfsairport(Vertex<Airport>*v,set<Airport>& res,bool first_time);
    void dfscities(Vertex<Airport>*v,set<string>& res,bool first_time);
    void dfscountries(Vertex<Airport>*v,set<string>& res,bool first_time);

public:
    FlightManager();
    void number_of_airports();
    void number_of_airlines();
    void number_of_flights_available();
    void number_of_flights_out();
    void number_of_flights_airline();
    void number_of_flights_cities();
    void number_of_countries_airport();
    void number_of_countries_city();
    void number_of_destinations_airport();
    void number_of_destinations_cities();
    void number_of_destinations_countries();
    void number_of_destinations_airport_x();
    void number_of_destinations_cities_x();
    void number_of_destinations_countries_x();
    void maximum_trip();
    void greatest_traffic_capacity();
    void essential_airports();
    void best_flight_option_input();
    void best_flight_option(list<string> src, list<string> dest);

    void identifyEssentialAirports();

    bool isReachable(Vertex<Airport> *source);
};
#endif //PROJETO2_FLIGHTMANAGER_H
