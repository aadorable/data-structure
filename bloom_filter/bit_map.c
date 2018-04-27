#define _CRT_SECURE_NO_WARNINGS 1

#include "bloom_filter.h"

//������65�����ԣ����Ҫ��ʾ�����������65������Ҫ2��uint64_t
size_t DataSize(size_t capacity)
{
	return capacity / (sizeof(uint64_t)* 8) + 1;        //uint64_t�ڸò���ϵͳ��������ռ8���ֽ�
}

void GetOffset(size_t index, size_t* n, size_t* offset)
{
	*n = index / (sizeof(uint64_t)* 8);
	*offset = index % (sizeof(uint64_t)* 8);
}

//capacity��ʾ��������λͼ�ܱ�������λ
void BitMapInit(BitMap* bm, size_t capacity)
{
	if (bm == NULL)
	{
		return;
	}
	bm->capacity = capacity;
	size_t size = DataSize(capacity);
	bm->data = (uint64_t*)malloc(sizeof(uint64_t)* size);
}

// �ѵ� index λ��Ϊ1 
void BitMapSet(BitMap* bm, size_t index)
{
	if (bm == NULL)
	{
		return;
	}
	if (index >= bm->capacity)
	{
		return;
	}
	size_t n, offset;        //64��bitλ��ʾһ������nΪ���ֵ��±ꣻoffset��ʾ�����bitλ
	GetOffset(index, &n, &offset);
	bm->data[n] |= (1ul << offset);        //��ָ��λ����Ϊ1

	//unsigned int    1u
	//long   1l
	//unsigned long   1ul
}

// �ѵ� index λ��Ϊ0 
void BitMapUnset(BitMap* bm, size_t index)
{
	if (bm == NULL)
	{
		return;
	}
	if (index >= bm->capacity)
	{
		return;
	}
	size_t n, offset;        //64��bitλ��ʾһ������nΪ���ֵ��±ꣻoffset��ʾ�����bitλ
	GetOffset(index, &n, &offset);
	bm->data[n] &= ~(1ul << offset);        //��ָ��λ����Ϊ0
}

// ���� index Ϊ�� 1 , ���� 0. �����1, �ͷ���1. ���򷵻�0. 
int BitMapTest(BitMap* bm, size_t index)
{
	if (bm == NULL)
	{
		return 0;
	}
	if (index >= bm->capacity)
	{
		return 0;
	}
	size_t n, offset;
	GetOffset(index, &n, &offset);
	//�ڽ��а�λ����ʱ���м�ע���ֹ�������
	uint64_t ret = bm->data[n] & (1ul << offset);
	return ret != 0 ? 1 : 0;
}

// ������λͼ���е�λ����Ϊ0. 
void BitMapClear(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	memset(bm->data, 0, sizeof(uint64_t)*DataSize(bm->capacity));
}

// ������λͼ���е�λ����Ϊ1. 
void BitMapFill(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	memset(bm->data, 0xff, sizeof(uint64_t)*DataSize(bm->capacity));
	//һ���ֽ�һ���ֽڵ�����Ϊ1��һ���ֽڶ�Ӧ8��bitλ
}

void BitMapDestroy(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	bm->capacity = 0;
	free(bm->data);
	bm->data = NULL;
	return;
}