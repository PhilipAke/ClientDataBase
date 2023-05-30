//
// Created by philip ake on 5/4/23.
//

#ifndef UNTITLED4_CLIENTS_H
#define UNTITLED4_CLIENTS_H

#endif //UNTITLED4_CLIENTS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>
#include <cstring>
#include <sstream>
using namespace std;

class Clients {
public:
    void returnToMenu();
    void returnTOClientMenu(){
        string userChoice3;
            cout << "Return to Client Menu? (Yes/No)" << endl;
            cin >> userChoice3;
            if (userChoice3 == "Yes" || userChoice3 == "yes" || userChoice3 == "Y" || userChoice3 == "y" ||
                userChoice3 == "YES" || userChoice3 == "YEs" || userChoice3 == "YeS" || userChoice3 == "yES" ||
                userChoice3 == "yEs" || userChoice3 == "yeS") {
                clientInfoMenu();
            }
            else if (userChoice3 != "Yes" || userChoice3 != "yes" || userChoice3 != "Y" || userChoice3 != "y" ||
                     userChoice3 != "YES" || userChoice3 != "YEs" || userChoice3 != "YeS" || userChoice3 != "yES" ||
                     userChoice3 != "yEs" || userChoice3 != "yeS") {
                cout << "Nothing Else To Do Here" << endl;
                returnTOClientMenu();
            }
        }

