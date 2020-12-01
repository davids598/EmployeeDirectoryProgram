#ifndef __EMPLOYEEDIRECTORY_HPP__
#define __EMPLOYEEDIRECTORY_HPP__

#include <vector>
#include <iostream>
#include "../src/Employee.cpp"
#include "Date.hpp"

using namespace std;

class Printer ;
class listPrint ;
class treePrint ;
class Employee ;

class employeeDirectory {
private:
    vector<Employee*> directory;
   // sortStrategy* sortStrat;
    Printer* printStrat;
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
    void set_print_strat(Printer* p) ;
    vector<Employee*> getDirectory() { return this->directory ; } ;
    void print();
};

class Printer {
	public:
		virtual void print(employeeDirectory* d) = 0 ;
		virtual ~Printer() {}  ;
} ;

class listPrint : public Printer {
        public:
                virtual void print(employeeDirectory* d) ;
		~listPrint() { }  ;
} ;

class treePrint : public Printer {
        public:
                virtual void print(employeeDirectory* d) ;
		~treePrint() { } ;
} ;

#endif
