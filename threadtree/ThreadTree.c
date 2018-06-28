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
