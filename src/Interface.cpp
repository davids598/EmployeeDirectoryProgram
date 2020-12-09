#include "../header/Interface.hpp"

Interface::Interface(employeeDirectory* _e){
	this->e = _e ;
}

void Interface::print_mainMenu(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                         Employee Directory                        |\n" ;
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
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::print_printSubMenu_1(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                            Print Menu                             |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -            All Employees                    |\n" ;	
	cout << "|                2    -          Single Employee                    |\n" ;
	cout << "|                3    -        Single Department                    |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::print_printSubMenu_2(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                            Print Menu                             |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -                 List All                    |\n" ;	
	cout << "|                2    -       List By Department                    |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::print_printSubMenu_3(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                             Sort Menu                             |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -             Sort By Name                    |\n" ;	
	cout << "|                2    -           Sort By Salary                    |\n" ;	
	cout << "|                3    -        Sort By Hire Date                    |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::print_printSubMenu_4(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                             Sort Menu                             |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -              High to Low                    |\n" ;	
	cout << "|                2    -              Low to High                    |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "|                                                                   |\n" ;	
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::mainMenu(){
	std::string input = "" ;
	this->print_mainMenu() ;
	while(input != "7"){
		getline(cin, input) ;
		if(input == "1"){
			this->readFromFile() ;
		}
		else if(input == "2"){
			this->print() ;
		}
		else if(input == "3"){
			this->add() ;
		}
		else if(input == "4"){
			this->modify() ;
		}
		else if(input == "5"){
			this->remove() ;
		}
		else if(input == "6"){
			this->writeToFile() ;
		}
		else{
			if(input != "7") std::cout << "\n**Error** - Invalid Input, please enter a single digit 1-7.\n\n" ;
			continue ;
		}
		this->print_mainMenu() ;
	}
	std::cout << "\n\n\n\nTerminating\n" ;	
}

void Interface::add(){	
}

void Interface::remove(){
}

void Interface::modify(){
}

void Interface::print(){
	this->print_printSubMenu_1() ;
	string input, input2, input3, input4 ;
	getline(cin, input) ;
	if(input == "2"){
		cout << "\nEnter name of Employee to print: " ;
		getline(cin, input) ;
		if(this->e->getEmployee(input)){
			employeeDirectory* t = new employeeDirectory(this->e->getEmployee(input)) ;
			t->print(new listPrint()) ;
			delete t ;
		}	
		else{
			cout << "\n\n**Error** - Employee \"" << input << "\" was not found in the Directory.\n\n" ;
			return ;
		}
	}
	else if(input == "3"){
		cout << "\nEnter name of Department to print: " ;
		getline(cin, input) ;
		transform(input.begin(), input.end(), input.begin(), ::toupper) ;
		if(e->getMap()->find(input) == e->getMap()->end()){
			cout << "\n\n**Error** - Department \"" << input << "\" was not found in the Directory.\n\n" ;
			return ;
		}
		else{
			employeeDirectory* t = new employeeDirectory(this->e->getMap()->at(input)) ;	
			this->print_printSubMenu_3() ;
			getline(cin, input) ;
			while(input != "1" && input != "2" && input != "3"){
				cout << "\n\n**Error** - Invalid Input, enter a single digit 1-3.\n\n" ;
				getline(cin, input) ;
			}
			this->print_printSubMenu_4() ;
			getline(cin, input2) ;
			while(input2 != "1" && input2 != "2"){
				cout << "\n\n**Error** - Invalid Input, enter a single digit 1-2.\n\n" ;
				getline(cin, input2) ;
			}	
			if(input == "1"){
				if(input2 == "1") t->print(new sortByName(new treePrint())) ;
				else if(input2 == "2") t->print(new sortByName(new LowToHigh(new treePrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else if(input == "2"){
				if(input2 == "1") t->print(new sortBySalary(new treePrint())) ;
				else if(input2 == "2") t->print(new sortBySalary(new LowToHigh(new treePrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else if(input == "3"){
				if(input2 == "1") t->print(new sortByHireDate(new treePrint())) ;
				else if(input2 == "2") t->print(new sortByHireDate(new LowToHigh(new treePrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else cout << "\n\n**Error** - Print Failed\n\n" ;
			delete t ;
		}
	}
	else if(input == "1"){
		this->print_printSubMenu_2() ;
		getline(cin, input2) ;
		while(input2 != "1" && input2 != "2"){
			cout << "\n\n**Error** - Invalid Input, enter a single digit 1-2.\n\n" ;
			getline(cin, input2) ;
		}
		this->print_printSubMenu_3() ;
		getline(cin, input3) ;
		while(input3 != "1" && input3 != "2" && input3 != "3"){
			cout << "\n\n**Error** - Invalid Input, enter a single digit 1-3.\n\n" ;
			getline(cin, input3) ;
		}
		this->print_printSubMenu_4() ;
		getline(cin, input4) ;
		while(input4 != "1" && input4 != "2"){
			cout << "\n\n**Error** - Invalid Input, enter a single digit 1-2.\n\n" ;
			getline(cin, input4) ;
		}
		if(input2 == "1"){
			if(input3 == "1"){
				if(input4 == "1") e->print(new sortByName(new listPrint())) ;
				else if(input4 == "2") e->print(new sortByName(new LowToHigh(new listPrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else if(input3 == "2"){
				if(input4 == "1") e->print(new sortBySalary(new listPrint())) ;
				else if(input4 == "2") e->print(new sortBySalary(new LowToHigh(new listPrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else if(input4 == "3"){
				if(input4 == "1") e->print(new sortByHireDate(new listPrint())) ;
				else if(input4 == "2") e->print(new sortByHireDate(new LowToHigh(new listPrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else cout << "\n\n**Error** - Print failed.\n\n" ;
	    	}
		else if(input2 == "2"){
			if(input3 == "1"){
				if(input4 == "1") e->print(new sortByName(new treePrint())) ;
				else if(input4 == "2") e->print(new sortByName(new LowToHigh(new treePrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else if(input3 == "2"){
				if(input4 == "1") e->print(new sortBySalary(new treePrint())) ;
				else if(input4 == "2") e->print(new sortBySalary(new LowToHigh(new treePrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else if(input4 == "3"){
				if(input4 == "1") e->print(new sortByHireDate(new listPrint())) ;
				else if(input4 == "2") e->print(new sortByHireDate(new LowToHigh(new treePrint()))) ;
				else cout << "\n\n**Error** - Print failed.\n\n" ;
			}
			else cout << "\n\n**Error** - Print failed.\n\n" ;
	    	}
		else cout << "\n\n**Error** - Print failed.\n\n" ;
	}
}

void Interface::readFromFile(){
}

void Interface::writeToFile(){
}


