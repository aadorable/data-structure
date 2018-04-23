#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"

#include <stdlib.h>

void HashInit(HashTable* ht, HashFunc hash_func)         //��ʼ��
{
	if (ht == NULL)
	{
		return;          //�Ƿ�����
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

int HashInsert(HashTable* ht, KeyType key, ValType value)     //����
{
	if (ht == NULL)
	{
		return 0;      //�Ƿ�����
	}
	//1.����hash������keyת���ɶ�Ӧ�������±�
	size_t offset = ht->hash_func(key);
	//2.�ж���ǰkey���������Ƿ����
	HashElem* ret = HashBucketFind(ht->data[offset], key);
	//    a)������ڣ�����ʧ��
	if (ret != NULL)
	{
		return 0;
	}
	//    b)��������ڣ�����ͷ��ķ�ʽ��Ԫ�ز���������
	else
	{
		HashElem* new_node = CreateHashElem(key, value);
		new_node->next = ht->data[offset];
		ht->data[offset] = new_node;
		ht->size++;
		return 1;
	}
}

int HashFind(HashTable* ht, KeyType key, ValType* value)       //����
{
	if (ht == NULL || value == NULL)
	{
		return 0;       //�Ƿ�����
	}
	//1.����key�ҵ���Ӧ�Ĺ�ϣͰ
	size_t offset = ht->hash_func(key);
	//2.�Ըù�ϣͰ�����������
	HashElem* ret = HashBucketFind(ht->data[offset], key);
	//    a)���������û���ҵ���Ӧ��key������ʧ��
	if (ret == NULL)
	{
		return 0;
	}
	//    b)����������Ѵ��ڶ�Ӧ��key���ͰѶ�Ӧ�Ľڵ��value���س���
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

void HashRemove(HashTable* ht, KeyType key)               //ɾ��
{
	if (ht == NULL)
	{
		return;             //�Ƿ�����
	}
	//1.����key�ҵ���Ӧ�Ĺ�ϣͰ
	size_t offset = ht->hash_func(key);
	//2.�Ըù�ϣͰ�����������
	HashElem* cur = NULL;
	HashElem* pre = NULL;
	int ret = HashBucketFindCurAndPre(ht->data[offset], key, &cur, &pre);
	//    a)���������û���ҵ���Ӧ��key��ɾ��ʧ��
	if (ret == 0)
	{
		return;
	}
	//    b)����������Ѵ��ڶ�Ӧ��key���Ͱ�key��������ɾ��
	if (cur == ht->data[offset])
	{
		//�պ�Ҫɾ������ͷ�ڵ�
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

size_t HashSize(HashTable* ht)             //����
{
	if (ht == NULL)
	{
		return 0;           //�Ƿ�����
	}
	return ht->size;
}

int HashEmpty(HashTable* ht)          //�п�
{
	if (ht == NULL)
	{
		return 0;           //�Ƿ�����
	}
	return ht->size == NULL ? 1 : 0;
}

void HashDestroy(HashTable* ht)        //����
{
	//1.size����Ϊ0
	ht->size = 0;
	//2.hash_func����Ϊ��
	ht->hash_func = NULL;
	//3.���ٹ�ϣͰ��ÿ������
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




