#include "ThreadTree.h"

#include <stdlib.h>

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
