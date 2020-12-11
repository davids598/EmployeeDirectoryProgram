#ifndef __TESTEMPLOYEE__
#define __TESTEMPLOYEE__

#include "gtest/gtest.h"
#include "header.h"

TEST(employeeTestSuite, defaultConstructorName) {
    Employee* temp = new Employee();
    std::string tempOutput = temp->getName();
    EXPECT_EQ(tempOutput, " ");
}

TEST(employeeTestSuite, defaultConstructorSalary) {
    Employee* temp = new Employee();
    double tempOutput = temp->getSalary();
    EXPECT_EQ(tempOutput, 0.0);
}

TEST(employeeTestSuite, defaultConstructorJobTitle) {
    Employee* temp = new Employee();
    std::string tempOutput = temp->getTitle();
    EXPECT_EQ(tempOutput, "");
}

TEST(employeeTestSuite, defaultConstructorHireDate) {
    Employee* temp = new Employee();
    Date* tempOutput = temp->getHireDate();
    EXPECT_EQ(tempOutput, nullptr);
}

TEST(employeeTestSuite, defaultConstructorDepartment) {
    Employee* temp = new Employee();
    std::string tempOutput = temp->getDepartment();
    EXPECT_EQ(tempOutput, "");
}

TEST(employeeTestSuite, DataConstructorName) {
    Employee* temp = new Employee("David", "Strathman", "Software Engineer", 50000.0, 4, 28, 2001, "Engineering");
    std::string tempOutput = temp->getName();
    EXPECT_EQ(tempOutput, "David Strathman");
}

TEST(employeeTestSuite, DataConstructorAllDataTest) {
    Employee* temp = new Employee("David", "Strathman", "Software Engineer", 50000.0, 4, 28, 2001, "Engineering");
    std::string tempOutput = temp->getName() + " " + temp->getTitle() + " " + temp->getDepartment();
    double slry = temp->getSalary();
    std::string hireDateInfo = (temp->getHireDate())->outputForFile();
    EXPECT_EQ(tempOutput, "David Strathman Software Engineer Engineering");
    EXPECT_EQ(slry, 50000);
    EXPECT_EQ(hireDateInfo, "4\n28\n2001\n");
}


//Done with employee, now testing constructors for employeeDirectory
TEST(employeeDirectoryTestSuite, ConstructorsTest) {
    employeeDirectory* directory = new employeeDirectory();
    //Testing constructor with one employee object
    Employee* temp = new Employee("Sean", "S", "Senior Software Engineer", 250000.0, 1, 1, 2020, "Engineering");
    employeeDirectory* directory_2 = new employeeDirectory(temp);
    EXPECT_EQ(directory->getCEOPointer(), nullptr);
    EXPECT_EQ(directory_2->getCEOPointer(), temp);
}

TEST(employeeDirectoryTestSuite, GetEmployeeFunction) {
    //Testing constructor with one employee object
    Employee* temp = new Employee("Sean", "S", "Senior Software Engineer", 250000.0, 1, 1, 2020, "Engineering");
    employeeDirectory* directory = new employeeDirectory(temp);
    Employee* getEmployee = directory->getEmployee("Sean S");
    EXPECT_EQ(directory->getEmployee("Sean S"), getEmployee);
}

TEST(employeeDirectoryTestSuite, AddEmployeeFunction) {
    //Testing constructor with one employee object
    Employee* temp = new Employee("Sean", "S", "Senior Software Engineer", 250000.0, 1, 1, 2020, "Engineering");
    employeeDirectory* directory = new employeeDirectory(temp);
    Employee* newEmployee = new Employee("David", "Strathman", "Software Engineer", 50000.0, 4, 28, 2001, "Engineering");
    directory->addEmployee(newEmployee);
    EXPECT_EQ(directory->getEmployee("David Strathman"), newEmployee);
}

TEST(employeeDirectoryTestSuite, RemoveEmployeeFunction) {
    //Testing constructor with one employee object
    Employee* temp = new Employee("Sean", "S", "Senior Software Engineer", 250000.0, 1, 1, 2020, "Engineering");
    employeeDirectory* directory = new employeeDirectory(temp);
    Employee* newEmployee = new Employee("David", "Strathman", "Software Engineer", 50000.0, 4, 28, 2001, "Engineering");
    directory->addEmployee(newEmployee);
    directory->removeEmployee(newEmployee);
    EXPECT_EQ(directory->getEmployee("David Strathman"), nullptr);
}

//Testing Interface now
TEST(interfaceTestSuite, MainMenu) {
    employeeDirectory* e = new employeeDirectory();
	Interface* i = new Interface(e);
    testing::internal::CaptureStdout() ;
    i->print_mainMenu();
    std::string output = testing::internal::GetCapturedStdout();
    std::string e_output = "\n\n*-------------------------------------------------------------------*\n|                         Employee Directory                        |\n|                                                                   |\n|                1    -         Import from File                    |\n|                2    -           View Employees                    |\n|                3    -             Add Employee                    |\n|                4    -          Remove Employee                    |\n|                5    -          Modify Employee                    |\n|                6    -             Save to File                    |\n|                7    -                     Exit                    |\n|                                                                   |\n|                                                                   |\n*-------------------------------------------------------------------*\n\n\n";
    EXPECT_EQ(output, e_output);
}

#endif
