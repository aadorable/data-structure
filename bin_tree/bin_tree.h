#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef char TreeNodeType;

typedef struct TreeNode{
	TreeNodeType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

void TreeInit(TreeNode** root);

void PreOrder(TreeNode* root);      //先序遍历

void InOrder(TreeNode* root);       //中序遍历

void PostOrder(TreeNode* root);     //后序遍历

void LevelOrder(TreeNode* root);    //层序遍历

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node);     //通过给出遍历结果创造一棵树

void TreeDestroy(TreeNode** root);  //销毁一棵树

TreeNode* TreeClone(TreeNode* root);    //克隆一棵树

size_t TreeSize(TreeNode* root);    //求树的节点数

size_t TreeLeafSize(TreeNode* root);    //求树的叶子节点数

size_t TreeKLevelSize(TreeNode* root, int K);   //求树的第K层节点数

size_t TreeHeight(TreeNode* root);

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find);

TreeNode* LChild(TreeNode* node);

TreeNode* RChild(TreeNode* node);

TreeNode* Parent(TreeNode* root, TreeNode* node);

void PreOrderByLoop(TreeNode* root);

void InOrderByLoop(TreeNode* root);

void PostOrderByLoop(TreeNode* root);

void TreeMirror(TreeNode* root);

int isCompleteTree(TreeNode* root);

