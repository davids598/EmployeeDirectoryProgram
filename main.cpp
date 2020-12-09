#include "header.h"

int main(){
	employeeDirectory* e = new employeeDirectory() ;
	Interface* i = new Interface(e) ;
	i->mainMenu() ;
	delete i ;
	return 0 ;
}
