#pragma once

#include <stddef.h>
#include <stdio.h>

typedef char LinkType;

typedef struct LinkNode{
	LinkType data;
	struct LinkNode* next;
}LinkNode;

void LinkListInit(LinkNode** head);            //��ʼ��

void LinkListPrintChar(LinkNode* head, const char* msg);    //��ӡ����

LinkNode* LinkListPushBack(LinkNode** head, LinkType value);   //β��

void LinkListPopBack(LinkNode** head);        //βɾ

void LinkListPushFront(LinkNode** head, LinkType value);    //ͷ��

void LinkListPopFront(LinkNode** head);     //ͷɾ

LinkNode* LinkListFind(LinkNode* head, LinkType to_find);     //����Ԫ���������е�λ��

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value);       //��pos֮ǰ����Ԫ��

void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value);       //��pos֮�����Ԫ��

void LinkListErase1(LinkNode** head, LinkNode* pos);           //ɾ��ָ��λ�õ�Ԫ��

void LinkListErase2(LinkNode** head, LinkNode** pos);

void LinkListRemove1(LinkNode** head, LinkType value);          //ɾ��ָ��ֵ��Ԫ��

void LinkListRemove2(LinkNode** head, LinkType value);         

void LinkListRemoveAll(LinkNode** head, LinkType value);          //ɾ��ָ��ֵ������Ԫ��

int LinkListEmpty(LinkNode* head);          //�ж������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0

size_t LinkListSize(LinkNode* head);        //������Ԫ�ظ���


//����������
void LinkListReversePrint(LinkNode* head);      //�����ӡ������

void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value);   //�������������, �� pos֮ǰ����

LinkNode* JosephCycle(LinkNode* head, size_t food);     //Լɪ��

void LinkListReverse(LinkNode** head);     //����������
void LinkListReverse2(LinkNode** head);

void LinkListBubbleSort(LinkNode* head);     //�������ð������

LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2);     //��������������, �ϲ���һ����������

LinkNode* FindMidNode(LinkNode* head);      //�ҵ��м�ڵ�

LinkNode* FindLastKNode(LinkNode* head, size_t K);       //�ҵ������� K ���ڵ�

void EraseLastKNode(LinkNode** head, size_t K);      //ɾ��������K���ڵ�

int HasCycle(LinkNode* head);      //�ж��������Ƿ����. �����������1

size_t GetCycleLen(LinkNode* head);       //����������, ������ĳ���

LinkNode* GetCycleEntry(LinkNode* head);       //����������, ����������

LinkNode* HasCross(LinkNode* head1, LinkNode* head2);       //�ж����������Ƿ��ཻ, ���������(������������)

LinkNode* HasCrossWithCycle(LinkNode* head1, LinkNode* head2);       //�ж����������Ƿ��ཻ(����������ܴ���)

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2);			//��������������������ͬ������

typedef struct ComplexNode{
	LinkType data;
	struct LinkNode* next;
	struct LinkNode* random;
}ComplexNode;
ComplexNode* CreateComplexNode(LinkType value);

ComplexNode* CopyComplex(ComplexNode* head);          //������������
ComplexNode* CopyComplex2(ComplexNode* head);          //������������

void LinkListDestroy(LinkNode** head);        //��������




