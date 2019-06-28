
#include <iostream>
#include <iomanip>
#include "hash.h"


using namespace std;


int Hash::hashing(string key) {
    int hash = 0;
    int index;

    for (int i = 0 ; i < key.length() ; i++)
    {
        hash += (int)key[i];
    }

    index = hash % tableSize;
    return index;
}

Hash::Hash() {
    for(int i = 0 ; i < tableSize ; i++)
    {
        HashTable[i] = new Item;
        HashTable[i]->product = "empty";
        HashTable[i]->qty = 0;
        HashTable[i]->price = 0;
        HashTable[i]->next = NULL;

    }
}

bool Hash::prdc(string product) {

    int index = hashing(product);
    bool foundName = false;

    Item * Ptr = HashTable[index];

    while(Ptr!=NULL){

        if(Ptr->product == product){
            foundName = true;
            return foundName;
        }
        Ptr = Ptr->next;
    }
    return foundName;

}

void Hash::showWarehouse() {

    if(totalItem==0){
        cout << "You Have No Items !"<< endl;
    }
    else{
        if(totalItem <= 5){

            for (int i = 0 ; i < tableSize ; i++)
            {
                if(HashTable[i]->product != "empty"){
                    cout << left << setw(15) << HashTable[i]->product;
                    cout << left << setw(15) << HashTable[i]->qty;
                    cout << left << setw(15) << HashTable[i]->price;
                    cout << endl << "----------------------------------------------------" << endl;
                }
            }
        }


        else{
            int index = 0;
            while(index <= 4){


                Item * Ptr = HashTable[index];

                while(Ptr != NULL && Ptr->product != "empty"){
                    cout << left << setw(15) << Ptr->product;
                    cout << left << setw(15) << Ptr->qty;
                    cout << left << setw(15) << Ptr->price;
                    cout << endl << "----------------------------------------------------" << endl;

                    Ptr = Ptr->next;
                }
                index++;
            }
        }

    }


}

void Hash::removeItem(string product) {

    int index = hashing(product);
    Item * delPtr;
    Item * p1;
    Item * p2;

    if(HashTable[index]->product == "empty" ){
        cout << "There is no item ! "<< endl;
    }
    else if (HashTable[index]->product == product && HashTable[index]->next == NULL)
    {
        HashTable[index]->product = "empty";
        HashTable[index]->qty = 0;
        HashTable[index]->price = 0;

        cout << product << " has been removed" << endl;
    }
    else if(HashTable[index]->product == product)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;

        cout << product << " has been removed" << endl;

    }
    else
    {

        p1 = HashTable[index]->next;
        p2 = HashTable[index];

        while(p1 != NULL && p1->product != product){
            p2 = p1;
            p1 = p1->next;
        }
        if(p1 == NULL){
            cout << product << "Can't found"<< endl;
        }
        else{
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;

            delete delPtr;

            cout << product << " has been removed" << endl;
        }
    }
}

void Hash::addItem(string product , int qty, float price) {
    if(prdc(product)){
        cout << "Item has already been inserted !" << endl;
    }
    else{

        int index = hashing(product);

        if (HashTable[index]->product == "empty") {
            HashTable[index]->product = product;
            HashTable[index]->qty = qty;
            HashTable[index]->price = price;

            cout << "Item Added" << endl;
            totalItem ++;

        } else {

            Item *temp = HashTable[index];
            Item *ptr = new Item;

            ptr->product = product;
            ptr->qty = qty;
            ptr->price = price;
            ptr->next = NULL;

            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            cout << "Item Added" << endl;
            totalItem ++;

        }
    }

}