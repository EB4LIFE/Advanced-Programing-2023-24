#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    //The program is to print :
    //The id and name of the worker who collected the least donations.The sum of
    //collections he collected should also be printed.
    //The id and name of the worker with the highest salary.His salary should also
    //be printed.
    
    // inititalize employee objects for input, least, most
    Employee employee, leastW, MostW; 
    leastW.setdonationscollected(999999);
    float maxSalary = 0;
    // ask user for employeer info - as per moodle

    cout << "enter details, to end enter 0:" << endl;


    do {
        int tempId;
        char tempname[21];
        float tempwage;
        int temphours;
        float tempmoney;

        cin >> tempId >> tempname >> tempwage >> temphours >> tempmoney;

        employee.setWorkerId(tempId);
        employee.setName(tempname);
        employee.sethourlywages(tempwage);
        employee.setHoursWorked(temphours);
        employee.setdonationscollected(tempmoney);

         if (tempId == 0) {
            break;
        }
        if (tempId < 0) {
            cout << "ERROR" << endl;
            continue;
        }
        if (tempwage < 0) {
            cout << "ERROR" << endl;
            continue;
        }
        if (temphours < 0) {
            cout << "ERROR" << endl;
            continue;
        }
        if (tempmoney < 0) {
            cout << "ERROR" << endl;
            continue;
        }
        //calc salary
        float tempsalary = employee.calcsalary(); //
        if (tempsalary > maxSalary) {
            MostW.setWorkerId(employee.getWorkerId()); 
            MostW.setName(employee.getName());
            MostW.sethourlywages(employee.gethourlywages());
            MostW.setHoursWorked(employee.getHoursWorked());
            MostW.setdonationscollected(employee.getdonationscollected());
            maxSalary = tempsalary;
        }
        //min donation
        if (employee.getdonationscollected() < leastW.getdonationscollected()) {
            leastW.setWorkerId(employee.getWorkerId());
            leastW.setName(employee.getName());
            leastW.sethourlywages(employee.gethourlywages());
            leastW.setHoursWorked(employee.getHoursWorked());
            leastW.setdonationscollected(employee.getdonationscollected()); 
        }

    } while (employee.getWorkerId() != 0);
     //Smallest amount
    cout << "minimum collected: " << leastW.getWorkerId() << " " << leastW.getName() << " " << leastW.getdonationscollected() << endl;
   //most amount
    cout << "highest salary: " << MostW.getWorkerId() << " " << MostW.getName() << " " << maxSalary << endl;

    return 0;
}
