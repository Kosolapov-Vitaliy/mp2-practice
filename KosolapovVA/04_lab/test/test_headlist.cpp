#include <gtest.h>
#include "headlist.h"

TEST(test_headlist, can_create_list)
{
    ASSERT_NO_THROW(HeadList<int> a);
}

TEST(test_headlist, can_create_copied_list)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    ASSERT_NO_THROW(HeadList<int> s(a));
}

TEST(test_headlist, check_comparison_operator)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    HeadList<int> s(a);
    EXPECT_EQ(true, s == a);
}

TEST(test_headlist, correct_create_copied_list)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    HeadList<int> s(a);
    EXPECT_TRUE(a == s);
}
TEST(test_headlist, can_use_the_assignment_operator)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    HeadList<int> s;
    ASSERT_NO_THROW(s = a);
}
TEST(test_headlist, correct_use_the_assignment_operator)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    HeadList<int> s;
    s = a;
    EXPECT_TRUE(s == a);
}
TEST(test_headlist, correct_push_front)
{
    HeadList<int> a;
    a.PushFront(8, 1);
    a.PushFront(10, 2);
    EXPECT_EQ(10, a.GetFirst());
}

TEST(test_headlist, correct_push_back)
{
    HeadList<int> a;
    a.PushBack(8, 2);
    a.PushBack(10, 1);
    EXPECT_EQ(8, a.GetFirst());
}

TEST(test_headlist, correct_pop_back)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    a.PushBack(10, 2);
    a.PopBack();
    EXPECT_EQ(8, a.GetFirst());
}

TEST(test_headlist, correct_pop_front)
{
    HeadList<int> a;
    a.PushBack(8, 3);
    a.PushBack(10, 1);
    a.PopFront();
    EXPECT_EQ(10, a.GetFirst());
}

TEST(test_headlist, cant_popback_from_empty_list)
{
    HeadList<int> st;
    ASSERT_ANY_THROW(st.PopBack());
}
TEST(test_headlist, cant_popfront_from_empty_list)
{
    HeadList<int> st;
    ASSERT_ANY_THROW(st.PopFront());
}
TEST(test_headlist, correct_get_size)
{
    HeadList<int> a;
    a.PushBack(8, 1);
    a.PushBack(10, 5);
    EXPECT_EQ(2, a.GetSZ());
}
TEST(test_headlist, is_empty_false_when_list_no_empty)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    EXPECT_EQ(false, a.IsEmpty());
}
TEST(test_headlist, is_empty_true_when_list_empty)
{
    HeadList<int> a;
    EXPECT_EQ(true, a.IsEmpty());
}

TEST(test_headlist, correct_get_cur)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    EXPECT_EQ(8, a.GetCurr());
}
TEST(test_headlist, correct_go_next)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    EXPECT_EQ(10, a.GetCurr());
}
TEST(test_headlist, correct_reset)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    a.Reset();
    EXPECT_EQ(8, a.GetCurr());
}
TEST(test_headlist, can_push_after_key)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushAfterKey(10, 10, 4));
}
TEST(test_headlist, cant_push_after_key_when_key_isnot_in_list)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_ANY_THROW(a.PushAfterKey(10, 10, 7));
}
TEST(test_headlist, correct_push_after_key)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PushAfterKey(17, 10, 5);
    a.Next();
    a.Next();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_headlist, can_push_before_key)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushBeforeKey(10, 10, 4));
}
TEST(test_headlist, cant_push_before_key_when_key_isnot_in_list)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_ANY_THROW(a.PushBeforeKey(10, 10, 7));
}
TEST(test_headlist, correct_push_before_key)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PushBeforeKey(17, 10, 4);
    a.Reset();
    EXPECT_EQ(17, a.GetCurr());
}
/*
TEST(test_headlist, can_push_after_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushAfterCurr(10, 10));
}

TEST(test_headlist, correct_push_after_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    a.PushAfterCurr(17, 10);
    a.Next();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_headlist, can_push_before_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushBeforeCurr(10, 10));
}

TEST(test_headlist, correct_push_before_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PushBeforeCurr(17, 10);
    a.Reset();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_headlist, can_pop_after_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PopAftterCurr());
}
TEST(test_headlist, can_pop_before_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    ASSERT_NO_THROW(a.PopBeforeCurr());
}
TEST(test_headlist, correct_pop_after_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PopAftterCurr();
    EXPECT_EQ(nullptr, a.SearchKey(5));
}
TEST(test_headlist, correct_pop_before_curr)
{
    HeadList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    a.PopBeforeCurr();
    EXPECT_EQ(nullptr, a.SearchKey(4));
}
*/
