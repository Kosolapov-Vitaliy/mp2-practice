#include <gtest.h>
#include "tab_rec.h"

TEST(test_tabrecord, can_create_tabrecord)
{
	int* data=new int[4];
	try
	{
		TabRecord<int, int> tr(10, data);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(test_tabrecord, can_create_copied_tabrecord)
{
	int* data = new int[4];
	TabRecord<int, int> tr1(10, data);
	try
	{
		TabRecord<int, int> tr2(tr1);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}