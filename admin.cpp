//
// Created by rafli on 25/06/2019.
//

#include <iostream>
#include <string>
#include <iomanip>

#include "admin.h"

void Admin::showOnGoing() {         // The Table For The Check Order
    cout << endl << "---------------------------------------------------------------------------------------" << endl;
    cout << left << setw(15) << "ORDER ID";
    cout << left << setw(15) << "NAME";
    cout << left << setw(15) << "SHOES";
    cout << left << setw(30) << "SERVICE";
    cout << left << setw(30) << "EST TIME";

    cout << endl << "---------------------------------------------------------------------------------------" << endl;

}


void Admin::checkRevenue() {        // The Table For The Check Revenue

    cout << endl << "--------------------------------------------------------" << endl;
    cout << left << setw(20) << "CAPITAL";
    cout << left << setw(20) << "CLEAN";
    cout << endl << "--------------------------------------------------------" << endl;
}

void Admin::showHistory() {         // The Table For The History

    cout << endl << "---------------------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "NAME";
    cout << left << setw(20) << "SHOES";
    cout << left << setw(30) << "SERVICE";
    cout << left << setw(30) << "DATE";

    cout << endl << "---------------------------------------------------------------------------------------" << endl;
}


