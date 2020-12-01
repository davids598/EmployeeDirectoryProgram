#ifndef __EMPLOYEE_CPP__
#define __EMPLOYEE_CPP__

#include <vector>
#include <iostream>
#include "../header/Employee.hpp"

using namespace std;

    Employee::Employee() {
        this->firstName = "";
        this->lastName = "";
        this->jobTitle = "";
        this->salary = 0.0;
        this->hireDate = nullptr;
        this->manager = nullptr;
    }

    Employee::Employee(string fName, string lName, string t, double d, int m, int day, int y, Employee* _manager){
        this->firstName = fName;
        this->lastName = lName;
        this->jobTitle = t;
        this->salary = d;
        this->hireDate = new Date(m, day, y) ;
        this->manager = _manager ;
    }

    Employee::Employee(string fName, string lName, string t, double d, Date* hDate, Employee* _manager){
	this->firstName = fName ;
	this->lastName = lName ;
	this->jobTitle = t ;
	this->salary = d ;
	this->hireDate = hDate ;
	this->manager = _manager ;
    }

    Employee::~Employee() {
        delete hireDate;
        delete manager;
    }

    string Employee::getName() {
        return firstName + " " + lastName;
    }

    string Employee::getTitle() {
        return jobTitle;
    }

    double Employee::getSalary() {
        return salary;
    }

    Date* Employee::getHireDate() {
        return hireDate;
    }

    vector<Employee*> Employee::getEmployees() {
        return employees;
    }

    void Employee::setName(string fName, string lName) {
        this->firstName = fName;
        this->lastName = lName;
    }

    void Employee::setTitle(string t) {
        this->jobTitle = t;
    }

    void Employee::setSalary(double s) {
        this->salary = s;
    }

    void Employee::setHireDate(Date* d) {
        this->hireDate = d;
    }

#endif
