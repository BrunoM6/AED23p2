//
// Created by joao on 26-12-2023.
//

#ifndef AED23P2_MENU_H
#define AED23P2_MENU_H

#include <iostream>
using namespace std;

/**
 * @class Menu
 * @brief Handles the printing of various menus for user interaction.
 */
class Menu {
    public:
    void print_mainMenu();
    void print_consultMenu();
    void print_globalNumberMenu();
    void print_flightscityMenu();
    void print_flytoMenu();
    void print_numberDestinationsMenu();
    void print_numberDestinationsXMenu();
    void print_ask_for_flight_option();
};


#endif //AED23P2_MENU_H
