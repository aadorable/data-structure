#pragma once
typedef char ThreadType;
//定义一个枚举类型用来表示某一节点的左右指针是子树还是线索
typedef enum Flag{
    CHILD;
    THREAD;
}Flag;

typedef struct ThreadNode{
    ThreadType data;
    ThreadNode* left;
    ThreadNode* right;
    Flag lflag;
    Flag rflag;
}ThreadNode;

ThreadNode* ThreadTreeCreate(ThreadType array[], size_t size, ThreadType invalid);
