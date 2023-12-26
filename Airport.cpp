//
// Created by brunow on 18-12-2023.
//
#include "Airport.h"
Airport::Airport(): code(""), name(""), city(""), country(""), latitude(0), longitude(0) {}
Airport::Airport(string code, string name, string city, string country, double latitude, double longitude)
        : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}
Airport::Airport(string code): code(code) {}
string Airport::getCode() const{
    return code;
}
void Airport::setCode(string code) {
    this->code = code;
}
string Airport::getName() const{
    return name;
}
void Airport::setName(string name) {
    this->name = name;
}
string Airport::getCity() const{
    return city;
}
void Airport::setCity(string city) {
    this->city = city;
}
string Airport::getCountry() const{
    return country;
}
void Airport::setCountry(string country) {
    this->country = country;
}
double Airport::getLatitude() const{
    return latitude;
}
void Airport::setLatitude(double latitude) {
    this->latitude = latitude;
}
double Airport::getLongitude() const{
    return longitude;
}
void Airport::setLongitude(double longitude) {
    this->longitude = longitude;
}
bool Airport::operator<(const Airport airport) const {
    return code< airport.getCode();
}
bool Airport::operator==(const Airport airport) const {
    return (this->code == airport.code && this->name == airport.name && this->city == airport.city && this->country == airport.country && this->latitude == airport.latitude && this->longitude == airport.longitude);
}