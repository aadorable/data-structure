#pragma once 

#include <stddef.h>
#include <stdint.h>

typedef struct BitMap {
	uint64_t* data;
	size_t capacity;   // max bit 
} BitMap;

void BitMapInit(BitMap* bm, size_t capacity);

// 把第 index 位置为1 
void BitMapSet(BitMap* bm, size_t index);

// 把第 index 位置为0 
void BitMapUnset(BitMap* bm, size_t index);

// 测试 index 为是 1 , 还是 0. 如果是1, 就返回1. 否则返回0. 
int BitMapTest(BitMap* bm, size_t index);

// 把整个位图所有的位都设为1. 
void BitMapFill(BitMap* bm);

// 把整个位图所有的位都设为0. 
void BitMapClear(BitMap* bm);

void BitMapDestroy(BitMap* bm);