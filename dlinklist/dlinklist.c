#define _CRT_SECURE_NO_WARNINGS 1

#include "dlinklist.h"

#include <stdlib.h>
#include <assert.h>

DLinkNode* CreateDLinkListNode(DLinkType value)
{
	DLinkNode* ptr = (DLinkNode*)malloc(sizeof(DLinkNode));
	ptr->data = value;
	ptr->next = ptr;
	ptr->prev = ptr;
	return ptr;
}

void DestroyDLinkListNode(DLinkNode* ptr)
{
	free(ptr);
}

void DLinkListInit(DLinkNode** head)
{
	if (head == NULL)
	{
		return;          //�Ƿ�����
	}
	*head = CreateDLinkListNode(0);
	return;
}

DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value)			//β��
{
	if (head == NULL)
	{
		return NULL;		//�Ƿ�����
	}
	DLinkNode* new_node = CreateDLinkListNode(value);
	DLinkNode* new_node_next = head;
	DLinkNode* new_node_prev = head->prev;

	new_node_prev->next = new_node;
	new_node->prev = new_node_prev;
	new_node_next->prev = new_node;
	new_node->next = new_node_next;
	return new_node;
}

void DLinkListPopBack(DLinkNode* head)				//βɾ
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	if (head->next == head)
	{
		return;		//������
	}
	DLinkNode* to_delete = head->prev;
	DLinkNode* to_delete_next = to_delete->next;
	DLinkNode* to_delete_prev = to_delete->prev;
	to_delete_prev->next = to_delete_next;
	to_delete_next->prev = to_delete_prev;
	DestroyDLinkListNode(to_delete);
	to_delete = NULL;
	return;
}

void DLinkListPushFront(DLinkNode* head, DLinkType value)			//ͷ��
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	DLinkNode* new_node = CreateDLinkListNode(value);
	DLinkNode* new_node_next = head->next;
	DLinkNode* new_node_prev = head;

	new_node_next->prev = new_node;
	new_node->next = new_node_next;
	
	new_node_prev->next = new_node;
	new_node->prev = new_node_prev;
}

void DLinkListPopFront(DLinkNode* head)			//ͷɾ
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	if (head == head->next)
	{
		return;		//������
	}
	//DLinkNode* to_delete = head->next;
	//DLinkNode* to_delete_next = to_delete->next;
	//DLinkNode* to_delete_prev = to_delete->prev;

	//to_delete_prev->next = to_delete_next;
	//to_delete_next->prev = to_delete_prev;
	//DestroyDLinkListNode(to_delete);
	//to_delete = NULL;
	DLinkListErase(head, head->next);
	return;
}

DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find)			//����Ԫ���������е�λ��
{
	if (head == NULL)
	{
		return NULL;		//�Ƿ�����
	}
	if (head == head->next)
	{
		return NULL;		//������
	}
	DLinkNode* cur = head->next;
	for (; cur != head; cur = cur->next)
	{
		if (cur->data == to_find)
		{
			return cur;
		}
	}
	return NULL;
}

void DLinkListInsert(DLinkNode* pos, DLinkType value)      //��ָ��λ��֮ǰ����һ��Ԫ��
{
	if (pos == NULL)
	{
		return;		//�Ƿ�����
	}
	DLinkNode* new_node = CreateDLinkListNode(value);
	DLinkNode* new_node_next = pos;
	DLinkNode* new_node_prev = pos->prev;
	new_node_next->prev = new_node;
	new_node->next = new_node_next;

	new_node_prev->next = new_node;
	new_node->prev = new_node_prev;
	return;
}

void DLinkListInsertAfter(DLinkNode* pos, DLinkType value)		//��ָ��λ��֮�����һ��Ԫ��
{
	if (pos == NULL)
	{
		return;		//�Ƿ�����
	}
	DLinkNode* new_node = CreateDLinkListNode(value);
	DLinkNode* new_node_next = pos->next;
	DLinkNode* new_node_prev = pos;
	new_node_next->prev = new_node;
	new_node->next = new_node_next;

	new_node_prev->next = new_node;
	new_node->prev = new_node_prev;
	return;
}

void DLinkListErase(DLinkNode* head, DLinkNode* pos)		//ɾ��ָ��λ�õ�Ԫ��
{
	if (head == NULL || pos == NULL)
	{
		return;		//�Ƿ�����
	}
	if (head == head->next)
	{
		return;		//������
	}
	DLinkNode* pos_prev = pos->prev;
	DLinkNode* pos_next = pos->next;
	pos_prev->next = pos_next;
	pos_next->prev = pos_prev;
	DestroyDLinkListNode(pos);
	pos = NULL;
	return;
}

void DLinkListRemove(DLinkNode* head, DLinkType value)		//ɾ��ָ��ֵ��Ԫ��
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	DLinkNode* to_find = head->next;
	for (; to_find != head; to_find = to_find->next)
	{
		if (to_find->data == value)
			break;
	}
	if (to_find != head)
	{
		DLinkNode* to_delete_prev = to_find->prev;
		DLinkNode* to_delete_next = to_find->next;
		to_delete_prev->next = to_delete_next;
		to_delete_next->prev = to_delete_prev;
		DestroyDLinkListNode(to_find);
	}
	return;
}

void DLinkListRemoveAll(DLinkNode* head, DLinkType value)		 //ɾ��ָ��ֵ������Ԫ��
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	while (1)
	{
		DLinkNode* pos = DLinkListFind(head, value);
		if (pos == NULL)
		{
			return;
		}
		DLinkListErase(head, pos);
	}
	return;
}

size_t DLinkListSize(DLinkNode* head)		 //������Ԫ�ظ���
{
	if (head == NULL)
	{
		return (size_t)-1;
	}
	size_t count = 0;
	DLinkNode* cur = head->next;
	for (; cur != head; cur = cur->next)
	{
		++count;
	}
	return count;
}

int DLinkListEmpty(DLinkNode* head)		//�ж������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
{
	assert(head);
	if (head->next == head)
	{
		return 1;
	}
	return 0;
}

void DLinkListDestroy(DLinkNode** head)		//��������
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	if (*head == NULL)
	{
		return;		//�������ͷ��㣬ͷָ�벻����ָ���
	}
	if ((*head) == (*head)->next)
	{
		//������
		DestroyDLinkListNode(*head);
		*head = NULL;
		return;
	}
	DLinkNode* cur = (*head)->next;
	while (cur != *head)
	{
		DLinkNode* next = cur->next;
		DestroyDLinkListNode(cur);
		cur = next;
	}
	DestroyDLinkListNode(*head);
	*head = NULL;
	return;
}