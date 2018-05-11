
#include "bin_tree.h"
#include <stdio.h>

#define TEST_HEADER printf("\n========================%s====================\n",__FUNCTION__)

void TestInit(){
	TEST_HEADER;
	TreeNode* root;
	TreeInit(&root);
	printf("root expect NULL, actual %p\n",root);
}

void TestPreOrder(){
	TEST_HEADER;
	TreeNode* root;
	TreeInit(&root);
	TreeNode* a = CreateTreeNode('a');
	TreeNode* b = CreateTreeNode('b');
	TreeNode* c = CreateTreeNode('c');
	TreeNode* d = CreateTreeNode('d');
	TreeNode* e = CreateTreeNode('e');
	TreeNode* f = CreateTreeNode('f');
	TreeNode* g = CreateTreeNode('g');
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;

	printf("[先序遍历结果]：");
	PreOrder(root);
	printf("\n");
}

void TestInOrder(){
	TEST_HEADER;
	TreeNode* root;
	TreeInit(&root);
	TreeNode* a = CreateTreeNode('a');
	TreeNode* b = CreateTreeNode('b');
	TreeNode* c = CreateTreeNode('c');
	TreeNode* d = CreateTreeNode('d');
	TreeNode* e = CreateTreeNode('e');
	TreeNode* f = CreateTreeNode('f');
	TreeNode* g = CreateTreeNode('g');
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;

	printf("[中序遍历结果]：");
	InOrder(root);
	printf("\n");
}

void TestPostOrder(){
	TEST_HEADER;
	TreeNode* root;
	TreeInit(&root);
	TreeNode* a = CreateTreeNode('a');
	TreeNode* b = CreateTreeNode('b');
	TreeNode* c = CreateTreeNode('c');
	TreeNode* d = CreateTreeNode('d');
	TreeNode* e = CreateTreeNode('e');
	TreeNode* f = CreateTreeNode('f');
	TreeNode* g = CreateTreeNode('g');
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;

	printf("[后序遍历结果]：");
	PostOrder(root);
	printf("\n");
}

void TestLevelOrder(){
    TEST_HEADER;
    TreeNode* root;
    TreeInit(&root);
    TreeNode* a = CreateTreeNode('a');
	TreeNode* b = CreateTreeNode('b');
	TreeNode* c = CreateTreeNode('c');
	TreeNode* d = CreateTreeNode('d');
	TreeNode* e = CreateTreeNode('e');
	TreeNode* f = CreateTreeNode('f');
	TreeNode* g = CreateTreeNode('g');
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;

    printf("[层序遍历结果]：");
    LevelOrder(root);
    printf("\n");
}

void TestCreate(){
    TEST_HEADER;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array,strlen(array),'#');

    printf("[先序遍历结果]：");
    PreOrder(root);
    printf("\n");

    printf("[中序遍历结果]：");
    InOrder(root);
    printf("\n");

    printf("[后序遍历结果]：");
    PostOrder(root);
    printf("\n");
}

void TestDestroy(){
    TEST_HEADER;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array,strlen(array),'#');

    TreeDestroy(&root);
    printf("root expect NULL, actual %p\n", root);
}

void TestClone(){
    TEST_HEADER;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array,strlen(array),'#');

    TreeNode* new_root = TreeClone(root);
    printf("new_root: %p, root: %p\n",new_root,root);

    printf("[先序遍历结果]：");
    PreOrder(new_root);
    printf("\n");

    printf("[中序遍历结果]：");
    InOrder(new_root);
    printf("\n");

    printf("[后序遍历结果]：");
    PostOrder(new_root);
    printf("\n");
}

void TestSize(){
    TEST_HEADER;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array,strlen(array),'#');
    printf("size expect 7, actual %lu\n",TreeSize(root));
}

void TestLeafSize(){
    TEST_HEADER;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array,strlen(array),'#');
    printf("leafsize expect 3, actual %lu\n",TreeLeafSize(root));
}

int main(){
	TestInit();
	TestPreOrder();
	TestInOrder();
	TestPostOrder();
    TestLevelOrder();
    TestCreate();
    TestDestroy();
    TestClone();
    TestSize();
    TestLeafSize();
	return 0;
}
