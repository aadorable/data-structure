// 1. ����һ����ȫ������ 
// 2. ��������, һ�ֽ�С��(С����, ��С��), 
//    һ�ֽд��(�����, ����). 
// 3. ��С��Ϊ��, ������ĸ��ڵ���������е���С��Ԫ�� 
//    ��������һ��������˵, �����ĸ��ڵ�, С�����Һ��ӽڵ��ֵ. 
// 4. �Դ��Ϊ��, ������ĸ��ڵ���������ֵ����Ԫ�� 
//    ��������һ��������˵, �����ĸ��ڵ�, �������Һ��ӽڵ��ֵ. 


//������С��Ϊ��
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

void HeapInit(Heap* heap, Compare compare);           //��ʼ����

void HeapPrintChar(Heap* heap, const char* msg);

void HeapInsert(Heap* heap, HeapType value);         //����Ԫ��

int HeapRoot(Heap* heap, HeapType* value);       // ȡ�Ѷ�Ԫ�� 

void HeapErase(Heap* heap);          // ɾ���Ѷ�Ԫ�� 

int HeapEmpty(Heap* heap);

size_t Heapsize(Heap* heap);

void Heapdestroy(Heap* heap);

void HeapSort1(HeapType array[], size_t size);          //������

// �����ǲ��뿪�ٶ���Ŀռ�, �������Ķ����ʱ���ǰ����, 
// �����������д�С��������, ����Ҫһ����� 
// �����������дӴ�С����, ����Ҫһ��С�� 
void HeapSort2(HeapType array[], size_t size);

void HeapSort3(HeapType array[], size_t size);

void AdjustUp(HeapType data[], size_t size, Compare cmp, size_t index);

void AdjustDown(HeapType data[], size_t size, Compare cmp, size_t index);

