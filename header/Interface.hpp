#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include "employeeDirectory.hpp"

class Interface{
	private:
		employeeDirectory* e ;
	public:
		Interface() { } 
		Interface(employeeDirectory* _e) ;
		~Interface() { 
			if(this->e){
				this->e->cleanup() ;
				delete this->e ; 
			}
		}
		void mainMenu() ;
		void print_mainMenu() ;
		void print_printSubMenu_1() ;
		void print_printSubMenu_2() ;
		void print_printSubMenu_3() ;
		void print_printSubMenu_4() ;	
		void add() ;
		void modify() ;
		void remove() ;
		void readFromFile() ;
		void writeToFile() ;
		void print() ;
} ;



#endif
