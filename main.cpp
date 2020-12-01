#include "src/employeeDirectory.cpp"

int main(){
	Employee* sean = new Employee("Sean", "S", "Programmer", 50000, 11, 30, 2020, "CS") ;
	Employee* bean = new Employee("Bean", "B", "Software Engineer", 76000, 11, 31, 2020, "CS") ;
	Employee* jean = new Employee("Jean", "J", "Sales Associate", 30000, 12, 1, 2020, "Sales") ; 
	employeeDirectory* e = new employeeDirectory(sean) ;
	e->addEmployee(bean) ;
	e->addEmployee(jean) ;
	Printer* p = new listPrint();
	e->set_print_strat(p) ;
	e->print() ;
	e->set_print_strat(new treePrint()) ;
	e->print() ;

	return 0 ;
}
