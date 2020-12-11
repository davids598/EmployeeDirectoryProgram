#ifndef __TESTEMPLOYEE__
#define __TESTEMPLOYEE__

#include "gtest/gtest.h"
#include "header.h"

TEST(employeeTestSuite, defaultConstructor) {
    Employee* temp = new Employee();
    std::string tempOutput = temp->getName();
    EXPECT_EQ(tempOutput, " ");
}

#endif
