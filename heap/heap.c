#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

#include <stdio.h>

void HeapInit(Heap* heap, Compare compare)           //初始化堆
{
	if (heap == NULL || compare == NULL)
	{
		return;           //非法输入
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
	//1.先找到当前节点对应的父节点
	if (index >= size)
	{
		return;
	}
	size_t child = index;
	size_t parent = (child - 1) / 2;
	//2.比较父节点与子节点的大小关系，
	//  如果子节点的值比父节点的小，交换父子节点的值；如果子节点的值比父节点大，说明调整完成了
	while (child > 0)
	{
		//3.将当前的父节点作为新的子节点，再去找子节点的父节点，循环进行比较和交换
		//4.子节点下标为0，结束
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

void HeapInsert(Heap* heap, HeapType value)          //插入元素
{
	if (heap == NULL)
	{
		return;          //非法输入
	}
	if (heap->size >= HeapMaxSize)
	{
		return;        //堆已满
	}
	heap->data[heap->size++] = value;
	AdjustUp(heap->data, heap->size, heap->cmp, heap->size - 1);
}

int HeapRoot(Heap* heap, HeapType* value)       // 取堆顶元素 
{
	if (heap == NULL)
	{
		return 0;       //非法输入
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
	//1.设定parent指向开始位置，找到对应的子节点
	size_t parent = index;
	//2.设定一个child指向parent的左子树
	size_t child = 2 * parent + 1;
	while (child < size)
	{
		//3.判定child和child+1的大小关系
		//  如果child+1的值比child的值小，就让child=child+1
		if (child+1 < size && cmp(data[child + 1], data[child]))
		{
			child = child + 1;
		}
		//4.判定parent和child的大小关系
		//  如果parent的值比child的值大，就需要进行交换，否则说明调整已完成
		if (cmp(data[child], data[parent]))
		{
			Swap(&data[child], &data[parent]);
		}
		else
		{
			break;
		}
		//5.parent赋值成child，child再重新赋值成parent的左孩子节点
		parent = child;
		child = 2 * parent + 1;
	}
	return;
}

void HeapErase(Heap* heap)          // 删除堆顶元素
{
	if (heap == NULL)
	{
		return;    //非法输入
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
		return 0;        //非法输入
	}
	return heap->size == 0 ? 1 : 0;
}

size_t Heapsize(Heap* heap)
{
	if (heap == NULL)
	{
		return 0;       //非法输入
	}
	return heap->size;
}

void Heapdestroy(Heap* heap)
{
	if (heap == NULL)
	{
		return;     //非法输入
	}
	heap->size = 0;
	return;
}




















