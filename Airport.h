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
    Airport(string code, string name, string city, string country, double latitude, double longitude);
    string getcode() const;
    void setcode(string code);
    string getname() const;
    void setname(string name);
    string getcountry() const;
    void setcountry(string country);
    double getlatitude() const;
    void setlatitude(double latitude);
    double getlongitude() const;
    void setlongitude(double longitude);
    bool operator==(const Airport ) const;
};

#endif //PROJETO2_AIRPORT_H
