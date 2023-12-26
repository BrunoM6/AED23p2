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
void FlightManager::number_of_airports() {
    cout << "Number of airports: "<< airports.size()<<'\n';
    set<string> res;
    for(auto airport : airports){
        res.insert(airport.getCountry());
    }
    cout << res.size() << '\n';
}

void FlightManager::number_of_airlines() {
    cout << "Number of airlines: "<< airlines.size()<<'\n';
}

void FlightManager::number_of_flights_available() {
    int res = 0;
    for(auto airport : flights.getVertexSet()) {
        res += airport->getAdj().size();
    }
    cout << "Number of flights available" << res<<'\n';
}
void FlightManager::number_of_flights_out() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<string> diffairlines;
    for(auto e :v->getAdj()){
        diffairlines.insert(e.getWeight());
    }
    cout << "The airport " << airport << " has " << v->getAdj().size() << " flights and " << diffairlines.size() << " airlines!\n";
}
void FlightManager::number_of_flights_airline() {
    string airline;
    cout << "Code of the airline: ";
    cin >> airline;
    int res = 0;
    bool found = false;
    for(auto v : flights.getVertexSet()){
        for(auto e : v->getAdj()){
            if(airline == e.getWeight()){
                res++;
                found = true;
            }
        }
    }
    if(!found){
        cout << "Invalid Input!\n";
        return;
    }
    cout << "The airline " << airline << " has " << res << " flights!\n";
}
void FlightManager::number_of_flights_cities() {
    string city;
    cout << "Name of the city: ";
    cin >> city;
    int res = 0;
    bool found = false;
    for(auto v : flights.getVertexSet()){
        if(v->getInfo().getCity() == city){
            found = true;
            for(auto e : v->getAdj()){
                res++;
            }
        }
    }
    if(!found){
        cout << "Invalid Input!\n";
        return;
    }
    cout << "The airline " << city << " has " << res << " flights!\n";
}
void FlightManager::number_of_countries_airport() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<string> diffcountries;
    for(auto e : v->getAdj()){
        diffcountries.insert(e.getDest()->getInfo().getCountry());
    }
    cout << "The airport " << airport << " can fly to "<< diffcountries.size() << " countries!\n";
}
void FlightManager::number_of_countries_city() {
    string city;
    cout << "Name of the city: ";
    cin >> city;
    set<string> diffcountries;
    bool found = false;
    for(auto v: flights.getVertexSet() ){
        if(v->getInfo().getCity() == city){
            found = true;
            for(auto e : v->getAdj()){
                diffcountries.insert(e.getDest()->getInfo().getCountry());
            }
        }
    }
    if(!found){
        cout << "Invalid Input!\n";
        return;
    }
    cout << "The city " << city << " can fly to " << diffcountries.size() << " countries!\n";
}
void FlightManager::number_of_destinations_airport() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<Airport> diffairports;
    for(auto vertex : flights.getVertexSet())vertex->setVisited(false);
    dfsairport(v,diffairports, true);
    cout << "The airport " << airport << " can reach " <<diffairports.size()<< " airports!\n";
}
void FlightManager::dfsairport(Vertex<Airport>*v, set<Airport>& res, bool first_time) {
    v->setVisited(true);
    if(!first_time)res.insert((*v).getInfo());
    for(auto& e: v->getAdj()){
        auto dest = e.getDest();
        if(!dest->isVisited())dfsairport(dest,res, false);
    }
}
void FlightManager::number_of_destinations_cities() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<string> diffcities;
    for(auto vertex : flights.getVertexSet())vertex->setVisited(false);
    dfscities(v,diffcities,true);
    cout << "The airport " << airport << " can reach " <<diffcities.size()<< " cities!\n";
}
void FlightManager::dfscities(Vertex<Airport> *v, set<std::string>& res, bool first_time) {
    v->setVisited(true);
    if(!first_time)res.insert((*v).getInfo().getCity());
    for(auto& e: v->getAdj()){
        auto dest = e.getDest();
        if(!dest->isVisited())dfscities(dest,res, false);
    }
}
void FlightManager::number_of_destinations_countries() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<string> diffcountries;
    for(auto vertex : flights.getVertexSet())vertex->setVisited(false);
    dfscountries(v,diffcountries, true);
    cout << "The airport " << airport << " can reach " <<diffcountries.size()<< " countries!\n";
}
void FlightManager::dfscountries(Vertex<Airport> *v, set<std::string> &res, bool first_time) {
    v->setVisited(true);
    if(!first_time)res.insert((*v).getInfo().getCountry());
    for(auto& e : v->getAdj()){
        auto des = e.getDest();
        if(!des->isVisited())dfscountries(des,res,false);
    }
}
void FlightManager::number_of_destinations_airport_x() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    int k;
    cout << "Number of stops: ";
    cin >> k;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<Airport> diffairports;
    for(auto vertex : flights.getVertexSet())vertex->setVisited(false);
    queue<pair<Vertex<Airport>*,int>> q;
    q.push({v,0});
    v->setVisited(true);
    while(!q.empty()){
        auto vertexpair = q.front();
        q.pop();
        if(vertexpair.second> k)break;
        diffairports.insert(vertexpair.first->getInfo());
        for(auto e : vertexpair.first->getAdj()){
            auto dest = e.getDest();
            if(!dest->isVisited()){
                q.push({dest,vertexpair.second+1});
                dest->setVisited(true);
            }
        }
    }
    cout << "The airport " << airport << " can reach " <<diffairports.size()<< " airports with " << k << " stops!\n";
}
void FlightManager::number_of_destinations_cities_x() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    int k;
    cout << "Number of stops: ";
    cin >> k;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<string> diffcitties;
    for(auto vertex : flights.getVertexSet())vertex->setVisited(false);
    queue<pair<Vertex<Airport>*,int>> q;
    q.push({v,0});
    v->setVisited(true);
    while(!q.empty()){
        auto vertexpair = q.front();
        q.pop();
        if(vertexpair.second> k)break;
        if(vertexpair.second>0)diffcitties.insert(vertexpair.first->getInfo().getCity());
        for(auto e : vertexpair.first->getAdj()){
            auto dest = e.getDest();
            if(!dest->isVisited()){
                q.push({dest,vertexpair.second+1});
                dest->setVisited(true);
            }
        }
    }
    cout << "The airport " << airport << " can reach " <<diffcitties.size()<< " citties with " << k << " stops!\n";
}
void FlightManager::number_of_destinations_countries_x() {
    string airport;
    cout << "Code of airport: ";
    cin >>airport;
    int k;
    cout << "Number of stops: ";
    cin >> k;
    auto airp = airports.find(Airport(airport));
    if(airp == airports.end()){
        cout << "Invalid Input!\n";
        return;
    }
    auto v = flights.findVertex(*airp);
    set<string> diffcountries;
    for(auto vertex : flights.getVertexSet())vertex->setVisited(false);
    queue<pair<Vertex<Airport>*,int>> q;
    q.push({v,0});
    v->setVisited(true);
    while(!q.empty()){
        auto vertexpair = q.front();
        q.pop();
        if(vertexpair.second> k)break;
        if(vertexpair.second>0)diffcountries.insert(vertexpair.first->getInfo().getCountry());
        for(auto e : vertexpair.first->getAdj()){
            auto dest = e.getDest();
            if(!dest->isVisited()){
                q.push({dest,vertexpair.second+1});
                dest->setVisited(true);
            }
        }
    }
    cout << "The airport " << airport << " can reach " <<diffcountries.size()<< " countries with " << k << " stops!\n";
}
void FlightManager::greatest_traffic_capacity() {
    for(auto v : flights.getVertexSet()){
        v->setIndegree(0);
    }
    for(auto v : flights.getVertexSet()){
        for(auto e : v->getAdj()){
            e.getDest()->setIndegree(e.getDest()->getIndegree()+1);
        }
    }
    int max = 0;
    Airport airport;
    for(auto v : flights.getVertexSet()){
        if((v->getIndegree() + v->getAdj().size()) > max){
            max = v->getIndegree() + v->getAdj().size();
            airport = v->getInfo();
        }
    }
    cout << "The airport with the greatest air traffic capacity is :\n";
    cout << "Code: " << airport.getCode()<<'\n';
    cout << "Name: " <<airport.getName()<<'\n';
    cout << "City: " <<airport.getCity()<<'\n';
    cout << "Country: " <<airport.getCountry()<<'\n';
    cout << "Latitude: " <<airport.getLatitude()<<'\n';
    cout << "Longitude: " << airport.getLongitude() <<'\n';
}