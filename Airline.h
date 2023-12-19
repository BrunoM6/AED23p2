//
// Created by brunow on 18-12-2023.
//
#include <string>
using namespace std;]
/**
 * @class Airline
 * @brief Represents an airline object.
 *
 * The Airline class contains the attributes code, name, callsign, and country, with getters and setters for all.
 */
#ifndef PROJETO2_AIRLINE_H
#define PROJETO2_AIRLINE_H

class Airline {
private:
    string code;
    string name;
    string callsign;
    string country;

public:
    Airline(string code, string name, string callsign, string country);
    string getcode() const;
    void setcode(string code);
    string getname() const;
    void setname(string name);
    string getcallsign() const;
    void setcallsign(string callsign);
    string getCountry() const;
    setCountry(string country);
    bool operator==(const Airline ) const;
};

#endif //PROJETO2_AIRLINE_H
