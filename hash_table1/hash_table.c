#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"

void HashInit(HashTable* ht, HashFunc hash_func)
{
	if (ht == NULL)
	{
		return;       //�Ƿ�����
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
		return 0;          //�Ƿ�����
	}
	//�趨��������Ϊ0.8
	if (ht->size >= HashMaxSize*0.8)
	{
		return 0;         //hash������������ʧ��
	}
	//���ҵ�key��Ӧ���±�
	size_t offset = ht->hash_func(key);
	while (1)
	{
		if (ht->data[offset].stat == Valid)
		{
			if (ht->data[offset].key == key)
			{
				return 0;     //������ͬԪ�أ�����ʧ��
			}
			//����hash��ͻ��ʹ������̽��ķ�ʽ������һ��Ԫ��
			++offset;
			if (offset >= HashMaxSize)
			{
				offset -= HashMaxSize;
			}
		}
		else
		{
			//���ڸ���������80%��һ���ܹ��ҵ�һ��λ�ò���
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
		return 0;    //�Ƿ�����
	}
	//1.��ͨ��hash�������������±�
	size_t offset = ht->hash_func(key);
	//2.����������±꿪ʼ�����Ե�������
	while (1)
	{
		//   a)����ҵ�ĳ��Ԫ�ص�key����Ҫ�ģ�����״̬statΪVaild,����Ϊ���ҵ��ˣ���value��ֵ���������
		if (ht->data[offset].key == key && ht->data[offset].stat == Valid)
		{
			*value = ht->data[offset].value;
			return 1;
		}
		//   b)�����ǰλ��״̬ΪEmpty������Ϊû�ҵ�
		else if (ht->data[offset].stat == Empty)
		{
			return 0;
		}
		//   c)�������Բ�����һ��λ��
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
	//1.��ͨ��hash�������������±�
	size_t offset = ht->hash_func(key);
	//2.����������±꿪ʼ�����Ե�������
	while (1)
	{
		//   a)����ҵ�ĳ��Ԫ�ص�key����Ҫ�ģ�����״̬statΪVaild,����Ϊ���ҵ��ˣ���״̬��ΪInVaild,��--size
		if (ht->data[offset].key == key && ht->data[offset].stat == Valid)
		{
			ht->data[offset].stat = Invalid;
			--ht->size;
			return;
		}
		//   b)�����ǰλ��״̬ΪEmpty������Ϊû�ҵ�
		else if (ht->data[offset].stat == Empty)
		{
			return;
		}
		//   c)�������Բ�����һ��λ��
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



