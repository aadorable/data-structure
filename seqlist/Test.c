
//以下是测试代码
#include "SeqList.h"
#include <stdio.h>

//#define TEST_HEADER printf("\n===================%s===================\n",__FUNCTION__)

//测试初始化顺序表
void TestSeqListInit()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPrint(&seq,"*****初始化顺序表*****");
}

//测试尾插一个元素
void TestSeqListPushEnd()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPrint(&seq, "*****尾插四个元素至顺序表*****");
}

// 测试尾删一个元素
void TestSeqListPopEnd()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopEnd(&seq);
	SeqListPrint(&seq, "*****在顺序表中尾删一个元素*****");
	printf("空表情况：\n");
	SeqListInit(&seq);
	SeqListPopEnd(&seq);
}

//测试头插一个元素
void TestSeqListPushStart()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushStart(&seq, 'e');
	SeqListPrint(&seq, "*****头插一个元素至顺序表*****");
}

//测试头删一个元素
void TestSeqListPopStart()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopStart(&seq);
	SeqListPrint(&seq, "*****在顺序表中头删一个元素*****");
	printf("空表情况：\n");
	SeqListInit(&seq);
	SeqListPopStart(&seq);
}

//测试在下标为pos处插入元素
void TestSeqListPushPosition()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushPosition(&seq, 2, 's');
	SeqListPrint(&seq, "*****在顺序表中指定位置插入一个元素*****");
	printf("非法坐标情况(在下标为20的位置插入元素)：\n");
	SeqListPushPosition(&seq, 20, 'r');
}

//测试删除下标为pos的元素
void TestSeqListPopPosition()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopPosition(&seq, 2);
	SeqListPrint(&seq, "*****在顺序表中指定位置删除一个元素*****");
	printf("非法坐标情况(删除下标为8的元素)：\n");
	SeqListPopPosition(&seq, 8);
}

//测试修改下标为pos的元素
void TestSeqListSetList()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListSetList(&seq, 1, 'o');
	SeqListPrint(&seq, "*****在顺序表中修改指定位置的元素*****");
	printf("非法坐标情况(修改下标为10的元素)：\n");
	SeqListSetList(&seq, 10,'k');
}

//测试读取下标为pos的元素
void TestSeqListGetList()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'g');
	SeqListPushEnd(&seq, 'h');
	SeqListPrint(&seq, "*****在顺序表中读取指定位置元素*****");
	char ch = SeqListGetList(&seq, 1);
	printf("下标为1的元素为%c\n", ch);
	printf("非法坐标情况(读取下标为6的元素)：\n");
	SeqListGetList(&seq, 6);
}

//测试查找value元素值的下标
void TestSeqListGetpos()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'g');
	SeqListPushEnd(&seq, 'h');
	SeqListPrint(&seq, "*****在顺序表中读取指定位置元素下标*****");
	size_t pos = SeqListGetpos(&seq, 'h');
	printf("h元素的下标为%ld\n", pos);
	printf("非法情况(读取元素W的下标)：\n");
	size_t pos1 = SeqListGetpos(&seq, 'W');
	printf("W元素的下标为%ld，坐标非法！\n\n", pos1);
}

//测试删除指定值的第一个
void TestSeqListRemove()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListRemove(&seq, 'a');
	SeqListPrint(&seq, "*****尝试在空表中删除*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'c');
	SeqListRemove(&seq, 'c');
	SeqListPrint(&seq, "*****删除顺序表中指定元素的第一个*****");
}

//测试删除指定值的所有值
void TestSeqListRemoveAll()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListRemoveAll(&seq, 'a');
	SeqListPrint(&seq, "*****尝试在空表中删除*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'c');
	SeqListRemoveAll(&seq, 'c');
	SeqListPrint(&seq, "*****删除顺序表中指定元素的所有值*****");
}

//测试获取顺序表中元素个数
void TestSeqListSize()
{
	SeqList seq;
	SeqListInit(&seq);
	size_t count = SeqListSize(&seq);
	printf("count = %lu\n", count);
	SeqListPrint(&seq, "*****统计空表中元素个数*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'e');
	size_t count1 = SeqListSize(&seq);
	printf("count = %lu\n", count1);
	SeqListPrint(&seq, "*****统计顺序表中元素个数*****");
}

//测试判断顺序表是否是空表
void TestSeqListEmpty()
{
	SeqList seq;
	SeqListInit(&seq);
	int flag = SeqListEmpty(&seq);
	if (flag == 0)
	{
		printf("该顺序表不是空表！\n");
	}
	else
	{
		printf("该顺序表是空表！\n");
	}
	SeqListPrint(&seq, "*****顺序表是空表*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	flag = SeqListEmpty(&seq);
	if (flag == 0)
	{
		printf("该顺序表不是空表！\n");
	}
	else
	{
		printf("该顺序表是空表！\n");
	}
	SeqListPrint(&seq, "*****顺序表不是空表情况*****");
}

//测试冒泡排序
void TestSeqListBubbleSort()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'i');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'b');
	SeqListPrint(&seq, "*****对顺序表进行冒泡排序前*****");
	SeqListBubbleSort(&seq);
	SeqListPrint(&seq, "*****对顺序表进行冒泡排序后*****");
}

//测试利用回调函数的冒泡排序
int int_cmp(const SeqListType a, const SeqListType b)            //从小到大顺序排序
{
	return a > b;
}
int int_cmp1(const SeqListType a, const SeqListType b)            //从大到小顺序排序
{
	return a < b;
}
void TestSeqListBubbleSortEx()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'i');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'b');
	SeqListPrint(&seq, "*****对顺序表进行冒泡排序前*****");
	SeqListBubbleSortEx(&seq, int_cmp);
	SeqListPrint(&seq, "*****对顺序表进行从小到大排序*****");
	SeqListBubbleSortEx(&seq, int_cmp1);
	SeqListPrint(&seq, "*****对顺序表进行从大到小排序*****");
}

//测试查找排序
void TestSeqListSelectSort()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'i');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'b');
	SeqListPrint(&seq, "*****对顺序表进行查找排序前*****");
	SeqListSelectSort(&seq);
	SeqListPrint(&seq, "*****对顺序表进行查找排序后*****");
}

//测试二分查找
void TestSeqListBinarySearch()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'i');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'b');
	size_t pos = SeqListBinarySearch(&seq, 'o');
	SeqListPrint(&seq, "*****查找一个不存在的元素o*****");
	printf("o expect -1:%lu\n", pos);
	pos = SeqListBinarySearch(&seq, 'd');
	SeqListPrint(&seq, "*****查找一个存在的元素d*****");
	printf("d expect 1:%lu\n", pos);
}

//测试销毁顺序表
void TestSeqListDestroy()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPrint(&seq, "*****销毁前*****");
	SeqListDestroy(&seq);
	SeqListPrint(&seq, "*****销毁后*****");
}

int main()
{
	TestSeqListInit();
	TestSeqListPushEnd();
	TestSeqListPopEnd();
	TestSeqListPushStart();
	TestSeqListPopStart();
	TestSeqListPushPosition();
	TestSeqListPopPosition();
	TestSeqListSetList();
	TestSeqListGetList();
	TestSeqListGetpos();
	TestSeqListRemove();
	TestSeqListRemoveAll();
	TestSeqListSize();
	TestSeqListEmpty();
	TestSeqListBubbleSort();
	TestSeqListBubbleSortEx();
	TestSeqListSelectSort();
	TestSeqListBinarySearch();
	TestSeqListDestroy();
	return 0;
}
