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
TEST(test_polynom, correct_transform)
{
    std::string ina = "2*x+2*x";
    std::string inb = "4*x";
    Polinom a(ina);
    Polinom b(inb);
    EXPECT_EQ(a, b);
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
    EXPECT_EQ(a - b, res);
}
TEST(test_polynom, correct_sub_operator_hard)
{
    std::string ina = "4*x^2*y*z^3+5*x^3*y*z^2-3*x*y^2+y*z^2-x^3*y";
    std::string inb = "10*x^3*y^3*z^3+4*x^2*y*z^3-2*x^3*y*z^2+x*y*z";
    std::string res = "7*x^3*y*z^2-3*x*y^2+y*z^2-x^3*y-10*x^3*y^3*z^3-x*y*z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    EXPECT_EQ(a - b, res);
}
TEST(test_polynom, correct_sub_const_operator)
{
    std::string ina = "2*x+y";
    std::string res = "2*x+y-5";
    Polinom a(ina);
    Polinom result(res);
    EXPECT_EQ(a - 5, res);
}
TEST(test_polynom, correct_mull_operator)
{
    std::string ina = "2*x+y";
    std::string inb = "2*y+z";
    std::string res = "4*x*y+2*x*z+2*y^2+y*z";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    EXPECT_EQ(a * b, res);
}
TEST(test_polynom, correct_mull_operator_hard)
{
    std::string ina = "x^3*y*z+10*x^4*z^3-5*y^2*z^2";
    std::string inb = "20*x^5-x^2*y^3*z^3";
    std::string res = "20*x^8*y*z-x^5*y^4*z^4+200*x^9*z^3-10*x^6*y^3*z^6-100*x^5*y^2*z^2+5*x^2*y^5*z^5";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    EXPECT_EQ(a * b, res);
}
TEST(test_polynom, correct_mull_on_const_operator)
{
    std::string ina = "2*x+y";
    std::string res = "4*x+2*y";
    Polinom a(ina);
    Polinom result(res);
    EXPECT_EQ(a * 2, res);
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
    EXPECT_EQ(a + b, res);
}
TEST(test_polynom, correct_add_operator_hard)
{
    std::string ina = "4*x^2*y*z^3+5*x^3*y*z^2-3*x*y^2+y*z^2-x^3*y";
    std::string inb = "10*x^3*y^3*z^3+4*x^2*y*z^3-2*x^3*y*z^2+x*y*z";
    std::string res = "5*x^3*y*z^2-3*x*y^2+y*z^2-x^3*y-2*x^3*y*z^2+x*y*z+10*x^3*y^3*z^3+8*x^2*y*z^3";
    Polinom a(ina);
    Polinom b(inb);
    Polinom result(res);
    EXPECT_EQ(a + b, res);
}
TEST(test_polynom, correct_add_const_operator)
{
    std::string ina = "2*x+y";
    std::string res = "2*x+y+5";
    Polinom a(ina);
    Polinom result(res);
    EXPECT_EQ(a + 5, res);
}
TEST(test_polynom, correct_create_copied)
{
    std::string in = "x^2*y^3+2*z^2";
    Polinom a(in);
    Polinom s(a);
    EXPECT_EQ(s, a);
}