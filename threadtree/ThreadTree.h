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

void PreThreading(ThreadNode* root);     //先序线索

void PreOrderByThreading(ThreadNode* root);      //先序遍历

void InThreading(ThreadNode* root);      //中序线索

void InOrderByThreading(ThreadNode* root);       //中序遍历

void PostThreading(ThreadNode* root);    //后序线索

void PostOrderByThreading(ThreadNode* root);     //后序遍历

typedef struct TreeNode{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* prev;
    struct TreeNode* next;
}TreeNode;
