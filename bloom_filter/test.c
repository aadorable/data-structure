#define _CRT_SECURE_NO_WARNINGS 1

#include "bloom_filter.h"

#include <stdio.h>
#include <windows.h>

#define TEST_HEADER printf("\n=================================%s=============================\n",__FUNCTION__)

void TestBloomFilter()
{
	TEST_HEADER;
	BloomFilter bloom_filter;
	BloomFilterInit(&bloom_filter);
	BloomFilterInsert(&bloom_filter, "hello");
	int ret = BloomFilterIsExist(&bloom_filter, "hello");
	printf("ret expect 1, actual %d\n", ret);
}

int main()
{
	TestBloomFilter();
	system("pause");
	return 0;
}