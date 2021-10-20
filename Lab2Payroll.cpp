#include <iostream>
#include <string>

using namespace std;

struct Employees {
    string employeeId[5], firstName[5], middleName[5], lastName[5], emailAd[5];
    string streetAd[5], suburbAd[5], cityAd[5];
    int postCode[5], phoneNo[5], irdNo[5];
    int hoursWorked[5], hourRate[5], taxRate[5], taxDeducted[5];
    int grossWeek[5], netWeek[5], index;

    Employees(int i = 0, string empId = "", string fN = "", string mN = "", string lN =  "", string email = "",
        string street =  "", string suburb =  "", string city = "",
        int post = 0, int phone = 0, int ird = 0 , int hourW = 0, int hourR =  0,
        int taxR = 0 , int taxD = 0, int gWeek = 0 , int nWeek = 0) {
        index = i;
        employeeId[i] = empId;
        firstName[i] = fN;
        middleName[i] = mN;
        lastName[i] = lN;
        emailAd[i] = email;
        streetAd[i] = street;
        suburbAd[i] = suburb;
        cityAd[i] = city;
        postCode[i] = post;
        phoneNo[i] = phone;
        irdNo[i] = ird;
        hoursWorked[i] = hourW;
        hourRate[i] = hourR;
        taxRate[i] = taxR;
        taxDeducted[i] = taxD;
        grossWeek[i] = gWeek;
        netWeek[i] = nWeek;
    }
};

void empDataInput();
void printLine();

int main()
{
    empDataInput();
}
void printLine() {
    cout << endl;
    for (int i = 0; i < 100; i++) {
        cout << "*";
    }
    cout << endl;
}

void empDataInput() {
    Employees emp;

    for (int i = 0; i < 1; i++) {        
        printLine();
        cout << "\nEnter Details for Employee #" << i+1 << endl;
        printLine();
        cout << "Enter Employee ID: ";
        getline(cin, emp.employeeId[i]);
        cout << "Enter First Name: ";
        getline(cin, emp.firstName[i]);
        cout << "Enter Middle Name: ";
        getline(cin, emp.middleName[i]);
        cout << "Enter Last Name: ";
        getline(cin, emp.lastName[i]);
        cout << "Enter Email Address: ";
        getline(cin, emp.emailAd[i]);
        cout << "Enter Street Address: ";
        getline(cin, emp.streetAd[i]);
        cout << "Enter Suburb: ";
        cin >> emp.suburbAd[i];
        cout << "Enter City: ";
        cin >> emp.cityAd[i];
        cout << "Enter Post Code: ";
        cin >> emp.postCode[i];
        cout << "Enter Phone Number: ";
        cin >> emp.phoneNo[i];
        cout << "Enter IRD Number: ";
        cin >> emp.irdNo[i];
        cout << "Enter Hours Worked: ";
        cin >> emp.hoursWorked[i];
        cout << "Enter Hourly Rate: ";
        cin >> emp.hourRate[i];
        cout << "Enter Tax Rate: ";
        cin >> emp.taxRate[i];
        cout << "Enter Tax Deducted: ";
        cin >> emp.taxDeducted[i];
        cout << "Enter Gross Week: ";
        cin >> emp.grossWeek[i];
        cout << "Enter Net Week: ";
        cin >> emp.netWeek[i];
    }
}
