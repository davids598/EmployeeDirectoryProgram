CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
	main.cpp
	header.h
	src/Employee.cpp
	src/Printer.cpp
	src/employeeDirectory.cpp
	src/Date.cpp
	header/Date.hpp
	header/Employee.hpp
	header/employeeDirectory.hpp
)

TARGET_LINK_LIBRARIES(main gtest)
TARGET_COMPILE_DEFINITIONS(main PRIVATE gtest_disable_pthreads=ON)
