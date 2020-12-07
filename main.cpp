#include "header.h"

int main(){
	Employee* sean = new Employee("Sean", "S", "Programmer", 50000, 11, 30, 2020, "CS") ;
	Employee* bean = new Employee("Bean", "B", "Software Engineer", 76000, 11, 31, 2020, "CS") ;
	Employee* jean = new Employee("Jean", "J", "Sales Associate", 30000, 12, 1, 2020, "Sales") ;
	employeeDirectory* e = new employeeDirectory(sean) ;
	e->addEmployee(bean) ;
	e->addEmployee(jean) ;
	Printer* p = new sortBySalary(new listPrint()) ;
	e->set_print_strat(p) ;
	e->print() ;
	delete p ;
	p = new treePrint() ;
	e->set_print_strat(p) ;
	e->print() ;
	delete e ;
	delete p ;

	return 0 ;
}
