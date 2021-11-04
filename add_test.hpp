#include "gtest/gtest.h"

#include "add.hpp"

TEST(AddTest, AddEvaluateInteger) {
     Add* test = new Add(3, 4);
     EXPECT_EQ(test->evaluate(), 12);
}
