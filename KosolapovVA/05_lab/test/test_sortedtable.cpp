#include <gtest.h>
#include "sortedtable.h"

TEST(test_sortedtable, can_create_scantable_with_correct_maxsz)
{
	try
	{
		SortedTable<int, int> sc(10);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_sortedtable, cant_create_scantable_with_incorrect_maxsz)
{
	try
	{
		SortedTable<int, int> sc(-1);
		ADD_FAILURE();
	}
	catch (const std::exception&)
	{
		ASSERT_NO_THROW();
	}
}

TEST(test_sortedtable, can_create_copied_sortedtable)
{
	SortedTable<int, int> sc1(10);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc1.Insert(tr1);
	sc1.Insert(tr2);
	try
	{
		SortedTable<int, int> sc2(sc1);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_sortedtable, can_create_copied_scantable)
{
	ScanTable<int, int> sc1(10);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc1.Insert(tr1);
	sc1.Insert(tr2);
	try
	{
		SortedTable<int, int> sc2(sc1);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_sortedtable, can_find)
{
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(test_sortedtable, cant_find_nonexistent_element)
{
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	EXPECT_TRUE(sc.Find(5) == nullptr);
}

TEST(test_sortedtable, can_remove)
{
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	ASSERT_NO_THROW(sc.Remove(1));
}

TEST(test_sortedtable, cant_remove_nonexistent_element)
{
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	ASSERT_ANY_THROW(sc.Remove(3));
}

TEST(test_sortedtable, can_insert)
{
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	ASSERT_NO_THROW(sc.Insert(tr2));
}

TEST(test_sortedtable, cant_insert_in_full_table)
{
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* tr3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	ASSERT_ANY_THROW(sc.Insert(tr3));
}