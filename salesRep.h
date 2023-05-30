//
// Created by philip ake on 5/4/23.
//

#ifndef UNTITLED4_SALESREP_H
#define UNTITLED4_SALESREP_H

#endif //UNTITLED4_SALESREP_H
#include "clients.h"
using namespace std;

class SalesRep {

public:
    void returnToRepMenu(){
        string userChoice3;
        cout << "Return to Sales Rep Menu? (Yes/No)" << endl;
        cin >> userChoice3;
        if (userChoice3 == "Yes" || userChoice3 == "yes" || userChoice3 == "Y" || userChoice3 == "y" ||
            userChoice3 == "YES" || userChoice3 == "YEs" || userChoice3 == "YeS" || userChoice3 == "yES" ||
            userChoice3 == "yEs" || userChoice3 == "yeS") {
            salesRepMenu();
        }
        else if (userChoice3 != "Yes" || userChoice3 != "yes" || userChoice3 != "Y" || userChoice3 != "y" ||
                 userChoice3 != "YES" || userChoice3 != "YEs" || userChoice3 != "YeS" || userChoice3 != "yES" ||
                 userChoice3 != "yEs" || userChoice3 != "yeS") {
            cout << "Nothing Else To Do Here" << endl;
            returnToRepMenu();
        }
    }
    int countSalesReps(){
        ifstream file("/Users/philipake/CLionProjects/untitled4/salesRep.txt");
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        return count;
    }
    void salesRepInfo(){

        cout << "Please enter Sales Rep Name" << endl;
        cin.ignore();
        getline(cin, salesRepName);
        cout << "Please enter Sales Rep Address" << endl;
        getline(cin, salesRepAddress);
        cout << "Please enter Sales Rep Sales" << endl;
        getline(cin, salesRepSales);
        //open file for writing
        ofstream fw("/Users/philipake/CLionProjects/untitled4/salesRep.txt", ofstream::app);
        //check if file was successfully opened for writing
        if (fw.is_open()) {
            int salesRepNumber = countSalesReps() + 1;
            fw << salesRepNumber << " ";
            fw << salesRepName << " ";
            fw << salesRepAddress << " ";
            fw << salesRepSales << " ";
            fw << endl;
            fw.close();
        }
        else{
            cout << "Problem with opening file";
        }

    }
    void salesRepInputData(){
        string userInput;
        cout << "Would You Like To Add A New Sales Rep?" << endl;
        cin >> userInput;
        if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y" || userInput == "YES" || userInput == "YEs" || userInput == "YeS" || userInput == "yES" || userInput == "yEs" || userInput == "yeS") {
            salesRepInfo();
            salesRepInputData();
        }
        else {
            salesRepMenu();
        }
    }
    void salesRepSearch(){
        cout << "Would You Like To Search For A Sales Rep?" << endl;
        string SalesRepSearchOpt;
        cin >> SalesRepSearchOpt;
        if (SalesRepSearchOpt == "Yes" || SalesRepSearchOpt == "yes" || SalesRepSearchOpt == "Y" || SalesRepSearchOpt == "y" ||
            SalesRepSearchOpt == "YES" || SalesRepSearchOpt == "YEs" || SalesRepSearchOpt == "YeS" ||
            SalesRepSearchOpt == "yES" ||
            SalesRepSearchOpt == "yEs" || SalesRepSearchOpt == "yeS") {
            salesRepSearch();
            string searchName;
            cout << "Please Enter The Sales Reps Full Name:" << endl;
            cin.ignore();
            getline(cin, searchName);
            ifstream is("/Users/philipake/CLionProjects/untitled4/salesRep.txt");
            string line;
            while (std::getline(is, line)) {
                if (line.find(searchName) != std::string::npos) {
                    cout << line << std::endl;
                }
            }
        } else {
            returnToRepMenu();
        }

    }
    void salesRepUpdate(){
        fstream current, temp;
        int count = 0;
        string repFName, repMName, repLName, repID, repStreetNum, repStreetName, repCity, repState, repZip,
                repSalesMonth, repSalesYear, repSalesTotal;
        string newRepName, newRepID, newRepAddress, newRepSales;
        string searchName;
        string userChoice;
        string userChoice2;
        cout << "Would you like to update a Rep?" << endl;
        cin >> userChoice2;
        if (userChoice2 == "Yes" || userChoice2 == "yes" || userChoice2 == "Y" || userChoice2 == "y" ||
            userChoice2 == "YES" || userChoice2 == "YEs" || userChoice2 == "YeS" || userChoice2 == "yES" ||
            userChoice2 == "yEs" || userChoice2 == "yeS") {
            current.open("salesRep.txt", ios::in);
            temp.open("TempRep.txt", ios::out);
            cout << "What would you like to update?" << endl;
            cout << "1) Full Name" << endl;
            cout << "2) Address" << endl;
            cout << "3) Sales Total" << endl;
            cout << "4) Return to Rep Menu" << endl;
            cin >> userChoice;
            if (userChoice == "1") {
                cout << "Enter the Rep ID to update: ";
                cin >> searchName;
                while (current >> repID >> repFName >> repMName >> repLName >> repStreetNum
                               >> repStreetName >> repCity >> repState
                               >> repZip >> repSalesMonth >> repSalesYear >> repSalesTotal) {
                    if (repID != searchName) {
                        temp << repID << " " << repFName << " " << repMName << " " << repLName << " "
                             << repStreetNum << " " << repStreetName << " " << repCity << " "
                             << repState
                             << " " << repZip << " " << repSalesMonth << " " << repSalesYear << " "
                             << repSalesTotal << endl;
                    } else {
                        cin.ignore();
                        cout << "Enter the new Full Name: ";
                        getline(cin, newRepName);
                        temp << repID << " " << newRepName << " " << repMName << " " << repLName << " "
                             << " "
                             << repStreetNum << " " << repStreetName << " " << repCity << " "
                             << repState
                             << " " << repZip << " " << repSalesMonth << " " << repSalesYear << " "
                             << repSalesTotal << endl;
                        count++;
                    }
                }
                if (count == 0) {
                    cout << "Record not found" << endl;
                } else {
                    cout << "Record updated" << endl;
                }
                current.close();
                temp.close();
                remove("salesRep.txt");
                rename("TempRep.txt", "salesRep.txt");
                salesRepUpdate();
            } else if (userChoice == "2") {
                cout << "Enter the Rep ID to update: ";
                cin >> searchName;
                while (current >> repID >> repFName >> repMName >> repLName >> repStreetNum
                               >> repStreetName >> repCity >> repState
                               >> repZip >> repSalesMonth >> repSalesYear >> repSalesTotal) {
                    if (repID != searchName) {
                        temp << repID << " " << repFName << " " << repMName << " " << repLName << " "
                             << repStreetNum << " " << repStreetName << " " << repCity << " "
                             << repState
                             << " " << repZip << " " << repSalesMonth << " " << repSalesYear << " "
                             << repSalesTotal << endl;
                    } else {
                        cin.ignore();
                        cout << "Enter the new Full Address: ";
                        getline(cin, newRepAddress);
                        temp << repID << " " << repFName << " " << repMName << " " << repLName << " "
                             << newRepAddress
                             << " " << repSalesMonth << " " << repSalesYear << " " << repSalesTotal
                             << endl;
                        count++;
                    }

                }
                if (count == 0) {
                    cout << "Record not found" << endl;
                } else {
                    cout << "Record updated" << endl;
                }
                current.close();
                temp.close();
                remove("salesRep.txt");
                rename("TempRep.txt", "salesRep.txt");
                salesRepUpdate();
            } else if (userChoice == "3") {
                cout << "Enter the Rep ID to update: ";
                cin >> searchName;
                while (current >> repID >> repFName >> repMName >> repLName >> repStreetNum
                               >> repStreetName >> repCity >> repState
                               >> repZip >> repSalesMonth >> repSalesYear >> repSalesTotal) {
                    if (repID != searchName) {
                        temp << repID << " " << repFName << " " << repMName << " " << repLName << " "
                             << repStreetNum << " " << repStreetName << " " << repCity << " "
                             << repState
                             << " " << repZip << " " << repSalesMonth << " " << repSalesYear << " "
                             << repSalesTotal << endl;
                    } else {
                        cin.ignore();
                        cout << "Enter the new Sales (month year total): ";
                        getline(cin, newRepSales);
                        temp << repID << " " << repFName << " " << repMName << " " << repLName << " "
                             << " "
                             << repStreetNum << " " << repStreetName << " " << repCity << " "
                             << repState
                             << " " << repZip << " " << newRepSales << endl;
                        count++;
                    }
                }
                if (count == 0) {
                    cout << "Record not found" << endl;
                } else {
                    cout << "Record updated" << endl;
                }
                current.close();
                temp.close();
                remove("salesRep.txt");
                rename("TempRep.txt", "salesRep.txt");
                salesRepUpdate();
            }
            else if (userChoice == "4") {
               returnToRepMenu();
            }
        }
        else if (userChoice2 != "Yes" || userChoice2 != "yes" || userChoice2 != "Y" || userChoice2 != "y" ||
                 userChoice2 != "YES" || userChoice2 != "YEs" || userChoice2 != "YeS" || userChoice2 != "yES" ||
                 userChoice2 != "yEs" || userChoice2 != "yeS"){
            returnToRepMenu();
        }
    }
    void allSalesRepInfo(){
        cout << "Would you like to view all Sales Rep information? (Yes/No)" << endl;
        string userChoice4;
        cin >> userChoice4;
        if (userChoice4 == "Yes" || userChoice4 == "yes" || userChoice4 == "Y" || userChoice4 == "y" ||
            userChoice4 == "YES" || userChoice4 == "YEs" || userChoice4 == "YeS" || userChoice4 == "yES" ||
            userChoice4 == "yEs" || userChoice4 == "yeS") {
            std::ifstream is("/Users/philipake/CLionProjects/untitled4/salesRep.txt");

            std::string line;
            std::cout << "All Sales Reps:\n";
            while (std::getline(is, line)) {
                std::cout << line << std::endl;
            }
        }
        else if (userChoice4 != "Yes" || userChoice4 != "yes" || userChoice4 != "Y" || userChoice4 != "y" ||
                 userChoice4 != "YES" || userChoice4 != "YEs" || userChoice4 != "YeS" || userChoice4 != "yES" ||
                 userChoice4 != "yEs" || userChoice4 != "yeS") {
            returnToRepMenu();
        }
    }
    void salesRepMenu() {
        string menuChoice2;
        cout << "Please Select what you would like to do:" << endl;
        cout << "1) Add Sales Rep" << endl;
        cout << "2) Search Sales Rep" << endl;
        cout << "3) Update Sales Rep" << endl;
        cout << "4) View All Sales Reps" << endl;
        cout << "5) Return to Main Menu" << endl;
        while ("6" != menuChoice2) {
            cin >> menuChoice2;
            if (menuChoice2 == "1") {
                salesRepInputData();
            }
            else if (menuChoice2 == "2") {
                salesRepSearch();
            }
            else if (menuChoice2 == "3") {
                salesRepUpdate();
            }
            else if (menuChoice2 == "4") {
                allSalesRepInfo();
            }
            else if (menuChoice2 == "5") {
                cout << "Returning to Main Menu" << endl;
                Clients n;
                n.returnToMenu();

            }
            else {
                cout << "Invalid Input Please Try Again." << endl;
                return salesRepMenu();
            }
        }
    }
private:
    string salesRepName;
    string salesRepAddress;
    string salesRepSales;
};