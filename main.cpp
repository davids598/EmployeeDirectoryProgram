#include "src/employeeDirectory.cpp"

int main(){
	Employee* sean = new Employee("Sean", "S", "Comp sci", 50000, 11, 30, 2020, NULL) ;
	Employee* bean = new Employee("Bean", "B", "Comp Sky", 76000, 11, 31, 2020, sean) ;
	employeeDirectory* e = new employeeDirectory(sean) ;
	e->addEmployee(bean) ;
	Printer* p = new listPrint();
	e->set_print_strat(p) ;
	e->print() ;
	p = new treePrint() ;
	e->set_print_strat(p) ;
	e->print() ;

	return 0 ;
}
