#pragma once
#include <stddef.h>
#include <stdio.h>

typedef char DLinkType;

typedef struct DLinkNode{
	DLinkType data;
	struct DLinkNode* next;
	struct DLinkNode* prev;
}DLinkNode;

void DLinkListInit(DLinkNode** head);			//��ʼ��

DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value);			//β��

void DLinkListPopBack(DLinkNode* head);				//βɾ

void DLinkListPushFront(DLinkNode* head, DLinkType value);			//ͷ��

void DLinkListPopFront(DLinkNode* head);			//ͷɾ

DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find);			//����Ԫ���������е�λ��

void DLinkListInsert(DLinkNode* pos, DLinkType value);      //��ָ��λ��֮ǰ����һ��Ԫ��

void DLinkListInsertAfter(DLinkNode* pos, DLinkType value);		//��ָ��λ��֮�����һ��Ԫ��

void DLinkListErase(DLinkNode* head, DLinkNode* pos);		//ɾ��ָ��λ�õ�Ԫ��

void DLinkListRemove(DLinkNode* head, DLinkType value);		//ɾ��ָ��ֵ��Ԫ��

void DLinkListRemoveAll(DLinkNode* head, DLinkType value);		 //ɾ��ָ��ֵ������Ԫ��

size_t DLinkListSize(DLinkNode* head);		 //������Ԫ�ظ���

int DLinkListEmpty(DLinkNode* head);		//�ж������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0

void DLinkListDestroy(DLinkNode** head);		//��������