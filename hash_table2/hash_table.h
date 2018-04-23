#pragma once 

#include <stddef.h>

#define HashMaxSize 1000 

typedef int KeyType;
typedef int ValType;

typedef size_t(*HashFunc)(KeyType key);

typedef struct HashElem {
	KeyType key;
	ValType value;
	struct HashElem* next;
} HashElem;

// 数组的每一个元素是一个不带头结点的链表 
// 对于空链表, 我们使用 NULL 来表示 
typedef struct HashTable {
	HashElem* data[HashMaxSize];
	size_t size;
	HashFunc hash_func;
} HashTable;

void HashInit(HashTable* ht, HashFunc hash_func);         //初始化

// 约定哈希表中不能包含 key 相同的值. 
int HashInsert(HashTable* ht, KeyType key, ValType value);     //插入

int HashFind(HashTable* ht, KeyType key, ValType* value);       //查找

void HashRemove(HashTable* ht, KeyType key);               //删除

size_t HashSize(HashTable* ht);             //长度

int HashEmpty(HashTable* ht);          //判空

void HashDestroy(HashTable* ht);        //销毁
