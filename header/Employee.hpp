#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include <vector>
#include <iostream>

using namespace std;

class Employee {
private:
    string firstName, lastName, jobTitle;
    double salary;
    Date hireDate;
    Employee* manager;
    vector<Employee*> employees;
public:
    Employee();
    Employee(string fName, string lName, string t, double d);
    string getName();
    string getTitle();
    double getSalary();
    Date getHireDate();
    vector<Employee*> getEmployees();

    void setName(string fName, string lname);
    void setTitle(string t);
    void setSalary(double d);
    void setHireDate(Date d);
};

#endif
