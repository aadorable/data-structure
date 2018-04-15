#pragma once     //防止头文件重复包含

#include <stddef.h> 

#define SeqListMaxNum 1000    //数组最大元素个数

typedef char SeqListType;    //重定义类型
typedef struct SeqList
{
	SeqListType SeqListArr[SeqListMaxNum];
	size_t size;      //元素个数
}SeqList;

void SeqListInit(SeqList* seq);       //初始化顺序表
void SeqListPrint(SeqList* seq, const char* ch);      //打印顺序表

void SeqListPushEnd(SeqList* seq, SeqListType value);     //尾插一个元素
void SeqListPopEnd(SeqList* seq);           // 尾删一个元素

void SeqListPushStart(SeqList* seq, SeqListType value);     //头插一个元素
void SeqListPopStart(SeqList* seq);        //头删一个元素

void SeqListPushPosition(SeqList* seq, size_t pos, SeqListType value);    //在下标为pos处插入元素
void SeqListPopPosition(SeqList* seq, size_t pos);               //删除下标为pos的元素

void SeqListSetList(SeqList* seq, size_t pos, SeqListType value);     //修改下标为pos的元素

SeqListType SeqListGetList(SeqList* seq, size_t pos);       //读下标为pos的元素
size_t SeqListGetpos(SeqList* seq, SeqListType value);      //查找value元素值的下标

void SeqListRemove(SeqList* seq, SeqListType to_delete);          //删除指定值的第一个
void SeqListRemoveAll(SeqList* seq, SeqListType to_delete);          //删除指定值的所有值

size_t SeqListSize(SeqList* seq);                  //获取顺序表中元素个数
int SeqListEmpty(SeqList* seq);                    //判断顺序表是否是空表

void SeqListBubbleSort(SeqList* seq);           //冒泡排序
void SeqListBubbleSortEx(SeqList* seq, int(*cmp)(SeqListType, SeqListType));       //利用回调函数的冒泡排序

void SeqListSelectSort(SeqList* seq);         //查找排序
size_t SeqListBinarySearch(SeqList* seq, SeqListType value);           //二分查找

void SeqListDestroy(SeqList* seq);          //销毁顺序表






