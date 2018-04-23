#pragma once 

#include <stddef.h>

#define HashMaxSize 1000 

typedef enum Stat {
	Empty,
	Valid,
	Invalid // 当前元素被删除了 
} Stat;

typedef int KeyType;
typedef int ValType;

typedef size_t(*HashFunc)(KeyType key);

typedef struct HashElem {
	KeyType key;
	ValType value;
	Stat stat; // 引入一个 stat 标记来作为是否有效的标记 
} HashElem;

typedef struct HashTable {
	HashElem data[HashMaxSize];
	size_t size;
	HashFunc hash_func;
} HashTable;

void HashInit(HashTable* ht, HashFunc hash_func);

int HashInsert(HashTable* ht, KeyType key, ValType value);

// 输入key, 查找对应key的value. 
int HashFind(HashTable* ht, KeyType key, ValType* value);

void HashRemove(HashTable* ht, KeyType key);

int HashEmpty(HashTable* ht);

size_t HashSize(HashTable* ht);

void HashDestroy(HashTable* ht);

