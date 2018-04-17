#pragma once
#include <stddef.h>
#include <stdio.h>

typedef char DLinkType;

typedef struct DLinkNode{
	DLinkType data;
	struct DLinkNode* next;
	struct DLinkNode* prev;
}DLinkNode;

void DLinkListInit(DLinkNode** head);			//初始化

DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value);			//尾插

void DLinkListPopBack(DLinkNode* head);				//尾删

void DLinkListPushFront(DLinkNode* head, DLinkType value);			//头插

void DLinkListPopFront(DLinkNode* head);			//头删

DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find);			//查找元素在链表中的位置

void DLinkListInsert(DLinkNode* pos, DLinkType value);      //往指定位置之前插入一个元素

void DLinkListInsertAfter(DLinkNode* pos, DLinkType value);		//往指定位置之后插入一个元素

void DLinkListErase(DLinkNode* head, DLinkNode* pos);		//删除指定位置的元素

void DLinkListRemove(DLinkNode* head, DLinkType value);		//删除指定值的元素

void DLinkListRemoveAll(DLinkNode* head, DLinkType value);		 //删除指定值的所有元素

size_t DLinkListSize(DLinkNode* head);		 //求链表元素个数

int DLinkListEmpty(DLinkNode* head);		//判断链表是否为空，为空返回1，否则返回0

void DLinkListDestroy(DLinkNode** head);		//销毁链表