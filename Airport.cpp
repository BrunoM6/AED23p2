//
// Created by brunow on 18-12-2023.
//
#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude)
        : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}
string Airport::getcode() const{
    return code;
}
void Airport::setcode(string code) {
    this->code = code;
}
string Airport::getname() const{
    return name;
}
void Airport::setname(string name) {
    this->name = name;
}
string Airport::getcity() const{
    return city;
}
void Airport::setcity(string city) {
    this->city = city;
}
string Airport::getcountry() const{
    return country;
}
void Airport::setcountry(string country) {
    this->country = country;
}
double Airport::getlatitude() const{
    return latitude;
}
void Airport::setlatitude(double latitude) {
    this->latitude = latitude;
}
double Airport::getlongitude() const{
    return longitude;
}
void Airport::setlongitude(double longitude) {
    this->longitude = longitude;
}
bool Airport::operator==(const Airport airport) const {
    return (this->code == airport.code && this->name == airport.name && this->city == airport.city && this->country == airport.country && this->latitude == airport.latitude && this->longitude == airport.longitude);
}