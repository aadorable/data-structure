#include "ThreadTree.h"

#include <stdlib.h>
#include <stdio.h>

ThreadNode* CreateThreadNode(ThreadType value){
    ThreadNode* new_node = (ThreadNode*)malloc(sizeof(ThreadNode));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->lflag = CHILD;
    new_node->rflag = CHILD;
    return new_node;
}

// ABD##EG###C#F##
ThreadNode* _ThreadTreeCreate(ThreadType array[], size_t size, size_t* index, ThreadType invalid){
    if(index == NULL || *index >= size){
        return NULL;
    }
    if(array[*index] == invalid){
        return NULL;
    }
    ThreadNode* root = CreateThreadNode(array[*index]);
    ++(*index);
    root->left = _ThreadTreeCreate(array, size, index, invalid);
    ++(*index);
    root->right = _ThreadTreeCreate(array, size, index, invalid);
    return root;
}
// 输入的array是二叉树的先序遍历结果(带有空指针域)
// ABD##EG###C#F##
// invalid表示用哪个特殊字符表示空节点。此处使用#
ThreadNode* ThreadTreeCreate(ThreadType array[], size_t size, ThreadType invalid){
    size_t index = 0;
    return _ThreadTreeCreate(array, size, &index, invalid);
}

void _PreThreading(ThreadNode* root, ThreadNode** prev){
    if(root == NULL || prev == NULL){
        return;
    }
    //处理根节点
    //1.如果当前子树的根节点的左子树为空，就把 left 指针指向前驱
    if(root->left == NULL){
        root->left = *prev;
        root->lflag = THREAD;
    }
    //2.如果当前子树的根节点的前驱的右子树为空，就把前驱的 right 指针指向根节点
    if(*prev != NULL && (*prev)->right == NULL){
        (*prev)->right = root;
        (*prev)->rflag = THREAD;
    }
    *prev = root;
    //处理左子树
    if(root->lflag == CHILD){
        _PreThreading(root->left, prev);
    }
    //处理右子树
    if(root->rflag == CHILD){
        _PreThreading(root->right, prev);
    }
    return;
}

void PreThreading(ThreadNode* root){
    ThreadNode* prev = NULL;
    _PreThreading(root, &prev);
}

void PreOrderByThreading(ThreadNode* root){
    if(root == NULL){
        return;
    }
    ThreadNode* cur = root;
    while(cur != NULL){
        while(cur->lflag == CHILD){
            printf("%c ", cur->data);
            cur = cur->left;
        }
        printf("%c ", cur->data);
        //无论 cur 的 right 指针指向后继还是指向右子树，都被下面的逻辑覆盖到了
        cur = cur->right;
    }
    printf("\n");
    return;
}

void _InThreading(ThreadNode* root, ThreadNode** prev){
    if(root == NULL || prev == NULL){
        return;
    }
    //处理左子树
    if(root->lflag == CHILD){
        _InThreading(root->left, prev);
    }
    //处理根节点
    if(root->left == NULL){
        root->left = *prev;
        root->lflag = THREAD;
    }
    if(*prev != NULL && (*prev)->right == NULL){
        (*prev)->right = root;
        (*prev)->rflag = THREAD;
    }
    *prev = root;
    //处理右子树
    if(root->rflag == CHILD){
        _InThreading(root->right, prev);
    }
}

void InThreading(ThreadNode* root){
    ThreadNode* prev = NULL;
    _InThreading(root, &prev);
}

void InOrderByThreading(ThreadNode* root){
    //1.定义cur指针指向root，找到最左侧的结点，并且在寻找的路径上不能访问
    if(root == NULL){
        return;
    }
    ThreadNode* cur = root;
    //当循环结束，cur就指向了这棵树的最左侧节点
    while(cur != NULL && cur->lflag == CHILD){
        cur = cur->left;
    }
    //2.进入循环，访问cur结点，如果cur节点为空，说明遍历完了
    while(cur != NULL){
        printf("%c ", cur->data);

        if(cur->rflag == THREAD){
            //3.如果cur的right刚好是线索，cur指向cur->right
            cur = cur->right;
        }else{
            //4.如果cur的right是子树，需要让cur指向cur->right这个子树的最左侧节点
            cur = cur->right;
            while(cur != NULL && cur->lflag == CHILD){
                cur = cur->left;
            }
        }
    }
    printf("\n");
    return;
}

void _PostThreading(ThreadNode* root, ThreadNode** prev){
    if(root == NULL || prev == NULL){
        return;
    }
    //处理左子树
    if(root->lflag == CHILD){
        _PostThreading(root->left, prev);
    }
    //处理右子树
    if(root->rflag == CHILD){
        _PostThreading(root->right, prev);
    }
    //处理根节点
    if(root->left == NULL){
        root->left = *prev;
        root->lflag = THREAD;
    }
    if(*prev != NULL && (*prev)->right == NULL){
        (*prev)->right = root;
        (*prev)->rflag = THREAD;
    }
    *prev = root;
}

void PostThreading(ThreadNode* root){
    ThreadNode* prev = NULL;
    _PostThreading(root, &prev);
}

void _PreOrderConvertToList(TreeNode* root, TreeNode** prev){
    if(root == NULL || prev == NULL){
        return;
    }
    //处理根节点
    root->prev = *prev;
    if(*prev != NULL){
        (*prev)->next = root;
    }
    *prev = root;
    //处理左子树
    _PreOrderConvertToList(root->left, prev);
    //处理右子树
    _PreOrderConvertToList(root->right, prev);
}

void PreOrderConvertToList(TreeNode* root){
    TreeNode* prev = NULL;
    _PreOrderConvertToList(root, &prev);
}
