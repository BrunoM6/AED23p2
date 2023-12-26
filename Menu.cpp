//
// Created by joao on 26-12-2023.
//

#include "Menu.h"
#include <iostream>
void Menu::print_mainMenu() {
    cout << "--------------------Menu---------------------"<< '\n';
    cout << "| 1-Consult                                 |"<<'\n';
    cout << "| 2-Best Flight Options                     |"<< '\n';
    cout << "| 3-Best Flight Option Filtred              |"<< '\n';
    cout << "| 4-Quit                                    |" << '\n';
    cout << "---------------------------------------------"<< '\n';
    cout << "Choose the option you want to do: ";
}
void Menu::print_consultMenu() {
    cout << "--------------------------------------Consult Menu--------------------------------------"<<'\n';
    cout << "| 1- Global number of airports/airlines/flights                                        |"<<'\n';
    cout << "| 2- Number of flights/airlines from airport                                           |"<<'\n';
    cout << "| 3- Number of flights from a city/airline                                             |"<<'\n';
    cout << "| 4- Number of countries that a airport/city flies to                                  |"<<'\n';
    cout << "| 5- Number of destinations(airports,cities or countries) available for a given airport|"<<'\n';
    cout << "| 6- Number of reachable destinations from a given airport with X stops                |"<<'\n';
    cout << "| 7- Maiximum trip and corresponding pair with the greatest number of stops            |"<<'\n';
    cout << "| 8- Airport with the greatest air traffic cappacity,greatest number of flights        |"<<'\n';
    cout << "| 9- Identify the airports that are essential to the network’s circulation capability  |"<<'\n';
    cout << "| 0- Quit                                                                              |"<<'\n';
    cout << "----------------------------------------------------------------------------------------"<<'\n';
}
void Menu::print_globalNumberMenu() {
    cout << "----------Global Number----------"<<'\n';
    cout << "| 1- Airport                    |"<<'\n';
    cout << "| 2- Airlines                   |"<<'\n';
    cout << "| 3-Flights                     |"<<'\n';
    cout << "| 4-Quit                        |"<<'\n';
    cout << "---------------------------------"<<'\n';
}