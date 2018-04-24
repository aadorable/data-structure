#define _CRT_SECURE_NO_WARNINGS 1

#include "search_tree.h"

#include <stdio.h>
#include <windows.h>

#define TEST_HEADER printf("\n===========================%s====================\n",__FUNCTION__)

void TestInit()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	printf("root except NULL,actual %p\n", root);
}

void PreOrder(SearchTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->key);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
	return;
}

void InOrder(SearchTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->lchild);
	printf("%c ", root->key);
	InOrder(root->rchild);
	return;
}

void TestInsert1()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert1(&root, 'd');
	SearchTreeInsert1(&root, 'h');
	SearchTreeInsert1(&root, 'f');
	SearchTreeInsert1(&root, 'a');
	SearchTreeInsert1(&root, 'l');
	SearchTreeInsert1(&root, 'e');
	SearchTreeInsert1(&root, 'c');
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");
}

void TestInsert2()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert2(&root, 'd');
	SearchTreeInsert2(&root, 'h');
	SearchTreeInsert2(&root, 'f');
	SearchTreeInsert2(&root, 'a');
	SearchTreeInsert2(&root, 'l');
	SearchTreeInsert2(&root, 'e');
	SearchTreeInsert2(&root, 'c');
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");
}

void TestFind1()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert1(&root, 'd');
	SearchTreeInsert1(&root, 'h');
	SearchTreeInsert1(&root, 'f');
	SearchTreeInsert1(&root, 'a');
	SearchTreeInsert1(&root, 'l');
	SearchTreeInsert1(&root, 'e');
	SearchTreeInsert1(&root, 'c');

	SearchTreeNode* ret = SearchTreeFind1(root, 'f');
	printf("查找f：ret expect %p,actual %p\n", root->rchild->lchild, ret);

	ret = SearchTreeFind1(root, 'c');
	printf("查找c：ret expect %p,actual %p\n", root->lchild->rchild, ret);
}

void TestFind2()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert1(&root, 'd');
	SearchTreeInsert1(&root, 'h');
	SearchTreeInsert1(&root, 'f');
	SearchTreeInsert1(&root, 'a');
	SearchTreeInsert1(&root, 'l');
	SearchTreeInsert1(&root, 'e');
	SearchTreeInsert1(&root, 'c');

	SearchTreeNode* ret = SearchTreeFind2(root, 'f');
	printf("查找f：ret expect %p,actual %p\n", root->rchild->lchild, ret);

	ret = SearchTreeFind2(root, 'c');
	printf("查找c：ret expect %p,actual %p\n", root->lchild->rchild, ret);
}

void TestRemove1()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert1(&root, 'd');
	SearchTreeInsert1(&root, 'h');
	SearchTreeInsert1(&root, 'f');
	SearchTreeInsert1(&root, 'a');
	SearchTreeInsert1(&root, 'l');
	SearchTreeInsert1(&root, 'e');
	SearchTreeInsert1(&root, 'c');
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove1(&root, 'h');
	printf("删除h后：\n");
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove1(&root, 'd');
	printf("删除d后：\n");
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove1(&root, 'c');
	printf("删除c后：\n");
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");
}

void TestRemove2()
{
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert1(&root, 'd');
	SearchTreeInsert1(&root, 'h');
	SearchTreeInsert1(&root, 'f');
	SearchTreeInsert1(&root, 'a');
	SearchTreeInsert1(&root, 'l');
	SearchTreeInsert1(&root, 'e');
	SearchTreeInsert1(&root, 'c');
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove2(&root, 'h');
	printf("删除h后：\n");
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove2(&root, 'd');
	printf("删除d后：\n");
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove2(&root, 'c');
	printf("删除c后：\n");
	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");
}

int main()
{
	TestInit();
	TestInsert1();
	TestInsert2();
	TestFind1();
	TestFind2();
	TestRemove1();
	TestRemove2();
	system("pause");
	return 0;
}