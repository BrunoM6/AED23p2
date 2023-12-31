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
#include <algorithm>
using namespace std;
class FlightManager {
private:
    Parser parser;
    set<Airport> airports;
    set<Airline> airlines;
    Graph<Airport> flights;

    /**
     * @brief Depth-first search to find connected airports.
     * @param v Starting vertex for DFS.
     * @param res Set to store the result.
     * @param first_time Flag indicating the first time DFS is called.
     */
    void dfsairport(Vertex<Airport>*v,set<Airport>& res,bool first_time);

    /**
     * @brief Depth-first search to find connected cities.
     * @param v Starting vertex for DFS.
     * @param res Set to store the result.
     * @param first_time Flag indicating the first time DFS is called.
     */
    void dfscities(Vertex<Airport>*v,set<string>& res,bool first_time);

    /**
     * @brief Depth-first search to find connected countries.
     * @param v Starting vertex for DFS.
     * @param res Set to store the result.
     * @param first_time Flag indicating the first time DFS is called.
     */
    void dfscountries(Vertex<Airport>*v,set<string>& res,bool first_time);
    void dfs_essential_airports(Vertex<Airport>*v,int& index,set<Airport>& res,Vertex<Airport> *parent);
    void best_flight_option_input(list<string>& src, list<string>& dest);


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
    void best_flight_option();
    void best_flight_option_filtred_min(list<string> src, list<string> dest);
    void best_flight_option_filtred_airline(list<string>& src, list<string>& dest,list<string> airline);
    void airlines_input();

};
#endif //PROJETO2_FLIGHTMANAGER_H
