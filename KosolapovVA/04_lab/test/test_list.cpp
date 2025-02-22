#include <gtest.h>
#include "list.h"

TEST(test_list, can_create_list)
{
    ASSERT_NO_THROW(List<int> a);
}

TEST(test_list, can_create_copied_list)
{
    List<int> a;
    a.PushBack(8,1);
    ASSERT_NO_THROW(List<int> s(a));
}

TEST(test_list, check_comparison_operator)
{
    List<int> a;
    a.PushBack(8,1);
    List<int> s(a);
    EXPECT_EQ(true, s == a);
}

TEST(test_list, correct_create_copied_list)
{
    List<int> a;
    a.PushBack(8,1);
    List<int> s(a);
    EXPECT_TRUE(a==s);
}
TEST(test_list, can_use_the_assignment_operator)
{
    List<int> a;
    a.PushBack(8, 1);
    List<int> s;
    ASSERT_NO_THROW(s = a);
}
TEST(test_list, correct_use_the_assignment_operator)
{
    List<int> a;
    a.PushBack(8, 1);
    List<int> s;
    s = a;
    EXPECT_TRUE(s == a);
}
TEST(test_list, correct_push_front)
{
    List<int> a;
    a.PushFront(8,1);
    a.PushFront(10,2);
    EXPECT_EQ(10, a.GetFirst());
}

TEST(test_list, correct_push_back)
{
    List<int> a;
    a.PushBack(8,2);
    a.PushBack(10,1);
    EXPECT_EQ(8, a.GetFirst());
}

TEST(test_list, correct_pop_back)
{
    List<int> a;
    a.PushBack(8,1);
    a.PushBack(10,2);
    a.PopBack();
    EXPECT_EQ(8, a.GetFirst());
}

TEST(test_list, correct_pop_front)
{
    List<int> a;
    a.PushBack(8,3);
    a.PushBack(10,1);
    a.PopFront();
    EXPECT_EQ(10, a.GetFirst());
}

TEST(test_list, cant_popback_from_empty_list)
{
    List<int> st;
    ASSERT_ANY_THROW(st.PopBack());
}
TEST(test_list, cant_popfront_from_empty_list)
{
    List<int> st;
    ASSERT_ANY_THROW(st.PopFront());
}
TEST(test_list, correct_get_size)
{
    List<int> a;
    a.PushBack(8,1);
    a.PushBack(10,5);
    EXPECT_EQ(2, a.GetSZ());
}
TEST(test_list, is_empty_false_when_list_no_empty)
{
    List<int> a;
    a.PushBack(8,4);
    a.PushBack(10,5);
    EXPECT_EQ(false, a.IsEmpty());
}
TEST(test_list, is_empty_true_when_list_empty)
{
    List<int> a;
    EXPECT_EQ(true, a.IsEmpty());
}