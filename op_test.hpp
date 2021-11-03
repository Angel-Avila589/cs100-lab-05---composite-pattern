#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"

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
#endif //__OP_TEST_HPP__
