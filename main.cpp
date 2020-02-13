// Name: Joshua Christensen
// Project: Published/RTA-ATR
// File: main.cpp
// Purposes: Convert Roman to Arabic and Arabic to Roman
// Date: 2/10/20

#include <iostream>
#include <map>
using namespace std;

class Group {
private:
    int numCount = 0;

public:
    int total = 0;
    int values[80];
    bool subtraction = false;


    Group() {
        for (int & value : values) {
            value = 0;
        }
    }

    void appendNum(int num) {
        values[numCount] = num;
        numCount++;
    }

    int getTotal() {
        bool needsSubtraction = subtraction;
        total = 0;
        for (int i = 0; i < 80; i++) {
            if (!needsSubtraction) {
                total += values[i];
            } else {
                if (values[i+1] > values[0]) {
                    needsSubtraction = false;
                }
                total -= values[i];
            }
        }

        return total;
    }
};

class Caesar {
private:
    map<char, int> numerals;

    Group groups[80];
public:
    Caesar(char in[80]) {
        numerals['M'] = 1000000;
        numerals['D'] = 500000;
        numerals['C'] = 100000;
        numerals['L'] = 50000;
        numerals['X'] = 10000;
        numerals['V'] = 5000;
        numerals['I'] = 1;
        numerals['m'] = 1000;
        numerals['d'] = 500;
        numerals['c'] = 100;
        numerals['l'] = 50;
        numerals['x'] = 10;
        numerals['v'] = 5;
        numerals['i'] = 1;

        int startNum = in[0];
        int currentPosition = 0; //we add to it first thing in the loop
        int currentGroup = 0;
        int canContinue = false; //flag to get around loop limiations
        do {
            do {
                cout << "in group " << currentGroup << " with position " << currentPosition << endl;
                groups[currentGroup].appendNum(numerals[in[currentPosition]]);
                cout << "append " << in[currentPosition] << endl;
                if(numerals[in[currentPosition]] < numerals[in[currentPosition+1]]) {
                    groups[currentGroup].subtraction = true;
                    cout << "Subtraction set to true\n";
                }
                currentPosition++;
            } while (groups[currentGroup].values[0] <= numerals[in[currentPosition]] && in[currentPosition] != '\0');
                cout << "stop group " << currentGroup << endl << endl;
                currentGroup++;
        } while (in[currentPosition] != '\0');
        cout << "done!\n";
    }

    int getTotal() {
        int total = 0;
        for (Group currentGroup : groups) {
            cout << currentGroup.getTotal() << endl;
            total += currentGroup.getTotal();
        }

        return total;
    }
};

class Nero {
private:
    map<int, char> numerals;
public:
    int number = 0;

    Nero(int num) {
        numerals[1000000] = 'M';
        numerals[500000] = 'D';
        numerals[100000] = 'C';
        numerals[50000] = 'L';
        numerals[10000] = 'X';
        numerals[5000] = 'V';
        numerals[1000] = 'm';
        numerals[500] = 'd';
        numerals[100] = 'c';
        numerals[50] = 'l';
        numerals[10] = 'x';
        numerals[5] = 'v';
        numerals[1] = 'i';

        number = num;
    }

    string convertToRoman() {
        string currentString;
        int currentTotal = number;

        while (currentTotal >= 1000000) {
            currentTotal -= 1000000;
            currentString.append("M");
        }

        if (currentTotal >= 900000) {
            currentTotal -= 900000;
            currentString.append("CM");
        }

        if (currentTotal >= 500000) {
            currentTotal -= 500000;
            currentString.append("D");
        }

        if (currentTotal >= 400000) {
            currentTotal -= 400000;
            currentString.append("CD");
        }

        while (currentTotal >= 100000) {
            currentTotal -= 100000;
            currentString.append("C");
        }

        if (currentTotal >= 90000) {
            currentTotal -= 90000;
            currentString.append("XC");
        }

        if (currentTotal >= 50000) {
            currentTotal -= 50000;
            currentString.append("L");
        }

        if (currentTotal >= 40000) {
            currentTotal -= 40000;
            currentString.append("XL");
        }

        while (currentTotal >= 10000) {
            currentTotal -= 10000;
            currentString.append("X");
        }

        if (currentTotal >= 9000) {
            currentTotal -= 9000;
            currentString.append("IX");
        }

        if (currentTotal >= 5000) {
            currentTotal -= 5000;
            currentString.append("V");
        }

        if (currentTotal >= 4000) {
            currentTotal -= 4000;
            currentString.append("mV");
        }

        while (currentTotal >= 1000) {
            currentTotal -= 1000;
            currentString.append("m");
        }

        if (currentTotal >= 900) {
            currentTotal -= 900;
            currentString.append("cm");
        }

        if (currentTotal >= 500) {
            currentTotal -= 500;
            currentString.append("d");
        }

        if (currentTotal >= 400) {
            currentTotal -= 400;
            currentString.append("cd");
        }

        while (currentTotal >= 100) {
            currentTotal -= 100;
            currentString.append("c");
        }

        if (currentTotal >= 90) {
            currentTotal -= 90;
            currentString.append("xc");
        }

        if (currentTotal >= 50) {
            currentTotal -= 50;
            currentString.append("l");
        }

        if (currentTotal >= 40) {
            currentTotal -= 40;
            currentString.append("xl");
        }

        while (currentTotal >= 10) {
            currentTotal -= 10;
            currentString.append("x");
        }

        if (currentTotal >= 9) {
            currentTotal -= 9;
            currentString.append("ix");
        }

        if (currentTotal >= 5) {
            currentTotal -= 5;
            currentString.append("v");
        }

        if (currentTotal >= 4) {
            currentTotal -= 4;
            currentString.append("iv");
        }

        while (currentTotal >= 1) {
            currentTotal -= 1;
            currentString.append("i");
        }

        return currentString;

    }

};
    }
};





void RTA() {
    char input[80];

    cout << "\nM = 1000000   m = 1000\n"
         <<   "D = 500000    d = 500\n"
         <<   "C = 100000    c = 100\n"
         <<   "L = 50000     l = 50\n"
         <<   "X = 10000     x = 10\n"
         <<   "V = 5000      v = 5\n"
         <<   "I = 1         i = 1;\n"
         << "[Enter roman numerals]: ";
    cin >> input;

    auto centruion = Caesar(input);

    cout << endl << centruion.getTotal() << endl << endl;
}

void ATR() {

}


int main() {
    int choice = 0;
    do {
        cout << "What would you like to do?\n"
             << "1: Roman to Arabic\n"
             << "2: Arabic to Roman\n"
             << "0: Exit\n"
             << "[Enter a number]: ";
        cin >> choice;

        if (choice == 1) {
            RTA();
        } else if (choice == 2) {
            ATR();
        }

    } while (choice != 0);

    return 0;
}
