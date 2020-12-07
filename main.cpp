#include "header.h"

int main(){
	Employee* sean = new Employee("Sean", "S", "Programmer", 50000, 11, 30, 2020, "CS") ;
	Employee* bean = new Employee("Bean", "B", "Software Engineer", 76000, 11, 31, 2020, "CS") ;
	Employee* jean = new Employee("Jean", "J", "Sales Associate", 30000, 12, 1, 2020, "Sales") ;
	employeeDirectory* e = new employeeDirectory(sean) ;
	e->addEmployee(bean) ;
	e->addEmployee(jean) ;
/*	
	cout << "normal list print \n\n" ;	
	Printer* p = new listPrint() ;
	e->set_print_strat(p) ;
	e->print() ;
	delete p ;
	
	cout << "salary sort list print\n\n" ;
	p = new sortBySalary(new listPrint()) ;
	e->set_print_strat(p) ;
	e->print() ;
	delete p ;

	cout << "name sort list print\n\n" ;
	p = new sortByName(new listPrint()) ;
	e->set_print_strat(p) ;
	e->print() ;
	delete p ;
*/
	Printer* p ;
	cout << "normal tree print \n\n" ;
	p = new treePrint() ;
	e->print(p) ;
	delete p ;

	cout << "sortByName tree print \n\n" ;
	p = new sortByName(new treePrint()) ;
	e->print(p) ;
	delete p ; 
/*
	cout << "low to high, name sort, tree print\n\n" ;
	p = new LowToHigh(new sortByName(new treePrint())) ;
	e->set_print_strat(p) ;
	e->print() ;
	delete p ;

	cout << "name sort, tree print\n\n" ;
	p = new sortByName(new treePrint()) ;
	e->set_print_strat(p) ;
	e->print() ;
	
*/
	delete e ;
	return 0 ;
}
