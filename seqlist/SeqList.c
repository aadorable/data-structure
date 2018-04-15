#include "SeqList.h"
#include <stdio.h>
#include <assert.h>

//初始化顺序表
void SeqListInit(SeqList* seq)
{
	assert(seq);
	seq->size = 0;
}

//打印顺序表
void SeqListPrint(SeqList* seq,const char* ch)
{
    if(seq == NULL)
    {
        return;
    }
	printf("%s\n", ch);
	size_t i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("下标为%lu的元素是：[%c]\n",i,seq->SeqListArr[i]);
	}
	printf("size = %lu\n\n", seq->size);
}

//尾插一个元素
void SeqListPushEnd(SeqList* seq, SeqListType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxNum)
	{
		printf("顺序表已满，无法插入！\n\n");
		return;
	}
	else
	{
		seq->SeqListArr[seq->size] = value; 
		seq->size++;
	}
}

// 尾删一个元素
void SeqListPopEnd(SeqList* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("顺序表为空表，无法删除！\n\n");
		return;
	}
	else
	{
		seq->size--;
	}
}

//头插一个元素
void SeqListPushStart(SeqList* seq, SeqListType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxNum)
	{
		printf("顺序表已满，无法插入！\n\n");
		return;
	}
	else
	{
		size_t i = seq->size - 1;
		for (; i >= 0; i--)
		{
			seq->SeqListArr[i + 1] = seq->SeqListArr[i];    //将所有元素后移，为头插元素留出空间
		}
		seq->SeqListArr[0] = value;
		seq->size++;
	}
}

//头删一个元素
void SeqListPopStart(SeqList* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("顺序表为空表，无法删除！\n\n");
		return;
	}
	else
	{
		size_t i = 0;
		for (; i < seq->size - 1;i++)
		{
			seq->SeqListArr[i] = seq->SeqListArr[i+1];     //删除一个元素只需将其覆盖掉即可
		}
		seq->size--;
	}
}

//在下标为pos处插入元素
void SeqListPushPosition(SeqList* seq, size_t pos, SeqListType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxNum)
	{
		printf("顺序表已满，无法插入！\n\n");
		return;
	}
	else if (pos >= seq->size)
	{
		printf("非法坐标！\n\n");
		return;
	}
	else
	{
		size_t i = seq->size - 1;
		for (; i >= pos; i--)
		{
			seq->SeqListArr[i + 1] = seq->SeqListArr[i];      //将pos下标后所有元素后移，为插入元素留出空间
		}
		seq->SeqListArr[pos] = value;
		seq->size++;
	}
}

//删除下标为pos的元素
void SeqListPopPosition(SeqList* seq, size_t pos)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("顺序表为空表，无法删除！\n\n");
		return;
	}
	else if (pos >= seq->size)
	{
		printf("非法坐标！\n\n");
		return;
	}
	else
	{
		size_t i = pos;
		for (; i < seq->size - 1; i++)
		{
			seq->SeqListArr[i] = seq->SeqListArr[i + 1];
		}
		seq->size--;
	}
}

//修改下标为pos的元素
void SeqListSetList(SeqList* seq, size_t pos, SeqListType value)
{
	assert(seq);
	if (pos >= seq->size)
	{
		printf("非法坐标！\n\n");
		return;
	}
	else
	{
		seq->SeqListArr[pos] = value;
	}
}

//读下标为pos的元素
SeqListType SeqListGetList(SeqList* seq, size_t pos)
{
	assert(seq);
	if (pos >= seq->size)
	{
		printf("非法坐标！\n\n");
		return -1;
	}
	else
	{
		return seq->SeqListArr[pos];
	}
}

//查找value元素值的下标
size_t SeqListGetpos(SeqList* seq, SeqListType value)
{
	assert(seq);
	size_t i = 0;
	for (; i < seq->size; i++)
	{
		if (seq->SeqListArr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

//删除指定值的第一个
void SeqListRemove(SeqList *seq, SeqListType to_delete)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("顺序表为空表，无法删除！\n");
		return;
	}
	size_t pos = SeqListGetpos(seq,to_delete);
	if (pos == (size_t)-1)
	{
		return;
	}
	SeqListPopPosition(seq, pos);
}

//删除指定值的所有值
void SeqListRemoveAll(SeqList *seq, SeqListType to_delete)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("顺序表是空表，无法删除！\n");
		return;
	}
	while (1)
	{
		size_t pos = SeqListGetpos(seq, to_delete);
		if (pos == (size_t)-1)
		{
			return;
		}
		SeqListPopPosition(seq, pos);
	}
	return;
}

//获取顺序表中元素个数
size_t SeqListSize(SeqList* seq)
{
	assert(seq);
	return seq->size;
}

//判断顺序表是否是空表
int SeqListEmpty(SeqList* seq)
{
	assert(seq);
	return seq->size == 0 ? 1 : 0;
}


static void swap(SeqListType* a, SeqListType* b)
{
	assert(a);
	assert(b);
	SeqListType tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
//冒泡排序
void SeqListBubbleSort(SeqList* seq)
{
	assert(seq);
	size_t count = 0;
	for (; count < seq->size - 1; ++count)
	{
		size_t flag = 0;
		size_t cur = 0;
		for (cur = 0; cur < seq->size - 1 - count; ++cur)
		{
			if (seq->SeqListArr[cur] > seq->SeqListArr[cur + 1])
			{
				flag = 1;
				swap(&seq->SeqListArr[cur], &seq->SeqListArr[cur + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//利用回调函数的冒泡排序
void SeqListBubbleSortEx(SeqList* seq, int(*cmp)(SeqListType, SeqListType))
{
	assert(seq);
	size_t count = 0;
	for (; count < seq->size - 1; ++count)
	{
		int flag = 0;
		size_t cur = 0;
		for (cur = 0; cur < seq->size - 1 - count; ++cur)
		{
			if (cmp(seq->SeqListArr[cur], seq->SeqListArr[cur + 1])>0)
			{
				flag = 1;
				swap(&seq->SeqListArr[cur], &seq->SeqListArr[cur + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//查找排序
void SeqListSelectSort(SeqList* seq)
{
	assert(seq);
	size_t min_pos = 0;
	for (; min_pos < seq->size; ++min_pos)
	{
		size_t cur = min_pos;
		for (; cur < seq->size; ++cur)
		{
			if (seq->SeqListArr[cur] < seq->SeqListArr[min_pos])
			{
				swap(&seq->SeqListArr[cur], &seq->SeqListArr[min_pos]);
			}
		}
	}
	return;
}

//二分查找
size_t SeqListBinarySearch(SeqList* seq, SeqListType value)
{
	assert(seq);
	size_t start = 0;
	size_t end = seq->size;
	while (start < end)
	{
		size_t mid = start + (end - start) / 2;
		if (value > seq->SeqListArr[mid])
		{
			start = mid + 1;
		}
		else if (value < seq->SeqListArr[mid])
		{
			end = mid;
		}
		else
		{
			return mid;
		}
	}
	return (size_t)-1;
}

//销毁顺序表
void SeqListDestroy(SeqList* seq)
{
	assert(seq);
	seq->size = 0;
	return;
}
