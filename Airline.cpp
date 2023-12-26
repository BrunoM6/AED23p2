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
string Airline::getCallsign() const {
    return callsign;
}
void Airline::setCallsign(string callsign) {
    this->callsign = callsign;
}
string Airline::getCountry() const {
    return country;
}
void Airline::setCountry(string country) {
    this->country = country;
}
bool Airline::operator<(const Airline airline) const {
    return code < airline.getCode();
}
bool Airline::operator==(const Airline airline) const {
    return (this->code == airline.code && this->name == airline.name && this->callsign == airline.callsign && this->country == airline.country);
}