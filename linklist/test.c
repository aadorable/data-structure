#include "linklist.h"

#define TEST_HEADER printf("\n========================================%s===========================================\n",__FUNCTION__)

void TestInit()
{
	LinkNode* head;
	LinkListInit(&head);
	printf("head = %p,%ld\n", head,(long)head);
}

void TestPushBack()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
}

void TestPopBack()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPopBack(&head);
	LinkListPrintChar(head, "���ԶԿ�����βɾ");
	LinkListPushBack(&head, 'a');
	LinkListPopBack(&head);
	LinkListPrintChar(head, "���Զ�ֻ��һ��Ԫ������βɾ");
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	LinkListPopBack(&head);
	LinkListPopBack(&head);
	LinkListPrintChar(head, "βɾ������Ԫ��");
}

void TestPushFront()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head, 'a');
	LinkListPushFront(&head, 'b');
	LinkListPushFront(&head, 'c');
	LinkListPushFront(&head, 'd');
	LinkListPrintChar(head, "ͷ���ĸ�Ԫ��");
}

void TestPopFront()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPopFront(&head);
	LinkListPrintChar(head, "���ԶԿ�����ͷɾ");
	LinkListPushFront(&head, 'a');
	LinkListPushFront(&head, 'b');
	LinkListPushFront(&head, 'c');
	LinkListPushFront(&head, 'd');
	LinkListPrintChar(head, "ͷ���ĸ�Ԫ��");
	LinkListPopFront(&head);
	LinkListPopFront(&head);
	LinkListPrintChar(head, "ͷɾ����Ԫ��");
	LinkListPopFront(&head);
	LinkListPopFront(&head);
	LinkListPrintChar(head, "��ͷɾ����Ԫ��");
}

void TestFind()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkNode* pos_c = LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");

	LinkNode* pos = LinkListFind(head, 'e');
	printf("[����e]��pos expect NULL,actual %p\n", pos);

	pos = LinkListFind(head, 'c');
	printf("[����c]��pos expect %p,actual %p\n", pos_c, pos);
}

void TestInsert()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListInsert(&head, head, 'b');
	LinkListPrintChar(head, "�Կ��������");

	LinkListInsert(&head, head, 'a');
	LinkListPrintChar(head, "��ֻ��ͷ����������");

	LinkNode* pos = LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β��һ��Ԫ��");

	LinkListInsert(&head, pos, 'c');
	LinkListPrintChar(head, "��d֮ǰ����");

	LinkListInsert(&head, NULL, 'e');
	LinkListPrintChar(head, "������β������");
}

void TestInsertAfter()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListInsertAfter(&head, head, 'a');
	LinkListPrintChar(head, "�Կ��������");

	LinkListInsertAfter(&head, head, 'b');
	LinkListPrintChar(head, "��ֻ��ͷ����������");

	LinkNode* pos = LinkListPushBack(&head, 'c');
	LinkListPrintChar(head, "β��һ��Ԫ��");

	LinkListInsertAfter(&head, pos, 'd');
	LinkListPrintChar(head, "��c֮�����");
}

void TestErase1()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListErase1(&head, NULL);
	LinkListPrintChar(head, "���ԶԿ��������ɾ��");
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkNode* pos_c = LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	LinkListErase1(&head, pos_c);
	LinkListPrintChar(head, "ɾ��Ԫ��c");
}

void TestErase2()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListErase2(&head, NULL);
	LinkListPrintChar(head, "���ԶԿ��������ɾ��");
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkNode* pos_c = LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	LinkListErase2(&head, &pos_c);
	LinkListPrintChar(head, "ɾ��Ԫ��c");
}

void TestRemove1()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");

	LinkListRemove1(&head, 'e');
	LinkListPrintChar(head, "����ɾ��������Ԫ��e");
	LinkListRemove1(&head, 'c');
	LinkListPrintChar(head, "����ɾ��Ԫ��c");
}

void TestRemove2()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");

	LinkListRemove2(&head, 'e');
	LinkListPrintChar(head, "����ɾ��������Ԫ��e");
	LinkListRemove2(&head, 'c');
	LinkListPrintChar(head, "����ɾ��Ԫ��c");
}

