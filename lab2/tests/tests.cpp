#include <gtest/gtest.h>
#include "../includes/octal.hpp"

TEST(OctalTest, DefaultConstructor) {
    Octal num;
    EXPECT_EQ(num.to_string(), "0");
    EXPECT_EQ(num.get_size(), 0);
}

TEST(OctalTest, SizeValueConstructor) {
    Octal num(3, 5);
    EXPECT_EQ(num.to_string(), "555");
    EXPECT_EQ(num.get_size(), 3);
}

TEST(OctalTest, SizeValueConstructorInvalidDigit) {
    EXPECT_THROW(Octal(3, 8), std::invalid_argument);
}

TEST(OctalTest, InitializerListConstructor) {
    Octal num({1, 2, 3, 4});
    EXPECT_EQ(num.to_string(), "4321");
    EXPECT_EQ(num.get_size(), 4);
}

TEST(OctalTest, InitializerListConstructorInvalidDigit) {
    EXPECT_THROW(Octal({1, 2, 8, 4}), std::invalid_argument);
}

TEST(OctalTest, StringConstructor) {
    Octal num("12345");
    EXPECT_EQ(num.to_string(), "12345");
    EXPECT_EQ(num.get_size(), 5);
}

TEST(OctalTest, StringConstructorInvalidDigit) {
    EXPECT_THROW(Octal("12845"), std::invalid_argument);
}

TEST(OctalTest, StringConstructorEmpty) {
    Octal num("");
    EXPECT_EQ(num.to_string(), "0");
    EXPECT_EQ(num.get_size(), 0);
}

TEST(OctalTest, CopyConstructor) {
    Octal original("12345");
    Octal copy(original);
    EXPECT_EQ(copy.to_string(), "12345");
    EXPECT_EQ(copy.get_size(), 5);
    EXPECT_TRUE(original.equals(copy));
}

TEST(OctalTest, MoveConstructor) {
    Octal original("777");
    Octal moved(std::move(original));
    EXPECT_EQ(moved.to_string(), "777");
    EXPECT_EQ(moved.get_size(), 3);
}

TEST(OctalTest, AddOperation) {
    Octal a("12");
    Octal b("7");
    Octal sum = a.add(b);
    EXPECT_EQ(sum.to_string(), "21");
}

TEST(OctalTest, AddOperationWithCarry) {
    Octal a("777");
    Octal b("1");
    Octal sum = a.add(b);
    EXPECT_EQ(sum.to_string(), "1000");
}

TEST(OctalTest, SubtractOperation) {
    Octal a("12");
    Octal b("7");
    Octal diff = a.subtract(b);
    EXPECT_EQ(diff.to_string(), "3");
}

TEST(OctalTest, SubtractEqualNumbers) {
    Octal a("777");
    Octal b("777");
    Octal diff = a.subtract(b);
    EXPECT_EQ(diff.to_string(), "0");
}

TEST(OctalTest, SubtractLargerFromSmaller) {
    Octal a("7");
    Octal b("12");
    EXPECT_THROW(a.subtract(b), std::invalid_argument);
}

TEST(OctalTest, EqualsComparison) {
    Octal a("123");
    Octal b("123");
    Octal c("124");
    
    EXPECT_TRUE(a.equals(b));
    EXPECT_FALSE(a.equals(c));
}

TEST(OctalTest, LessThanComparison) {
    Octal a("12");
    Octal b("20");
    
    EXPECT_TRUE(a.less_than(b));
    EXPECT_FALSE(b.less_than(a));
}

TEST(OctalTest, GreaterThanComparison) {
    Octal a("20");
    Octal b("12");
    
    EXPECT_TRUE(a.greater_than(b));
    EXPECT_FALSE(b.greater_than(a));
}

TEST(OctalTest, GetDigit) {
    Octal num("123");
    EXPECT_EQ(num.get_digit(0), 3);
    EXPECT_EQ(num.get_digit(1), 2);
    EXPECT_EQ(num.get_digit(2), 1);
}

TEST(OctalTest, GetDigitOutOfRange) {
    Octal num("123");
    EXPECT_THROW(num.get_digit(5), std::out_of_range);
}

TEST(OctalTest, RemoveLeadingZeros) {
    Octal num("00123");
    EXPECT_EQ(num.to_string(), "123");
    EXPECT_EQ(num.get_size(), 3);
}

TEST(OctalTest, RemoveLeadingZerosAllZeros) {
    Octal num("000");
    EXPECT_EQ(num.to_string(), "0");
    EXPECT_EQ(num.get_size(), 1);
}

TEST(OctalTest, CopyMethod) {
    Octal original("4567");
    Octal copy = original.copy();
    EXPECT_EQ(copy.to_string(), "4567");
    EXPECT_TRUE(original.equals(copy));
}

TEST(OctalTest, Immutability) {
    Octal a("12");
    Octal b("7");
    Octal sum = a.add(b);
    Octal diff = a.subtract(b);
    
    EXPECT_EQ(a.to_string(), "12");
    EXPECT_EQ(b.to_string(), "7");
}

TEST(OctalTest, LargeNumbers) {
    Octal a("7777777");
    Octal b("1");
    Octal sum = a.add(b);
    EXPECT_EQ(sum.to_string(), "10000000");
}