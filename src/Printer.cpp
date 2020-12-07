#include "../header/Printer.hpp"
#include "../header/employeeDirectory.hpp"
#include "../header/Employee.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

void listPrint::print(employeeDirectory* d) {
        std::cout << "\n              List Print\n" ;
        std::cout << "-------------------------------------------\n" ;
        for(auto it : *d->getDirectory()){
                std::cout << it->getName()     << "\n" ;
                std::cout << it->getDepartment() << "\n" ;
                std::cout << it->getTitle()    << "\n" ;
                std::cout  << *(it->getHireDate()) << "\n" ;
                std::cout  << "$" << it->getSalary() << "\n\n" ;
        }
        std::cout << "-------------------------------------------\n" ;
}

void treePrint::print(employeeDirectory* d){
        std::cout << "\n              Tree Print\n" ;
        std::cout << "-------------------------------------------\n" ;
        std::vector<string> keys ;
        map<string, vector<Employee*>>* m = d->getMap() ;
        for(auto it : *m){
                keys.push_back(it.first) ;
        }
        std::cout << "Departments: \n" ;
        std::cout << "-------------------------------------------\n" ;
        for(auto i : keys){
                std::cout << i << ":\n" ;
                std::cout << "-------------------------------------------\n\n" ;
                for(auto j : m->at(i)){
                        std::cout << j->getName() << "\n" ;
                        std::cout << j->getTitle() << "\n" ;
                        std::cout << *(j->getHireDate()) << "\n" ;
                        std::cout << "$" << j->getSalary() << "\n\n" ;
                }
                std::cout << "-------------------------------------------\n" ;
        }

}

bool compareSalary(Employee* a, Employee* b){
	return a->getSalary() > b->getSalary() ;
}

void sortBySalary::print(employeeDirectory* d){
	vector<Employee*>* v = d->getDirectory() ;
	map<string, vector<Employee*>>* m = d->getMap() ;
	vector<string> key = d->getDepartments() ;
	for(auto it : key){
		vector<Employee*>& t = m->at(it) ;
		sort(t.begin(), t.end(), compareSalary) ;
		m->at(it) = t ;
	}
	sort(v->begin(), v->end(), compareSalary) ; 
	this->p->print(d) ;
}

bool compareName(Employee* a, Employee* b){
	return a->getName() < b->getName() ;
}

void sortByName::print(employeeDirectory* d){
	vector<Employee*>* v = d->getDirectory() ;
	map<string, vector<Employee*>>* m = d->getMap() ;
	vector<string> key = d->getDepartments() ;
	for(auto it : key){
		vector<Employee*>& t = m->at(it) ;
		sort(t.begin(), t.end(), compareName) ;
		m->at(it) = t ;
	}
	sort(v->begin(), v->end(), compareName) ;
	this->p->print(d) ;
}

void LowToHigh::print(employeeDirectory* d){
	vector<Employee*>* temp = d->getDirectory() ;
	reverse(temp->begin(), temp->end()) ;
	vector<string> key = d->getDepartments() ;
	map<string, vector<Employee*>>* m = d->getMap() ;
	for(auto it : key){
		vector<Employee*>& t = m->at(it) ;
		reverse(t.begin(), t.end()) ;
		m->at(it) = t ;
	}
	this->p->print(d) ;
}	


