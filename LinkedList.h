//
// Created by rafli on 25/06/2019.
//
#include <iostream>
#include <string>
#include "admin.h"
using namespace std;
#ifndef FINALPROJECT_LINKEDLIST_H
#define FINALPROJECT_LINKEDLIST_H

class LinkedList{
    struct Node{
        string name;
        string shoes;
        string service;
        string time;
        Node*next;
        Node*prev;
    };
public:
    Node * head;
    Node * tail;
    LinkedList(){
        head = NULL;
        tail = NULL;

    }
    ~LinkedList(){

    }
    void showHistory();
    void addToHistory(string name , string shoes , string service , string time);

};


#endif //FINALPROJECT_LINKEDLIST_H
