#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v(10);
  TDynamicVector<int> v1(v);
  int res;
  res = (v == v1);
  EXPECT_EQ(1, res);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
   TDynamicVector<int> v(10);
   TDynamicVector<int> v1(v);
   int res;
   res = (&v != &v1);
   EXPECT_EQ(1, res);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(5);
  ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> v(5);
  ASSERT_ANY_THROW(v.at(10));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v1(3), v2(4);
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    const int size = 4;
    TDynamicVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    const int size =4;
    TDynamicVector<int> v1(3), v2(size);
    v1 = v2;
    EXPECT_EQ(v1.size(), size);
  ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v1(3), v2(4);
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}
