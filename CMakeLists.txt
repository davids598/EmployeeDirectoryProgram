CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
	main.cpp
	src/Date.cpp
	src/Employee.cpp
	src/employeeDirectory.cpp
	src/Printer.cpp
)

TARGET_LINK_LIBRARIES(main gtest)
TARGET_COMPILE_DEFINITIONS(main PRIVATE gtest_disable_pthreads=ON)
