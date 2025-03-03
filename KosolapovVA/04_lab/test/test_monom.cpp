#include <gtest.h>
#include "monom.h"

TEST(test_monom, can_create_monom)
{
    ASSERT_NO_THROW(Monom a);
}
TEST(test_monom, can_create_monom_with_correct_parametr)
{
    ASSERT_NO_THROW(Monom a(10,250));
}
TEST(test_monom, cant_create_monom_with_incorrect_parametr)
{
    ASSERT_ANY_THROW(Monom a(10, 1050));
}
TEST(test_monom, can_create_copied)
{
    Monom a(10, 250);
    ASSERT_NO_THROW(Monom s(a));
}
TEST(test_monom, correct_create_copied)
{
    Monom a(10, 250);
    Monom s(a);
    EXPECT_EQ(s, a);
}
TEST(test_monom, correct_add_operator)
{
    Monom a(10, 250);
    Monom b(5, 250);
    Monom res(15, 250);
    EXPECT_EQ(a + b, res);
}
TEST(test_monom, correct_sub_operator)
{
    Monom a(10, 250);
    Monom b(5, 250);
    Monom res(5, 250);
    EXPECT_EQ(a - b, res);
}
TEST(test_monom, correct_mull_operator)
{
    Monom a(10, 120);
    Monom b(5, 250);
    Monom res(50, 370);
    EXPECT_EQ(a * b, res);
}
TEST(test_monom, correct_calculate_monom)
{
    Monom a(10, 120);
    EXPECT_EQ(a.Calculate(1, 1, 1), 10);
}