void TestRemoveAll()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListRemoveAll(&head, 'a');
	LinkListPrintChar(head, "���ԶԿ��������ɾ��");

	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���߸�Ԫ��");

	LinkListRemoveAll(&head, 'e');
	LinkListPrintChar(head, "����ɾ��������Ԫ��e");
	LinkListRemoveAll(&head, 'c');
	LinkListPrintChar(head, "����ɾ��Ԫ��c");
}

void TestEmpty()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	int ret = LinkListEmpty(head);
	printf("ret expect 1,actual %d\n", ret);

	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	ret = LinkListEmpty(head);
	printf("ret expect 0,actual %d\n", ret);
}

void TestSize()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	size_t ret = LinkListSize(head);
	printf("ret expect 0,actual %d\n", ret);

	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	ret = LinkListSize(head);
	printf("ret expect 4,actual %d\n", ret);
}

//����������

void TestReversePrint()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	printf("[�����ӡ]��");
	LinkListReversePrint(head);
	printf("\n");
}

void TestInsertBefore()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkNode* pos_c = LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPrintChar(head, "β���ĸ�Ԫ��");
	LinkListInsertBefore(&head, pos_c, 'x');
	LinkListPrintChar(head, "��c֮ǰ����Ԫ��x");
}

void TestJosephCycle()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPushBack(&head, 'f');
	LinkListPushBack(&head, 'g');
	LinkNode* pos = LinkListPushBack(&head, 'h');
	pos->next = head;
	pos = JosephCycle(head, 5);
	printf("JosephCycle: %c\n", pos->data);
}

void TestReverse()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPushBack(&head, 'f');
	LinkListPrintChar(head, "β������Ԫ��");
	LinkListReverse(&head);
	LinkListPrintChar(head, "���ú�Ľ��");
}

void TestReverse2()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPushBack(&head, 'f');
	LinkListPrintChar(head, "β������Ԫ��");
	LinkListReverse2(&head);
	LinkListPrintChar(head, "���ú�Ľ��");
}

void TestBubbleSort()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'f');
	LinkListPushBack(&head, 'e');
	LinkListPushBack(&head, 'c');
	LinkListPrintChar(head, "β������Ԫ��");
	LinkListBubbleSort(head);
	LinkListPrintChar(head, "�����Ľ��");
}

void TestMerge()
{
	TEST_HEADER;
	LinkNode* head1 = NULL;
	LinkListInit(&head1);
	LinkListPushBack(&head1, 'a');
	LinkListPushBack(&head1, 'd');
	LinkListPushBack(&head1, 'e');
	LinkListPushBack(&head1, 'h');
	LinkListPrintChar(head1, "β���ĸ�Ԫ��");

	LinkNode* head2 = NULL;
	LinkListInit(&head2);
	LinkListPushBack(&head2, 'b');
	LinkListPushBack(&head2, 'c');
	LinkListPushBack(&head2, 'f');
	LinkListPrintChar(head2, "β������Ԫ��");

	LinkNode* new_head = LinkListMerge(head1, head2);
	LinkListPrintChar(new_head, "�ϲ���Ľ��");
}

void TestMidNode()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPrintChar(head, "β�����Ԫ��");
	LinkNode* mid = FindMidNode(head);
	printf("mid expect c, actual %c\n", mid->data);
}

void TestLastK()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPrintChar(head, "β�����Ԫ��");
	LinkNode* node = FindLastKNode(head, 2);
	printf("last 2 node expect d,actual %c\n", node->data);
}

void TestEraseLastK()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPrintChar(head, "β�����Ԫ��");
	EraseLastKNode(&head, 2);
	LinkListPrintChar(head, "ɾ��d ����");
}

void TestHasCycle()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkNode* pos = LinkListPushBack(&head, 'e');
	pos->next = head;
	printf("list has cycle: expect 1, actual %p\n", HasCycle(head));
}

void TestCycleLen()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkNode* pos = LinkListPushBack(&head, 'e');
	pos->next = head;
	printf("cycle len expect 5, actual %lu\n", GetCycleLen(head));
}

