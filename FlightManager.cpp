//
// Created by brunow on 19-12-2023.
//
#include "FlightManager.h"
#include "Menu.h"

FlightManager::FlightManager() {
    Parser parser1;
    parser = parser1;
    airports = parser.parseAirports();
    airlines = parser.parseAirlines();
    flights = parser.parseFlights();
}
void FlightManager::number_of_airports() {
    cout << "Number of airports: "<< airports.size()<<'\n';
}

void FlightManager::number_of_airlines() {
    cout << "Number of airlines: "<< airlines.size()<<'\n';
}

void FlightManager::number_of_flights_available() {
    int res = 0;
    for(auto airport : flights.getVertexSet()) {
        res += airport->getAdj().size();
    }
    cout << "Number of flights available: " << res<<'\n';
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
    getline(cin>>ws,city);
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
    cout << "The city " << city << " has " << res << " flights!\n";
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
    getline(cin>>ws,city);
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
        if(vertexpair.second>0)diffairports.insert(vertexpair.first->getInfo());
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
void FlightManager::maximum_trip() {
    int max = 0;
    vector<pair<string,string>> res;
    string src;
    string dest;
    for(auto v : flights.getVertexSet()){
        for(auto v1 : flights.getVertexSet())v1->setVisited(false);
        queue<pair<Vertex<Airport>*,int>> q;
        q.push({v,0});
        v->setVisited(true);
        while (!q.empty()){
            auto vertexpair = q.front();
            q.pop();
            if(vertexpair.second > max){
                max = vertexpair.second;
            }
            for(auto e : vertexpair.first->getAdj()){
                auto w = e.getDest();
                if(!w->isVisited()){
                    q.push({w,vertexpair.second+1});
                    w->setVisited(true);
                }
            }
        }
    }
    for(auto v : flights.getVertexSet()){
        for(auto v1 : flights.getVertexSet())v1->setVisited(false);
        queue<pair<Vertex<Airport>*,int>> q;
        q.push({v,0});
        v->setVisited(true);
        src = v->getInfo().getCode();
        while (!q.empty()){
            auto vertexpair = q.front();
            q.pop();
            if(vertexpair.second == max){
                dest = vertexpair.first->getInfo().getCode();
                res.push_back({src,dest});
            }
            for(auto e : vertexpair.first->getAdj()){
                auto w = e.getDest();
                if(!w->isVisited()){
                    q.push({w,vertexpair.second+1});
                    w->setVisited(true);
                }
            }
        }
    }
    for(auto p : res){
        cout << "From " << p.first << " to " << p.second << "\n";
    }
    cout << "Max distance: "<< max<<'\n';
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
void FlightManager::essential_airports() {
    set<Airport> res;
    int index = 1;
    for (auto v : flights.getVertexSet()) {
        v->setVisited(false);
        v->setNum(0);
        v->setLow(0);
    }
    for (auto v : flights.getVertexSet()) {
        if (!v->isVisited()) {
            dfs_essential_airports(v, index, res, nullptr);
        }
    }
    cout <<"There are "<< res.size()<<" essential airports!";
}

void FlightManager::dfs_essential_airports(Vertex<Airport> *v, int& index, set<Airport> &res, Vertex<Airport> *parent) {
    v->setVisited(true);
    v->setNum(index);
    v->setLow(index);
    index++;
    int children = 0;
    for (auto e : v->getAdj()) {
        auto w = e.getDest();
        if (w == parent) {
            continue;
        }
        if (!w->isVisited()) {
            children++;
            dfs_essential_airports(w, index, res, v);
            v->setLow(min(v->getLow(), w->getLow()));
            if ((parent != nullptr && w->getLow() >= v->getNum()) || (parent == nullptr && children > 1)) {
                res.insert(v->getInfo());
            }
        } else {
            v->setLow(min(v->getLow(), w->getNum()));
        }
    }
}

void FlightManager::best_flight_option_input() {
    Menu menu;
    menu.print_ask_for_flight_option();
    cout << "Choose the option you want to do: ";
    list<string> src;
    list<string> dest;
    char i;
    cin >> i;
    cout << "Choose the source!\n";
    if(i == '1'){
        cout << "---------------------"<<'\n';
        cout << "| 1- Code           |"<<'\n';
        cout << "| 2- Name           |"<<'\n';
        cout << "---------------------"<<'\n';
        cout << "Choose the option you want to do: ";
        char k;
        cin >> k;
        if(k == '1'){
            string  code;
            cout << "Airport Code: ";
            getline(cin>>ws,code);
            auto itr = airports.find(Airport(code));
            if(itr == airports.end()){
                cout <<"Invalid Input!\n";
                return;
            }
            src.push_back(code);
        }
        if(k == '2'){
            string name;
            cout << "Airport Name: ";
            getline(cin>>ws,name);
            for(auto airport: airports){
                if(airport.getName() == name){
                    src.push_back(airport.getCode());
                    break;
                }
            }
            if(src.size()==0){
                cout <<"Invalid Input!\n";
                return;
            }
        }
    }
    else if(i == '2'){
        cout << "City name: ";
        string city;
        getline(cin>>ws,city);
        for(auto airport: airports){
            if(airport.getCity() == city){
                src.push_back(airport.getCode());
            }
        }
        if(src.size()==0){
            cout <<"Invalid Input!\n";
            return;
        }
    }
    else if(i == '3'){
        cout << "Latitude:";
        double latitude;
        cin >> latitude;
        cout << "Longitude:";
        double longitude;
        cin >> longitude;

        double closestDistance = INT_MAX;
        string closestAirport;
        string airportCode;

        for(auto airport = airports.begin(); airport != airports.end(); airport++){
            double distance = airport -> distance(latitude,longitude);
            if (distance < closestDistance){
                closestDistance = distance;
                airportCode = airport -> getCode();
            }
        }
        src.push_back(airportCode);
    }
    else if(i == '4')return;
    else {
        cout <<"Invalid Input!\n";
        return;
    }
    menu.print_ask_for_flight_option();
    cout << "Choose the option you want to do: ";
    char l;
    cin >> l;
    cout << "Choose the destination!\n";
    if(l == '1'){
        cout << "---------------------"<<'\n';
        cout << "| 1- Code           |"<<'\n';
        cout << "| 2- Name           |"<<'\n';
        cout << "---------------------"<<'\n';
        cout << "Choose the option you want to do: ";
        char k;
        cin >> k;
        if(k == '1'){
            string  code;
            cout << "Airport Code: ";
            getline(cin>>ws,code);
            auto itr = airports.find(Airport(code));
            if(itr == airports.end()){
                cout <<"Invalid Input!\n";
                return;
            }
            dest.push_back(code);
        }
        if(k == '2'){
            string name;
            cout << "Airport Name: ";
            getline(cin>>ws,name);
            for(auto airport: airports){
                if(airport.getName() == name){
                    dest.push_back(airport.getCode());
                    break;
                }
            }
            if(dest.size()==0) {
                cout << "Invalid Input!\n";
                return;
            }
        }
    }
    else if(l == '2'){
        cout << "City name: ";
        string city;
        getline(cin>>ws,city);
        for(auto airport: airports){
            if(airport.getCity() == city){
                dest.push_back(airport.getCode());
            }
        }
        if(dest.size()==0){
            cout <<"Invalid Input!\n";
            return;
        }
    }
    else if(l == '3'){
        cout << "Latitude:";
        double latitude;
        cin >> latitude;
        cout << "Longitude:";
        double longitude;
        cin >> longitude;

        double closestDistance = INT_MAX;
        string closestAirport;
        string airportCode;

        for(auto airport = airports.begin(); airport != airports.end(); airport++){
            double distance = airport -> distance(latitude,longitude);
            if (distance < closestDistance){
                closestDistance = distance;
                airportCode = airport -> getCode();
            }
        }
        dest.push_back(airportCode);
    }
    else if(l == '4')return;
    else {
        cout <<"Invalid Input!\n";
        return;
    }
    best_flight_option(src,dest);
}

void FlightManager::best_flight_option(list<std::string> src, list<std::string> dest) {
    vector<list<string>> res;
    for (auto v : flights.getVertexSet())v->setVisited(false);
    for(auto vsrc :src){
        for(auto vdest:dest){
            auto airsrc = airports.find(Airport(vsrc));
            auto airdest = airports.find(Airport(vdest));
            auto vertexsrc = flights.findVertex(*airsrc);
            auto verterxdest = flights.findVertex(*airdest);
            queue<pair<Vertex<Airport>*,list<string>>> vertexpath;
            list<string> path;
            string destcity = verterxdest->getInfo().getName() + " , " + verterxdest->getInfo().getCity();
            vertexpath.push({vertexsrc,path});
            vertexsrc->setVisited(true);
            while(!vertexpath.empty()){
                auto vpath = vertexpath.front();
                vertexpath.pop();
                string city = vpath.first->getInfo().getName() + " , " + vpath.first->getInfo().getCity();
                auto itr = std::find(vpath.second.begin(), vpath.second.end(),destcity);
                if(itr == vpath.second.end()){
                    vpath.second.push_back(city);
                }
                if(vpath.first == verterxdest)res.push_back(vpath.second);
                for(auto e : vpath.first->getAdj()){
                    auto w = e.getDest();
                    if(!w->isVisited()){
                        vertexpath.push({w,vpath.second});
                        w->setVisited(true);
                    }
                }
            }
        }
    }
    int min = 0;
    bool first_time = true;
    for(auto i : res){
        if(first_time){
            min = i.size();
            first_time = false;
        }
        else if(i.size() < min){
            min = i.size();
        }
    }
    for(auto i : res){
        first_time = true;
        if(i.size() == min){
            for(auto city : i){
                if(first_time){
                    cout << "PATH:\n";
                    first_time = false;
                    cout << city<<"\n";
                }
                else{
                    cout << "     | \n";
                    cout << "     | \n";
                    cout << "     v \n";
                    cout << city <<"\n";
                }
            }
        }
    }
}