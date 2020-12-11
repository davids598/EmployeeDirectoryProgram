#include "gtest/gtest.h"

#include "test.hpp"
#include "testEmployee.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
