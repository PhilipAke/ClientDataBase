//
// Created by philip ake on 5/6/23.
//

#ifndef UNTITLED4_SALES_H
#define UNTITLED4_SALES_H

#endif //UNTITLED4_SALES_H
#include "salesRep.h"
class Sales {
public:
    void salesMenu(){
        string menuChoice;
        cout << "Please Select what you would like to do:" << endl;
        cout << "1) Annual Sales" << endl;
        cout << "2) Monthly Sales" << endl;
        cout << "3) Return to Main Menu" << endl;
        while ("3" != menuChoice) {
            cin >> menuChoice;
            if (menuChoice == "1") {
                annualSales();
            } else if (menuChoice == "2") {
                monthlySales();
            } else if (menuChoice == "3") {
                Clients m;
                m.returnToMenu();
            } else {
                cout << "Invalid Input Please Try Again." << endl;
                salesMenu();
            }
        }
    }
    void annualSales(){
        fstream sales;
        cout << "Enter the year you would like to view: ";
        int yearCheck;
        cin >> yearCheck;
        int yearSales = 0;
        string line1, line2, line3, line4, line5, line6, line7, line8, line9, month, salestotal;
        int year2;
        Clients l;
        int count = l.countClients();
        sales.open("/Users/philipake/CLionProjects/untitled4/salesRep.txt", ios::in);
        for (int i = 0; i < count; i++){
            while (sales >> line1 >> line2 >> line3 >> line4 >> line5 >> line6 >> line7 >> line8 >> line9>> month >> year2 >> salestotal) {
                if (year2 == yearCheck) {
                    yearSales = stoi(salestotal) + yearSales;
                }
            }
        }
        cout << "Total Sales For " << yearCheck << ": " << yearSales << endl;
        cout << "Return to Sales Menu? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            salesMenu();
        }
        else if (choice == "No" or choice == "no" or choice == "N" or choice == "n"){
            Clients m;
            m.returnToMenu();
        }
        else{
            cout << "Invalid Input Please Try Again." << endl;
            monthlySales();
        }

    }
    void monthlySales() {
        fstream sales;
        cout << "Enter the year you would like to view: ";
        int yearCheck;
        cin >> yearCheck;
        int monthSales1 = 0;
        int monthSales2 = 0;
        int monthSales3 = 0;
        int monthSales4 = 0;
        int monthSales5 = 0;
        int monthSales6 = 0;
        int monthSales7 = 0;
        int monthSales8 = 0;
        int monthSales9 = 0;
        int monthSales10 = 0;
        int monthSales11 = 0;
        int monthSales12 = 0;
        string line1, line2, line3, line4, line5, line6, line7, line8, line9, month, salestotal;
        int year2;
        Clients l;
        int count = l.countClients();
        sales.open("/Users/philipake/CLionProjects/untitled4/salesRep.txt", ios::in);
        for (int i = 0; i < count; i++){
            while (sales >> line1 >> line2 >> line3 >> line4 >> line5 >> line6 >> line7 >> line8 >> line9>> month >> year2 >> salestotal) {
                {       if (month == "01" and year2 == yearCheck) {
                        monthSales1 = stoi(salestotal) + monthSales1;
                        cout << yearCheck;
                    }
                    if (month == "02" and year2 == yearCheck) {
                        monthSales2 = stoi(salestotal) + monthSales2;
                    }
                    if (month == "03" and year2 == yearCheck) {
                        monthSales3 = stoi(salestotal) + monthSales3;
                    }
                    if (month == "04" and year2 == yearCheck) {
                        monthSales4 = stoi(salestotal) + monthSales4;
                    }
                    if (month == "05" and year2 == yearCheck) {
                        monthSales5 = stoi(salestotal) + monthSales5;
                    }
                    if (month == "06" and year2 == yearCheck) {
                        monthSales6 = stoi(salestotal) + monthSales6;
                    }
                    if (month == "07" and year2 == yearCheck) {
                        monthSales7 = stoi(salestotal) + monthSales7;
                    }
                    if (month == "08" and year2 == yearCheck) {
                        monthSales8 = stoi(salestotal) + monthSales8;
                    }
                    if (month == "09" and year2 == yearCheck) {
                        monthSales9 = stoi(salestotal) + monthSales9;
                    }
                    if (month == "10" and year2 == yearCheck) {
                        monthSales10 = stoi(salestotal) + monthSales10;
                    }
                    if (month == "11" and year2 == yearCheck) {
                        monthSales11 = stoi(salestotal) + monthSales11;
                    }
                    if (month == "12" and year2 == yearCheck) {
                        monthSales12 = stoi(salestotal) + monthSales12;
                    }
                }
            }

        }




        cout << "Total Sales For January: " << monthSales1 << endl;
        cout << "Total Sales For February: " << monthSales2 << endl;
        cout << "Total Sales For March: " << monthSales3 << endl;
        cout << "Total Sales For April: " << monthSales4 << endl;
        cout << "Total Sales For May: " << monthSales5 << endl;
        cout << "Total Sales For June: " << monthSales6 << endl;
        cout << "Total Sales For July: " << monthSales7 << endl;
        cout << "Total Sales For August: " << monthSales8 << endl;
        cout << "Total Sales For September: " << monthSales9 << endl;
        cout << "Total Sales For October: " << monthSales10 << endl;
        cout << "Total Sales For November: " << monthSales11 << endl;
        cout << "Total Sales For December: " << monthSales12 << endl;
        cout << "Return to Sales Menu? (Y/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" or choice == "yes" or choice == "Y" or choice == "y"){
            salesMenu();
        }
        else if (choice == "No" or choice == "no" or choice == "N" or choice == "n"){
            Clients m;
            m.returnToMenu();
        }
        else{
            cout << "Invalid Input Please Try Again." << endl;
            monthlySales();
        }









    }

private:

};