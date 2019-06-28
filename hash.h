//
// Created by rafli on 25/06/2019.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef FINALPROJECT_HASH_H
#define FINALPROJECT_HASH_H
class Hash{
private:

    static const int tableSize = 5;
    int totalItem;

    struct Item{
        string product;
        int qty;
        float price;
        Item * next;
    };


    Item * HashTable[tableSize];

public:
    Hash();
    int hashing(string key);
    bool prdc(string product);
    void removeItem(string name);
    void addItem(string product , int qty , float price);
    void showWarehouse();
};
#endif //FINALPROJECT_HASH_H
