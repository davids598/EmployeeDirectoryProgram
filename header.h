#ifndef HEADER_H
#define HEADER_H

#include "header/Employee.hpp"
#include "header/employeeDirectory.hpp"
#include "header/Printer.hpp"
#include "header/Interface.hpp"

#include <iostream>
#include <string>

using namespace std ;


string mainMenu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                       Employee Directory                          |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -         Import from file                    |\n" ;	
	cout << "|                2    -           View Employees                    |\n" ;	
	cout << "|                3    -             Add Employee                    |\n" ;	
	cout << "|                4    -          Remove Employee                    |\n" ;	
	cout << "|                5    -          Modify Employee                    |\n" ;	
	cout << "|                6    -             Save to File                    |\n" ;	
	cout << "|                7    -                     Exit                    |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

string add_employee_Menu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                             Add Employee                          |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|         Enter the following information line by line:             |\n" ;	
	cout << "|                      1.              First Name                   |\n" ;	
	cout << "|                      2.               Last Name                   |\n" ;   
	cout << "|                      3.               Job Title                   |\n" ;	
	cout << "|                      4.          Job Department                   |\n" ;	
	cout << "|                      5.                  Salary                   |\n" ;	
	cout << "|                      6.  Hire Date (MM DD YYYY)                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

string remove_employee_Menu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                           Remove Employee                         |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

string modify_employee_Menu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                         Employee Directory                        |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

string view_employee_Menu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                         Employee Directory                        |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

string save_Menu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                         Employee Directory                        |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

string load_Menu(){
	cout << "*-------------------------------------------------------------------*\n" ;
	cout << "|                         Employee Directory                        |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n" ;
}

#endif
