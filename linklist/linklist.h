#pragma once

#include <stddef.h>
#include <stdio.h>

typedef char LinkType;

typedef struct LinkNode{
	LinkType data;
	struct LinkNode* next;
}LinkNode;

void LinkListInit(LinkNode** head);            //初始化

void LinkListPrintChar(LinkNode* head, const char* msg);    //打印链表

LinkNode* LinkListPushBack(LinkNode** head, LinkType value);   //尾插

void LinkListPopBack(LinkNode** head);        //尾删

void LinkListPushFront(LinkNode** head, LinkType value);    //头插

void LinkListPopFront(LinkNode** head);     //头删

LinkNode* LinkListFind(LinkNode* head, LinkType to_find);     //查找元素在链表中的位置

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value);       //在pos之前插入元素

void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value);       //在pos之后插入元素

void LinkListErase1(LinkNode** head, LinkNode* pos);           //删除指定位置的元素

void LinkListErase2(LinkNode** head, LinkNode** pos);

void LinkListRemove1(LinkNode** head, LinkType value);          //删除指定值的元素

void LinkListRemove2(LinkNode** head, LinkType value);         

void LinkListRemoveAll(LinkNode** head, LinkType value);          //删除指定值的所有元素

int LinkListEmpty(LinkNode* head);          //判断链表是否为空，为空返回1，否则返回0

size_t LinkListSize(LinkNode* head);        //求链表元素个数


//经典面试题
void LinkListReversePrint(LinkNode* head);      //逆序打印单链表

void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value);   //不允许遍历链表, 在 pos之前插入

LinkNode* JosephCycle(LinkNode* head, size_t food);     //约瑟夫环

void LinkListReverse(LinkNode** head);     //单链表逆置
void LinkListReverse2(LinkNode** head);

void LinkListBubbleSort(LinkNode* head);     //单链表的冒泡排序

LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2);     //将两个有序链表, 合并成一个有序链表

LinkNode* FindMidNode(LinkNode* head);      //找到中间节点

LinkNode* FindLastKNode(LinkNode* head, size_t K);       //找到倒数第 K 个节点

void EraseLastKNode(LinkNode** head, size_t K);      //删除倒数第K个节点

int HasCycle(LinkNode* head);      //判定单链表是否带环. 如果带环返回1

size_t GetCycleLen(LinkNode* head);       //如果链表带环, 求出环的长度

LinkNode* GetCycleEntry(LinkNode* head);       //如果链表带环, 求出环的入口

LinkNode* HasCross(LinkNode* head1, LinkNode* head2);       //判定两个链表是否相交, 并求出交点(假设链表不带环)

LinkNode* HasCrossWithCycle(LinkNode* head1, LinkNode* head2);       //判定两个链表是否相交(假设链表可能带环)

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2);			//求两个已排序单链表中相同的数据

typedef struct ComplexNode{
	LinkType data;
	struct LinkNode* next;
	struct LinkNode* random;
}ComplexNode;
ComplexNode* CreateComplexNode(LinkType value);

ComplexNode* CopyComplex(ComplexNode* head);          //拷贝复杂链表
ComplexNode* CopyComplex2(ComplexNode* head);          //拷贝复杂链表

void LinkListDestroy(LinkNode** head);        //销毁链表




