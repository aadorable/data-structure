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

// �����ÿһ��Ԫ����һ������ͷ�������� 
// ���ڿ�����, ����ʹ�� NULL ����ʾ 
typedef struct HashTable {
	HashElem* data[HashMaxSize];
	size_t size;
	HashFunc hash_func;
} HashTable;

void HashInit(HashTable* ht, HashFunc hash_func);         //��ʼ��

// Լ����ϣ���в��ܰ��� key ��ͬ��ֵ. 
int HashInsert(HashTable* ht, KeyType key, ValType value);     //����

int HashFind(HashTable* ht, KeyType key, ValType* value);       //����

void HashRemove(HashTable* ht, KeyType key);               //ɾ��

size_t HashSize(HashTable* ht);             //����

int HashEmpty(HashTable* ht);          //�п�

void HashDestroy(HashTable* ht);        //����
