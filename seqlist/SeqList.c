#include "SeqList.h"
#include <stdio.h>
#include <assert.h>

//��ʼ��˳���
void SeqListInit(SeqList* seq)
{
	assert(seq);
	seq->size = 0;
}

//��ӡ˳���
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
		printf("�±�Ϊ%lu��Ԫ���ǣ�[%c]\n",i,seq->SeqListArr[i]);
	}
	printf("size = %lu\n\n", seq->size);
}

//β��һ��Ԫ��
void SeqListPushEnd(SeqList* seq, SeqListType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxNum)
	{
		printf("˳����������޷����룡\n\n");
		return;
	}
	else
	{
		seq->SeqListArr[seq->size] = value; 
		seq->size++;
	}
}

// βɾһ��Ԫ��
void SeqListPopEnd(SeqList* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("˳���Ϊ�ձ��޷�ɾ����\n\n");
		return;
	}
	else
	{
		seq->size--;
	}
}

//ͷ��һ��Ԫ��
void SeqListPushStart(SeqList* seq, SeqListType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxNum)
	{
		printf("˳����������޷����룡\n\n");
		return;
	}
	else
	{
		size_t i = seq->size - 1;
		for (; i >= 0; i--)
		{
			seq->SeqListArr[i + 1] = seq->SeqListArr[i];    //������Ԫ�غ��ƣ�Ϊͷ��Ԫ�������ռ�
		}
		seq->SeqListArr[0] = value;
		seq->size++;
	}
}

//ͷɾһ��Ԫ��
void SeqListPopStart(SeqList* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("˳���Ϊ�ձ��޷�ɾ����\n\n");
		return;
	}
	else
	{
		size_t i = 0;
		for (; i < seq->size - 1;i++)
		{
			seq->SeqListArr[i] = seq->SeqListArr[i+1];     //ɾ��һ��Ԫ��ֻ�轫�串�ǵ�����
		}
		seq->size--;
	}
}

//���±�Ϊpos������Ԫ��
void SeqListPushPosition(SeqList* seq, size_t pos, SeqListType value)
{
	assert(seq);
	if (seq->size >= SeqListMaxNum)
	{
		printf("˳����������޷����룡\n\n");
		return;
	}
	else if (pos >= seq->size)
	{
		printf("�Ƿ����꣡\n\n");
		return;
	}
	else
	{
		size_t i = seq->size - 1;
		for (; i >= pos; i--)
		{
			seq->SeqListArr[i + 1] = seq->SeqListArr[i];      //��pos�±������Ԫ�غ��ƣ�Ϊ����Ԫ�������ռ�
		}
		seq->SeqListArr[pos] = value;
		seq->size++;
	}
}

//ɾ���±�Ϊpos��Ԫ��
void SeqListPopPosition(SeqList* seq, size_t pos)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("˳���Ϊ�ձ��޷�ɾ����\n\n");
		return;
	}
	else if (pos >= seq->size)
	{
		printf("�Ƿ����꣡\n\n");
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

//�޸��±�Ϊpos��Ԫ��
void SeqListSetList(SeqList* seq, size_t pos, SeqListType value)
{
	assert(seq);
	if (pos >= seq->size)
	{
		printf("�Ƿ����꣡\n\n");
		return;
	}
	else
	{
		seq->SeqListArr[pos] = value;
	}
}

//���±�Ϊpos��Ԫ��
SeqListType SeqListGetList(SeqList* seq, size_t pos)
{
	assert(seq);
	if (pos >= seq->size)
	{
		printf("�Ƿ����꣡\n\n");
		return -1;
	}
	else
	{
		return seq->SeqListArr[pos];
	}
}

//����valueԪ��ֵ���±�
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

//ɾ��ָ��ֵ�ĵ�һ��
void SeqListRemove(SeqList *seq, SeqListType to_delete)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("˳���Ϊ�ձ��޷�ɾ����\n");
		return;
	}
	size_t pos = SeqListGetpos(seq,to_delete);
	if (pos == (size_t)-1)
	{
		return;
	}
	SeqListPopPosition(seq, pos);
}

//ɾ��ָ��ֵ������ֵ
void SeqListRemoveAll(SeqList *seq, SeqListType to_delete)
{
	assert(seq);
	if (seq->size == 0)
	{
		printf("˳����ǿձ��޷�ɾ����\n");
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

//��ȡ˳�����Ԫ�ظ���
size_t SeqListSize(SeqList* seq)
{
	assert(seq);
	return seq->size;
}

//�ж�˳����Ƿ��ǿձ�
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
//ð������
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

//���ûص�������ð������
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

//��������
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

//���ֲ���
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

//����˳���
void SeqListDestroy(SeqList* seq)
{
	assert(seq);
	seq->size = 0;
	return;
}
