
# Employee Directory
 > Authors: \<[Sean Sponagle](https://github.com/sspon001)\> \<[David Strathman](https://github.com/davids598)\>
 
## Project Description
We are planning to demonstrate our ability to use these design patterns by implementing them into an Employee Directory program.  This program will be written in C++ and utilize text files, possibly SQL, for database management.  This program will be able to start from scratch or import an existing database and allow the user manage the employee directory.  This includes adding and removing employees as well as modifying and displaying them in various ways.  Each employee will also contain data regarding that unique employee, such as salary, hire date etc.  The user will interact with the program via the terminal and will be given plenty of useful commands to use the program and display and modify the data as needed.  The program will output all changes to the database if the user wishes to do so.  This program will implement the following design patterns: Composite and Strategy

Composite - The program will implement the composite design pattern by creating a base class for all types of employees.  Each specific type of Employee will inherit from the base Employee class.  We picked this pattern for this purpose because it seems to fit perfectly with the idea.  The user will have access to all employees through the composite class. 

Strategy - This program will make use of the strategy design pattern by implementing functions such as `print()` and `sortDirectory()` that will work differently depending on what kind of output the user wants during runtime.  There will be a variety of options for each function available to the user. 

## Phase II

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-sspon001/blob/master/images/final_diagram.png)

 In this program, we will use the strategy design pattern to implement the sorting function as well as our print function to display the data.  The employeeDirectory class will rely on a vector of Employee object pointers to store different types of employees.  The user will be able to sort the employees in 3 different ways, by name, salary, or department.  The user will also be able to print in 3 different ways.  They can print a single employee, a whole department, or the entire directory.  An administrator, someone who has logged into the program with credentials, can add employees, remove employees, or modify existing employees.
 
 I (Sean) ended up implementing the print function as a strategy pattern, with a decorator pattern to add different ways of printing.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 ![Main menu](https://github.com/cs100/final-project-sspon001/blob/master/images/mainmenu.PNG)
 
 >This is the main menu of the program
 
 ![list print](https://github.com/cs100/final-project-sspon001/blob/master/images/listPrint.PNG)
 
 >An example of the list Print function
 
 ![tree print](https://github.com/cs100/final-project-sspon001/blob/master/images/treePrint.PNG)
 
 >An example of the tree Print function
 
 ![last](https://github.com/cs100/final-project-sspon001/blob/master/images/exportAndValgrind.PNG)

>An example of exporting the directory to a text file, and showing that our program is free of memory leaks
 
 ## Installation/Usage
 Simply type ./main to run the program
 A user can import employees from a file called "outputFile.txt", or add employees directly through the program.
 Once there are employees loaded, the user can view, modify, or remove them.  
 There are a variety of ways the user can view the employees, but it can broken down as the following:
 The user can print all employees in a list, or group them by department.
 For any print, the user can sort the employees by name, salary, or hire date.
 Additionally, the user can sort the employees from Least to Greatest and Greatest to Least
 At any time, the user is able to save the current directory to a text file, outputFile.txt, and load it again for later use.
 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
