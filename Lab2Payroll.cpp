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

void empDataInput(float tGross, float tNet, float tTax);
void printLine();
float grossWeekPay(float hours, float rate);

int main()
{
    float totalGross = 0, totalNet = 0, totalTax = 0;
    empDataInput(totalGross, totalNet, totalTax);

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

void empDataInput(float tGross, float tNet, float tTax) {
    Employees emp;

    for (int i = 0; i < 2; i++) {
        printLine();
        cout << "\nEnter Details for Employee #" << i + 1 << endl;
        printLine();
        cout << "\nEnter Employee ID: ";
        getline(cin, emp.employeeId[i]);
        cout << "\nEnter First Name: ";
        getline(cin, emp.firstName[i]);
        cout << "\nEnter Middle Name: ";
        getline(cin, emp.middleName[i]);
        cout << "\nEnter Last Name: ";
        getline(cin, emp.lastName[i]);
        cout << "\nEnter Email Address: ";
        getline(cin, emp.emailAd[i]);
        cout << "\nEnter Street Address: ";
        getline(cin, emp.streetAd[i]);
        cout << "\nEnter Suburb: ";
        getline(cin, emp.suburbAd[i]);
        cout << "\nEnter City: ";
        getline(cin, emp.cityAd[i]);
        cout << "\nEnter Post Code: ";
        cin >> emp.postCode[i];
        cout << "\nEnter Phone Number: ";
        cin >> emp.phoneNo[i];
        cout << "\nEnter IRD Number: ";
        cin >> emp.irdNo[i];
        bool inRange = false;
        do {
            cout << "\nEnter Hours Worked: ";
            cin >> emp.hoursWorked[i];
            if (emp.hoursWorked[i] >= 1 && emp.hoursWorked[i] <= 49) { 
                inRange = true;
            }
        } while (inRange == false);
        do {
            cout << "\nEnter Hourly Rate: ";
            cin >> emp.hourRate[i];
            if (emp.hourRate[i] >= 20 && emp.hourRate[i] <= 50) {
                inRange = true;
            }
        } while (inRange == false);
        cout << "\nEnter Hourly Rate: ";
        cin >> emp.hourRate[i];
        cout << "\nEnter Tax Rate: ";
        cin >> emp.taxRate[i];
        emp.grossWeek[i] = grossWeekPay(emp.hoursWorked[i], emp.hourRate[i]);
        tGross += emp.grossWeek[i];
        cout << "\nGross Week Pay: " << emp.grossWeek[i];
        emp.taxDeducted[i] = emp.grossWeek[i] * (emp.taxRate[i] * 0.01);
        tTax += emp.taxDeducted[i];
        cout << "\nTotal Tax Deducted: " << emp.taxDeducted[i];
        emp.netWeek[i] = emp.grossWeek[i] - emp.taxDeducted[i];
        tNet += emp.netWeek[i];
        cout << "\nTotal Net Week: " << emp.netWeek[i] << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << tGross << tNet << tTax;
}
