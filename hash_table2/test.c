#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"

#include <stdio.h>
#include <windows.h>

#define TEST_HEADER printf("\n=========================%s=====================\n",__FUNCTION__)

size_t HashFuncDefault(KeyType key)
{
	return key % HashMaxSize;
}

void HashPrintChar(HashTable* ht, const char* msg)
{
	printf("[%s]��\n", msg);
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		if (ht->data[i] == NULL)
		{
			continue;
		}
		printf("[%lu] ", i);
		HashElem* cur = ht->data[i];
		for (; cur != NULL; cur = cur->next)
		{
			printf("%d:%d  ", cur->key, cur->value);
		}
		printf("\n");
	}
}

void TestInit()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	printf("ht->size expect 0,actual %lu\n", ht.size);
	printf("ht->hash_func expect %p,actual %p\n", HashFuncDefault, ht.hash_func);
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		if (ht.data[i] != NULL)
		{
			printf("ht->data[%iu] error��", i);
		}
	}
}

void TestInsert()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1003, 500);
	HashPrintChar(&ht, "����5��Ԫ��");
}

void TestFind()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	int ret = 0;
	int value = 0;
	ret = HashFind(&ht, 1, &value);
	printf("����1��ret expect 0,actual %d\n", ret);

	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1003, 500);
	HashPrintChar(&ht, "����5��Ԫ��");

	ret = HashFind(&ht, 1, &value);
	printf("����1��value expect 100,actual %d\n", value);

	ret = HashFind(&ht, 1002, &value);
	printf("����1002��value expect 400,actual %d\n", value);
}

void TestRemove()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1003, 500);
	HashPrintChar(&ht, "����5��Ԫ��");

	HashRemove(&ht, 2);
	int ret = 0;
	int value = 0;
	ret = HashFind(&ht, 2, &value);
	printf("ɾ��2��ret expect 0,actual %d\n", ret);

	ret = HashFind(&ht, 1, &value);
	printf("����1��ret expect 1,actual %d\n", ret);

	HashRemove(&ht, 1);
	ret = HashFind(&ht, 1, &value);
	printf("ɾ��1��ret expect 0,actual %d\n", ret);
}

void TestSize()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	size_t ret = HashSize(&ht);
	printf("ret expect 0,actual %lu\n", ret);

	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1003, 500);
	HashPrintChar(&ht, "����5��Ԫ��");
	ret = HashSize(&ht);
	printf("ret expect 5,actual %lu\n", ret);
}

void TestEmpty()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	int ret = HashEmpty(&ht);
	printf("ret expect 1,actual %lu\n", ret);

	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1003, 500);
	HashPrintChar(&ht, "����5��Ԫ��");
	ret = HashEmpty(&ht);
	printf("ret expect 0,actual %lu\n", ret);
}

void TestDestroy()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1003, 500);
	HashPrintChar(&ht, "����5��Ԫ��");

	HashDestroy(&ht);
	printf("ht->size = %lu\n", ht.size);
}

int main()
{
	TestInit();
	TestInsert();
	TestFind();
	TestRemove();
	TestSize();
	TestEmpty();
	TestDestroy();
	system("pause");
	return 0;
}