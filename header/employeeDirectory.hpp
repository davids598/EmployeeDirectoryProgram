#ifndef __EMPLOYEEDIRECTORY_HPP__
#define __EMPLOYEEDIRECTORY_HPP__

#include <vector>
#include <iostream>

using namespace std;

class employeeDirectory {
private:
    vector<Employee*> directory;
    sortStrategy* sortStrat;
    printStrategy* printstrat;
    Employee* CEOPointer;

public:
    employeeDirectory();
    employeeDirectory(vector<Employee*> d);
    employeeDirectory(Employee* e);
    Employee* getCEOPointer();
    Employee* getEmployee(string name);
    void addEmployee(Employee* e);
    void removeEmployee(Employee* e);
    void editEmployee(Employee* e);
    void sortEmployees();
    void print(employeeDirectory d);
}
#endif
