#ifndef __EMPLOYEEDIRECTORY_HPP__
#define __EMPLOYEEDIRECTORY_HPP__

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "Date.hpp"
#include "Employee.hpp"
#include "Printer.hpp"

using namespace std;

class employeeDirectory {
private:
    vector<Employee*> directory;
   // sortStrategy* sortStrat;
    Printer* printStrat;
    Employee* CEOPointer;
    map<string, vector<Employee*>> departmentMap ;

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
    vector<string> getDepartments() ;
    vector<Employee*>* getDirectory() { return &this->directory ; } 
    map<string, vector<Employee*>>* getMap() { return &this->departmentMap ; } 
    void print(Printer* p);
    ~employeeDirectory(){
	for(int i = 0 ; i < this->directory.size() ; i++) delete this->directory.at(i) ;
    }
};

#endif
