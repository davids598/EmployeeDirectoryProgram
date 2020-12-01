#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include <vector>
#include <iostream>
#include "../src/Date.cpp"

using namespace std;

class Employee {
private:
    string firstName, lastName, jobTitle;
    double salary;
    Date* hireDate;
    string department ;
    vector<Employee*> employees;
public:
    Employee();
    Employee(string fName, string lName, string t, double d, int m, int day, int y, string _department) ;
    Employee(string fName, string LName, string t, double d, Date* hDate, string _department) ;
    ~Employee();
    string getName();
    string getTitle();
    string getDepartment() ;
    double getSalary();
    Date* getHireDate();
    vector<Employee*> getEmployees();

    void setName(string fName, string lname);
    void setTitle(string t);
    void setSalary(double d);
    void setHireDate(Date* d);
    void setDepartment(string _d) ;
};

#endif
