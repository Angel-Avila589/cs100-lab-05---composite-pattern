#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "add.hpp"

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

//Below are the tests for the Add class
TEST(AddTest, AddInt){
     Base* three = new Op(3);
     Base* four = new Op(4);
     Base* test = new Add(three, four);
     EXPECT_EQ(test->evaluate(), 7);
     EXPECT_EQ(test->stringify(), "(3.000000 + 4.000000)");
}

TEST(AddTest, AddDec){
     Base* four = new Op(4.123);
     Base* five = new Op(5.523);
     Base* test = new Add(four, five);
     EXPECT_EQ(test->evaluate(), 9.646);
     EXPECT_EQ(test->stringify(), "(4.123000 + 5.523000)");
}
 

TEST(AddTest, AddZero){
    Base* zero = new Op(0);
    Base* thirteen = new Op(13);
    Base* test = new Add(zero, thirteen);
    EXPECT_EQ(test->evaluate(), 13);
    EXPECT_EQ(test->stringify(), "(0.000000 + 13.000000)");
}

TEST(AddTest, AddNeg){
     Base* negTwo = new Op(-2);
     Base* negEleven = new Op(-11);
     Base* test = new Add(negTwo, negEleven);
     EXPECT_EQ(test->evaluate(), -13);
     EXPECT_EQ(test->stringify(), "(-2.000000 + -11.000000)");
}

TEST(AddTest, AddPosNeg){
     Base* nine = new Op(9);
     Base* negFifteen = new Op(-15);
     Base* test = new Add(nine, negFifteen);
     EXPECT_EQ(test->evaluate(), -6);
     EXPECT_EQ(test->stringify(), "(9.000000 + -15.000000)");
}

TEST(AddTest, AddNegPos){
     Base* neg_one = new Op(-1);
     Base* five = new Op(5);
     Base* test = new Add(neg_one, five);
     EXPECT_EQ(test->evaluate(), 4);
     EXPECT_EQ(test-> stringify(), "(-1.000000 + 5.000000)");
}

TEST(AddTest, DecAddNegPos){
    Base* first = new Op(-2.5);
    Base* second = new Op(5.0);
    Base* test = new Add(first, second);
    EXPECT_EQ(test->evaluate(), 2.5);
    EXPECT_EQ(test->stringify(), "(-2.500000 + 5.000000)");
}

TEST(AddTest, DecAddPosPos){
    Base* first = new Op(8.0);
    Base* second = new Op(11.8);
    Base* test = new Add(first, second);
    EXPECT_EQ(test->evaluate(), 19.8);
    EXPECT_EQ(test->stringify(), "(8.000000 + 11.800000)");
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

//Below are the tests for the Sub class
TEST(SubTest, SubNonZero){
    Base* num1 = new Op(7);
    Base* num2 = new Op(3);
    Base* num3 = new Sub(num1, num2);
    EXPECT_EQ(num3->evaluate(), 4);
    EXPECT_EQ(num3->stringify(), "(7.000000 - 3.000000)");
}

TEST(SubTest, SubNegativeNum){
    Base* num1 = new Op(9);
    Base* num2 = new Op(-3);
    Base* num3 = new Sub(num1, num2);
    EXPECT_EQ(num3->evaluate(), 12);
    EXPECT_EQ(num3->stringify(), "(9.000000 - -3.000000)");
}

TEST(SubTest, MulSub){
    Base* num1 = new Op(9);
    Base* num2 = new Op(3);
    Base* num3 = new Op(5);
    Base* mult = new Mult(num1, num2);
    Base* minus = new Sub(mult, num3);
    EXPECT_EQ(minus->evaluate(), 22);
    EXPECT_EQ(minus->stringify(), "((9.000000 * 3.000000) - 5.000000)");
}
 
//Below is the test for the Rand class
TEST(RandTest, RandomNumber){
    Base* num1 = new Rand();
    EXPECT_NEAR(0, num1->evaluate(), 100);
}

//Below are the tests for the Pow class
TEST(PowTest, PowNonZero){
    Base* num1 = new Op(2);
    Base* num2 = new Op(3);
    Base* power = new Pow(num1, num2);
    EXPECT_EQ(power->evaluate(), 8);
    EXPECT_EQ(power->stringify(), "(2.000000 ** 3.000000)");
} 

TEST(PowTest, PowNegativePower){
    Base* num1 = new Op(4);
    Base* num2 = new Op(-3);
    Base* power = new Pow(num1, num2);
    EXPECT_EQ(power->evaluate(), 0.015625);
    EXPECT_EQ(power->stringify(), "(4.000000 ** -3.000000)");
}

TEST(PowTest, PowMultSub){
    Base* num1 = new Op(5);
    Base* num2 = new Op(3);
    Base* num3 = new Op(4);
    Base* num4 = new Op(2);
    Base* mul = new Mult(num1, num2);
    Base* minus = new Sub(mul, num3);
    Base* power = new Pow(minus, num4);
    EXPECT_EQ(power->evaluate(), 121);
    EXPECT_EQ(power->stringify(), "(((5.000000 * 3.000000) - 4.000000) ** 2.000000)");
}

//Below are the tests for the Div class
TEST(DivTest, DivNonZero){
    Base* num1 = new Op(5.4);
    Base* num2 = new Op(2);
    Base* divide = new Div(num1, num2);
    EXPECT_EQ(divide->evaluate(), 2.7);
    EXPECT_EQ(divide->stringify(), "(5.400000 / 2.000000)");
}

TEST(DivTest, DivZeroDenominator){
    Base* num1 = new Op(8);
    Base* num2 = new Op(0);
    Base* divide = new Div(num1, num2);
    ASSERT_EXIT(divide->evaluate(), ::testing::ExitedWithCode(1), "Error Zero Denominator");
    EXPECT_EQ(divide->stringify(), "(8.000000 / 0.000000)");
}

TEST(DivTest, DivSubMulPow){
    Base* num1 = new Op(3);
    Base* num2 = new Op(3);
    Base* num3 = new Op(7);
    Base* num4 = new Op(4);
    Base* num5 = new Op(5);
    Base* power = new Pow(num1, num2);
    Base* minus = new Sub(power, num3);
    Base* multi = new Mult(minus, num4);
    Base* divide = new Div(multi, num5);
    EXPECT_EQ(divide->evaluate(), 16);
    EXPECT_EQ(divide->stringify(), "((((3.000000 ** 3.000000) - 7.000000) * 4.000000) / 5.000000)");
}
#endif //__OP_TEST_HPP__
