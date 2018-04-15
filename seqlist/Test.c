
//�����ǲ��Դ���
#include "SeqList.h"
#include <stdio.h>

//#define TEST_HEADER printf("\n===================%s===================\n",__FUNCTION__)

//���Գ�ʼ��˳���
void TestSeqListInit()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPrint(&seq,"*****��ʼ��˳���*****");
}

//����β��һ��Ԫ��
void TestSeqListPushEnd()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPrint(&seq, "*****β���ĸ�Ԫ����˳���*****");
}

// ����βɾһ��Ԫ��
void TestSeqListPopEnd()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopEnd(&seq);
	SeqListPrint(&seq, "*****��˳�����βɾһ��Ԫ��*****");
	printf("�ձ������\n");
	SeqListInit(&seq);
	SeqListPopEnd(&seq);
}

//����ͷ��һ��Ԫ��
void TestSeqListPushStart()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushStart(&seq, 'e');
	SeqListPrint(&seq, "*****ͷ��һ��Ԫ����˳���*****");
}

//����ͷɾһ��Ԫ��
void TestSeqListPopStart()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopStart(&seq);
	SeqListPrint(&seq, "*****��˳�����ͷɾһ��Ԫ��*****");
	printf("�ձ������\n");
	SeqListInit(&seq);
	SeqListPopStart(&seq);
}

//�������±�Ϊpos������Ԫ��
void TestSeqListPushPosition()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushPosition(&seq, 2, 's');
	SeqListPrint(&seq, "*****��˳�����ָ��λ�ò���һ��Ԫ��*****");
	printf("�Ƿ��������(���±�Ϊ20��λ�ò���Ԫ��)��\n");
	SeqListPushPosition(&seq, 20, 'r');
}

//����ɾ���±�Ϊpos��Ԫ��
void TestSeqListPopPosition()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopPosition(&seq, 2);
	SeqListPrint(&seq, "*****��˳�����ָ��λ��ɾ��һ��Ԫ��*****");
	printf("�Ƿ��������(ɾ���±�Ϊ8��Ԫ��)��\n");
	SeqListPopPosition(&seq, 8);
}

//�����޸��±�Ϊpos��Ԫ��
void TestSeqListSetList()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListSetList(&seq, 1, 'o');
	SeqListPrint(&seq, "*****��˳������޸�ָ��λ�õ�Ԫ��*****");
	printf("�Ƿ��������(�޸��±�Ϊ10��Ԫ��)��\n");
	SeqListSetList(&seq, 10,'k');
}

//���Զ�ȡ�±�Ϊpos��Ԫ��
void TestSeqListGetList()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'g');
	SeqListPushEnd(&seq, 'h');
	SeqListPrint(&seq, "*****��˳����ж�ȡָ��λ��Ԫ��*****");
	char ch = SeqListGetList(&seq, 1);
	printf("�±�Ϊ1��Ԫ��Ϊ%c\n", ch);
	printf("�Ƿ��������(��ȡ�±�Ϊ6��Ԫ��)��\n");
	SeqListGetList(&seq, 6);
}

//���Բ���valueԪ��ֵ���±�
void TestSeqListGetpos()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'g');
	SeqListPushEnd(&seq, 'h');
	SeqListPrint(&seq, "*****��˳����ж�ȡָ��λ��Ԫ���±�*****");
	size_t pos = SeqListGetpos(&seq, 'h');
	printf("hԪ�ص��±�Ϊ%ld\n", pos);
	printf("�Ƿ����(��ȡԪ��W���±�)��\n");
	size_t pos1 = SeqListGetpos(&seq, 'W');
	printf("WԪ�ص��±�Ϊ%ld������Ƿ���\n\n", pos1);
}

//����ɾ��ָ��ֵ�ĵ�һ��
void TestSeqListRemove()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListRemove(&seq, 'a');
	SeqListPrint(&seq, "*****�����ڿձ���ɾ��*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'c');
	SeqListRemove(&seq, 'c');
	SeqListPrint(&seq, "*****ɾ��˳�����ָ��Ԫ�صĵ�һ��*****");
}

//����ɾ��ָ��ֵ������ֵ
void TestSeqListRemoveAll()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListRemoveAll(&seq, 'a');
	SeqListPrint(&seq, "*****�����ڿձ���ɾ��*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'c');
	SeqListRemoveAll(&seq, 'c');
	SeqListPrint(&seq, "*****ɾ��˳�����ָ��Ԫ�ص�����ֵ*****");
}

//���Ի�ȡ˳�����Ԫ�ظ���
void TestSeqListSize()
{
	SeqList seq;
	SeqListInit(&seq);
	size_t count = SeqListSize(&seq);
	printf("count = %lu\n", count);
	SeqListPrint(&seq, "*****ͳ�ƿձ���Ԫ�ظ���*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushEnd(&seq, 'e');
	size_t count1 = SeqListSize(&seq);
	printf("count = %lu\n", count1);
	SeqListPrint(&seq, "*****ͳ��˳�����Ԫ�ظ���*****");
}

//�����ж�˳����Ƿ��ǿձ�
void TestSeqListEmpty()
{
	SeqList seq;
	SeqListInit(&seq);
	int flag = SeqListEmpty(&seq);
	if (flag == 0)
	{
		printf("��˳����ǿձ�\n");
	}
	else
	{
		printf("��˳����ǿձ�\n");
	}
	SeqListPrint(&seq, "*****˳����ǿձ�*****");
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	flag = SeqListEmpty(&seq);
	if (flag == 0)
	{
		printf("��˳����ǿձ�\n");
	}
	else
	{
		printf("��˳����ǿձ�\n");
	}
	SeqListPrint(&seq, "*****˳����ǿձ����*****");
}

//����ð������
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
	SeqListPrint(&seq, "*****��˳������ð������ǰ*****");
	SeqListBubbleSort(&seq);
	SeqListPrint(&seq, "*****��˳������ð�������*****");
}

//�������ûص�������ð������
int int_cmp(const SeqListType a, const SeqListType b)            //��С����˳������
{
	return a > b;
}
int int_cmp1(const SeqListType a, const SeqListType b)            //�Ӵ�С˳������
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
	SeqListPrint(&seq, "*****��˳������ð������ǰ*****");
	SeqListBubbleSortEx(&seq, int_cmp);
	SeqListPrint(&seq, "*****��˳�����д�С��������*****");
	SeqListBubbleSortEx(&seq, int_cmp1);
	SeqListPrint(&seq, "*****��˳�����дӴ�С����*****");
}

//���Բ�������
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
	SeqListPrint(&seq, "*****��˳�����в�������ǰ*****");
	SeqListSelectSort(&seq);
	SeqListPrint(&seq, "*****��˳�����в��������*****");
}

//���Զ��ֲ���
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
	SeqListPrint(&seq, "*****����һ�������ڵ�Ԫ��o*****");
	printf("o expect -1:%lu\n", pos);
	pos = SeqListBinarySearch(&seq, 'd');
	SeqListPrint(&seq, "*****����һ�����ڵ�Ԫ��d*****");
	printf("d expect 1:%lu\n", pos);
}

//��������˳���
void TestSeqListDestroy()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPrint(&seq, "*****����ǰ*****");
	SeqListDestroy(&seq);
	SeqListPrint(&seq, "*****���ٺ�*****");
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
