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
        if (e->getName() == directory.at(i)->getName()) {
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
        delete it ;
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
        cin.ignore();
        if (choice == 1) {
            string fName, lName;
            cout << "Enter the employee's new first and last name" << endl;
            cin >> fName >> lName;
            cin.ignore();
            e->setName(fName, lName);
            cout << "Name has been changed!" << endl;
        }
        else if (choice == 2) {
            string title;
            cout << "Enter the employee's new job title" << endl;
            getline(cin, title);
            e->setTitle(title);
            cout << "Title has been changed!" << endl;
        }
        else if (choice == 3) {
            double salary;
            cout << "Enter the employee's new salary" << endl;
            cin >> salary;
            cin.ignore();
            e->setSalary(salary);
            cout << "Salary has been set!" << endl;
        }
        else if (choice == 4) {
            int d, m, y;
            cout << "Enter the employee's new hire date\n"
            << "The format is month day year" << endl;
            cin >> m >> d >> y;
            cin.ignore();
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
        if (i + 1 == directory.size()) {
            outFS  << temp->getSalary() ;
        }
        else {
            outFS  << temp->getSalary() << "\n" ;
        }
    }
    outFS.close();
}

void employeeDirectory::readFromFile() {
    ifstream inFS;
    inFS.open("outputFile.txt");
    if (!inFS.is_open()) {
        cout << "An ouput file was not found" << endl;
        return;
    }
    //If file opens properly, read employees from File
    //Employee::Employee(string fName, string lName, string t, double d, int m, int day, int y, string _department)
    string fName, lName, title, department;
    int m, d, y;
    double salary;
    while (!inFS.eof()) {
        //Go through the file and get data for each employee, create a pointer to that employee and add the employee to the Directory
        inFS >> fName >> lName;
        inFS.ignore();
        getline(inFS, department);
        getline(inFS, title);
        m = inFS.get();
        inFS.ignore();
        d = inFS.get();
        inFS.ignore();
        y = inFS.get();
        inFS.ignore(); //ignore final newline
        inFS >> salary;
        inFS.ignore();

        //Got all employee data, now to create object and add to Directory
        Employee* temp = new Employee(fName, lName, title, salary, m, d, y, department);
        this->addEmployee(temp);
    }
}

#endif
