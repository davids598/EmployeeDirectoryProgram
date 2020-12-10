#ifndef __EMPLOYEEDIRECTORY_CPP__
#define __EMPLOYEEDIRECTORY_CPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "../header/employeeDirectory.hpp"
#include "../header/Printer.hpp"
#include "../header/Employee.hpp"
#include "../header/Date.hpp"


using namespace std;

employeeDirectory::employeeDirectory() {
    this->CEOPointer = nullptr;
}

employeeDirectory::employeeDirectory(vector<Employee*> d) {
    this->CEOPointer = d.at(0);
    for (int i = 0; i < d.size(); ++i) {
        directory.push_back(d.at(i));
	string key = directory.back()->getDepartment() ;
	std::transform(key.begin(), key.end(), key.begin(), ::toupper) ;
	departmentMap[key].push_back(d.at(i)) ;
    }
}

employeeDirectory::employeeDirectory(Employee* e) {
    this->CEOPointer = e;
    this->directory.push_back(e);
    string key = e->getDepartment() ;
    transform(key.begin(), key.end(), key.begin(), ::toupper) ;
    this->departmentMap[key].push_back(e) ;
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
    string key = directory.back()->getDepartment() ;
    std::transform(key.begin(), key.end(), key.begin(), ::toupper) ;
    this->departmentMap[key].push_back(e) ;
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
    string key = e->getDepartment() ;
    transform(key.begin(), key.end(), key.begin(), ::toupper) ;
    int j = 0 ;
    for(auto it : departmentMap[key]){
	j++ ;
	if(it == e){
		departmentMap[key].erase(departmentMap[key].begin() + j) ;
		break ;
	}
   }
}

void employeeDirectory::print(Printer* _p) {
	this->printStrat = _p ;
	this->printStrat->print(this) ;
	delete this->printStrat ;
}

vector<string> employeeDirectory::getDepartments(){
	vector<string> keys ;
	map<string, vector<Employee*>>* m = this->getMap() ;
	for(auto it : *m) keys.push_back(it.first) ;
	return keys ;
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
            << "The format is month day year" << endl;
            cin >> m >> d >> y;
            Date* temp = new Date(m, d , y);
            e->setHireDate(temp);
        }
        else {
            cout << "Your choice was invalid" << endl;
        }
     }
}


void employeeDirectory::writeToFile() {
    ofstream outFS;
    outFS.open("outputFile.txt");
    for (unsigned i = 0; i < directory.size(); ++i) {
        Employee* temp = directory.at(i);
        outFS << temp->getName()     << "\n" ;
        outFS << temp->getDepartment() << "\n" ;
        outFS << temp->getTitle()    << "\n" ;
        outFS  << *(temp->getHireDate()) << "\n" ;
        outFS  << temp->getSalary() << "\n" ;

    }
    outFS.close();
}

#endif
