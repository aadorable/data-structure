//实现二叉搜索树的递归和非递归版本

#pragma once 

typedef char SearchTreeType;

typedef struct SearchTreeNode {
	SearchTreeType key; // 关键码 
	struct SearchTreeNode* lchild;
	struct SearchTreeNode* rchild;
} SearchTreeNode;

void SearchTreeInit(SearchTreeNode** root);               //初始化

void SearchTreeInsert1(SearchTreeNode** root, SearchTreeType key);          //插入

void SearchTreeInsert2(SearchTreeNode** root, SearchTreeType key);          //插入(递归)

SearchTreeNode* SearchTreeFind1(SearchTreeNode* root,SearchTreeType to_find);          //查找

SearchTreeNode* SearchTreeFind2(SearchTreeNode* root, SearchTreeType to_find);          //查找(递归)

void SearchTreeRemove1(SearchTreeNode** root, SearchTreeType key);             //删除

void SearchTreeRemove2(SearchTreeNode** root, SearchTreeType key);             //删除(递归)