void TestGetEntry()
{
	TEST_HEADER;
	LinkNode* head = NULL;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkNode* pos_c = LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	LinkListPushBack(&head, 'f');
	LinkNode* pos_g = LinkListPushBack(&head, 'g');
	pos_g->next = pos_c;
	printf("cycle entry expect c,actual %c\n", GetCycleEntry(head)->data);
}

void TestHasCross()
{
	TEST_HEADER;
	LinkNode* head1 = NULL;
	LinkListInit(&head1);
	LinkListPushBack(&head1, 'a');
	LinkNode* pos_d = LinkListPushBack(&head1, 'd');
	LinkListPushBack(&head1, 'e');
	LinkListPushBack(&head1, 'h');

	LinkNode* head2 = NULL;
	LinkListInit(&head2);
	LinkListPushBack(&head2, 'b');
	LinkListPushBack(&head2, 'c');
	LinkNode* pos_f = LinkListPushBack(&head2, 'f');
	pos_f->next = pos_d;

	LinkNode* cross = HasCross(head1, head2);
	printf("cross expect d, actual %c\n", cross->data);
}

void TestHasCrossWithCycle()
{
	TEST_HEADER;
	LinkNode* head1 = NULL;
	LinkListInit(&head1);
	LinkNode* pos_a = LinkListPushBack(&head1, 'a');
	LinkNode* pos_b = LinkListPushBack(&head1, 'b');
	LinkListPushBack(&head1, 'c');
	LinkNode* pos_d = LinkListPushBack(&head1, 'd');
	pos_d->next = pos_b;

	LinkNode* head2 = NULL;
	LinkListInit(&head2);
	LinkListPushBack(&head2, 'e');
	LinkListPushBack(&head2, 'f');
	LinkNode* pos_g = LinkListPushBack(&head2, 'g');
	pos_g->next = pos_a;

	int ret = HasCrossWithCycle(head1, head2);
	printf("ret expect 1, actual %d\n", ret);
}

void TestUnionSet()
{
	TEST_HEADER;
	LinkNode* head1 = NULL;
	LinkListInit(&head1);
	LinkListPushBack(&head1, 'a');
	LinkListPushBack(&head1, 'd');
	LinkListPushBack(&head1, 'e');
	LinkListPushBack(&head1, 'h');
	LinkListPrintChar(head1, "��������һ");

	LinkNode* head2 = NULL;
	LinkListInit(&head2);
	LinkListPushBack(&head2, 'b');
	LinkListPushBack(&head2, 'c');
	LinkListPushBack(&head2, 'd');
	LinkListPushBack(&head2, 'e');
	LinkListPushBack(&head2, 'f');
	LinkListPushBack(&head2, 'h');
	LinkListPrintChar(head2, "���������");

	LinkNode* new_head = UnionSet(head1, head2);
	LinkListPrintChar(new_head, "��������");
}

void TestComplexCopy()
{
	TEST_HEADER;
	ComplexNode* a = CreateComplexNode('a');
	ComplexNode* b = CreateComplexNode('b');
	ComplexNode* c = CreateComplexNode('c');
	ComplexNode* d = CreateComplexNode('d');
	a->next = a;
	b->next = c;
	c->next = d;
	d->next = NULL;
	a->random = c;
	b->random = a;
	c->random = NULL;
	d->random = d;

	ComplexNode* new_head = CopyComplex2(a);
	printf("new_head:%p\n", new_head);
}

int main()
{
	TestInit();
	TestPushBack();
	TestPopBack();
	TestPushFront();
	TestPopFront();
	TestFind();
	TestInsert();
	TestInsertAfter();
	TestErase1();
	TestErase2();
	TestRemove1();
	TestRemove2();
	TestRemoveAll();
	TestEmpty();
	TestSize();
	//����������
	TestReversePrint();
	TestInsertBefore();
	TestJosephCycle();
	TestReverse();
	TestReverse2();
	TestBubbleSort();
	TestMerge();
	TestMidNode();
	TestLastK();
	TestEraseLastK();
	TestHasCycle();
	TestCycleLen();
	TestGetEntry();
	TestHasCross();
	TestHasCrossWithCycle();
	TestUnionSet();
	//TestComplexCopy();
	return 0;
}
