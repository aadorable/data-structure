#include "bin_tree.h"
#include "seqqueue.h"

#include <stdio.h>

TreeNode* CreateTreeNode(TreeNodeType value){
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = value;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

void DestroyTreeNode(TreeNode* ptr){
    free(ptr);
}

void TreeInit(TreeNode** root){
	if(root == NULL){
		return;
	}
	*root = NULL;
}

void PreOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	printf("%c ",root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	InOrder(root->lchild);
	printf("%c ",root->data);
	InOrder(root->rchild);
}

void PostOrder(TreeNode* root){	
	if(root == NULL){
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%c ",root->data);
}

void LevelOrder(TreeNode* root){
    if(root == NULL){
        //空树
        return;
    }
    SeqQueue q;
    SeqQueueInit(&q);
    //1.先把根节点插入到队列
    SeqQueuePush(&q, root);
    //2.循环取队首元素
    TreeNode* cur = NULL;
    while(SeqQueueFront(&q, &cur)){
         //3.访问队首元素并出队列
         printf("%c ", cur->data);
         SeqQueuePop(&q);
         //4.将队首元素的左右子树依次入队列
         if(cur->lchild != NULL){
             SeqQueuePush(&q, cur->lchild);
         }
         if(cur->rchild != NULL){
             SeqQueuePush(&q, cur->rchild);
         }
         //5.进入下一次循环，直到队列为空
    }
}

TreeNode* _TreeCreate(TreeNodeType array[], size_t size, size_t* index, TreeNodeType null_node){
    if(index == NULL){
        return NULL;    //非法输入
    }
    if(*index >= size){
        //构建已完成
        return NULL;
    }
    if(array[*index] == null_node){
        return NULL;
    }
    TreeNode* new_node = CreateTreeNode(array[*index]);
    ++(*index);
    new_node->lchild = _TreeCreate(array,size,index,null_node);
    ++(*index);
    new_node->rchild = _TreeCreate(array,size,index,null_node);
    return new_node;
}

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node){
    //当前读到了数组的第几个元素
    size_t index = 0;
    return _TreeCreate(array, size, &index, null_node);
}

void TreeDestroy(TreeNode** root){
    if(root == NULL){
        return;    //非法输入
    }
    if(*root == NULL){
        return;
    }
    TreeNode* to_delete = *root;
    TreeNode* to_delete_lchild = to_delete->lchild;
    TreeNode* to_delete_rchild = to_delete->rchild;
    DestroyTreeNode(to_delete);
    TreeDestroy(&to_delete_lchild);
    TreeDestroy(&to_delete_rchild);
    *root = NULL;
}

TreeNode* TreeClone(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    TreeNode* new_root = CreateTreeNode(root->data);
    new_root->lchild = TreeClone(root->lchild);
    new_root->rchild = TreeClone(root->rchild);
    return new_root;
}

//size_t TreeSize(TreeNode* root){
//    if(root == NULL){
//        return 0;
//    }
//    return 1 + TreeSize(root->lchild) + TreeSize(root->rchild);
//}
//
void _TreeSize(TreeNode* root,size_t* size){
    if(root == NULL || size == NULL){
        return;    //非法输入
    }
    //访问当前元素，每次访问一个就把size++
    ++(*size);
    _TreeSize(root->lchild,size);
    _TreeSize(root->rchild,size);
}

size_t TreeSize(TreeNode* root){
    size_t size = 0;
    _TreeSize(root,&size);
    return size;
}

size_t TreeLeafSize(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }
    return TreeLeafSize(root->lchild) + TreeLeafSize(root->rchild);
}

size_t TreeKLevelSize(TreeNode* root, int K){
    if(root == NULL || K < 1){
        return 0;
    }
    if(K == 1){
        return 1;
    }
    return TreeKLevelSize(root->lchild, K - 1) + TreeKLevelSize(root->rchild, K - 1);
}

size_t TreeHeight(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    size_t lheight = TreeHeight(root->lchild);
    size_t rheight = TreeHeight(root->rchild);
    return lheight > rheight ? lheight + 1 : rheight + 1;
}
