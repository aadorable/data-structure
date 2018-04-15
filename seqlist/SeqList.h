#pragma once     //��ֹͷ�ļ��ظ�����

#include <stddef.h> 

#define SeqListMaxNum 1000    //�������Ԫ�ظ���

typedef char SeqListType;    //�ض�������
typedef struct SeqList
{
	SeqListType SeqListArr[SeqListMaxNum];
	size_t size;      //Ԫ�ظ���
}SeqList;

void SeqListInit(SeqList* seq);       //��ʼ��˳���
void SeqListPrint(SeqList* seq, const char* ch);      //��ӡ˳���

void SeqListPushEnd(SeqList* seq, SeqListType value);     //β��һ��Ԫ��
void SeqListPopEnd(SeqList* seq);           // βɾһ��Ԫ��

void SeqListPushStart(SeqList* seq, SeqListType value);     //ͷ��һ��Ԫ��
void SeqListPopStart(SeqList* seq);        //ͷɾһ��Ԫ��

void SeqListPushPosition(SeqList* seq, size_t pos, SeqListType value);    //���±�Ϊpos������Ԫ��
void SeqListPopPosition(SeqList* seq, size_t pos);               //ɾ���±�Ϊpos��Ԫ��

void SeqListSetList(SeqList* seq, size_t pos, SeqListType value);     //�޸��±�Ϊpos��Ԫ��

SeqListType SeqListGetList(SeqList* seq, size_t pos);       //���±�Ϊpos��Ԫ��
size_t SeqListGetpos(SeqList* seq, SeqListType value);      //����valueԪ��ֵ���±�

void SeqListRemove(SeqList* seq, SeqListType to_delete);          //ɾ��ָ��ֵ�ĵ�һ��
void SeqListRemoveAll(SeqList* seq, SeqListType to_delete);          //ɾ��ָ��ֵ������ֵ

size_t SeqListSize(SeqList* seq);                  //��ȡ˳�����Ԫ�ظ���
int SeqListEmpty(SeqList* seq);                    //�ж�˳����Ƿ��ǿձ�

void SeqListBubbleSort(SeqList* seq);           //ð������
void SeqListBubbleSortEx(SeqList* seq, int(*cmp)(SeqListType, SeqListType));       //���ûص�������ð������

void SeqListSelectSort(SeqList* seq);         //��������
size_t SeqListBinarySearch(SeqList* seq, SeqListType value);           //���ֲ���

void SeqListDestroy(SeqList* seq);          //����˳���






