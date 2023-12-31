//
// Created by brunow on 18-12-2023.
//
/**
 * @class Parser
 * @brief Represents a Parser object.
 *
 * The Parser class deals with the parsing of the files from the dataset and the creation of the graphs needed.
 */
#ifndef PROJETO2_PARSER_H
#define PROJETO2_PARSER_H

#include "Airport.h"
#include "Airline.h"
#include "Graph.h"
#include <set>
#include "unordered_set"
class Parser {
private:
    set<Airport> airports;
    set<Airline> airlines;
    Graph<Airport> flights;
public:
    set<Airport>  parseAirports();
    set<Airline> parseAirlines();
    Graph<Airport> parseFlights();

};
#endif //PROJETO2_PARSER_H
