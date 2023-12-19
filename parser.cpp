//
// Created by brunow on 18-12-2023.
//
#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

void parser::parseAirports() {
    ifstream file('../dataset/airports.csv');
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string code, name, city, country;
        double latitude, longitude;
        int timezone, DST;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        ss >> latitude;
        ss.ignore(1);
        ss >> longitude;
        ss.ignore(1);
        Airport airport(code, name, city, country, latitude, longitude);
        airports.addVertex(airport);
        airports.findVertex(airport).setinfo(code);
        airports_code[code] = name;
    }
}

void parser::parseAirlines() {
    ifstream file('../dataset/airlines.csv');
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string code, name, callsign, country;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, callsign, ',');
        getline(ss, country, ',');
        Airline airline(code, name, callsign, country);
        airlines.addVertex(airline);
        airlines_code[code] = name;
    }
}

void parser::parseFlights() {
    ifstream file('../dataset/flights.csv');
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string origin, destination, airline;
        getline(ss, source, ',');
        getline(ss, target, '');
        getline(ss, airline, ';');
        airports.findVertex(origin).addEdge(airports.findVertex(destination), airlines.findVertex(airline));
    }
}

parser::parser() {
    parseAirports();
    parseAirlines();
    parseFlights();
}