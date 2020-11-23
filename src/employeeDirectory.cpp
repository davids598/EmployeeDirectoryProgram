#ifndef __EMPLOYEEDIRECTORY_CPP__
#define __EMPLOYEEDIRECTORY_CPP__

#include <iostream>
#include <vector>
#include "../header/employeeDirectory.hpp"

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

Employee* employeeDirectoy::getEmployee(string name) {
    for (int i = 0; i < directory.size(); ++i) {
        if (directory.at(i)->firstName + " " + directory.at(i)->lastName == name) {
            return directory.at(i);
        }
    }
    return nullptr;
}



#endif
