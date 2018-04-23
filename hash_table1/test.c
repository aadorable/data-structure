#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"

#include <stdio.h>
#include <windows.h>

#define TEST_HEADER printf("\n=======================%s======================\n",__FUNCTION__)

size_t HashFuncDefault(KeyType key)
{
	return key % HashMaxSize;
}

void HashPrintInt(HashTable* ht, const char* msg)
{
	printf("[%s]:\n", msg);
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		if (ht->data[i].stat != Empty)
		{
			printf("[%lu]: key=%d, value=%d\n", i, ht->data[i].key, ht->data[i].value);
		}
	}
}

void CountNum()
{
	TEST_HEADER;
	int array[] = { 1, 1, 1, 2, 2, 3,101,1001};
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	size_t i = 0;
	for (; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		int value = 0;
		int ret = HashFind(&ht, array[i], &value);
		if (ret == 0)
		{
			//û�ҵ���ֱ�Ӳ���
			HashInsert(&ht, array[i], 1);
		}
		else
		{
			//��Ԫ�ش��ڣ���ɾ����Ԫ�أ�Ȼ���ٲ���
			HashRemove(&ht, array[i]);
			HashInsert(&ht, array[i], value + 1);
		}
	}
	HashPrintInt(&ht, "���ս��Ϊ");
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
		if (ht.data[i].stat != Empty)
		{
			printf("pos[%lu] elem error!\n", i);
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
	HashInsert(&ht, 1, 500);
	HashPrintInt(&ht, "�������Ԫ��");
}

void TestFind()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1, 500);
	HashPrintInt(&ht, "�������Ԫ��");

	int value = 0;
	int ret = HashFind(&ht, 1, &value);
	printf("[����1]��\n");
	printf("ret expect 1,actual %d\n", ret);
	printf("value expect 100,actual %d\n\n", value);

	ret = HashFind(&ht, 1001, &value);
	printf("[����1001]��\n");
	printf("ret expect 1,actual %d\n", ret);
	printf("value expect 300,actual %d\n\n", value);

	ret = HashFind(&ht, 1003, &value);
	printf("[����1003]��\n");
	printf("ret expect 0,actual %d\n", ret);
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
	HashInsert(&ht, 1, 500);
	HashPrintInt(&ht, "�������Ԫ��");

	HashRemove(&ht, 1);
	int value = 0;
	int ret = HashFind(&ht, 1, &value);
	printf("[ɾ��1֮��]��\n");
	printf("ret expect 0,actual %d\n\n", ret);
	
	HashRemove(&ht, 1001);
	ret = HashFind(&ht, 1001, &value);
	printf("[ɾ��1001֮��]��\n");
	printf("ret expect 0,actual %d\n\n", ret);

	HashRemove(&ht, 1003);
	ret = HashFind(&ht, 1003, &value);
	printf("[ɾ��1003֮��]��\n");
	printf("ret expect 0,actual %d\n", ret);
}

void TestEmpty()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	int ret = HashEmpty(&ht);
	printf("ret expect 1, actual %d\n", ret);

	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1, 500);
	HashPrintInt(&ht, "�������Ԫ��");
	ret = HashEmpty(&ht);
	printf("ret expect 0, actual %d\n", ret);

	HashRemove(&ht, 1);
	HashRemove(&ht, 2);
	HashRemove(&ht, 1001);
	HashRemove(&ht, 1002);
	ret = HashEmpty(&ht);
	printf("ret expect 1, actual %d\n", ret);
}

void TestSize()
{
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	size_t ret = HashSize(&ht);
	printf("ret expect 0, actual %d\n", ret);

	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashInsert(&ht, 1, 500);
	HashPrintInt(&ht, "�������Ԫ��");
	ret = HashSize(&ht);
	printf("ret expect 4, actual %d\n", ret);

	HashRemove(&ht, 1);
	HashRemove(&ht, 2);
	HashRemove(&ht, 1001);
	HashRemove(&ht, 1002);
	ret = HashSize(&ht);
	printf("ret expect 0, actual %d\n", ret);

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
	HashInsert(&ht, 1, 500);
	HashPrintInt(&ht, "�������Ԫ��");
	HashDestroy(&ht);
	printf("���ٹ�ϣ���\n");
	printf("ht->size expect 0,actual %lu\n", ht.size);
	printf("ht->hash_func expect NULL,actual %p\n", ht.hash_func);
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		if (ht.data[i].stat != Empty)
		{
			printf("pos[%lu] elem error!\n", i);
		}
	}
}

int main()
{
	TestInit();
	TestInsert();
	TestFind();
	TestRemove();
	TestEmpty();
	TestSize();
	TestDestroy();
	CountNum();
	system("pause");
	return 0;
}