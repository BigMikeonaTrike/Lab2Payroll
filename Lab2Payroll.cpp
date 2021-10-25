#include <iostream>
#include <string>

using namespace std;

struct Employees {
    
    char taxCode;
    string employeeId, firstName, middleName, lastName, emailAd;
    string streetAd, suburbAd, cityAd;
    int postCode, phoneNo, irdNo;
    int hoursWorked, hourRate, taxRate, taxDeducted;
    int grossWeek, netWeek, index;

    Employees(int i = 0, char tCode = '0', string empId = "", string fN = "", string mN = "", string lN =  "", string email = "",
        string street =  "", string suburb =  "", string city = "",
        int post = 0, int phone = 0, int ird = 0 , int hourW = 0, int hourR =  0,
        int taxR = 0 , int taxD = 0, int gWeek = 0 , int nWeek = 0) {
        index = i;
        employeeId = empId;
        firstName = fN;
        middleName = mN;
        lastName = lN;
        emailAd = email;
        streetAd = street;
        suburbAd = suburb;
        cityAd = city;
        postCode = post;
        phoneNo = phone;
        irdNo = ird;
        hoursWorked = hourW;
        hourRate = hourR;
        taxRate = taxR;
        taxDeducted = taxD;
        grossWeek = gWeek;
        netWeek = nWeek;
        taxCode = tCode;
    }
};

void empDataInput(int i);
void printLine();
float grossWeekPay(float hours, float rate);
void empPayslip(int i);
void weekReport(string start, string end);
Employees emp[5];
float totalGross = 0, totalNet = 0, totalTax = 0;

int main()
{
    string weekStart, weekEnd;
    bool inputDone = false;
    int j;
a:
    cout << "Which program would you like to use:\n1. Employee Data Input\n2. Employee Payslip\n3. Weekly Report\n4. Exit\nEnter Program No: ";
    cin >> j;
    if (j > 1 && inputDone == false) {
        cout << "\nMust Enter Employee Data First\n";
        goto a;
    }
    if (j == 1) {
        inputDone = true;
        cout << "Enter Week Start Date: ";
        cin >> weekStart;
        cout << "Enter Week End Date: ";
        cin >> weekEnd;
        for (int i = 0; i < 5; i++) {
            empDataInput(i);
        }
        goto a;
    }
    else if (j == 2) {
        for (int i = 0; i < 5; i++) {
            empPayslip(i);
        }
        goto a;
    }
    else if (j == 3) {
        weekReport(weekStart, weekEnd);
        goto a;
    }
    else {
        return 0;
    }
}

void weekReport(string start, string end) {
    printLine();
    cout << "Weekly Statitics\nWeek Start: " << start << "\t\tWeek End: "<< end;
    printLine();
    cout << "\nTotal amount paid in Gross Pay: " << totalGross;
    cout << "\nTotal amount of Tax Deducted: " << totalTax;
    cout << "\nTotal amount paid in Net Pay: " << totalNet;
    cout << endl << endl;
    printLine();
}

void empPayslip(int i) {
    printLine();
    cout << "\nPAYSLIP for week: \n";
    printLine();
        cout << "\nEmployee ID   :" << emp[i].employeeId;
        cout << "\nFirst Name    :" << emp[i].firstName;
        cout << "\nMiddle Name   :" << emp[i].middleName;
        cout << "\nLast Name     :" << emp[i].lastName;
        cout << "\nEmail Address :" << emp[i].emailAd;
        cout << "\nAddress       :" << emp[i].streetAd << ", " << emp[i].suburbAd << ", " << emp[i].cityAd;
        cout << "\nPost Code     :" << emp[i].postCode;
        cout << "\nPhone Number  :" << emp[i].phoneNo;
        cout << "\nIRD Number    :" << emp[i].irdNo;
        cout << "\nTax Code      :" << emp[i].taxCode;
        cout << "\nHours Worked  :" << emp[i].hoursWorked;
        cout << "\nHourly Rate   :" << emp[i].hourRate;
        cout << "\nTax Rate      :" << emp[i].taxRate;
        cout << "\nTax Deducted  :" << emp[i].taxDeducted;
        cout << "\nGross Week    :" << emp[i].grossWeek;
        cout << "\nNet Week      :" << emp[i].netWeek;
}

float grossWeekPay(float hours, float rate) {
    if (hours <= 40) {
        return hours * rate;
    }
    else {
        int temp = hours - 40;
        return ((hours - temp) * rate) + (temp * (rate * 1.5));
    }
}

void printLine() {
    cout << endl;
    for (int i = 0; i < 100; i++) {
        cout << "*";
    }
    cout << endl;
}

void empDataInput(int i) {
    printLine();
    cout << "\nEnter Details for Employee #" << i + 1 << endl;
    printLine();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter Employee ID: ";
    getline(cin, emp[i].employeeId);
    cout << "\nEnter First Name: ";
    getline(cin, emp[i].firstName);
    cout << "\nEnter Middle Name: ";
    getline(cin, emp[i].middleName);
    cout << "\nEnter Last Name: ";
    getline(cin, emp[i].lastName);
    cout << "\nEnter Email Address: ";
    getline(cin, emp[i].emailAd);
    cout << "\nEnter Street Address: ";
    getline(cin, emp[i].streetAd);
    cout << "\nEnter Suburb: ";
    getline(cin, emp[i].suburbAd);
    cout << "\nEnter City: ";
    getline(cin, emp[i].cityAd);
    cout << "\nEnter Post Code: ";
    cin >> emp[i].postCode;
    cout << "\nEnter Phone Number: ";
    cin >> emp[i].phoneNo;
    cout << "\nEnter IRD Number: ";
    cin >> emp[i].irdNo;
    cout << "\nEnter Tax Code: ";
    cin >> emp[i].taxCode;

    bool inRange = false;
    do {
        cout << "\nEnter Hours Worked: ";
        cin >> emp[i].hoursWorked;
        if (emp[i].hoursWorked >= 1 && emp[i].hoursWorked <= 49) {
            inRange = true;
        }
    } while (inRange == false);
    inRange = false;
    do {
        cout << "\nEnter Hourly Rate: ";
        cin >> emp[i].hourRate;
        if (emp[i].hourRate >= 20 && emp[i].hourRate <= 50) {
            inRange = true;
        }
    } while (inRange == false);
    inRange = false;
    do {
        cout << "\nEnter Tax Rate: ";
        cin >> emp[i].taxRate;
        if (emp[i].taxRate >= 10.5 && emp[i].taxRate <= 39) {
            inRange = true;
        }
    } while (inRange == false);
    emp[i].grossWeek = grossWeekPay(emp[i].hoursWorked, emp[i].hourRate);
    totalGross += emp[i].grossWeek;
    emp[i].taxDeducted = emp[i].grossWeek * (emp[i].taxRate * 0.01);
    totalTax += emp[i].taxDeducted;
    emp[i].netWeek = emp[i].grossWeek - emp[i].taxDeducted;
    totalNet += emp[i].netWeek;
}
