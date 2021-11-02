#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero){
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegative){
    Op* test = new Op(-1);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(OpTest, OpEvaluateDecimal){
    Op* test = new Op(1.334);
    EXPECT_EQ(test->evaluate(), 1.334);
}

TEST(OpTest, OpEvaluateNegativeDecimal){
    Op* test = new Op(-2.11899);
    EXPECT_EQ(test->evaluate(), -2.11899);
}

TEST(OpTest, OpStringifyZero){
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0.000000");    
}

TEST(OpTest, OpStringifyNonZero){
    Op* test = new Op(9);
    EXPECT_EQ(test->stringify(), "9.000000");
}

TEST(OpTest, OpStringifyDecimal) {
    Op* test = new Op(7.1123);
    EXPECT_EQ(test->stringify(), "7.112300");
}

TEST(OpTest, OpStringifyNegative){
    Op* test = new Op(-3);
    EXPECT_EQ(test->stringify(), "-3.000000");
}

TEST(OpTest, OpStringifyNegativeDec){
    Op* test = new Op(-3.444419);
    EXPECT_EQ(test->stringify(), "-3.444419");
}



#endif //__OP_TEST_HPP__
