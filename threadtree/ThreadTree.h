#pragma once
//执行效率
//空间占用
//代码简单

#include <stddef.h>

typedef char ThreadType;
//定义一个枚举类型用来表示某一节点的左右指针是子树还是线索
typedef enum Flag{
    CHILD,
    THREAD,
}Flag;

typedef struct ThreadNode{
    ThreadType data;
    struct ThreadNode* left;
    struct ThreadNode* right;
    //引入两个 flag 来分别表示左右指针指向的是子树还是线索
    Flag lflag;
    Flag rflag;
}ThreadNode;

ThreadNode* ThreadTreeCreate(ThreadType array[], size_t size, ThreadType invalid);

void PreThreading(ThreadNode* root);

void PreOrderByThreading(ThreadNode* root);

void InThreading(ThreadNode* root);

void InOrderByThreading(ThreadNode* root);

void PostThreading(ThreadNode* root);

void PostOrderByThreading(ThreadNode* root);
