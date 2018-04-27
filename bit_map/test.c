#define _CRT_SECURE_NO_WARNINGS 1

#include "bit_map.h"

#include <stdio.h>
#include <windows.h>

#define TEST_HEADER printf("\n\n=======================%s=======================\n",__FUNCTION__)

void TestInit()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 65);
	printf("bm->capacity expect 65,actual %lu\n", bm.capacity);
	size_t size = bm.capacity / (sizeof(uint64_t)* 8) + 1;
	printf("size expect 2,actual %lu\n", size);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}
}

void TestSet()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 127);
	BitMapSet(&bm, 63);

	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}
}

void TestUnset()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 127);
	BitMapSet(&bm, 63);
	BitMapUnset(&bm, 63);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}
}

void TestBitMapTest()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 127);
	BitMapSet(&bm, 63);

	int ret = BitMapTest(&bm, 63);
	printf("ret expect 1,actual %d\n", ret);

	BitMapUnset(&bm, 63);
	ret = BitMapTest(&bm, 63);
	printf("ret expect 0,actual %d", ret);
}

void TestClear()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 127);

	BitMapSet(&bm, 63);
	BitMapSet(&bm, 1);
	BitMapSet(&bm, 2);
	BitMapSet(&bm, 64);
	BitMapSet(&bm, 65);
	BitMapSet(&bm, 31);

	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}

	printf("\n");
	BitMapClear(&bm);
	for (i = 0; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}
}

void TestFill()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 127);

	BitMapFill(&bm);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}
}

void TestDestroy()
{
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 127);
	BitMapSet(&bm, 63);

	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8) + 1; ++i)
	{
		printf("[%lu]£º%lx  ", i, bm.data[i]);
	}

	printf("\n");
	printf("[Ïú»Ùºó]£º\n");

	BitMapDestroy(&bm);
	printf("bm->capacity expect 0, actual %lu\n", bm.capacity);
	printf("bm->data expect NULL, actual %p\n", bm.data);
}

int main()
{
	TestInit();
	TestSet();
	TestUnset();
	TestBitMapTest();
	TestClear();
	TestFill();
	TestDestroy();
	system("pause");
	return 0;
}