#include "../header/Interface.hpp"

Interface::Interface(employeeDirectory* _e){
	this->e = _e ;
}

void Interface::print_mainMenu(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                         Employee Directory                        |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -         Import from File                    |\n" ;
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
	cout << "|                2    -       List by Department                    |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::print_printSubMenu_3(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                             Sort Menu                             |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -             Sort by Name                    |\n" ;
	cout << "|                2    -           Sort by Salary                    |\n" ;
	cout << "|                3    -        Sort by Hire Date                    |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "*-------------------------------------------------------------------*\n\n\n" ;
}

void Interface::print_printSubMenu_4(){
	cout << "\n\n*-------------------------------------------------------------------*\n" ;
	cout << "|                             Sort Menu                             |\n" ;
	cout << "|                                                                   |\n" ;
	cout << "|                1    -        Greatest to Least                    |\n" ;
	cout << "|                2    -        Least to Greatest                    |\n" ;
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
			this->remove() ;
		}
		else if(input == "5"){
			this->modify() ;
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
	string fName, lName, title, dpmt;
	int m, d, y;
	double slry;
	std::cout << "You are attempting to add an employee to the directory" << std::endl;
	std::cout << "Enter the name of the employee you would like to edit" << std::endl;
	std::cout << "Format: FirstName lastName" << std::endl;
	cin >> fName >> lName;
	std::cout << "Enter the department for the new employee" << std::endl;
	cin.ignore(); //Might need to remove, supposed to move past newline that is just created on the line of output text before
	getline(cin, dpmt);
	std::cout << "Enter the job title for the new employee" << std::endl;
	//cin.ignore(); //Might need to remove, supposed to move past newline that is just created on the line of output text before
	getline(cin, title);
	std::cout << "Enter the employee's salary" << std::endl;
	cin >> slry;
	std::cout << "Enter the employee's hire date\nThe format is month day year" << std::endl;
	cin >> m >> d >> y;
	cin.ignore();
	//Employee::Employee(string fName, string lName, string t, double d, int m, int day, int y, string _department)
	Employee* newEmployee = new Employee(fName, lName, title, slry, m, d, y, dpmt);
	e->addEmployee(newEmployee);
}

void Interface::remove(){
	std::cout << "Enter the name of the employee you would like to remove" << std::endl;
	std::cout << "Format: FirstName lastName" << std::endl;
	string fName, lName, fullName;
	cin >> fName >> lName;
	cin.ignore();
	fullName = fName + " " + lName;
	Employee* temp = e->getEmployee(fullName);
	if (temp == nullptr) {
		std::cout << "The employee you were looking to remove is not in the database" << std::endl;
	}
	else {
		//std::cout << "Got to here";
		e->removeEmployee(temp);
		std::cout << "The employee was found and removed" << std::endl;
	}
}

void Interface::modify(){
	std::cout << "Enter the name of the employee you would like to edit" << std::endl;
	std::cout << "Format: FirstName lastName" << std::endl;
	string fName, lName, fullName;
	cin >> fName >> lName;
	cin.ignore();
	fullName = fName + " " + lName;
	Employee* temp = e->getEmployee(fullName);
	if (temp == nullptr) {
		std::cout << "The employee you were looking to edit is not in the database" << std::endl;
	}
	else {
		e->editEmployee(temp);
	}
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
			else if(input3 == "3"){
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
			else if(input3 == "3"){
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
	std::cout << "Attempting to read from file" << std::endl;
	this->e->readFromFile();
}

void Interface::writeToFile(){
	std::cout << "Attempting to write to file" << std::endl;
	this->e->writeToFile();
	std::cout << "Wrote employee directory to file" << std::endl;
}
