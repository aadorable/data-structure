#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

#include <stdio.h>
#include <windows.h>

#define TEST_HEADER printf("\n=============================%s============================\n",__FUNCTION__)

int Less(HeapType a, HeapType b)
{
	return a < b;
}

int More(HeapType a, HeapType b)
{
	return a > b;
}

void HeapSort1(HeapType array[], size_t size)          //������
{
	Heap heap;
	HeapInit(&heap, Less);
	//1.�Ƚ������е�����Ԫ�ض����뵽����
	size_t i = 0;
	for (; i < size; ++i)
	{
		HeapInsert(&heap, array[i]);
	}
	//2.����ȡ�Ѷ�Ԫ�أ��Żص�ԭ���飬��ɾ���Ѷ�Ԫ��
	size_t index = 0;
	while (!HeapEmpty(&heap))
	{
		HeapType root = 0;
		HeapRoot(&heap, &root);
		array[index++] = root;
		HeapErase(&heap);
	}
	return;
}

void HeapSort2(HeapType array[], size_t size)
{
	//1.ֱ���������ǰ��������һ���ѣ�ѭ���������γ�һ��С��
	//2.����ȡ�Ѷ�Ԫ�ز�����ɾ��
	if (size == 0 || size == 1)
	{
		return;
	}
	size_t heap_size = 0;
	for (; heap_size < size; ++heap_size)
	{
		AdjustUp(array, heap_size, More, heap_size - 1);
		//AdjustUp(array, heap_size, Less, heap_size - 1);
	}
	while (heap_size>0)
	{
		Swap(&array[0], &array[heap_size - 1]);
		--heap_size;
		AdjustDown(array, heap_size, More, 0);
		//AdjustDown(array, heap_size, Less, 0);
	}
	return;
}

void HeapSort3(HeapType array[], size_t size)
{
	if (size == 0 || size == 1)
	{
		return;
	}
	//�������³������ѣ���Ӻ���ǰ�������飬ȡ����һ��Ԫ��֮���ҵ���Ԫ�ص����Һ��ӽڵ�
	size_t end = (size - 1 - 1) / 2;
	for (; end > 0; --end)
	{
		AdjustDown(array, size, More, end - 1);
		//AdjustDown(array, size, Less, end - 1);
	}
	size_t heap_size = size;
	while (heap_size > 0)
	{
		Swap(&array[0], &array[heap_size - 1]);
		--heap_size;
		AdjustDown(array, heap_size, More, 0);
		//AdjustDown(array, heap_size, Less, 0);
	}
	return;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////�����ǲ��Ժ���///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TestInit()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	printf("heap->size expect 0,actual %lu\n", heap.size);
	printf("heap->cmp expect %p,actual %p\n", Less, heap.cmp);
}

void TestInsert()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 23);
	HeapInsert(&heap, 17);
	HeapInsert(&heap, 2);
	HeapPrintChar(&heap, "����5��Ԫ��");
}

void TestRoot()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 23);
	HeapInsert(&heap, 17);
	HeapInsert(&heap, 2);
	HeapPrintChar(&heap, "����5��Ԫ��");
	HeapType value = 0;
	int ret = HeapRoot(&heap, &value);
	printf("ret expect 1,actual %d\n", ret);
	printf("value expect 2,actual %d\n", value);
}

void TestErase()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 23);
	HeapInsert(&heap, 17);
	HeapInsert(&heap, 2);
	HeapPrintChar(&heap, "����5��Ԫ��");
	HeapErase(&heap);
	HeapPrintChar(&heap, "ɾ���Ѷ�Ԫ��֮��");
}

void TestEmpty()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	int ret = HeapEmpty(&heap);
	printf("ret expect 1,actual %d\n", ret);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 23);
	HeapInsert(&heap, 17);
	HeapInsert(&heap, 2);
	HeapPrintChar(&heap, "����5��Ԫ��");
	ret = HeapEmpty(&heap);
	printf("ret expect 0,actual %d\n", ret);
}

void TestSize()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	size_t ret = Heapsize(&heap);
	printf("ret expect 0,actual %d\n", ret);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 23);
	HeapInsert(&heap, 17);
	HeapInsert(&heap, 2);
	HeapPrintChar(&heap, "����5��Ԫ��");
	ret = Heapsize(&heap);
	printf("ret expect 5,actual %d\n", ret);
}

void TestDestroy()
{
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, Less);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 23);
	HeapInsert(&heap, 17);
	HeapInsert(&heap, 2);
	HeapPrintChar(&heap, "����5��Ԫ��");
	printf("heap->size expect 5,actual %lu\n", heap.size);
	Heapdestroy(&heap);
	HeapPrintChar(&heap, "���ٺ�");
	printf("heap->size expect 0,actual %lu\n", heap.size);
}

void TestSort1()
{
	TEST_HEADER;
	int array[] = { 8, 6, 12, 18, 25, 1, 14, 9 };
	int len = sizeof(array) / sizeof(array[0]);
	printf("[����ǰ]��");
	size_t i = 0;
	for (; i < len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	HeapSort1(array, len);
	printf("[�����]��");
	for (i = 0; i < len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void TestSort2()
{
	TEST_HEADER;
	int array[] = { 8, 6, 12, 18, 25, 1, 14, 9 };
	int len = sizeof(array) / sizeof(array[0]);
	printf("[����ǰ]��");
	size_t i = 0;
	for (; i < len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	HeapSort2(array, len);
	printf("[�����]��");
	for (i = 0; i < len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void TestSort3()
{
	TEST_HEADER;
	int array[] = { 8, 6, 12, 18, 25, 1, 14, 9 };
	int len = sizeof(array) / sizeof(array[0]);
	printf("[����ǰ]��");
	size_t i = 0;
	for (; i < len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	HeapSort3(array, len);
	printf("[�����]��");
	for (i = 0; i < len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	TestInit();
	TestInsert();
	TestRoot();
	TestErase();
	TestEmpty();
	TestSize();
	TestDestroy();
	TestSort1();
	TestSort2();
	TestSort3();
	system("pause");
	return 0;
}