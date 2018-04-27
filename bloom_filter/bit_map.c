#define _CRT_SECURE_NO_WARNINGS 1

#include "bloom_filter.h"

//可以拿65来测试，如果要表示的最大数字是65，则需要2个uint64_t
size_t DataSize(size_t capacity)
{
	return capacity / (sizeof(uint64_t)* 8) + 1;        //uint64_t在该操作系统编译器下占8个字节
}

void GetOffset(size_t index, size_t* n, size_t* offset)
{
	*n = index / (sizeof(uint64_t)* 8);
	*offset = index % (sizeof(uint64_t)* 8);
}

//capacity表示容量，即位图能保存的最大位
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

// 把第 index 位置为1 
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
	size_t n, offset;        //64个bit位表示一个数，n为数字的下标；offset表示具体的bit位
	GetOffset(index, &n, &offset);
	bm->data[n] |= (1ul << offset);        //将指定位设置为1

	//unsigned int    1u
	//long   1l
	//unsigned long   1ul
}

// 把第 index 位置为0 
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
	size_t n, offset;        //64个bit位表示一个数，n为数字的下标；offset表示具体的bit位
	GetOffset(index, &n, &offset);
	bm->data[n] &= ~(1ul << offset);        //将指定位设置为0
}

// 测试 index 为是 1 , 还是 0. 如果是1, 就返回1. 否则返回0. 
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
	//在进行按位操作时，切记注意防止整型溢出
	uint64_t ret = bm->data[n] & (1ul << offset);
	return ret != 0 ? 1 : 0;
}

// 把整个位图所有的位都设为0. 
void BitMapClear(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	memset(bm->data, 0, sizeof(uint64_t)*DataSize(bm->capacity));
}

// 把整个位图所有的位都设为1. 
void BitMapFill(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	memset(bm->data, 0xff, sizeof(uint64_t)*DataSize(bm->capacity));
	//一个字节一个字节的设置为1，一个字节对应8个bit位
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