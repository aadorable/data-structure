#define _CRT_SECURE_NO_WARNINGS 1

#include "dlinklist.h"

#include <windows.h> 

#define TEST_HEADER printf("\n===========================%s===========================\n",__FUNCTION__)

void DLinkListPrintChar(DLinkNode* head, const char* msg)
{
	printf("[%s]：", msg);
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
	DLinkListPrintChar(head, "尾插四个元素");
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
	DLinkListPrintChar(head, "尾插四个元素");

	DLinkListPopBack(head);
	DLinkListPopBack(head);
	DLinkListPrintChar(head, "尾删两个元素");

	DLinkListPopBack(head);
	DLinkListPopBack(head);
	DLinkListPrintChar(head, "尾删两个元素");

	DLinkListPopBack(head);
	DLinkListPrintChar(head, "对空链表尾删");
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
	DLinkListPrintChar(head, "头插四个元素");
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
	DLinkListPrintChar(head, "头插四个元素");

	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrintChar(head, "头删两个元素");

	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrintChar(head, "头删两个元素");

	DLinkListPopFront(head);
	DLinkListPrintChar(head, "对空链表头删");
}

void TestFind()
{
	TEST_HEADER;
	DLinkNode* head = NULL;
	DLinkListInit(&head);
	DLinkNode* pos = DLinkListFind(head, 'a');
	printf("[对空链表查找]：");
	printf("pos expect NULL, actual %p\n", pos);

	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrintChar(head, "尾插四个元素");
	pos = DLinkListFind(head, 'b');
	printf("[查找元素b]：");
	printf("pos expect %p, actual %p\n", pos_b, pos);

	pos = DLinkListFind(head, 'x');
	printf("[查找不存在元素x]：");
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
	DLinkListPrintChar(head, "尾插四个元素");
	DLinkListInsert(pos_b, 'x');
	DLinkListPrintChar(head, "在b之前插入x");
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
	DLinkListPrintChar(head, "尾插四个元素");
	DLinkListInsertAfter(pos_b, 'x');
	DLinkListPrintChar(head, "在b之后插入x");
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
	DLinkListPrintChar(head, "尾插四个元素");
	DLinkListErase(head, pos_b);
	DLinkListPrintChar(head, "删除元素b 后");
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
	DLinkListPrintChar(head, "尾插四个元素");
	DLinkListRemove(head, 'a');
	DLinkListPrintChar(head, "删除元素a 后");

	DLinkListRemove(head, 'x');
	DLinkListPrintChar(head, "删除不存在元素x");
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
	DLinkListPrintChar(head, "尾插六个元素");
	DLinkListRemoveAll(head, 'c');
	DLinkListPrintChar(head, "删除元素c 后");

	DLinkListRemoveAll(head, 'x');
	DLinkListPrintChar(head, "删除不存在元素x");
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
	DLinkListPrintChar(head, "尾插六个元素");
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
	DLinkListPrintChar(head, "尾插四个元素");
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
	DLinkListPrintChar(head, "尾插四个元素");
	DLinkListDestroy(&head);
	printf("[销毁链表后]：head expect NULL, actual %p\n", head);
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