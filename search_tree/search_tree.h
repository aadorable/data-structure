//ʵ�ֶ����������ĵݹ�ͷǵݹ�汾

#pragma once 

typedef char SearchTreeType;

typedef struct SearchTreeNode {
	SearchTreeType key; // �ؼ��� 
	struct SearchTreeNode* lchild;
	struct SearchTreeNode* rchild;
} SearchTreeNode;

void SearchTreeInit(SearchTreeNode** root);               //��ʼ��

void SearchTreeInsert1(SearchTreeNode** root, SearchTreeType key);          //����

void SearchTreeInsert2(SearchTreeNode** root, SearchTreeType key);          //����(�ݹ�)

SearchTreeNode* SearchTreeFind1(SearchTreeNode* root,SearchTreeType to_find);          //����

SearchTreeNode* SearchTreeFind2(SearchTreeNode* root, SearchTreeType to_find);          //����(�ݹ�)

void SearchTreeRemove1(SearchTreeNode** root, SearchTreeType key);             //ɾ��

void SearchTreeRemove2(SearchTreeNode** root, SearchTreeType key);             //ɾ��(�ݹ�)

