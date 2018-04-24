#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

#include <stdio.h>

void HeapInit(Heap* heap, Compare compare)           //��ʼ����
{
	if (heap == NULL || compare == NULL)
	{
		return;           //�Ƿ�����
	}
	heap->size = 0;
	heap->cmp = compare;
	return;
}

void HeapPrintChar(Heap* heap, const char* msg)
{
	printf("[%s]:", msg);
	size_t i = 0;
	for (; i < heap->size; ++i)
	{
		printf("[%lu]:%d  ", i, heap->data[i]);
	}
	printf("\n");
}

void Swap(HeapType *a, HeapType *b)
{
	HeapType tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void AdjustUp(HeapType data[], size_t size, Compare cmp, size_t index)
{
	//1.���ҵ���ǰ�ڵ��Ӧ�ĸ��ڵ�
	if (index >= size)
	{
		return;
	}
	size_t child = index;
	size_t parent = (child - 1) / 2;
	//2.�Ƚϸ��ڵ����ӽڵ�Ĵ�С��ϵ��
	//  ����ӽڵ��ֵ�ȸ��ڵ��С���������ӽڵ��ֵ������ӽڵ��ֵ�ȸ��ڵ��˵�����������
	while (child > 0)
	{
		//3.����ǰ�ĸ��ڵ���Ϊ�µ��ӽڵ㣬��ȥ���ӽڵ�ĸ��ڵ㣬ѭ�����бȽϺͽ���
		//4.�ӽڵ��±�Ϊ0������
		if (cmp(data[child], data[parent]))
		{
			Swap(&data[child], &data[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
	return;
}

void HeapInsert(Heap* heap, HeapType value)          //����Ԫ��
{
	if (heap == NULL)
	{
		return;          //�Ƿ�����
	}
	if (heap->size >= HeapMaxSize)
	{
		return;        //������
	}
	heap->data[heap->size++] = value;
	AdjustUp(heap->data, heap->size, heap->cmp, heap->size - 1);
}

int HeapRoot(Heap* heap, HeapType* value)       // ȡ�Ѷ�Ԫ�� 
{
	if (heap == NULL)
	{
		return 0;       //�Ƿ�����
	}
	if (heap->size == 0)
	{
		return 0;
	}
	*value = heap->data[0];
	return 1;
}

void AdjustDown(HeapType data[], size_t size, Compare cmp, size_t index)
{
	//1.�趨parentָ��ʼλ�ã��ҵ���Ӧ���ӽڵ�
	size_t parent = index;
	//2.�趨һ��childָ��parent��������
	size_t child = 2 * parent + 1;
	while (child < size)
	{
		//3.�ж�child��child+1�Ĵ�С��ϵ
		//  ���child+1��ֵ��child��ֵС������child=child+1
		if (child+1 < size && cmp(data[child + 1], data[child]))
		{
			child = child + 1;
		}
		//4.�ж�parent��child�Ĵ�С��ϵ
		//  ���parent��ֵ��child��ֵ�󣬾���Ҫ���н���������˵�����������
		if (cmp(data[child], data[parent]))
		{
			Swap(&data[child], &data[parent]);
		}
		else
		{
			break;
		}
		//5.parent��ֵ��child��child�����¸�ֵ��parent�����ӽڵ�
		parent = child;
		child = 2 * parent + 1;
	}
	return;
}

void HeapErase(Heap* heap)          // ɾ���Ѷ�Ԫ��
{
	if (heap == NULL)
	{
		return;    //�Ƿ�����
	}
	if (heap->size == 0)
	{
		return;
	}
	Swap(&heap->data[0], &heap->data[heap->size - 1]);
	--heap->size;
	AdjustDown(heap->data, heap->size, heap->cmp, 0);
}

int HeapEmpty(Heap* heap)
{
	if (heap == NULL)
	{
		return 0;        //�Ƿ�����
	}
	return heap->size == 0 ? 1 : 0;
}

size_t Heapsize(Heap* heap)
{
	if (heap == NULL)
	{
		return 0;       //�Ƿ�����
	}
	return heap->size;
}

void Heapdestroy(Heap* heap)
{
	if (heap == NULL)
	{
		return;     //�Ƿ�����
	}
	heap->size = 0;
	return;
}




















