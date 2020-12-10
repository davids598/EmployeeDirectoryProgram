CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
	main.cpp
	src/Date.cpp
	src/Employee.cpp
	src/employeeDirectory.cpp
	src/Printer.cpp
	src/Interface.cpp
)
ADD_EXECUTABLE(test
	test.cpp
	src/Date.cpp
	src/Employee.cpp
	src/employeeDirectory.cpp
	src/Printer.cpp
	src/Interface.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
