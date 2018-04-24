// 1. 堆是一个完全二叉树 
// 2. 堆有两种, 一种叫小堆(小根堆, 最小堆), 
//    一种叫大堆(大根堆, 最大堆). 
// 3. 以小堆为例, 这个树的根节点是这个树中的最小的元素 
//    对于任意一个子树来说, 子树的根节点, 小于左右孩子节点的值. 
// 4. 以大堆为例, 这个树的根节点是这个树种的最大元素 
//    对于任意一个子树来说, 子树的根节点, 大于左右孩子节点的值. 


//下面以小堆为例
#pragma once 

#include <stddef.h>

#define HeapMaxSize 1000 
typedef int HeapType;

typedef int(*Compare)(HeapType a, HeapType b);

typedef struct Heap {
	HeapType data[HeapMaxSize];
	size_t size;
	Compare cmp;
} Heap;

void HeapInit(Heap* heap, Compare compare);           //初始化堆

void HeapPrintChar(Heap* heap, const char* msg);

void HeapInsert(Heap* heap, HeapType value);         //插入元素

int HeapRoot(Heap* heap, HeapType* value);       // 取堆顶元素 

void HeapErase(Heap* heap);          // 删除堆顶元素 

int HeapEmpty(Heap* heap);

size_t Heapsize(Heap* heap);

void Heapdestroy(Heap* heap);

void HeapSort1(HeapType array[], size_t size);          //堆排序

// 在我们不想开辟额外的空间, 或者消耗额外的时间的前提下, 
// 如果我们想进行从小到大排序, 就需要一个大堆 
// 如果我们想进行从大到小排序, 就需要一个小堆 
void HeapSort2(HeapType array[], size_t size);

void HeapSort3(HeapType array[], size_t size);

void AdjustUp(HeapType data[], size_t size, Compare cmp, size_t index);

void AdjustDown(HeapType data[], size_t size, Compare cmp, size_t index);

