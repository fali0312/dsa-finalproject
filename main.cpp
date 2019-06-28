#include <iostream>
#include <iomanip>
#include <string>

#include "admin.h"
#include "trees.h"
#include "LinkedList.h"
#include "hash.h"

using namespace std;
int main() {

    //SNIPPET CODE DATE TIME FROM INTERNET
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);


    Admin admin;
    Trees trees;
    LinkedList linkedList;
    Hash hash;
    while (true) {
        int choice;
        cout << endl << "Welcome to Kickstudio.id" << endl << endl;                 //  Menu Print
        cout    << "1. Check Warehouse" << endl
                << "2. Check Order" << endl
                << "3. Order" << endl
                << "4. Check Revenue" << endl
                << "5. History" << endl
                << "6. Exit" << endl << endl
                << "Enter Choice : " << endl;

        cin >> choice;
        if (choice == 1) {
            while (true) {
                int warehouseChoice;                                                // Warehouse Menu
                cout << "1. View" << endl
                     << "2. Add" << endl
                     << "3. Remove" << endl
                     << "4. Back To Home" << endl << endl
                     << "Enter Choice : " << endl;

                cin >> warehouseChoice;
                if (warehouseChoice == 1) {                                        // Viewing The Warehouse Equipment

                    cout << endl << "----------------------------------------------------" << endl;
                    cout << left << setw(15) << "PRODUCT";
                    cout << left << setw(15) << "QUANTITY";
                    cout << left << setw(15) << "PRICE";
                    cout << endl << "----------------------------------------------------" << endl;
                    hash.showWarehouse();
                }
                else if( warehouseChoice == 2){                                     // Inserting New Equipment
                    string product;                                                 // Requires Product Name, Quantity and Price
                    int quantity;
                    float price;

                    cout << "Product Name : " << endl;
                    cin.ignore();
                    getline(cin, product);

                    cout << "Insert Quantity : " << endl;
                    cin >> quantity;

                    cout << "Insert Price : " << endl;
                    cin >> price;

                    hash.addItem(product , quantity , price);           //  Using hash.add to add item to the hash table
                    int capital = quantity * price;                     //  The calculation qty * price
                    admin.balance[0] += capital;              //    By inserting the item, the revenue will increase base on the equipment qty and price
                }
                else if ( warehouseChoice == 3){

                    string removeProduct;                       // Remove Product from Warehouse

                    cout << endl << "----------------------------------------------------" << endl;
                    cout << left << setw(15) << "PRODUCT";
                    cout << left << setw(15) << "QUANTITY";
                    cout << left << setw(15) << "PRICE";
                    cout << endl << "----------------------------------------------------" << endl << endl;
                    hash.showWarehouse();                       // Calling the hash table

                    cout << "Which Product Do You Want To Remove ?" << endl;
                    cin >> removeProduct;                       // Erased based on the name of the product, insert the product to be removed
                    hash.removeItem(removeProduct);

                }
                else if ( warehouseChoice == 4){
                    break;
                }
            }
        }
        else if(choice == 2){                                   // Check order Menu
            admin.showOnGoing();
            trees.printAllData(trees.root);                     // Calling all data from the trees
            while(true) {
                int doneCleaning;
                cout    << "1. Done Cleaning" << endl
                        << "2. Back To Home" << endl << endl
                        << "Insert Your Choice : " << endl;
                cin >> doneCleaning;

                if (doneCleaning == 1) {
                    int orderID;
                    cout << "Enter Order ID" << endl;

                    cin >> orderID;

                    if(trees.Search(trees.root , orderID)){     // Searching for trees by orderID
                        string name , shoes , service , time;
                        int price;
                        name = trees.getFullName(trees.root , orderID);
                        shoes = trees.getShoes(trees.root , orderID);
                        service = trees.getService(trees.root , orderID);
                        time = trees.getTime(trees.root , orderID);
                        if(service == "Fast Cleaning (Rp. 35.000)")
                            price = 35000;
                        else price = 65000;
                        linkedList.addToHistory(name , shoes , service , time);     // After done cleaning it will be inserted to History using LinkedList
                        trees.root = trees.deleteNode(trees.root , orderID);        // After done cleaning it will delete the node base on the OrderID we inserted
                        admin.balance[1] += price;                                  // Also added the amount of money to revenue


                        break;
                    }
                    else{
                        cout << "Invalid Order ID" << endl;
                        break;
                    }

                }
                else if (doneCleaning == 2) {
                    break;
                }
            }
        }
        else if(choice == 3){

            string name , shoes , service , datey;
            int date;
            int id = rand() % 1000 + (1);           // The program will give the ID randomly from 1 to 1000
            cout << "Insert Name : " << endl;
            cin.ignore();
            getline(cin , name);
            cout << "Insert Shoes : " << endl;
            getline(cin, shoes);
            while (true){
                int order;
                cout    << "Please Select Service : " << endl
                        << "1. Fast Cleaning (Rp. 35.000)" << endl
                        << "2. Deep Cleaning (Rp. 65.000)" << endl << endl
                        << "Enter Your Choice :" << endl;

                cin >> order;


                if (order == 1){
                    service = "Fast Cleaning (Rp. 35.000)";
                    date = (tPtr->tm_mday);             // By Choosing Fast Cleaning it will finish the same day because Fast Cleaning took only 30 min
                    datey = to_string(date);
                    break;

                }
                else if (order == 2){
                    service = "Deep Cleaning (Rp. 65.000)";
                    date = (tPtr->tm_mday)+1;           // By Choosing Deep Cleaning it will finish 1 day after the day the shoe inserted
                    datey = to_string(date);
                    break;

                }
                else cout << "Wrong Input ! "<< endl;

            }
            cout << "ORDER SUCCESSFUL !"<< endl;

            int month = (tPtr->tm_mon)+1;
            string monthy = to_string(month);

            int year = (tPtr->tm_year)+1900;
            string yeary = to_string(year);



            string tanggal = datey  + "/" + monthy + "/"  + yeary ;
            trees.root = trees.insert(trees.root , id, name , shoes , service , tanggal);   // The data of the customer's order being inserted to trees

        }
        else if(choice == 4){

            admin.checkRevenue();   // Calling the admin.checkRevenue to show the Revenue
            cout << left << setw(20) << admin.balance[0];
            cout << left << setw(20) << admin.balance[1];
            cout << endl << "--------------------------------------------------------" << endl;

        }
        else if(choice == 5){

            admin.showHistory();
            linkedList.showHistory();       // Show History using linkedlist

        }
        else if(choice == 6){
            break;
        }
        else{
            cout << "Wrong Input" << endl;
        }
    }
    return 0;
}