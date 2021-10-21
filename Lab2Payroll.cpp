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
float grossWeekPay(float hours, float rate);

int main()
{
    empDataInput();

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

void empDataInput() {
    Employees emp;

    for (int i = 0; i < 1; i++) {
        printLine();
        cout << "\nEnter Details for Employee #" << i + 1 << endl;
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
        getline(cin, emp.suburbAd[i]);
        cout << "Enter City: ";
        getline(cin, emp.cityAd[i]);
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
        emp.grossWeek[i] = grossWeekPay(emp.hoursWorked[i], emp.hourRate[i]);
        cout << "Gross Week Pay: " << emp.grossWeek[i];
        emp.taxDeducted[i] = emp.grossWeek[i] * (emp.taxRate[i] * 0.01);
        cout << "\nTotal Tax Deducted: " << emp.taxDeducted[i];
        emp.netWeek[i] = emp.grossWeek[i] - emp.taxDeducted[i];
        cout << "\nTotal Net Week: " << emp.netWeek[i];
    }
}
