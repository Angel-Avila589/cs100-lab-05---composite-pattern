#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "mult.hpp"

//Below are the tests for the Op class
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

//Below are the tests for the Mult class
TEST(MultTest, MultEvaluateNonZero){
    Base* num1 = new Op(5);
    Base* num2 = new Op(3);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->evaluate(), 15);
}

TEST(MultTest, MultStringifyNonZero){
    Base* num1 = new Op(7);
    Base* num2 = new Op(4);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->stringify(), "(7.000000 * 4.000000)");
}

TEST(MultTest, MultEvaluateZero){
    Base* num1 = new Op(0);
    Base* num2 = new Op(0);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->evaluate(), 0);
}

TEST(MultTest, MultStringifyZero){
    Base* num1 = new Op(0);
    Base* num2 = new Op(0);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->stringify(), "(0.000000 * 0.000000)");
}

TEST(MultTest, MultEvaluateNegative){
    Base* num1 = new Op(-5);
    Base* num2 = new Op(2);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->evaluate(), -10);
}

TEST(MultTest, MultStringifyNegative){
    Base* num1 = new Op(-8);
    Base* num2 = new Op(15);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->stringify(), "(-8.000000 * 15.000000)");
}

TEST(MultTest, MultEvaluateNegatives){
    Base* num1 = new Op(-2);
    Base* num2 = new Op(-9);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->evaluate(), 18);
}

TEST(MultTest, MultStringifyNegatives){
    Base* num1 = new Op(-6);
    Base* num2 = new Op(-3);
    Base* num3 = new Mult(num1, num2);
    EXPECT_EQ(num3->stringify(), "(-6.000000 * -3.000000)");
}
#endif //__OP_TEST_HPP__
