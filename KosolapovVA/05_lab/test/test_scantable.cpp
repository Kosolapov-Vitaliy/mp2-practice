#include <gtest.h>
#include "scantable.h"

TEST(test_scantable, can_create_scantable_with_correct_maxsz)
{
	try
	{
		ScanTable<int, int> sc(10);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_scantable, cant_create_scantable_with_incorrect_maxsz)
{
	try
	{
		ScanTable<int, int> sc(-1);
		ADD_FAILURE();
	}
	catch (const std::exception&)
	{
		ASSERT_NO_THROW();
	}
}

TEST(test_scantable, can_create_copied_scantable)
{
	ScanTable<int, int> sc1(10);
	try
	{
		ScanTable<int, int> sc2(sc1);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_scantable, can_find)
{
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	EXPECT_FALSE(sc.Find(1)==nullptr);
}

TEST(test_scantable, cant_find_nonexistent_element)
{
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	EXPECT_TRUE(sc.Find(5)==nullptr);
}

TEST(test_scantable, can_remove)
{
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	ASSERT_NO_THROW(sc.Remove(1));
}

TEST(test_scantable, cant_remove_nonexistent_element)
{
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	ASSERT_ANY_THROW(sc.Remove(3));
}

TEST(test_scantable, can_insert)
{
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	sc.Insert(tr1);
	ASSERT_NO_THROW(sc.Insert(tr2));
}

TEST(test_scantable, cant_insert_in_full_table)
{
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* tr1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* tr2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* tr3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(tr1);
	sc.Insert(tr2);
	ASSERT_ANY_THROW(sc.Insert(tr3));
}
