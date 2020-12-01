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
        this->department = "" ;
    }

    Employee::Employee(string fName, string lName, string t, double d, int m, int day, int y, string _department){
        this->firstName = fName;
        this->lastName = lName;
        this->jobTitle = t;
        this->salary = d;
        this->hireDate = new Date(m, day, y) ;
        this->department = _department ;
    }

    Employee::Employee(string fName, string lName, string t, double d, Date* hDate, string _department){
	this->firstName = fName ;
	this->lastName = lName ;
	this->jobTitle = t ;
	this->salary = d ;
	this->hireDate = hDate ;
	this->department = _department ;
    }

    Employee::~Employee() {
        delete hireDate;
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

    string Employee::getDepartment() {
	return this->department ;
    }

    vector<Employee*> Employee::getEmployees() {
        return this->employees;
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

    void Employee::setDepartment(string _d) {
	this->department = _d ;
    }

#endif
