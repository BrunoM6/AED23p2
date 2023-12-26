//
// Created by brunow on 18-12-2023.
//
#include <string>
using namespace std;
/**
 * @class Airport
 * @brief Represents an airport object.
 *
 * The Airport class contains the attributes code, name, city, country, latitude, and longitude, with getters and setters for all.
 */
#ifndef PROJETO2_AIRPORT_H
#define PROJETO2_AIRPORT_H

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
public:
    Airport();
    Airport(string code, string name, string city, string country, double latitude, double longitude);
    Airport(string code);
    string getCode() const;
    void setCode(string code);
    string getName() const;
    void setName(string name);
    string getCity() const;
    void setCity(string city);
    string getCountry() const;
    void setCountry(string country);
    double getLatitude() const;
    void setLatitude(double latitude);
    double getLongitude() const;
    void setLongitude(double longitude);
    bool operator<(const Airport airport) const;
    bool operator==(const Airport airport) const;
};

#endif //PROJETO2_AIRPORT_H
