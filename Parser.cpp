//
// Created by brunow on 18-12-2023.
//
#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

set<Airport> Parser::parseAirports() {
    ifstream in;
    in.open("../dataset/airports.csv");
    string line;
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string code, name, city, country;
        double latitude, longitude;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        ss >> latitude;
        ss.ignore(1);
        ss >> longitude;
        ss.ignore(1);
        Airport airport(code, name, city, country, latitude, longitude);
        airports.insert(airport);
        flights.addVertex(airport);
    }
    return airports;
}

set<Airline>  Parser::parseAirlines() {
    ifstream in;
    in.open("../dataset/airlines.csv");
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    string line;
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string code, name, callsign, country;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, callsign, ',');
        getline(ss, country);
        Airline airline(code, name, callsign, country);
        airlines.insert(airline);
    }
    return airlines;
}

Graph<Airport>  Parser::parseFlights() {
    ifstream in;
    in.open("../dataset/flights.csv");
    string line;
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string origin, destination, airline;
        getline(ss, origin, ',');
        getline(ss, destination, ',');
        getline(ss, airline);
        auto src = airports.find(Airport(origin));
        auto dest = airports.find(Airport(destination));
        flights.addEdge(*src,*dest,airline);
    }
    return flights;
}


