// Name: Joshua Christensen
// Project: Published/RTA-ATR
// File: main.cpp
// Purposes: Convert Roman to Arabic and Arabic to Roman
// Date: 2/10/20

#include <iostream>
using namespace std;

void RTA() {
    char input[16];
    int count = 0;

}

void ATR() {
    char
}


int main() {
    int choice = 0;
    do {
        cout << "What would you like to do?\n"
             << "1: Roman to Arabic\n"
             << "2: Arabic to Roman\n"
             << "[Enter a number]: ";
        cin >> choice;

        if (choice == 1) {
            RTA();
        } else {
            ATR();
        }

    } while (choice != 0);
}
