//
// Created by brunow on 19-12-2023.
//
#include "FlightManager.h"
FlightManager::FlightManager() {
    Parser parser1;
    parser = parser1;
    airports = parser.parseAirports();
    airlines = parser.parseAirlines();
    flights = parser.parseFlights();
}
int FlightManager::number_of_airports() {
    return airports.size();
}

int FlightManager::number_of_airlines() {
    return airlines.size();
}

int FlightManager::number_of_flights_available() {
    int res = 0;
    for(auto airport : flights.getVertexSet()) {
        res += airport->getAdj().size();
    }
    return res;
}
int FlightManager::number_of_flights_out(Airport airport) {
    return flights.findVertex(airport)->getAdj().size();
}
int FlightManager::number_of_flights_out_airlines(Airport airport) {
    set<string> diffairlines;
    auto v = flights.findVertex(airport);
    for(auto e :v->getAdj()){
        diffairlines.insert(e.getWeight());
    }
    return diffairlines.size();
}
int FlightManager::number_of_flights_airline(string airline) {
    int res = 0;
    for(auto v : flights.getVertexSet()){
        for(auto e : v->getAdj()){
            if(airline == e.getWeight())res++;
        }
    }
    return res;
}
int FlightManager::number_of_flights_cities(string city) {
    int res = 0;
    for(auto v : flights.getVertexSet()){
        if(v->getInfo().getCity() == city){
            for(auto e : v->getAdj())res++;
        }
    }
    return res;
}
int FlightManager::number_of_countries_airport(string airport) {
    auto airp = airports.find(Airport(airport));
    auto v = flights.findVertex(*airp);
    set<string> diffcountries;
    for(auto e : v->getAdj()){
        diffcountries.insert(e.getDest()->getInfo().getCountry());
    }
    return diffcountries.size();
}
int FlightManager::number_of_countries_city(string city) {
    set<string> diffcountries;
    for(auto v: flights.getVertexSet() ){
        if(v->getInfo().getCity() == city){
            for(auto e : v->getAdj()){
                diffcountries.insert(e.getDest()->getInfo().getCountry());
            }
        }
    }
    return diffcountries.size();
}
int FlightManager::number_of_destinations_airport(Airport airport) {
    auto v = flights.findVertex(airport);
    set<Airport> diffairports;
    for(auto v : flights.getVertexSet())v->setVisited(false);
    dfsairport(v,diffairports, true);
    return diffairports.size();
}
void FlightManager::dfsairport(Vertex<Airport>*v, set<Airport>& res, bool first_time) {
    v->setVisited(true);
    if(!first_time)res.insert((*v).getInfo());
    for(auto& e: v->getAdj()){
        auto dest = e.getDest();
        if(!dest->isVisited())dfsairport(dest,res, false);
    }
}
int FlightManager::number_of_destinations_cities(Airport airport) {
    auto v = flights.findVertex(airport);
    set<string> diffcities;
    for(auto v : flights.getVertexSet())v->setVisited(false);
    dfscities(v,diffcities,true);
    return diffcities.size();
}
void FlightManager::dfscities(Vertex<Airport> *v, set<std::string>& res, bool first_time) {
    v->setVisited(true);
    if(!first_time)res.insert((*v).getInfo().getCity());
    for(auto& e: v->getAdj()){
        auto dest = e.getDest();
        if(!dest->isVisited())dfscities(dest,res, false);
    }
}
int FlightManager::number_of_destinations_countries(Airport airport) {
    auto v = flights.findVertex(airport);
    set<string> diffcountries;
    for(auto v : flights.getVertexSet())v->setVisited(false);
    dfscountries(v,diffcountries, true);
    return diffcountries.size();
}
void FlightManager::dfscountries(Vertex<Airport> *v, set<std::string> &res, bool first_time) {
    v->setVisited(true);
    if(!first_time)res.insert((*v).getInfo().getCountry());
    for(auto& e : v->getAdj()){
        auto des = e.getDest();
        if(!des->isVisited())dfscountries(des,res,false);
    }
}