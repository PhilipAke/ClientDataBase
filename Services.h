//
// Created by philip ake on 5/7/23.
//

#ifndef UNTITLED4_SERVICES_H
#define UNTITLED4_SERVICES_H

#endif //UNTITLED4_SERVICES_H
#include "Sales.h"
class Services {
public:
    void servicesMenu() {
        string menuChoice;
        cout << "Please Select what you would like to do:" << endl;
        cout << "1) Add Oil Change" << endl;
        cout << "2) Add Tire Rotation" << endl;
        cout << "3) Add Brake Change" << endl;
        cout << "4) Checkout" << endl;
        cout << "5) Change Order" << endl;
        cout << "6) Return to Main Menu" << endl;
        while ("4" != menuChoice) {
            cin >> menuChoice;
            if (menuChoice == "1") {
                oilChange();
            } else if (menuChoice == "2") {
                tireRotation();
            } else if (menuChoice == "3") {
                brakeChange();
            } else if (menuChoice == "4") {
                checkout();
            } else if (menuChoice == "5") {
                deleteOrder();
            } else if (menuChoice == "6") {
                Clients m;
                m.returnToMenu();
            } else {
                cout << "Invalid Input Please Try Again." << endl;
                servicesMenu();
            }
        }
    }
    void oilChange(){
        cout << "Would you like to add an oil change to your order? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            orderTotal = orderTotal + oilChangePrice;
            cout << "Oil Change Added to Order" << endl;
        }
        else if (choice == "No" or choice == "no" or choice == "N" or choice == "n"){
            cout << "Oil Change Not Added to Order" << endl;
        }
        else {
            cout << "Invalid Input Please Try Again." << endl;
            oilChange();
        }
        servicesMenu();
    }
    void tireRotation(){
        cout << "Would you like to add a tire rotation to your order? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            orderTotal = orderTotal + tireRotationPrice;
            cout << "Tire Rotation Added to Order" << endl;
        }
        else if (choice == "No" or choice == "no" or choice == "N" or choice == "n"){
            cout << "Tire Rotation Not Added to Order" << endl;
        }
        else {
            cout << "Invalid Input Please Try Again." << endl;
            tireRotation();
        }
        servicesMenu();
    }
    void brakeChange(){
        cout << "Would you like to add a brake change to your order? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            orderTotal = orderTotal + brakeChangePrice;
            cout << "Brake Change Added to Order" << endl;
        }
        else if (choice == "No" or choice == "no" or choice == "N" or choice == "n"){
            cout << "Brake Change Not Added to Order" << endl;
        }
        else {
            cout << "Invalid Input Please Try Again." << endl;
            brakeChange();
        }
        servicesMenu();
    }
    void checkout(){
        cout << "Your total is: $" << orderTotal << endl;
        cout << "Would you like to checkout? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            cout << "Please enter Sales Rep ID: " << endl;
            string id;
            cin >> id;
            fstream salesTotal, temp;
            salesTotal.open("/Users/philipake/CLionProjects/untitled4/salesRep.txt", ios::in);
            temp.open("/Users/philipake/CLionProjects/untitled4/TempRep.txt", ios::out);
            int salesFinal;
            string salesRepID, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11;
            while(salesTotal >> salesRepID >> line2 >> line3 >> line4 >> line5 >> line6 >> line7 >> line8 >> line9 >> line10 >> line11 >> salesFinal){
                if (id != salesRepID) {
                    temp << salesRepID << " " << line2 << " " << line3 << " " << line4 << " " << line5 << " " << line6
                         << " " << line7 << " " << line8 << " " << line9 << " " << line10 << " " << line11 << " "
                         << salesFinal << endl;
                }
                else {
                    int salesFinalInt = salesFinal;
                    salesFinalInt = salesFinalInt + orderTotal;
                    salesFinal = salesFinalInt;
                    temp << salesRepID << " " << line2 << " " << line3 << " " << line4 << " " << line5 << " " << line6 << " " << line7 << " " << line8 << " " << line9 << " " << line10 << " " << line11 << " " << salesFinal << endl;
                    cout << "Thank you for your purchase!" << endl;

                }
            }
            salesTotal.close();
            temp.close();
            remove("/Users/philipake/CLionProjects/untitled4/salesRep.txt");
            rename("/Users/philipake/CLionProjects/untitled4/TempRep.txt", "/Users/philipake/CLionProjects/untitled4/salesRep.txt");
            orderTotal = 0;
        }
        else if (choice == "No" or choice == "no" or choice == "N" or choice == "n"){
            cout << "Returning to Services Menu" << endl;
            servicesMenu();

        }
        else {
            cout << "Invalid Input Please Try Again." << endl;
            checkout();
        }
        servicesMenu();

    }
    void deleteOrder(){
        cout << "Would you like to change your order? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            cout << "What would you like to remove from your order?" << endl;
            cout << "1) Oil Change" << endl;
            cout << "2) Tire Rotation" << endl;
            cout << "3) Brake Change" << endl;
            cout << "4) Delete Order" << endl;
            cout << "5) Return to Services Menu" << endl;
            string choice2;
            cin >> choice2;
            if (choice2 == "1" and orderTotal >= oilChangePrice){
                orderTotal = orderTotal - oilChangePrice;
                cout << "Oil Change Removed from Order" << endl;
                cout << "New Order Total: $" << orderTotal << endl;
                servicesMenu();
            }
            else if (choice2 == "2" and orderTotal >= tireRotationPrice){
                orderTotal = orderTotal - tireRotationPrice;
                cout << "Tire Rotation Removed from Order" << endl;
                cout << "New Order Total: $" << orderTotal << endl;
                servicesMenu();
            }
            else if (choice2 == "3" and orderTotal >= brakeChangePrice){
                orderTotal = orderTotal - brakeChangePrice;
                cout << "Brake Change Removed from Order" << endl;
                cout << "New Order Total: $" << orderTotal << endl;
                servicesMenu();
            }
            else if (choice2 == "4"){
                orderTotal = 0;
                cout << "Order Deleted" << endl;
            }
            else if (choice2 == "5"){
                cout << "Returning to Services Menu" << endl;
                servicesMenu();
            }
            else {
                cout << "Invalid Input Please Try Again." << endl;
                deleteOrder();
            }
        }
        else {
            cout << "Returning to Services Menu" << endl;
            servicesMenu();}


    }
private:
    int oilChangePrice = 50;
    int tireRotationPrice = 20;
    int brakeChangePrice = 100;
    int orderTotal = 0;

};