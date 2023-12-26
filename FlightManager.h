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
class FlightManager {
private:
    Parser parser;
    set<Airport> airports;
    set<Airline> airlines;
    Graph<Airport> flights;
public:
    FlightManager();
    int number_of_airports();
    int number_of_airlines();
    int number_of_flights_available();
    int number_of_flights_out(Airport airport);
    int number_of_flights_out_airlines(Airport airport);
    int number_of_flights_airline(string airline);
    int number_of_flights_cities(string city);
    int number_of_countries_airport(string airport);
    int number_of_countries_city(string city);
    int number_of_destinations_airport(Airport airport);
    void dfsairport(Vertex<Airport>*v,set<Airport>& res,bool first_time);
    int number_of_destinations_cities(Airport airport);
    void dfscities(Vertex<Airport>*v,set<string>& res,bool first_time);
    int number_of_destinations_countries(Airport airport);
    void dfscountries(Vertex<Airport>*v,set<string>& res,bool first_time);

};
#endif //PROJETO2_FLIGHTMANAGER_H
