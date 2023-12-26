//
// Created by brunow on 18-12-2023.
//
#include <string>
using namespace std;
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
    string getCode() const;
    void setCode(string code);
    string getName() const;
    void setName(string name);
    string getCallsign() const;
    void setCallsign(string callsign);
    string getCountry() const;
    void setCountry(string country);
    bool operator<(const Airline airline) const;
    bool operator==(const Airline airline) const;
};

#endif //PROJETO2_AIRLINE_H
