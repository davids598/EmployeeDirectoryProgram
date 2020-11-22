#ifndef PRINT_HPP
#define PRINT_HPP

#include "employeeDirectory.cpp"
#include <vector>
#include <iostream>

class Printer {
	public:
		Printer() ;
	virtual void print(employeeDirectory* d) = 0 ;
	virtual ~Printer() {} ;
}

class listPrint : public Printer {
	public:
		virtual void print(employeeDirectory* d) {
			for(auto it : d->directory){
				std::cout << it->getName()     << "\n" <<
					  << it->getTitle()    << "\n" <<	
					  << it->getHireDate() << "\n" <<
					  << "$" 
					  << it->getSalary()   << "\n" << ;
			}
		}
}

class treePrint : public Printer {
	public:
		        Employee* getCEOpointer (employeeDirectory* d){
			for(auto it : d->getDirectory()){
				if(it->getTitle() == "CEO") return it ;
			}
			return 0 ;
		}
		virtual void print(employeeDirectory* d) {
			Employee* CEOpointer = getCEOpointer(d) ;
			employeeDirectory* CEO, departmentHeads ;
			vector<employeeDirectory*> temp ;
			CEO = new employeeDirectory(CEOpointer) ;
			Printer* p = new listPrint() ;
			p->print(CEO) ; std::cout << "\n" ;
			departmentHeads = new employeeDirectory(CEOpointer->getEmployees()) ; 
			for(auto i : departmentHeads){
				std::cout << i->getName()     << "\n" <<
                                          << i->getTitle()    << "\n" <<
                                          << i->getHireDate() << "\n" <<
                                          << "$"
                                          << i->getSalary()   << "\n\n" <<
					  << "Manages:\n\n" ;
				temp.push_back(new employeeDirectory(i->getEmployees())) ;
				p->print(temp.back()) ;
				std::cout << "\n" ;
			}
			for(auto it : temp) delete it ;
			delete CEO ;
			delete departmentHeads ;
			delete p ;
		}
}


#endif
