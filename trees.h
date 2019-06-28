//
// Created by rafli on 25/06/2019.
//

#include <iostream>
#include <string>

using namespace std;
#ifndef FINALPROJECT_TREES_H
#define FINALPROJECT_TREES_H
class Trees{
//ID, NAME , SHOES , SERVICE ,EST TIME

public:
    struct Node{
        int id;
        string name;
        string shoes;
        string service;
        string estTime;
        Node * left;
        Node * right;
    };
    Node * root;
    Trees(){
        root = NULL;
    }


    Node * getNewNode(int id , string name , string shoes , string service , string estTime);
    Node * insert(Node* root ,int id , string name , string shoes , string service , string estTime);
    bool Search(Node * root , int id);
    Node * minValueNode(Node* node);
    Node* deleteNode(Node* root, int id);
    void printAllData(Node*root);

    string getFullName(Node * root , int id);
    string getShoes(Node * root , int id);
    string getService(Node * root , int id);
    string getTime(Node * root , int id);




};
#endif //FINALPROJECT_TREES_H
