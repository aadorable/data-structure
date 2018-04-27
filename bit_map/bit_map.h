#pragma once 

#include <stddef.h>
#include <stdint.h>

typedef struct BitMap {
	uint64_t* data;
	size_t capacity;   // max bit 
} BitMap;

void BitMapInit(BitMap* bm, size_t capacity);

// �ѵ� index λ��Ϊ1 
void BitMapSet(BitMap* bm, size_t index);

// �ѵ� index λ��Ϊ0 
void BitMapUnset(BitMap* bm, size_t index);

// ���� index Ϊ�� 1 , ���� 0. �����1, �ͷ���1. ���򷵻�0. 
int BitMapTest(BitMap* bm, size_t index);

// ������λͼ���е�λ����Ϊ1. 
void BitMapFill(BitMap* bm);

// ������λͼ���е�λ����Ϊ0. 
void BitMapClear(BitMap* bm);

void BitMapDestroy(BitMap* bm);