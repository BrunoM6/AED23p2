//
// Created by brunow on 19-12-2023.
//
#include "flightmanager.h"

int flightmanager::number_of_airports() {
    return parser.airports.getNumVertex();
}
int flightmanager::number_of_airlines() {
    return parser.airlines.getNumVertex();
}
int flightmanager::number_of_flights_available() {
    int res = 0;
    for(auto airport : parser.airports) {
        res += airport.getAdj().size();
    }
    return res;
}
int flightmanager::number_of_flights_out(Airport airport) {
    return parser.airports.findVertex(airport).getAdj().size();
}
/*
int flightmanager::number_of_flights_out(Airport airport, int jumps) {
    return parser.airports.findVertex(airport).getAdj().size();
}*/
int flightmanager::number_of_flights_in(Airport airport) {
    int res = 0;
    for(auto airport1 : parser.airports) {
        for(auto flight : airport1.getAdj()) {
            if((flight.getDest() == airport || flights.getDest() == parser.airports_code[airport]) && airport1 != airport) {
                res++;
            }
        }
    }
    return res;
}
int flightmanager::number_of_flights_airline(Airline airline) {
    int res = 0;
    for(auto airport : parser.airports) {
        for(auto flight : airport.getAdj()) {
            if(flight.getWeight() == airline || flight.getWeight() == parser.airlines_code[airline]) {
                res++;
            }
        }
    }
    return res;
}
int flightmanager::number_of_countries(Airport airport) {\
    unordered_set<string> countries;
    Airport airport1 = parser.airports.findVertex(airport);
    for(auto flights : airport1.getAdj()) {
        countries.insert(flights.getDest().getCountry());
    }
    return countries.size();
}
int flightmanager::number_of_cities(Airport airport) {
    unordered_set<string> cities;
    Airport airport1 = parser.airports.findVertex(airport);
    for(auto flights : airport1.getAdj()) {
        cities.insert(flights.getDest().getCity());
    }
    return cities.size();
}

Airport flightmanager::ranking_airport(int rank) {
    vector<pair<int, Airport>> ranking;
    for(auto airport : parser.airports) {
        ranking.push_back(make_pair(number_of_flights_out(airport), airport));
    }
    sort(ranking.begin(), ranking.end(), [](const std::pair<int, Airport>& a, const std::pair<int, Airport>& b) {
        return a.first > b.first;);
    return flights[rank - 1].second;
}

int flightmanager::essential_airports() {

    }