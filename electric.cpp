#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct customersDC {
    string customerNAME, classiFICT;
    double totalKWU, ratePKU, groAMT, misceCHAR, totalAMT, prevREADING, currREADING;
    int meterID;
};

vector<customersDC> customersD;

void elecCAL();
void dataBASE();
void SAVEDFILES();
void exit();
void disPLAY();

int main() {
    while (true) {
        int choice;
        cout << "\n[ELECTRIC COMPANY]";
        cout << "\n1. Calculate Bill";
        cout << "\n2. Visit Database";
        cout << "\n3. Exit";
        cout << "\nEnter: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
            elecCAL();
            break;
            case 2:
            dataBASE();
            break;
            case 3:
            exit();
            return 0;
            default:
            for (int i = 0; i < 3; i++) {
                cout << "\n[PLEASE ENTER A CORRECT INPUT]";
            }
        }
    }
}

void elecCAL() {
    customersDC customersINFO;
    cout << "\n[CALCULATE ELECTRIC BILL]";
    cout << "\nEnter Customer Name: ";
    getline(cin, customersINFO.customerNAME);
    cout << "\nEnter Meter ID: ";
    cin >> customersINFO.meterID;
    cin.ignore();
    cout << "\nEnter Classification: ";
    getline(cin, customersINFO.classiFICT);
    cout << "\nEnter Previous Reading: ";
    cin >> customersINFO.prevREADING;
    cout << "\nEnter Current Reading: ";
    cin >> customersINFO.currREADING;

    //BRUHHH
    customersINFO.totalKWU = customersINFO.currREADING - customersINFO.prevREADING;
    if (customersINFO.classiFICT == "Residential" || customersINFO.classiFICT == "residential" || customersINFO.classiFICT == "RESIDENTIAL") {
        if (customersINFO.totalKWU > 300) {
            customersINFO.misceCHAR = 0.8;
            customersINFO.ratePKU = 0.55;
            customersINFO.groAMT = customersINFO.totalKWU * customersINFO.ratePKU;
            customersINFO.totalAMT = customersINFO.groAMT + customersINFO.misceCHAR;
            customersD.push_back(customersINFO);
            SAVEDFILES();
            disPLAY();
        } else if (customersINFO.totalKWU >= 100 && customersINFO.totalKWU <= 299) {
            customersINFO.misceCHAR = 0.5;
            customersINFO.ratePKU = 0.55;
            customersINFO.groAMT = customersINFO.totalKWU * customersINFO.ratePKU;
            customersINFO.totalAMT = customersINFO.groAMT + customersINFO.misceCHAR;
            customersD.push_back(customersINFO);
            SAVEDFILES();
            disPLAY();
        } else if (customersINFO.totalKWU < 100) {
            customersINFO.misceCHAR = 0;
            customersINFO.ratePKU = 0.55;
            customersINFO.groAMT = customersINFO.totalKWU * customersINFO.ratePKU;
            customersINFO.totalAMT = customersINFO.groAMT;
            customersD.push_back(customersINFO);
            SAVEDFILES();
            disPLAY();
        }
    } else if (customersINFO.classiFICT == "Commercial" || customersINFO.classiFICT == "commercial" || customersINFO.classiFICT == "COMMERCIAL") {
        if (customersINFO.totalKWU > 300) {
            customersINFO.misceCHAR = 0.8;
            customersINFO.ratePKU = 0.75;
            customersINFO.groAMT = customersINFO.totalKWU * customersINFO.ratePKU;
            customersINFO.totalAMT = customersINFO.groAMT + customersINFO.misceCHAR;
            customersD.push_back(customersINFO);
            SAVEDFILES();
            disPLAY();
        } else if (customersINFO.totalKWU >= 100 && customersINFO.totalKWU <= 299) {
            customersINFO.misceCHAR = 0.5;
            customersINFO.ratePKU = 0.75;
            customersINFO.groAMT = customersINFO.totalKWU * customersINFO.ratePKU;
            customersINFO.totalAMT = customersINFO.groAMT + customersINFO.misceCHAR;
            customersD.push_back(customersINFO);
            SAVEDFILES();
            disPLAY();
        } else if (customersINFO.totalKWU < 100) {
            customersINFO.misceCHAR = 0;
            customersINFO.ratePKU = 0.75;
            customersINFO.groAMT = customersINFO.totalKWU * customersINFO.ratePKU;
            customersINFO.totalAMT = customersINFO.groAMT;
            customersD.push_back(customersINFO);
            SAVEDFILES();
            disPLAY();
        }
    }
}

void dataBASE() {
    ifstream file("customers.txt");
    string line;
    cout << "\n[CUSTOMERS' DATABASE]" << endl << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void disPLAY() {
    for (const auto &customer : customersD) {
        cout <<
        "CUSTOMER NAME: " << customer.customerNAME << "\n" <<
        "TOTAL KILOWATT USAGE: " << customer.totalKWU << "\n" <<
        "RATE PER KILOWATT: " << customer.ratePKU << "\n" <<
        "GROSS AMOUNT: " << customer.groAMT << "\n" <<
        "MISCELLANEOUS CHARGE: " << customer.misceCHAR << "\n" <<
        "TOTAL AMOUNT DUE: " << customer.totalAMT << "\n" << endl;
    }
}

void exit() {
    cout << "\n[THANK YOU FOR USING]";
}

void SAVEDFILES() {
    ofstream file ("customers.txt");
    for (const auto &customer : customersD) {
        file <<
        "CUSTOMER NAME: " << customer.customerNAME << "\n" <<
        "METER ID: " << customer.meterID << "\n" <<
        "PREVIOUS READING: " << customer.prevREADING << "\n" <<
        "CURRENT READING: " << customer.currREADING << "\n" <<
        "TOTAL KILOWATT USAGE: " << customer.totalKWU << "\n" <<
        "RATE PER KILOWATT: " << customer.ratePKU << "\n" <<
        "GROSS AMOUNT: " << customer.groAMT << "\n" <<
        "MISCELLANEOUS CHARGE: " << customer.misceCHAR << "\n" <<
        "TOTAL AMOUNT DUE: " << customer.totalAMT << "\n" << endl;
    }
}