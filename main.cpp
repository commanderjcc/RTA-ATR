// Name: Joshua Christensen
// Project: Published/RTA-ATR
// File: main.cpp
// Purposes: Convert Roman to Arabic and Arabic to Roman
// Date: 2/10/20

#include <iostream>
#include <map>
using namespace std;

class Group {
public:
    int total = 0;
    int values[80];
    bool subtraction = false;

    int getTotal() {
        for (int i = 0; i < 80; i++) {
            if (!subtraction) {
                total += values[i];
            } else {
                if (values[i+1] > values[i]) {
                    subtraction = false;
                }
                total -= values[i];
            }
        }

        return total;
    }
};


void RTA() {
    char input[80];
    int count = 0;

}

void ATR() {

}


int main() {
//    int choice = 0;
//    do {
//        cout << "What would you like to do?\n"
//             << "1: Roman to Arabic\n"
//             << "2: Arabic to Roman\n"
//             << "[Enter a number]: ";
//        cin >> choice;
//
//        if (choice == 1) {
//            RTA();
//        } else {
//            ATR();
//        }
//
//    } while (choice != 0);

    auto *myGroup = new Group;

    myGroup->values[0] = 10;
    myGroup->values[1] = 5;
    myGroup->values[2] = 1;
    myGroup->values[4] = 50;
//    myGroup->values[3] = 50;
//    myGroup->values[4] = 5;
//    myGroup->values[5] = 1;
//    myGroup->values[6] = 1;
    myGroup->subtraction = true;

    cout << myGroup->getTotal();

}
