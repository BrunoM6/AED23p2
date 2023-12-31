//
// Created by brunow on 18-12-2023.
//
#include <string>
#include <cmath>

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

    /**
     * @brief Checks if this airport has less priority than the specified airport by comparing their codes.
     * @param airport Airport to be compared.
     * @return True if this airport has less priority than the specified airport, else false.
     */
    bool operator<(const Airport airport) const;

    /**
     * @brief Checks if this airport is equal to the specified airport by comparing their codes.
     * @param airport Airport to be compared.
     * @return True if this airport is equal to the specified airport, else false.
     */
    bool operator==(const Airport airport) const;

    /**
     * Calculates the distance between an airport and a location
     * @param latitude1 of location
     * @param longitude1 of location
     * @return distance
     */
    double distance(double latitude1, double longitude1) const;
};


#endif //PROJETO2_AIRPORT_H
