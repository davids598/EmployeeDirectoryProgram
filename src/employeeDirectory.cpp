#ifndef __EMPLOYEEDIRECTORY_CPP__
#define __EMPLOYEEDIRECTORY_CPP__

#include <iostream>
#include <vector>
#include "../header/employeeDirectory.hpp"
#include "../header/Date.hpp"

using namespace std;

employeeDirectory::employeeDirectory() {
    this->CEOPointer = nullptr;
}

employeeDirectory::employeeDirectory(vector<Employee*> d) {
    this->CEOPointer = d.at(0);
    for (int i = 0; i < d.size(); ++i) {
        directory.push_back(d.at(i));
    }
}

employeeDirectory::employeeDirectory(Employee* e) {
    this->CEOPointer = e;
    this->directory.push_back(e);
}

Employee* employeeDirectory::getCEOPointer() {
    return this->CEOPointer;
}

Employee* employeeDirectory::getEmployee(string name) {
    for (int i = 0; i < directory.size(); ++i) {
        if (directory.at(i)->getName() == name) {
            return directory.at(i);
        }
    }
    return nullptr;
}

void employeeDirectory::addEmployee(Employee* e) {
    this->directory.push_back(e);
}

void employeeDirectory::removeEmployee(Employee* e) {
    vector<Employee*>::iterator v;
    int position = -1;
    for (unsigned i = 0; i < directory.size(); ++i) {
        if (e == directory.at(i)) {
            position = i;
        }
    }
    v = directory.begin();
    directory.erase(v + position);
}
void employeeDirectory::set_print_strat(Printer* p){
	this->printStrat = p ;
}
void employeeDirectory::print() {
    this->printStrat->print(this) ;
}

void employeeDirectory::editEmployee(Employee* e) {
    int choice = 0;
    while (choice != -1) {
        cout << "Enter a -1 to quit editing an employee" << endl;
        cout << "What do you want to edit about this employee?\n"
        << "1. Name\n"
        << "2. Job Title\n"
        << "3. Salary\n"
        << "4. Hire Date" << endl;
        cin >> choice;
        if (choice == 1) {
            string fName, lName;
            cout << "Enter the employee's new first and last name" << endl;
            cin >> fName, lName;
            e->setName(fName, lName);
            cout << "Name has been changed!" << endl;
        }
        else if (choice == 2) {
            string title;
            cout << "Enter the employee's new job title" << endl;
            cin >> title;
            e->setTitle(title);
            cout << "Title has been changed!" << endl;
        }
        else if (choice == 3) {
            double salary;
            cout << "Enter the employee's new salary" << endl;
            cin >> salary;
            e->setSalary(salary);
            cout << "Salary has been set!" << endl;
        }
        else if (choice == 4) {
            int d, m, y;
            cout << "Enter the employee's new hire date\n"
            << "The format is day month year" << endl;
            cin >> d >> m >> y;
            Date* temp = new Date(d, m , y);
            e->setHireDate(temp);
        }
        else {
            cout << "Your choice was invalid" << endl;
        }
     }
}

void listPrint::print(employeeDirectory* d) {
        for(auto it : d->getDirectory()){
                std::cout << it->getName()     << "\n" ;
                std::cout << it->getTitle()    << "\n" ;
                std::cout  << *(it->getHireDate()) << "\n" ;
                std::cout  << "$" << it->getSalary() << "\n" ;
        }
}


void treePrint::print(employeeDirectory* d){
        Employee* CEOpointer = d->getCEOPointer() ;
        employeeDirectory* CEO ;
        employeeDirectory* departmentHeads ;
        vector<employeeDirectory*> temp ;
        CEO = new employeeDirectory(CEOpointer) ;
        Printer* p = new listPrint() ;
        p->print(CEO) ; std::cout << "\n" ;
        departmentHeads = new employeeDirectory(CEOpointer->getEmployees()) ;
        for(auto i : departmentHeads->getDirectory()){
                std::cout << i->getName() << "\n" ;
                std::cout << i->getTitle() << "\n" ;
                std::cout << i->getHireDate() << "\n" ;
                std::cout << "$" ;
                std::cout << i->getSalary() << "\n\n" ;
                std::cout << "Manages:\n\n" ;
                temp.push_back(new employeeDirectory(i->getEmployees())) ;
                p->print(temp.back()) ;
                std::cout << "\n" ;
        }
}

#endif
