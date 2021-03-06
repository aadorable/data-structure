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

size_t TreeHeight(TreeNode* root);        //树的高度

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find);     //查找元素

TreeNode* LChild(TreeNode* node);       //左孩子节点

TreeNode* RChild(TreeNode* node);       //右孩子节点

TreeNode* Parent(TreeNode* root, TreeNode* node);       //父亲节点

void PreOrderByLoop(TreeNode* root);     //非递归版本的先序遍历

void InOrderByLoop(TreeNode* root);      //非递归版本的中序遍历 

void PostOrderByLoop(TreeNode* root);    //非递归版本的后序遍历

void TreeMirror(TreeNode* root);         //二叉树的镜像

int isCompleteTree(TreeNode* root);      //判断该二叉树是否是完全二叉树

TreeNode* ReBuildTree(TreeNodeType pre_order[], size_t pre_order_size, TreeNodeType in_order[], size_t in_order_size);  //重建一棵树
