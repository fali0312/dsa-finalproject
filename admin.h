//
// Created by rafli on 25/06/2019.
//

#include <iostream>
#include "trees.h"
using namespace std;
#ifndef RAFLIFINALPROJECT_ADMIN_H
#define RAFLIFINALPROJECT_ADMIN_H

class Admin{
public:
    int balance[2]={0,0};       //Balance for the revenue
    void showOnGoing();
    void checkRevenue();
    void showHistory();
};


#endif //RAFLIFINALPROJECT_ADMIN_H