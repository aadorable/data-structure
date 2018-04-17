#define _CRT_SECURE_NO_WARNINGS 1

#include "dlinklist.h"

#include <windows.h> 

#define TEST_HEADER printf("\n===========================%s===========================\n",__FUNCTION__)

void DLinkListPrintChar(DLinkNode* head, const char* msg)
{
	printf("[%s]��", msg);
	printf("[head]");
	DLinkNode* cur = head->next;
	for (; cur != head; cur = cur->next)
	{
		printf(" -> [%c:%p]", cur->data, cur);
	}
	printf("\n");
	printf("                ");
	printf("[head]");
	for (cur = head->prev; cur != head; cur = cur->prev)
	{
		printf(" -> [%c:%p]", cur->data, cur);
	}
	printf("\n");
}

void TestInit()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	printf("head = %p\n", head);
	printf("head->next = %p\n", head->next);
	printf("head->prev = %p\n", head->prev);
}

void TestPushBack()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
}

void TestPopBack()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");

	DLinkListPopBack(head);
	DLinkListPopBack(head);
	DLinkListPrintChar(head, "βɾ����Ԫ��");

	DLinkListPopBack(head);
	DLinkListPopBack(head);
	DLinkListPrintChar(head, "βɾ����Ԫ��");

	DLinkListPopBack(head);
	DLinkListPrintChar(head, "�Կ�����βɾ");
}

void TestPushFront()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushFront(head, 'd');
	DLinkListPushFront(head, 'c');
	DLinkListPushFront(head, 'b');
	DLinkListPushFront(head, 'a');
	DLinkListPrintChar(head, "ͷ���ĸ�Ԫ��");
}

void TestPopFront()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushFront(head, 'd');
	DLinkListPushFront(head, 'c');
	DLinkListPushFront(head, 'b');
	DLinkListPushFront(head, 'a');
	DLinkListPrintChar(head, "ͷ���ĸ�Ԫ��");

	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrintChar(head, "ͷɾ����Ԫ��");

	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrintChar(head, "ͷɾ����Ԫ��");

	DLinkListPopFront(head);
	DLinkListPrintChar(head, "�Կ�����ͷɾ");
}

void TestFind()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkNode* pos = DLinkListFind(head, 'a');
	printf("[�Կ��������]��");
	printf("pos expect NULL, actual %p\n", pos);

	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	pos = DLinkListFind(head, 'b');
	printf("[����Ԫ��b]��");
	printf("pos expect %p, actual %p\n", pos_b, pos);

	pos = DLinkListFind(head, 'x');
	printf("[���Ҳ�����Ԫ��x]��");
	printf("pos expect NULL, actual %p\n", pos);
}

void TestInsert()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	DLinkListInsert(pos_b, 'x');
	DLinkListPrintChar(head, "��b֮ǰ����x");
}

void TestInsertAfter()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	DLinkListInsertAfter(pos_b, 'x');
	DLinkListPrintChar(head, "��b֮�����x");
}

void TestErase()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	DLinkListErase(head, pos_b);
	DLinkListPrintChar(head, "ɾ��Ԫ��b ��");
}

void TestRemove()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	DLinkListRemove(head, 'a');
	DLinkListPrintChar(head, "ɾ��Ԫ��a ��");

	DLinkListRemove(head, 'x');
	DLinkListPrintChar(head, "ɾ��������Ԫ��x");
}

void TestRemoveAll()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β������Ԫ��");
	DLinkListRemoveAll(head, 'c');
	DLinkListPrintChar(head, "ɾ��Ԫ��c ��");

	DLinkListRemoveAll(head, 'x');
	DLinkListPrintChar(head, "ɾ��������Ԫ��x");
}

void TestSize()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	size_t size = DLinkListSize(head);
	printf("size expect (size_t)-1, actual %lu\n", size);

	DLinkListInit(&head);
	size = DLinkListSize(head);
	printf("size expect 0, actual %lu\n", size);

	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β������Ԫ��");
	size = DLinkListSize(head);
	printf("size expect 6, actual %lu\n", size);
}

void TestEmpty()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	int ret = DLinkListEmpty(head);
	printf("ret expect 1, actual %d\n", ret);

	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	ret = DLinkListEmpty(head);
	printf("ret expect 0, actual %d\n", ret);
}

void TestDestroy()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "β���ĸ�Ԫ��");
	DLinkListDestroy(&head);
	printf("[���������]��head expect NULL, actual %p\n", head);
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
	TestErase();
	TestRemove();
	TestRemoveAll();
	TestSize();
	TestEmpty();
	TestDestroy();
	system("pause");
	return 0;
}