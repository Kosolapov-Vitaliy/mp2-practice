#include "arrayhashtable.h"

#include <gtest.h>

// ++

TEST(ArrayHashTable, can_create_ArrayHashTable) {
	try
	{
		ArrayHashTable<int, int> st2(10, 2);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}

	// ïðîñòî íàïèñàòü 
	// ASSERT_NO_THROW(TabRecord<int, int> tr(1, data));
	// íå ïîëó÷àåòñÿ 
	// (îñîáåííîñòü gtest, òàì ïðîèñõîäèò íåÿâíîå
	// ïðèâåäåíèå è êîìïèëÿòîð ìîæåò íå ïîíÿòü)
	//
}

TEST(ArrayHashTable, can_find) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Find(1));
}


TEST(ArrayHashTable, can_find_existing_elem) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(ArrayHashTable, cant_find_not_existing_elem) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_TRUE(sc.Find(11) == nullptr);
}


TEST(ArrayHashTable, can_insert) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	ASSERT_NO_THROW(sc.Insert(add1));
}

TEST(ArrayHashTable, cant_insert_in_full_ArrayHashTable) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_ANY_THROW(sc.Insert(add3));
}

TEST(ArrayHashTable, can_remove_existing_key) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Remove(1));
}


TEST(ArrayHashTable, cant_remove_not_existing_key) {
	ArrayHashTable<int, int> sc(2, 2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_ANY_THROW(sc.Remove(2));
}



// Additional hard-tests


TEST(ArrayHashTable, can_insert_after_removing) {
	ArrayHashTable<int, int> sc(2, 3);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(6, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	sc.Remove(5);
	ASSERT_NO_THROW(sc.Insert(add3));
}

TEST(ArrayHashTable, can_remove_after_insert_when_keys_has_same_hash) {
	ArrayHashTable<int, int> sc(5, 3);
	// hash:   currID = key % this->maxsz;
	// hash2: (currID + hashstep) % maxsz;

	for (int i = 0; i < 5; i++) {
		sc.Insert(new TabRecord<int, int>(1 + i * 5, nullptr));
	}
	ASSERT_NO_THROW(sc.Remove(1 + 4 * 5));
}

TEST(ArrayHashTable, insertion_removing_mix_when_keys_has_same_hash) {
	ArrayHashTable<int, int> sc(5, 3);
	sc.Insert(new TabRecord<int, int>(1 + 1 * 5, nullptr)); // 6
	sc.Insert(new TabRecord<int, int>(1 + 2 * 5, nullptr)); // 6 11
	sc.Remove(1 + 1 * 5);  // 11
	sc.Insert(new TabRecord<int, int>(1 + 3 * 5, nullptr)); // 11 16
	sc.Insert(new TabRecord<int, int>(1 + 4 * 5, nullptr)); // 11 16 21
	sc.Remove(1 + 3 * 5); // 11 21
	sc.Remove(1 + 2 * 5); // 21
	sc.Insert(new TabRecord<int, int>(1 + 5 * 5, nullptr)); // 21 26
	sc.Remove(1 + 5 * 5); // 21
	ASSERT_NO_THROW(sc.Remove(21));
}

TEST(ArrayHashTable, insertion_removing_mix) {
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