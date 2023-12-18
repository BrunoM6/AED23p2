//
// Created by brunow on 18-12-2023.
//
#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country)
        : code(code), name(name), callsign(callsign), country(country) {}

string Airline::getCode() const {
    return code;
}
void Airline::setCode(string code) {
    this->code = code;
}
string Airline::getName() const {
    return name;
}
void Airline::setName(string name) {
    this->name = name;
}
string Airline::getcallsign() const {
    return callsign;
}
void Airline::setcallsign(string callsign) {
    this->callsign = callsign;
}
string Airline::getCountry() const {
    return country;
}
void Airline::setCountry(string country) {
    this->country = country;
}

