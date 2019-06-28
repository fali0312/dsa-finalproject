//
// Created by rafli on 25/06/2019.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "trees.h"
using namespace std;
//ID, NAME , SHOES , SERVICE ,EST TIME

Trees::Node * Trees::getNewNode(int id , string name , string shoes , string service , string estTime) {    // Making a new Node
    Node * newNode = new Node();
    newNode->id = id;
    newNode->name = name;
    newNode->shoes = shoes;
    newNode->service = service;
    newNode->estTime = estTime;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Trees::Node * Trees::insert(Node* root ,int id , string name , string shoes , string service , string estTime){     //Inserting a new Node

    if(root == NULL){
        root = getNewNode(id ,  name , shoes , service , estTime);
        cout << "" << endl;
        return root;
    }
    else if(id <= root->id)
        root->left = insert(root->left , id ,  name , shoes , service , estTime);
    else
        root->right = insert(root->right, id ,  name , shoes , service , estTime);
    return root;
}

bool Trees::Search(Trees::Node *root, int id) {         // Function to Check Order by it's id
    if(root == NULL){
        cout << "" << endl;
        return false;
    }


    else if(root->id == id){
        return true;
    }

    else if(id <= root->id) return Search(root->left, id);

    else return Search(root->right , id);
}

string Trees::getFullName(Trees::Node *root, int id) {      //Function to get the Full Name from the Order Menu
    if(root == NULL) cout << "" << endl;

    else if(root->id == id){
        return root->name;
    }

    else if(id <= root->id) getFullName(root->left, id);

    else return getFullName(root->right , id);
}

string Trees::getShoes(Trees::Node *root, int id) {         //Function to get the Shoe Name from the Order Menu
    if(root == NULL) cout << "" << endl;

    else if(root->id == id){
        return root->shoes;
    }

    else if(id <= root->id) getShoes(root->left, id);

    else return getShoes(root->right , id);
}

string Trees::getService(Trees::Node *root, int id) {       //Function to get the service that the customer wants
    if(root == NULL) cout << "" << endl;

    else if(root->id == id){
        return root->service;
    }

    else if(id <= root->id) getService(root->left, id);

    else return getService(root->right , id);
}

string Trees::getTime(Trees::Node *root, int id) {          //Function to get the date and time
    if(root == NULL) cout << "" << endl;

    else if(root->id == id){
        return root->estTime;
    }

    else if(id <= root->id) getTime(root->left, id);

    else return getTime(root->right , id);
}


Trees::Node * Trees::minValueNode(Trees::Node *node) {
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Trees::Node * Trees::deleteNode(Trees::Node *root, int id) {        // Remove node after they done cleaning
    if (root == NULL) return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);

    else if (id > root->id)
        root->right = deleteNode(root->right, id);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->id = temp->id;

        root->right = deleteNode(root->right, temp->id);    //Removing node
    }
    return root;
}

void Trees::printAllData(Trees::Node *root) {           //Print all data from the trees
    if (!root) return;

    printAllData (root->left);
    cout << left << setw(15) << root->id;
    cout << left << setw(15) << root->name;
    cout << left << setw(15) << root->shoes;
    cout << left << setw(30) << root->service;
    cout << left << setw(30) << root->estTime;
    cout << endl << "---------------------------------------------------------------------------------------" << endl;
    printAllData (root->right);
}