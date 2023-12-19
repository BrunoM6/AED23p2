//
// Created by brunow on 18-12-2023.
//
/**
 * @class Parser
 * @brief Represents a parser object.
 *
 * The parser class deals with the parsing of the files from the dataset and the creation of the graphs needed.
 */
#ifndef PROJETO2_PARSER_H
#define PROJETO2_PARSER_H

#include "Airport.h"
#include "Airline.h"
#include "graph.h"
#include "unordered_map"
class parser {
private:
    Graph<Airport> airports;
    Graph<Airline> airlines;
    unordered_map<string> airlines_code;
    unordered_map<string> airports_code;
public:
    void parseAirports();
    void parseAirlines();
    void parseFlights();
    parser() {}
};
#endif //PROJETO2_PARSER_H
