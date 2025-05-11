#include <gtest.h>
#include "arrayhashtable.h"

TEST(test_arrayhashtable, can_create_arrayhashtable)
{
	try
	{
		ArrayHashTable<int, int> st2(10, 2);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_arrayhashtable, can_find) 
{
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(test_arrayhashtable, cant_find_notexist_elem)
{
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_TRUE(sc.Find(11) == nullptr);
}


TEST(test_arrayhashtable, can_insert)
{
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	ASSERT_NO_THROW(sc.Insert(add1));
}

TEST(test_arrayhashtable, cant_insert_in_full_arrayhashtable)
{
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_ANY_THROW(sc.Insert(add3));
}

TEST(test_arrayhashtable, can_remove)
{
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Remove(1));
}


TEST(test_arrayhashtable, cant_remove_nonexist_key)
{
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_ANY_THROW(sc.Remove(2));
}


TEST(test_arrayhashtable, can_insert_after_removing)
{
	ArrayHashTable<int, int> sc(2, 3);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(6, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	sc.Remove(5);
	ASSERT_NO_THROW(sc.Insert(add3));
}

TEST(test_arrayhashtable, can_remove_after_insert_when_keys_has_same_hash)
{
	ArrayHashTable<int, int> sc(5, 3);
	for (int i = 0; i < 5; i++) {
		sc.Insert(new TabRecord<int, int>(1 + i * 5, nullptr));
	}
	ASSERT_NO_THROW(sc.Remove(1 + 4 * 5));
}

TEST(test_arrayhashtable, insertion_removing_mix_when_keys_has_same_hash)
{
	ArrayHashTable<int, int> sc(5, 3);
	sc.Insert(new TabRecord<int, int>(1 + 1 * 5, nullptr));
	sc.Insert(new TabRecord<int, int>(1 + 2 * 5, nullptr)); 
	sc.Remove(1 + 1 * 5);  
	sc.Insert(new TabRecord<int, int>(1 + 3 * 5, nullptr)); 
	sc.Insert(new TabRecord<int, int>(1 + 4 * 5, nullptr)); 
	sc.Remove(1 + 3 * 5); 
	sc.Remove(1 + 2 * 5); 
	sc.Insert(new TabRecord<int, int>(1 + 5 * 5, nullptr)); 
	sc.Remove(1 + 5 * 5);
	ASSERT_NO_THROW(sc.Remove(21));
}

TEST(test_arrayhashtable, insertion_removing_mix)
{
	ArrayHashTable<int, int> sc(5, 3);
	sc.Insert(new TabRecord<int, int>(1, nullptr));
	sc.Insert(new TabRecord<int, int>(6, nullptr));
	sc.Remove(1);
	sc.Insert(new TabRecord<int, int>(11, nullptr));
	sc.Insert(new TabRecord<int, int>(7, nullptr));
	sc.Remove(6);
	sc.Remove(7);
	sc.Insert(new TabRecord<int, int>(14, nullptr));
	sc.Remove(14);
	ASSERT_NO_THROW(sc.Remove(11));
}