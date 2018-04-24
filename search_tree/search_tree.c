#define _CRT_SECURE_NO_WARNINGS 1

#include "search_tree.h"

#include <stdlib.h>

void SearchTreeInit(SearchTreeNode** root)              //��ʼ��
{
	if (root == NULL)
	{
		return;          //�Ƿ�����
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

void SearchTreeInsert1(SearchTreeNode** root, SearchTreeType key)          //����
{
	if (root == NULL)
	{
		return;        //�Ƿ�����
	}
	//1.���������ǿ�����ֱ�Ӵ���һ���ڵ�
	if (*root == NULL)
	{
		*root = CreateSearchTreeNode(key);
		return;
	}
	//2.���������Ƿǿ���
	SearchTreeNode* cur = *root;
	SearchTreeNode* parent = NULL;
	while (1)
	{
		//  a)�Ȳ��ҵ�һ�����ʵĲ���λ��
		if (cur == NULL)
		{
			break;        //���ʵ�λ�����ҵ�
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
			return;          //Լ���������ֵ�뵱ǰԪ�����ʱ������ʧ��
		}
	}
	//  b)���ڶ�Ӧ��λ���ϴ����ڵ�
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

void SearchTreeInsert2(SearchTreeNode** root, SearchTreeType key)          //����(�ݹ�)
{
	if (root == NULL)
	{
		return;          //�Ƿ�����
	}
	//1.���ҵ����ĸ�λ�ò���
	//2.�����µĽڵ㣬���ڶ�Ӧλ����
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
		return;      //����ʧ��
	}
}

SearchTreeNode* SearchTreeFind1(SearchTreeNode* root, SearchTreeType to_find)          //����
{
	if (root == NULL)
	{
		return;       //�Ƿ�����
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

SearchTreeNode* SearchTreeFind2(SearchTreeNode* root, SearchTreeType to_find)          //����(�ݹ�)
{
	if (root == NULL)
	{
		return NULL;        //�Ƿ�����
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
void SearchTreeRemove1(SearchTreeNode** root, SearchTreeType key)             //ɾ��
{
	if (root == NULL)
	{
		return;        //�Ƿ�����
	}
	//1.������������ֱ�ӷ���
	if (*root == NULL)
	{
		return;
	}
	SearchTreeNode* to_remove = *root;
	SearchTreeNode* parent = NULL;
	//2.�ҵ�Ҫɾ���ڵ��λ�ã��Լ�Ҫɾ���ڵ�ĸ��ڵ�
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
	//3.���Ҫɾ��Ԫ��������û���ҵ���Ҳֱ�ӷ���
	if (to_remove == NULL)
	{
		return;
	}
	//4.���Ҫɾ���ڵ��ҵ��ˣ���������ۣ�
	//     a)Ҫɾ���ڵ�û��������ֱ��ɾ���ýڵ㣬�����ýڵ�ĸ��ڵ��ÿ�
	if (to_remove->lchild == NULL && to_remove->rchild == NULL)
	{
		if (to_remove == *root)
		{
			//Ҫɾ�����Ǹ��ڵ�
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
	//     b)Ҫɾ���ڵ㣬ֻ����������ɾ���ýڵ��ͬʱ�����ýڵ���������ҵ����ڵ���
	else if(to_remove->lchild != NULL && to_remove->rchild == NULL)
	{
		if (to_remove == *root)
		{
			//Ҫɾ�����Ǹ��ڵ�
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
	//     c)Ҫɾ���ڵ㣬ֻ����������ɾ���ýڵ��ͬʱ�����ýڵ���������ҵ����ڵ���
	else if (to_remove->lchild == NULL && to_remove->rchild != NULL)
	{
		if (to_remove == *root)
		{
			//Ҫɾ�����Ǹ��ڵ�
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
	//     d)Ҫɾ���ڵ㣬ͬʱ�������������ҵ��������е���Сֵ��
	//       Ȼ�󽫸���Сֵ��ֵ��Ҫɾ����λ�ã�Ȼ����ɾ�����������е���Сֵ�ڵ㣬
	//       �����Ľڵ����ֻ��һ������������ת���������c)
	else
	{
		SearchTreeNode* min = to_remove->rchild;
		SearchTreeNode* min_parent = to_remove;
		while (min->lchild != NULL)
		{
			min_parent = min;
			min = min->lchild;
		}
		//����ִ�е����min���Ѿ�ָ��to_remove����������Сֵ
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

void SearchTreeRemove2(SearchTreeNode** root, SearchTreeType key)             //ɾ��(�ݹ�)
{
	if (root == NULL)
	{
		return;     //�Ƿ�����
	}
	//1.������������ֱ�ӷ���
	if (*root == NULL)
	{
		return;
	}
	//2.���û�ҵ��Ļ�������Ҫ�����κ�ɾ������
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
	//3.�ҵ����������ۣ�
	else
	{
		SearchTreeNode* to_remove = *root;
		//     a)Ҫɾ���ڵ�û��������ֱ��ɾ���ýڵ㣬�����ýڵ�ĸ��ڵ��ÿ�
		if (to_remove->lchild == NULL && to_remove->rchild == NULL)
		{
			*root = NULL;
			DestroySearchTreeNode(to_remove);
			return;
		}
		//     b)Ҫɾ���ڵ㣬ֻ����������ɾ���ýڵ��ͬʱ�����ýڵ���������ҵ����ڵ���
		else if (to_remove->lchild != NULL && to_remove->rchild == NULL)
		{
			*root = to_remove->lchild;
			DestroySearchTreeNode(to_remove);
			return;
		}
		//     c)Ҫɾ���ڵ㣬ֻ����������ɾ���ýڵ��ͬʱ�����ýڵ���������ҵ����ڵ���
		else if (to_remove->lchild == NULL && to_remove->rchild != NULL)
		{
			*root = to_remove->rchild;
			DestroySearchTreeNode(to_remove);
			return;
		}
		//     b)Ҫɾ���ڵ㣬ͬʱ�������������ҵ��������е���Сֵ��
		//       Ȼ�󽫸���Сֵ��ֵ��Ҫɾ����λ�ã�Ȼ����ɾ�����������е���Сֵ�ڵ㣬
		//       �����Ľڵ����ֻ��һ������������ת���������c)
		else
		{
			SearchTreeNode* min = to_remove->rchild;
			while (min->lchild != NULL)
			{
				min = min->lchild;
			}
			//����ִ�е����min���Ѿ�ָ��to_remove����������Сֵ
			to_remove->key = min->key;
			SearchTreeRemove2(&to_remove->rchild, min->key);
			return;
		}
	}
}
