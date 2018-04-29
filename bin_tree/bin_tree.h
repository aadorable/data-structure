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

void PreOrder(TreeNode* root);

void InOrder(TreeNode* root);

void PostOrder(TreeNode* root);

void LevelOrder(TreeNode* root);

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node);

void TreeDestroy(TreeNode** root);

TreeNode* TreeClone(TreeNode* root);

size_t TreeSize(TreeNode* root);

size_t TreeLeafSize(TreeNode* root);
