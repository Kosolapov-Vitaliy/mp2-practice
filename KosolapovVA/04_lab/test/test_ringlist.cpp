#include <gtest.h>
#include "ringlist.h"

TEST(test_ringlist, can_create_list)
{
    ASSERT_NO_THROW(RingList<int> a);
}


TEST(test_ringlist, can_create_copied_list)
{
    RingList<int> a;    
    a.PushFront(2, 1);
    ASSERT_NO_THROW(RingList<int> s(a));
}
TEST(test_ringlist, check_comparison_operator)
{
    RingList<int> a;
    a.PushBack(8, 1);
    RingList<int> s(a);
    EXPECT_EQ(true, s == a);
}

TEST(test_ringlist, correct_create_copied_list)
{
    RingList<int> a;
    a.PushBack(8, 1);
    RingList<int> s(a);
    EXPECT_TRUE(a == s);
}
TEST(test_ringlist, can_use_the_assignment_operator)
{
    RingList<int> a;
    a.PushBack(8, 1);
    RingList<int> s;
    ASSERT_NO_THROW(s = a);
}
TEST(test_ringlist, correct_use_the_assignment_operator)
{
    RingList<int> a;
    a.PushBack(8, 1);
    RingList<int> s;
    s = a;
    EXPECT_TRUE(s == a);
}
TEST(test_ringlist, correct_push_front)
{
    RingList<int> a;
    a.PushFront(8, 1);
    a.PushFront(10, 2);
    EXPECT_EQ(10, a.GetFirst());
}

TEST(test_ringlist, correct_push_back)
{
    RingList<int> a;
    a.PushBack(8, 2);
    a.PushBack(10, 1);
    EXPECT_EQ(8, a.GetFirst());
}

TEST(test_ringlist, correct_pop_back)
{
    RingList<int> a;
    a.PushBack(8, 1);
    a.PushBack(10, 2);
    a.PopBack();
    EXPECT_EQ(8, a.GetFirst());
}

TEST(test_ringlist, correct_pop_front)
{
    RingList<int> a;
    a.PushBack(8, 3);
    a.PushBack(10, 1);
    a.PopFront();
    EXPECT_EQ(10, a.GetFirst());
}

TEST(test_ringlist, cant_popback_from_empty_list)
{
    RingList<int> st;
    ASSERT_ANY_THROW(st.PopBack());
}
TEST(test_ringlist, cant_popfront_from_empty_list)
{
    RingList<int> st;
    ASSERT_ANY_THROW(st.PopFront());
}
TEST(test_ringlist, correct_get_size)
{
    RingList<int> a;
    a.PushBack(8, 1);
    a.PushBack(10, 5);
    EXPECT_EQ(2, a.GetSZ());
}
TEST(test_ringlist, is_empty_false_when_list_no_empty)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    EXPECT_EQ(false, a.IsEmpty());
}
TEST(test_ringlist, is_empty_true_when_list_empty)
{
    RingList<int> a;
    EXPECT_EQ(true, a.IsEmpty());
}

TEST(test_ringlist, correct_search_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    //EXPECT_EQ(10, a.SearchKey(5));
}
TEST(test_ringlist, checkkey_true_when_key_in_list)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    EXPECT_EQ(true, a.CheckKey(5));
}
TEST(test_ringlist, checkkey_false_when_key_isnot_in_list)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    EXPECT_EQ(false, a.CheckKey(7));
}
TEST(test_ringlist, correct_get_cur)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    EXPECT_EQ(8, a.GetCurr());
}
TEST(test_ringlist, correct_go_next)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    EXPECT_EQ(10, a.GetCurr());
}
TEST(test_ringlist, correct_reset)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    a.Reset();
    EXPECT_EQ(8, a.GetCurr());
}
TEST(test_ringlist, can_push_after_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushAfterKey(10, 10, 4));
}
TEST(test_ringlist, cant_push_after_key_when_key_isnot_in_list)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_ANY_THROW(a.PushAfterKey(10, 10, 7));
}
TEST(test_ringlist, correct_push_after_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PushAfterKey(17, 10, 5);
    a.Next();
    a.Next();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_ringlist, can_push_before_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushBeforeKey(10, 10, 4));
}
TEST(test_ringlist, cant_push_before_key_when_key_isnot_in_list)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_ANY_THROW(a.PushBeforeKey(10, 10, 7));
}
TEST(test_ringlist, correct_push_before_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PushBeforeKey(17, 10, 4);
    a.Reset();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_ringlist, can_pop_after_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PopAftterKey(4));
}
TEST(test_ringlist, can_pop_before_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PopBeforeKey(5));
}
TEST(test_ringlist, cant_pop_after_key_when_key_isnt_inlist)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_ANY_THROW(a.PopAftterKey(8));
}
TEST(test_ringlist, cant_pop_before_key_when_key_isnt_inlist)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_ANY_THROW(a.PopBeforeKey(8));
}
TEST(test_ringlist, correct_pop_after_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PopAftterKey(4);
    EXPECT_EQ(false, a.CheckKey(5));
}
TEST(test_ringlist, correct_pop_before_key)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PopBeforeKey(5);
    EXPECT_EQ(false, a.CheckKey(4));
}
TEST(test_ringlist, can_push_after_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushAfterCurr(10, 10));
}

TEST(test_ringlist, correct_push_after_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    a.PushAfterCurr(17, 10);
    a.Next();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_ringlist, can_push_before_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PushBeforeCurr(10, 10));
}

TEST(test_ringlist, correct_push_before_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PushBeforeCurr(17, 10);
    a.Reset();
    EXPECT_EQ(17, a.GetCurr());
}
TEST(test_ringlist, can_pop_after_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    ASSERT_NO_THROW(a.PopAftterCurr());
}
TEST(test_ringlist, can_pop_before_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    ASSERT_NO_THROW(a.PopBeforeCurr());
}
TEST(test_ringlist, correct_pop_after_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.PopAftterCurr();
    EXPECT_EQ(false, a.CheckKey(5));
}
TEST(test_ringlist, correct_pop_before_curr)
{
    RingList<int> a;
    a.PushBack(8, 4);
    a.PushBack(10, 5);
    a.Next();
    a.PopBeforeCurr();
    EXPECT_EQ(false, a.CheckKey(4));
}
