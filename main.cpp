#include <iostream>
#include "Menu.h"
#include "FlightManager.h"

int main(){
    Menu menu;
    FlightManager flightManager;
    while (true){
        menu.print_mainMenu();
        char i;
        cin >> i;
        bool close = false;
        switch (i) {
            case '1':
                while (true){
                    menu.print_consultMenu();
                    char k;
                    cin >> k;
                    bool close_consult = false;
                    switch (k) {
                        case '0':
                            close_consult = true;
                            break;
                        case '1':
                            menu.print_globalNumberMenu();
                            char j;
                            cin >> j;
                            switch (j) {
                                case '1':
                                    flightManager.number_of_airports();
                                    break;
                                case '2':
                                    flightManager.number_of_airlines();
                                    break;
                                case '3':
                                    flightManager.number_of_flights_available();
                                    break;
                                case '4':
                                    break;
                                default:
                                    cout <<"Invalid Input!\n";
                                    break;

                            }
                            break;
                        case '2':
                            flightManager.number_of_flights_out();
                            break;
                        case '3':
                            menu.print_flightscityMenu();
                            char p;
                            cin >> p;
                            switch (p) {
                                case '1':
                                    flightManager.number_of_flights_airline();
                                    break;
                                case '2':
                                    flightManager.number_of_flights_cities();
                                    break;
                                case '3':
                                    break;
                                default:
                                    cout <<"Invalid Input!\n";
                                    break;

                            }
                            break;
                        case'4':
                            menu.print_flytoMenu();
                            char o;
                            cin >> o;
                            switch (o) {
                                case '1':
                                    flightManager.number_of_countries_airport();
                                    break;
                                case '2':
                                    flightManager.number_of_countries_city();
                                    break;
                                case '3':
                                    break;
                                default:
                                    cout <<"Invalid Input!\n";
                                    break;

                            }
                            break;
                        case '5':
                            menu.print_numberDestinationsMenu();
                            char l;
                            cin >> l;
                            switch (l) {
                                case '1':
                                    flightManager.number_of_destinations_airport();
                                    break;
                                case '2':
                                    flightManager.number_of_destinations_cities();
                                    break;
                                case '3':
                                    flightManager.number_of_destinations_countries();
                                    break;
                                case '4':
                                    break;
                                default:
                                    cout <<"Invalid Input!\n";
                                    break;

                            }
                            break;
                        case '6':
                            menu.print_numberDestinationsXMenu();
                            char e;
                            cin >> e;
                            switch (e) {
                                case '1':
                                    flightManager.number_of_destinations_airport_x();
                                    break;
                                case '2':
                                    flightManager.number_of_destinations_cities_x();
                                    break;
                                case '3':
                                    flightManager.number_of_destinations_countries_x();
                                    break;
                                case '4':
                                    break;
                                default:
                                    cout <<"Invalid Input!\n";
                                    break;

                            }
                            break;
                        case '7':
                            flightManager.maximum_trip();
                            break;
                        case '8':
                            flightManager.greatest_traffic_capacity();
                            break;
                        case '9':
                            flightManager.essential_airports();
                            break;
                        default:
                            cout <<"Invalid Input!\n";
                            break;
                    }
                    if(close_consult)break;
                }
                break;
            case '2':
                flightManager.best_flight_option();
                break;
            case '3':
                flightManager.airlines_input();
                break;
            case '4':
                close = true;
                break;
            default:
                cout <<"Invalid Input!\n";
                break;
        }
        if(close)break;
    }
    return 0;
}