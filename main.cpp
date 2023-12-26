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
                                    cout << flightManager.number_of_airports()<<'\n';
                                    break;
                                case '2':
                                    cout << flightManager.number_of_airlines()<<'\n';
                                    break;
                                case '3':
                                    cout << flightManager.number_of_flights_available()<<'\n';
                                    break;
                                case '4':
                                    break;
                                default:
                                    cout <<"Invalid Input!\n";
                                    break;

                            }
                            break;
                        case '2':
                            break;
                        case '3':
                            break;
                        case'4':
                            break;
                        case '5':
                            break;
                        case '6':
                            break;
                        case '7':
                            break;
                        case '8':
                            break;
                        case '9':
                            break;
                        default:
                            cout <<"Invalid Input!\n";
                            break;
                    }
                    if(close_consult)break;
                }
                break;
            case '2':
                cout << "Best Flight Option \n";
                break;
            case '3':
                cout << "Filtred flight Option \n";
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