#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"

void HashInit(HashTable* ht, HashFunc hash_func)
{
	if (ht == NULL)
	{
		return;       //非法输入
	}
	ht->size = 0;
	ht->hash_func = hash_func;
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		ht->data[i].stat = Empty;
	}
	return;
}

int HashInsert(HashTable* ht, KeyType key, ValType value)
{
	if (ht == NULL)
	{
		return 0;          //非法输入
	}
	//设定负载因子为0.8
	if (ht->size >= HashMaxSize*0.8)
	{
		return 0;         //hash表已满，插入失败
	}
	//先找到key对应的下标
	size_t offset = ht->hash_func(key);
	while (1)
	{
		if (ht->data[offset].stat == Valid)
		{
			if (ht->data[offset].key == key)
			{
				return 0;     //存在相同元素，插入失败
			}
			//出现hash冲突，使用线性探测的方式查找下一个元素
			++offset;
			if (offset >= HashMaxSize)
			{
				offset -= HashMaxSize;
			}
		}
		else
		{
			//由于负载因子是80%，一定能够找到一个位置插入
			ht->data[offset].key = key;
			ht->data[offset].value = value;
			ht->data[offset].stat = Valid;
			++ht->size;
			return 1;
		}
	}
	return 0;
}

int HashFind(HashTable* ht, KeyType key, ValType* value)
{
	if (ht == NULL || value == NULL)
	{
		return 0;    //非法输入
	}
	//1.先通过hash函数计算数组下标
	size_t offset = ht->hash_func(key);
	//2.从这个数组下标开始，线性的向后查找
	while (1)
	{
		//   a)如果找到某个元素的key是想要的，并且状态stat为Vaild,就认为是找到了，将value赋值给输出参数
		if (ht->data[offset].key == key && ht->data[offset].stat == Valid)
		{
			*value = ht->data[offset].value;
			return 1;
		}
		//   b)如果当前位置状态为Empty，就认为没找到
		else if (ht->data[offset].stat == Empty)
		{
			return 0;
		}
		//   c)继续尝试查找下一个位置
		++offset;
		if (offset >= HashMaxSize)
		{
			offset -= HashMaxSize;
		}
	}
	return 0;
}

void HashRemove(HashTable* ht, KeyType key)
{
	if (ht == NULL)
	{
		return;
	}
	//1.先通过hash函数计算数组下标
	size_t offset = ht->hash_func(key);
	//2.从这个数组下标开始，线性的向后查找
	while (1)
	{
		//   a)如果找到某个元素的key是想要的，并且状态stat为Vaild,就认为是找到了，将状态置为InVaild,并--size
		if (ht->data[offset].key == key && ht->data[offset].stat == Valid)
		{
			ht->data[offset].stat = Invalid;
			--ht->size;
			return;
		}
		//   b)如果当前位置状态为Empty，就认为没找到
		else if (ht->data[offset].stat == Empty)
		{
			return;
		}
		//   c)继续尝试查找下一个位置
		++offset;
		if (offset >= HashMaxSize)
		{
			offset -= HashMaxSize;
		}
	}
	return;
}

int HashEmpty(HashTable* ht)
{
	if (ht == NULL)
	{
		return 1;
	}
	return ht->size == 0 ? 1 : 0;
}

size_t HashSize(HashTable* ht)
{
	if (ht == NULL)
	{
		return 0;
	}
	return ht->size;
}

void HashDestroy(HashTable* ht)
{
	size_t i = 0;
	for (; i < HashMaxSize; ++i)
	{
		ht->data[i].stat = Empty;
	}
	ht->size = 0;
	ht->hash_func = NULL;
	return;
}