    int countClients() {
        ifstream file("/Users/philipake/CLionProjects/untitled4/clientdata1.txt");
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        return count;
    }
    void clientInfo() {
        cout << "Please enter Client Name" << endl;
        cin.ignore();
        getline(cin, fullName);
        cout << "Please enter Client Address" << endl;
        getline(cin, clientAddress);
        cout << "Please enter Client Sales Total" << endl;
        getline(cin, clientSalesTotal);
        //open file for writing
        ofstream fw("/Users/philipake/CLionProjects/untitled4/clientdata1.txt",ofstream::app);
        //check if file was successfully opened for writing
        if (fw.is_open()) {
            int clientNumber = countClients() + 1;
            fw << clientNumber << " ";
            fw << fullName << " ";
            fw << clientAddress << " ";
            fw << clientSalesTotal << " ";
            fw << endl;
            fw.close();
        } else {
            cout << "Problem with opening file";
        }
    }
    void clientInputData() {
        string userInput;
        cout << "Would You Like To Add A New Client?" << endl;
        cin >> userInput;
        if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y" ||
            userInput == "YES" || userInput == "YEs" || userInput == "YeS" || userInput == "yES" ||
            userInput == "yEs" || userInput == "yeS") {
            clientInfo();
            clientInputData();
        } else {
            returnTOClientMenu();
        }
    }
    void clientSearch() {
        cout << "Would You Like To Search For A Client?" << endl;
        string clientSearchOpt;
        cin >> clientSearchOpt;
        if (clientSearchOpt == "Yes" || clientSearchOpt == "yes" || clientSearchOpt == "Y" || clientSearchOpt == "y" ||
            clientSearchOpt == "YES" || clientSearchOpt == "YEs" || clientSearchOpt == "YeS" ||
            clientSearchOpt == "yES" ||
            clientSearchOpt == "yEs" || clientSearchOpt == "yeS") {
            clientSearch();
            string searchName;
            cout << "Please Enter The Clients Full Name:" << endl;
            cin.ignore();
            getline(cin, searchName);
            ifstream is("/Users/philipake/CLionProjects/untitled4/clientdata1.txt");
            string line;
            while (std::getline(is, line)) {
                if (line.find(searchName) != std::string::npos) {
                    cout << line << std::endl;
                }
            }
        } else {
            returnTOClientMenu();
        }

    }
    void clientUpdate() {
        fstream current, temp;
        int count = 0;
        string clientFName, clientMName, clientLName, clientID, clientStreetNum, clientStreetName, clientCity, clientState, clientZip,
                clientSalesMonth, clientSalesYear, clientSalesTotal;
        string newClient, newClientID, newClientAddress, newClientSales;
        string searchName;
        string userChoice;
        string userChoice2;
        cout << "Would you like to update a client?" << endl;
        cin >> userChoice2;
        if (userChoice2 == "Yes" || userChoice2 == "yes" || userChoice2 == "Y" || userChoice2 == "y" ||
            userChoice2 == "YES" || userChoice2 == "YEs" || userChoice2 == "YeS" || userChoice2 == "yES" ||
            userChoice2 == "yEs" || userChoice2 == "yeS") {
            current.open("/Users/philipake/CLionProjects/untitled4//Users/philipake/CLionProjects/untitled4/clientdata1.txt", ios::in);
            temp.open("/Users/philipake/CLionProjects/untitled4//Users/philipake/CLionProjects/untitled4/Tempclient1.txt", ios::out);
            cout << "What would you like to update?" << endl;
            cout << "1) Full Name" << endl;
            cout << "2) Address" << endl;
            cout << "3) Sales Total" << endl;
            cout << "4) Return to Client Menu" << endl;
            cin >> userChoice;
            if (userChoice == "1") {
                cout << "Enter the client ID to update: ";
                cin >> searchName;
                while (current >> clientID >> clientFName >> clientMName >> clientLName >> clientStreetNum
                               >> clientStreetName >> clientCity >> clientState
                               >> clientZip >> clientSalesMonth >> clientSalesYear >> clientSalesTotal) {
                    if (clientID != searchName) {
                        temp << clientID << " " << clientFName << " " << clientMName << " " << clientLName << " "
                             << clientStreetNum << " " << clientStreetName << " " << clientCity << " "
                             << clientState
                             << " " << clientZip << " " << clientSalesMonth << " " << clientSalesYear << " "
                             << clientSalesTotal << endl;
                    }
                    else {
                        cin.ignore();
                        cout << "Enter the new Full Name: ";
                        getline(cin, newClient);
                        temp << clientID << " " << newClient << " "
                             << clientStreetNum << " " << clientStreetName << " " << clientCity << " "
                             << clientState
                             << " " << clientZip << " " << clientSalesMonth << " " << clientSalesYear << " "
                             << clientSalesTotal << endl;
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
                remove("/Users/philipake/CLionProjects/untitled4//Users/philipake/CLionProjects/untitled4/clientdata1.txt");
                rename("/Users/philipake/CLionProjects/untitled4//Users/philipake/CLionProjects/untitled4/Tempclient1.txt", "/Users/philipake/CLionProjects/untitled4//Users/philipake/CLionProjects/untitled4/clientdata1.txt");
                clientUpdate();
            } else if (userChoice == "2") {
                cout << "Enter the client ID to update: ";
                cin >> searchName;
                while (current >> clientID >> clientFName >> clientMName >> clientLName >> clientStreetNum
                               >> clientStreetName >> clientCity >> clientState
                               >> clientZip >> clientSalesMonth >> clientSalesYear >> clientSalesTotal) {
                    if (clientID != searchName) {
                        temp << clientID << " " << clientFName << " " << clientMName << " " << clientLName << " "
                             << clientStreetNum << " " << clientStreetName << " " << clientCity << " "
                             << clientState
                             << " " << clientZip << " " << clientSalesMonth << " " << clientSalesYear << " "
                             << clientSalesTotal << endl;
                    } else {
                        cin.ignore();
                        cout << "Enter the new Full Address: ";
                        getline(cin, newClientAddress);
                        temp << clientID << " " << clientFName << " " << clientMName << " " << clientLName << " "
                             << newClientAddress
                             << " " << clientSalesMonth << " " << clientSalesYear << " " << clientSalesTotal
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
                remove("/Users/philipake/CLionProjects/untitled4/clientdata1.txt");
                rename("/Users/philipake/CLionProjects/untitled4/Tempclient1.txt", "/Users/philipake/CLionProjects/untitled4/clientdata1.txt");
                clientUpdate();
            } else if (userChoice == "3") {
                cout << "Enter the client ID to update: ";
                cin >> searchName;
                while (current >> clientID >> clientFName >> clientMName >> clientLName >> clientStreetNum
                               >> clientStreetName >> clientCity >> clientState
                               >> clientZip >> clientSalesMonth >> clientSalesYear >> clientSalesTotal) {
                    if (clientID != searchName) {
                        temp << clientID << " " << clientFName << " " << clientMName << " " << clientLName << " "
                             << clientStreetNum << " " << clientStreetName << " " << clientCity << " "
                             << clientState
                             << " " << clientZip << " " << clientSalesMonth << " " << clientSalesYear << " "
                             << clientSalesTotal << endl;
                    } else {
                        cin.ignore();
                        cout << "Enter the new Sales (month year total): ";
                        getline(cin, newClientSales);
                        temp << clientID << " " << clientFName << " " << clientMName << " " << clientLName << " "
                             << " "
                             << clientStreetNum << " " << clientStreetName << " " << clientCity << " "
                             << clientState
                             << " " << clientZip << " " << newClientSales << endl;
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
                remove("/Users/philipake/CLionProjects/untitled4/clientdata1.txt");
                rename("/Users/philipake/CLionProjects/untitled4/Tempclient1.txt", "/Users/philipake/CLionProjects/untitled4/clientdata1.txt");
                clientUpdate();
            }
            else if (userChoice == "4") {
                returnTOClientMenu();
            }
        }
        else if (userChoice2 != "Yes" || userChoice2 != "yes" || userChoice2 != "Y" || userChoice2 != "y" ||
                 userChoice2 != "YES" || userChoice2 != "YEs" || userChoice2 != "YeS" || userChoice2 != "yES" ||
                 userChoice2 != "yEs" || userChoice2 != "yeS") {
            returnTOClientMenu();
        }
    }

    void allClientInfo() {
        cout << "Would you like to view all client information? (Yes/No)" << endl;
        string userChoice4;
        cin >> userChoice4;
        if (userChoice4 == "Yes" || userChoice4 == "yes" || userChoice4 == "Y" || userChoice4 == "y" ||
            userChoice4 == "YES" || userChoice4 == "YEs" || userChoice4 == "YeS" || userChoice4 == "yES" ||
            userChoice4 == "yEs" || userChoice4 == "yeS") {
            std::ifstream is("/Users/philipake/CLionProjects/untitled4/clientdata1.txt");

            std::string line;
            std::cout << "All clients:\n";
            while (std::getline(is, line)) {
                std::cout << line << std::endl;
            }
        }
        else if (userChoice4 != "Yes" || userChoice4 != "yes" || userChoice4 != "Y" || userChoice4 != "y" ||
                 userChoice4 != "YES" || userChoice4 != "YEs" || userChoice4 != "YeS" || userChoice4 != "yES" ||
                 userChoice4 != "yEs" || userChoice4 != "yeS") {
            returnTOClientMenu();
        }
    }
    void clientInfoMenu() {
        string menuChoice2;
        cout << "Welcome To The Client Info Menu!" << endl;
        cout << "Please Select What You Would Like To Do:" << endl;
        cout << "1) Add New Client Info?" << endl;
        cout << "2) View All Client Info?" << endl;
        cout << "3) Search For A Client?" << endl;
        cout << "4) Update A Client?" << endl;
        cout << "5) Return To Main Menu?" << endl;
        cin >> menuChoice2;
        if (menuChoice2 == "1") {
            clientInputData();
        } else if (menuChoice2 == "2") {
            allClientInfo();
        } else if (menuChoice2 == "3") {
            clientSearch();
        } else if (menuChoice2 == "4") {
            clientUpdate();
        } else if (menuChoice2 == "5") {
            returnToMenu();
        } else {
            cout << "Invalid Input Please Try Again." << endl;
            clientInfoMenu();
        }
    }

private:
    string fullName;
    string clientAddress;
    string clientSalesTotal;
    string searchName;
};
