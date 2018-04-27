#pragma once

#include <stdint.h>

#include "F:\VS2013_RTM_ULT_CHS\作业代码\数据结构\BitMap\BitMap\bit_map.h"

#define HashFuncMaxSize 2 
#define BitMapCapacity 1024 

typedef size_t(*HashFunc)(const char*);

typedef struct BloomFilter {
	BitMap bitmap;
	HashFunc hash_func[HashFuncMaxSize];
} BloomFilter;

void BloomFilterInit(BloomFilter* bf);

void BloomFilterInsert(BloomFilter* bf, const char* str);

int BloomFilterIsExist(BloomFilter* bf, const char* str);

void BloomFilterDestroy(BloomFilter* bf);

// 按照当前的设计, 是不允许删除的. 
