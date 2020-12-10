#ifndef __TEST__
#define __TEST__

#include "gtest/gtest.h"
#include "header.h"

TEST(PrintTestSuite, noEmployee_listPrint){
	employeeDirectory* e = new employeeDirectory() ;
	Printer* p = new listPrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(PrintTestSuite, singleEmployee_listPrint){
	Employee* t = new Employee("John", "Smith", "Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	employeeDirectory* e = new employeeDirectory(t) ;
	testing::internal::CaptureStdout() ;
	Printer* p = new listPrint() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\nJohn Smith\nProgramming\nSoftware Engineer\n12/8/2007\n$50000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(PrintTestSuite, manyEmployees_listPrint){
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 60000, 8, 14, 2003, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	Printer* p = new listPrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$60000\n\n-------------------------------------------\n" ;

	EXPECT_EQ(output, e_output) ;	
}

TEST(PrintTestSuite, noEmployee_treePrint){	
	employeeDirectory* e = new employeeDirectory() ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
}

TEST(PrintTestSuite, singleEmployee_treePrint){
	Employee* t = new Employee("John", "Smith", "Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	employeeDirectory* e = new employeeDirectory(t) ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJohn Smith\nSoftware Engineer\n12/8/2007\n$50000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(PrintTestSuite, manyEmployees_treePrint){	
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 60000, 8, 14, 2003, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nFront End Developer\n8/14/2003\n$60000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, sortByName_listPrint){	
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 60000, 8, 14, 2003, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	Printer* p = new listPrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$60000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByName(new listPrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              List Print\n-------------------------------------------\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$60000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, sortByName_treePrint){
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 60000, 8, 14, 2003, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nFront End Developer\n8/14/2003\n$60000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByName(new treePrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJason Smith\nFront End Developer\n8/14/2003\n$60000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, sortBySalary_listPrint){	
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 65000, 8, 14, 2003, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	Printer* p = new listPrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$65000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortBySalary(new listPrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              List Print\n-------------------------------------------\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$65000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, sortBySalary_treePrint){
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 65000, 8, 14, 2003, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nFront End Developer\n8/14/2003\n$65000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortBySalary(new treePrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nFront End Developer\n8/14/2003\n$65000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\n-------------------------------------------\n" ;
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, sortByHireDate_listPrint){	
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 66000, 8, 14, 2003, "Programming") ;
	Employee* t4 = new Employee("Jackson", "Smith", "Front End Developer", 65000, 9, 4, 2002, "Programming") ;
	Employee* t5 = new Employee("James", "Smith", "Front End Developer", 90000, 3, 8, 2000, "Programming") ;
	Employee* t6 = new Employee("Jay", "Smith", "Front End Developer", 70000, 2, 4, 20122, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	e->addEmployee(t4) ;
	e->addEmployee(t5) ;
	e->addEmployee(t6) ;
	Printer* p = new listPrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$66000\n\nJackson Smith\nProgramming\nFront End Developer\n9/4/2002\n$65000\n\nJames Smith\nProgramming\nFront End Developer\n3/8/2000\n$90000\n\nJay Smith\nProgramming\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByHireDate(new listPrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              List Print\n-------------------------------------------\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJames Smith\nProgramming\nFront End Developer\n3/8/2000\n$90000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJackson Smith\nProgramming\nFront End Developer\n9/4/2002\n$65000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$66000\n\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJay Smith\nProgramming\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, sortByHireDate_treePrint){
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 66000, 8, 14, 2003, "Programming") ;
	Employee* t4 = new Employee("Jackson", "Smith", "Front End Developer", 65000, 9, 4, 2002, "Programming") ;
	Employee* t5 = new Employee("James", "Smith", "Front End Developer", 90000, 3, 8, 2000, "Programming") ;
	Employee* t6 = new Employee("Jay", "Smith", "Front End Developer", 70000, 2, 4, 20122, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	e->addEmployee(t4) ;
	e->addEmployee(t5) ;
	e->addEmployee(t6) ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nFront End Developer\n8/14/2003\n$66000\n\nJackson Smith\nFront End Developer\n9/4/2002\n$65000\n\nJames Smith\nFront End Developer\n3/8/2000\n$90000\n\nJay Smith\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByHireDate(new treePrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJames Smith\nFront End Developer\n3/8/2000\n$90000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJackson Smith\nFront End Developer\n9/4/2002\n$65000\n\nJason Smith\nFront End Developer\n8/14/2003\n$66000\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJay Smith\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, LowToHigh_listPrint){	
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 66000, 8, 14, 2003, "Programming") ;
	Employee* t4 = new Employee("Jackson", "Smith", "Front End Developer", 65000, 9, 4, 2002, "Programming") ;
	Employee* t5 = new Employee("James", "Smith", "Front End Developer", 90000, 3, 8, 2000, "Programming") ;
	Employee* t6 = new Employee("Jay", "Smith", "Front End Developer", 70000, 2, 4, 20122, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	e->addEmployee(t4) ;
	e->addEmployee(t5) ;
	e->addEmployee(t6) ;
	Printer* p = new listPrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              List Print\n-------------------------------------------\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$66000\n\nJackson Smith\nProgramming\nFront End Developer\n9/4/2002\n$65000\n\nJames Smith\nProgramming\nFront End Developer\n3/8/2000\n$90000\n\nJay Smith\nProgramming\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByHireDate(new listPrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              List Print\n-------------------------------------------\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\nJames Smith\nProgramming\nFront End Developer\n3/8/2000\n$90000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJackson Smith\nProgramming\nFront End Developer\n9/4/2002\n$65000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$66000\n\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJay Smith\nProgramming\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByHireDate(new LowToHigh(new listPrint())) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              List Print\n-------------------------------------------\nJay Smith\nProgramming\nFront End Developer\n2/4/20122\n$70000\n\nJohn Smith\nProgramming\nJr. Software Engineer\n12/8/2007\n$50000\n\nJason Smith\nProgramming\nFront End Developer\n8/14/2003\n$66000\n\nJackson Smith\nProgramming\nFront End Developer\n9/4/2002\n$65000\n\nJean Smith\nProgramming\nSoftware Analyst\n5/22/2002\n$60000\n\nJames Smith\nProgramming\nFront End Developer\n3/8/2000\n$90000\n\nJerry Smith\nProgramming\nSenior Software Engineer\n11/11/1997\n$90000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
}

TEST(sortTestSuite, LowToHigh_treePrint){
	Employee* t = new Employee("John", "Smith", "Jr. Software Engineer", 50000, 12, 8, 2007, "Programming") ;
	Employee* t1 = new Employee("Jean", "Smith", "Software Analyst", 60000, 5, 22, 2002, "Programming") ;
	Employee* t2 = new Employee("Jerry", "Smith", "Senior Software Engineer", 90000, 11, 11, 1997, "Programming") ;
	Employee* t3 = new Employee("Jason", "Smith", "Front End Developer", 66000, 8, 14, 2003, "Programming") ;
	Employee* t4 = new Employee("Jackson", "Smith", "Front End Developer", 65000, 9, 4, 2002, "Programming") ;
	Employee* t5 = new Employee("James", "Smith", "Front End Developer", 90000, 3, 8, 2000, "Programming") ;
	Employee* t6 = new Employee("Jay", "Smith", "Front End Developer", 70000, 2, 4, 20122, "Programming") ;
	employeeDirectory* e = new employeeDirectory() ;
	e->addEmployee(t) ;
	e->addEmployee(t1) ;
	e->addEmployee(t2) ;
	e->addEmployee(t3) ;
	e->addEmployee(t4) ;
	e->addEmployee(t5) ;
	e->addEmployee(t6) ;
	Printer* p = new treePrint() ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	std::string output = testing::internal::GetCapturedStdout() ;
	std::string e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJason Smith\nFront End Developer\n8/14/2003\n$66000\n\nJackson Smith\nFront End Developer\n9/4/2002\n$65000\n\nJames Smith\nFront End Developer\n3/8/2000\n$90000\n\nJay Smith\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;
	p = new sortByHireDate(new treePrint()) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\nJames Smith\nFront End Developer\n3/8/2000\n$90000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJackson Smith\nFront End Developer\n9/4/2002\n$65000\n\nJason Smith\nFront End Developer\n8/14/2003\n$66000\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJay Smith\nFront End Developer\n2/4/20122\n$70000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	delete p ;	
	p = new sortByHireDate(new LowToHigh(new treePrint())) ;
	testing::internal::CaptureStdout() ;
	p->print(e) ;
	output = testing::internal::GetCapturedStdout() ;
	e_output = "\n              Tree Print\n-------------------------------------------\nDepartments: \n-------------------------------------------\nPROGRAMMING:\n-------------------------------------------\n\nJay Smith\nFront End Developer\n2/4/20122\n$70000\n\nJohn Smith\nJr. Software Engineer\n12/8/2007\n$50000\n\nJason Smith\nFront End Developer\n8/14/2003\n$66000\n\nJackson Smith\nFront End Developer\n9/4/2002\n$65000\n\nJean Smith\nSoftware Analyst\n5/22/2002\n$60000\n\nJames Smith\nFront End Developer\n3/8/2000\n$90000\n\nJerry Smith\nSenior Software Engineer\n11/11/1997\n$90000\n\n-------------------------------------------\n" ;	
	EXPECT_EQ(output, e_output) ;
	
}

#endif
