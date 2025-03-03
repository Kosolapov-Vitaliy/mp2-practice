#include <gtest.h>
#include "polinom.h"

TEST(test_polynom, can_create_polynom)
{
    ASSERT_NO_THROW(Polinom a);
}
TEST(test_polynom, can_create_polynom_with_correct_parametr)
{
    std::string in = "x^2*y^3+2*z^2";
    ASSERT_NO_THROW(Polinom a(in));
}
TEST(test_polynom, cant_create_polynom_with_incorrect_parametr)
{
    std::string in = "2^2*y^x+2z^2";
    ASSERT_ANY_THROW(Polinom a(in));
}
TEST(test_polynom, can_create_copied)
{
    std::string in = "x^2*y^3+2*z^2";
    Polinom a(in);
    ASSERT_NO_THROW(Polinom s(a));
}

TEST(test_polynom, correct_sub_operator)
{
    std::string ina = "2*x+y";
    std::string inb = "2*y+z";
    std::string res = "2*x-y-z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    Polinom s = a - b;
    EXPECT_EQ((a-b) == res, true);
}
TEST(test_polynom, correct_mull_operator)
{
    std::string ina = "2*x+y";
    std::string inb = "2*y+z";
    std::string res = "4*x*y+2*x*z+2*y^2+y*z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    EXPECT_EQ((a * b)==res, true);
}
TEST(test_polynom, correct_calculate_polynom)
{
    std::string res = "4*x*y+2*x*z+2*y^2+y*z";
    Polinom result(res);
    EXPECT_EQ(result.Calculate(1, 2, 3), 28);
}
TEST(test_polynom, correct_add_operator)
{
    std::string ina = "2*x+y";
    std::string inb = "2*y+z";
    std::string res = "2*x+3*y+z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    EXPECT_EQ((a + b)==res, true);
}
TEST(test_polynom, correct_create_copied)
{
    std::string in = "x^2*y^3+2*z^2";
    Polinom a(in);
    Polinom s(a);
    EXPECT_EQ(s==a,true);
}