//
// Created by rafli on 25/06/2019.
//
#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

void LinkedList::showHistory() {    //Use linkedlist to check the history and if the there's no data it will print out
    Node * temp = head;
    if(temp == NULL){
        cout <<"There is no data" << endl;
    }
    else{
        while(temp!= NULL){
            cout << left << setw(20) << temp->name;     //If there's a data, then it will print out based on the table
            cout << left << setw(20) << temp->shoes;
            cout << left << setw(30) << temp->service;
            cout << left << setw(30) << temp->time;


            cout << endl << "---------------------------------------------------------------------------------------" << endl;

            temp = temp->next;
        }
    }
}

void LinkedList::addToHistory(string name , string shoes , string service , string time) {

// Adding data to the history

    Node * temp = new Node;         //Making a new node for the new data
    temp->name = name;
    temp->shoes = shoes;
    temp->service = service;
    temp->time = time;

    if(head == NULL){
        tail = temp;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else{
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}