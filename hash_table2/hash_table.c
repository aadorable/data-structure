#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"

#include <stdlib.h>

void HashInit(HashTable* ht, HashFunc hash_func)         //初始化
{
	if (ht == NULL)
	{
		return;          //非法输入
	}
	ht->size = 0;
	ht->hash_func = hash_func;
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		ht->data[i] = NULL;
	}
	return;
}

HashElem* CreateHashElem(KeyType key, ValType value)
{
	HashElem* new_node = (HashElem*)malloc(sizeof(HashElem));
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

HashElem* HashBucketFind(HashElem* head, KeyType key)
{
	HashElem *cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->key == key)
		{
			return cur;
		}
	}
	return NULL;
}

int HashInsert(HashTable* ht, KeyType key, ValType value)     //插入
{
	if (ht == NULL)
	{
		return 0;      //非法输入
	}
	//1.根据hash函数将key转化成对应的数组下标
	size_t offset = ht->hash_func(key);
	//2.判定当前key在链表上是否存在
	HashElem* ret = HashBucketFind(ht->data[offset], key);
	//    a)如果存在，插入失败
	if (ret != NULL)
	{
		return 0;
	}
	//    b)如果不存在，就用头插的方式将元素插入链表中
	else
	{
		HashElem* new_node = CreateHashElem(key, value);
		new_node->next = ht->data[offset];
		ht->data[offset] = new_node;
		ht->size++;
		return 1;
	}
}

int HashFind(HashTable* ht, KeyType key, ValType* value)       //查找
{
	if (ht == NULL || value == NULL)
	{
		return 0;       //非法输入
	}
	//1.根据key找到对应的哈希桶
	size_t offset = ht->hash_func(key);
	//2.对该哈希桶进行链表查找
	HashElem* ret = HashBucketFind(ht->data[offset], key);
	//    a)如果链表上没有找到对应的key，查找失败
	if (ret == NULL)
	{
		return 0;
	}
	//    b)如果链表上已存在对应的key，就把对应的节点的value返回出来
	else
	{
		*value = ret->value;
		return 1;
	}
}

int HashBucketFindCurAndPre(HashElem* head, KeyType key, HashElem** cur_output, HashElem** pre_output)
{
	HashElem* pre = NULL;
	HashElem* cur = head;
	for (; cur != NULL; pre = cur, cur = cur->next)
	{
		if (cur->key == key)
		{
			*pre_output = pre;
			*cur_output = cur;
			return 1;
		}
	}
	return 0;
}

void DestroyHashElem(HashElem* elem)
{
	free(elem);
}

void HashRemove(HashTable* ht, KeyType key)               //删除
{
	if (ht == NULL)
	{
		return;             //非法输入
	}
	//1.根据key找到对应的哈希桶
	size_t offset = ht->hash_func(key);
	//2.对该哈希桶进行链表查找
	HashElem* cur = NULL;
	HashElem* pre = NULL;
	int ret = HashBucketFindCurAndPre(ht->data[offset], key, &cur, &pre);
	//    a)如果链表上没有找到对应的key，删除失败
	if (ret == 0)
	{
		return;
	}
	//    b)如果链表上已存在对应的key，就把key从链表中删除
	if (cur == ht->data[offset])
	{
		//刚好要删除的是头节点
		ht->data[offset] = cur->next;
	}
	else
	{
		pre->next = cur->next;
	}
	DestroyHashElem(cur);
	--ht->size;
	return;
}

size_t HashSize(HashTable* ht)             //长度
{
	if (ht == NULL)
	{
		return 0;           //非法输入
	}
	return ht->size;
}

int HashEmpty(HashTable* ht)          //判空
{
	if (ht == NULL)
	{
		return 0;           //非法输入
	}
	return ht->size == NULL ? 1 : 0;
}

void HashDestroy(HashTable* ht)        //销毁
{
	//1.size设置为0
	ht->size = 0;
	//2.hash_func设置为空
	ht->hash_func = NULL;
	//3.销毁哈希桶上每个链表
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		HashElem* cur = ht->data[i];
		if (cur != NULL)
		{
			HashElem* to_delete = cur;
			cur = cur->next;
			DestroyHashElem(to_delete);
		}
	}
	return;
}




