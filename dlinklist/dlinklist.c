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
		return;          //非法输入
	}
	*head = CreateDLinkListNode(0);
	return;
}

DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value)			//尾插
{
	if (head == NULL)
	{
		return NULL;		//非法输入
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

void DLinkListPopBack(DLinkNode* head)				//尾删
{
	if (head == NULL)
	{
		return;		//非法输入
	}
	if (head->next == head)
	{
		return;		//空链表
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

void DLinkListPushFront(DLinkNode* head, DLinkType value)			//头插
{
	if (head == NULL)
	{
		return;		//非法输入
	}
	DLinkNode* new_node = CreateDLinkListNode(value);
	DLinkNode* new_node_next = head->next;
	DLinkNode* new_node_prev = head;

	new_node_next->prev = new_node;
	new_node->next = new_node_next;
	
	new_node_prev->next = new_node;
	new_node->prev = new_node_prev;
}

void DLinkListPopFront(DLinkNode* head)			//头删
{
	if (head == NULL)
	{
		return;		//非法输入
	}
	if (head == head->next)
	{
		return;		//空链表
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

DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find)			//查找元素在链表中的位置
{
	if (head == NULL)
	{
		return NULL;		//非法输入
	}
	if (head == head->next)
	{
		return NULL;		//空链表
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

void DLinkListInsert(DLinkNode* pos, DLinkType value)      //往指定位置之前插入一个元素
{
	if (pos == NULL)
	{
		return;		//非法输入
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

void DLinkListInsertAfter(DLinkNode* pos, DLinkType value)		//往指定位置之后插入一个元素
{
	if (pos == NULL)
	{
		return;		//非法输入
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

void DLinkListErase(DLinkNode* head, DLinkNode* pos)		//删除指定位置的元素
{
	if (head == NULL || pos == NULL)
	{
		return;		//非法输入
	}
	if (head == head->next)
	{
		return;		//空链表
	}
	DLinkNode* pos_prev = pos->prev;
	DLinkNode* pos_next = pos->next;
	pos_prev->next = pos_next;
	pos_next->prev = pos_prev;
	DestroyDLinkListNode(pos);
	pos = NULL;
	return;
}

void DLinkListRemove(DLinkNode* head, DLinkType value)		//删除指定值的元素
{
	if (head == NULL)
	{
		return;		//非法输入
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

void DLinkListRemoveAll(DLinkNode* head, DLinkType value)		 //删除指定值的所有元素
{
	if (head == NULL)
	{
		return;		//非法输入
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

size_t DLinkListSize(DLinkNode* head)		 //求链表元素个数
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

int DLinkListEmpty(DLinkNode* head)		//判断链表是否为空，为空返回1，否则返回0
{
	assert(head);
	if (head->next == head)
	{
		return 1;
	}
	return 0;
}

void DLinkListDestroy(DLinkNode** head)		//销毁链表
{
	if (head == NULL)
	{
		return;		//非法输入
	}
	if (*head == NULL)
	{
		return;		//该链表带头结点，头指针不可能指向空
	}
	if ((*head) == (*head)->next)
	{
		//空链表
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