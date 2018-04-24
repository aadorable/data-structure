#define _CRT_SECURE_NO_WARNINGS 1

#include "search_tree.h"

#include <stdlib.h>

void SearchTreeInit(SearchTreeNode** root)              //初始化
{
	if (root == NULL)
	{
		return;          //非法输入
	}
	*root = NULL;
	return;
}

SearchTreeNode* CreateSearchTreeNode(SearchTreeType key)
{
	SearchTreeNode* new_node = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
	new_node->key = key;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

void SearchTreeInsert1(SearchTreeNode** root, SearchTreeType key)          //插入
{
	if (root == NULL)
	{
		return;        //非法输入
	}
	//1.如果这个树是空树，直接创建一个节点
	if (*root == NULL)
	{
		*root = CreateSearchTreeNode(key);
		return;
	}
	//2.如果这个树是非空树
	SearchTreeNode* cur = *root;
	SearchTreeNode* parent = NULL;
	while (1)
	{
		//  a)先查找到一个合适的插入位置
		if (cur == NULL)
		{
			break;        //合适的位置已找到
		}
		if (key < cur->key)
		{
			parent = cur;
			cur = cur->lchild;
		}
		else if (key > cur->key)
		{
			parent = cur;
			cur = cur->rchild;
		}
		else
		{
			return;          //约定当插入的值与当前元素相等时，插入失败
		}
	}
	//  b)再在对应的位置上创建节点
	SearchTreeNode* new_node = CreateSearchTreeNode(key);
	if (key < parent->key)
	{
		parent->lchild = new_node;
	}
	else
	{
		parent->rchild = new_node;
	}
	return;
}

void SearchTreeInsert2(SearchTreeNode** root, SearchTreeType key)          //插入(递归)
{
	if (root == NULL)
	{
		return;          //非法输入
	}
	//1.先找到在哪个位置插入
	//2.创建新的节点，放在对应位置上
	if (*root == NULL)
	{
		*root = CreateSearchTreeNode(key);
		return;
	}
	if (key < (*root)->key)
	{
		SearchTreeInsert2(&(*root)->lchild, key);
		return;
	}
	else if (key > (*root)->key)
	{
		SearchTreeInsert2(&(*root)->rchild, key);
		return;
	}
	else
	{
		return;      //插入失败
	}
}

SearchTreeNode* SearchTreeFind1(SearchTreeNode* root, SearchTreeType to_find)          //查找
{
	if (root == NULL)
	{
		return;       //非法输入
	}
	SearchTreeNode* cur = root;
	while (cur != NULL)
	{
		if (to_find < cur->key)
		{
			cur = cur->lchild;
		}
		else if (to_find > cur->key)
		{
			cur = cur->rchild;
		}
		else
		{
			break;
		}
	}
	return cur;
}

SearchTreeNode* SearchTreeFind2(SearchTreeNode* root, SearchTreeType to_find)          //查找(递归)
{
	if (root == NULL)
	{
		return NULL;        //非法输入
	}
	if (to_find < root->key)
	{
		SearchTreeFind2(root->lchild, to_find);
	}
	else if (to_find > root->key)
	{
		SearchTreeFind2(root->rchild, to_find);
	}
	else
	{
		return root;
	}
}

void DestroySearchTreeNode(SearchTreeNode* to_remove)
{
	free(to_remove);
}
void SearchTreeRemove1(SearchTreeNode** root, SearchTreeType key)             //删除
{
	if (root == NULL)
	{
		return;        //非法输入
	}
	//1.处理空树情况，直接返回
	if (*root == NULL)
	{
		return;
	}
	SearchTreeNode* to_remove = *root;
	SearchTreeNode* parent = NULL;
	//2.找到要删除节点的位置，以及要删除节点的父节点
	while (to_remove != NULL)
	{
		if (key < to_remove->key)
		{
			parent = to_remove;
			to_remove = to_remove->lchild;
		}
		else if (key > to_remove->key)
		{
			parent = to_remove;
			to_remove = to_remove->rchild;
		}
		else
		{
			break;
		}
	}
	//3.如果要删除元素在树中没有找到，也直接返回
	if (to_remove == NULL)
	{
		return;
	}
	//4.如果要删除节点找到了，分情况讨论：
	//     a)要删除节点没有子树，直接删除该节点，并将该节点的父节点置空
	if (to_remove->lchild == NULL && to_remove->rchild == NULL)
	{
		if (to_remove == *root)
		{
			//要删除的是根节点
			*root = NULL;
		}
		else
		{
			if (parent->lchild == to_remove)
			{
				parent->lchild = NULL;
			}
			else
			{
				parent->rchild = NULL;
			}
			DestroySearchTreeNode(to_remove);
			return;
		}
	}
	//     b)要删除节点，只有左子树，删除该节点的同时，将该节点的左子树挂到父节点上
	else if(to_remove->lchild != NULL && to_remove->rchild == NULL)
	{
		if (to_remove == *root)
		{
			//要删除的是根节点
			*root = to_remove->lchild;
			DestroySearchTreeNode(to_remove);
		}
		else
		{
			if (to_remove == parent->lchild)
			{
				parent->lchild = to_remove->lchild;
			}
			else
			{
				parent->rchild = to_remove->lchild;
			}
			DestroySearchTreeNode(to_remove);
			return;
		}
	}
	//     c)要删除节点，只有右子树，删除该节点的同时，将该节点的右子树挂到父节点上
	else if (to_remove->lchild == NULL && to_remove->rchild != NULL)
	{
		if (to_remove == *root)
		{
			//要删除的是根节点
			*root = to_remove->rchild;
			DestroySearchTreeNode(to_remove);
		}
		else
		{
			if (to_remove == parent->lchild)
			{
				parent->lchild = to_remove->rchild;
			}
			else
			{
				parent->rchild = to_remove->rchild;
			}
			DestroySearchTreeNode(to_remove);
			return;
		}
	}
	//     d)要删除节点，同时有左右子树，找到右子树中的最小值，
	//       然后将该最小值赋值给要删除的位置，然后再删除该右子树中的最小值节点，
	//       这样的节点最多只有一个右子树，就转换成了情况c)
	else
	{
		SearchTreeNode* min = to_remove->rchild;
		SearchTreeNode* min_parent = to_remove;
		while (min->lchild != NULL)
		{
			min_parent = min;
			min = min->lchild;
		}
		//代码执行到这里，min就已经指向to_remove右子树的最小值
		to_remove->key = min->key;
		if (min_parent->lchild == min)
		{
			min_parent->lchild = min->rchild;
		}
		else
		{
			min_parent->rchild = min->rchild;
		}
		DestroySearchTreeNode(min);
		return;
	}
}

void SearchTreeRemove2(SearchTreeNode** root, SearchTreeType key)             //删除(递归)
{
	if (root == NULL)
	{
		return;     //非法输入
	}
	//1.处理空树情况，直接返回
	if (*root == NULL)
	{
		return;
	}
	//2.如果没找到的话，不需要进行任何删除动作
	if (key < (*root)->key)
	{
		SearchTreeRemove2(&(*root)->lchild, key);
		return;
	}
	else if (key>(*root)->key)
	{
		SearchTreeRemove2(&(*root)->rchild, key);
		return;
	}
	//3.找到后分情况讨论：
	else
	{
		SearchTreeNode* to_remove = *root;
		//     a)要删除节点没有子树，直接删除该节点，并将该节点的父节点置空
		if (to_remove->lchild == NULL && to_remove->rchild == NULL)
		{
			*root = NULL;
			DestroySearchTreeNode(to_remove);
			return;
		}
		//     b)要删除节点，只有左子树，删除该节点的同时，将该节点的左子树挂到父节点上
		else if (to_remove->lchild != NULL && to_remove->rchild == NULL)
		{
			*root = to_remove->lchild;
			DestroySearchTreeNode(to_remove);
			return;
		}
		//     c)要删除节点，只有右子树，删除该节点的同时，将该节点的右子树挂到父节点上
		else if (to_remove->lchild == NULL && to_remove->rchild != NULL)
		{
			*root = to_remove->rchild;
			DestroySearchTreeNode(to_remove);
			return;
		}
		//     b)要删除节点，同时有左右子树，找到右子树中的最小值，
		//       然后将该最小值赋值给要删除的位置，然后再删除该右子树中的最小值节点，
		//       这样的节点最多只有一个右子树，就转换成了情况c)
		else
		{
			SearchTreeNode* min = to_remove->rchild;
			while (min->lchild != NULL)
			{
				min = min->lchild;
			}
			//代码执行到这里，min就已经指向to_remove右子树的最小值
			to_remove->key = min->key;
			SearchTreeRemove2(&to_remove->rchild, min->key);
			return;
		}
	}
}
