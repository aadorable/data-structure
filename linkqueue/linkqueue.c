#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

void LinkQueueInit(LinkQueue* q){
    if(q == NULL){
        //非法输入
        //要求调用者已经为 LinkQueue 变量分配好内存了
        return;
    }
    q->head = NULL;
    q->tail = NULL;
}

LinkQueueNode* CreateLinkQueueNode(LinkQueueType value){
    LinkQueueNode* new_node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void DestoryLinkQueueNode(LinkQueueNode* ptr){
    free(ptr);
}

void LinkQueuePush(LinkQueue* q, LinkQueueType value){
    if(q == NULL){
        return;
    }
    LinkQueueNode* new_node = CreateLinkQueueNode(value);
    if(q->head == NULL){
        //空队列
        q->head = q->tail = new_node;
        return;
    }
    q->tail->next = new_node;
    q->tail = q->tail->next;
    return;
}

void LinkQueuePop(LinkQueue* q){
    if(q == NULL){
        //非法输入
        return;
    }
    if(q->head == NULL){
        //空队列
        return;
    }
    if(q->head == q->tail){
        //只有一个节点
        DestoryLinkQueueNode(q->head);
        q->head = q->tail = NULL;
        return;
    }
    //有多个节点
    LinkQueueNode* to_delete = q->head;
    q->head = to_delete->next;
    DestoryLinkQueueNode(to_delete);
}

int LinkQueueFront(LinkQueue* q, LinkQueueType* value){
    if(q == NULL || value == NULL){
        //非法输入
        return 0;
    }
    if(q->head == NULL){
        //空队列
        return 0;
    }
    *value = q->head->data;
    return 1;
}

void LinkQueueDestroy(LinkQueue* q){
    if(q == NULL){
        //非法输入
    }
    while(q->head != NULL){
        LinkQueueNode* next = q->head->next;
        DestoryLinkQueueNode(q->head);
        q->head = next;
    }
    q->head = NULL;
    return;
}

/////////////////////////////////////////////////////////////////////////
//以下是测试函数
/////////////////////////////////////////////////////////////////////////
#if 1

#define TEST_HEADER printf("\n=============%s=============\n", __FUNCTION__)

void TestInit(){
    TEST_HEADER;
    LinkQueue q;
    LinkQueueInit(&q);
}

void Test(){
    TEST_HEADER;
    LinkQueue q;
    LinkQueueInit(&q);
    LinkQueuePush(&q, 'a');
    LinkQueuePush(&q, 'b');
    LinkQueuePush(&q, 'c');
    LinkQueuePush(&q, 'd');

    LinkQueueType tmp;
    LinkQueueFront(&q, &tmp);
    printf("tmp expect a, actual %c\n", tmp);

    LinkQueuePop(&q);
    LinkQueueFront(&q, &tmp);
    printf("tmp expect b, actual %c\n", tmp);

    LinkQueuePop(&q);
    LinkQueueFront(&q, &tmp);
    printf("tmp expect c, actual %c\n", tmp);

    LinkQueuePop(&q);
    LinkQueueFront(&q, &tmp);
    printf("tmp expect d, actual %c\n", tmp);
    
    LinkQueuePush(&q, 'a');
    LinkQueueDestroy(&q);
    int ret = LinkQueueFront(&q, &tmp);
    printf("ret expect 0, actual %d\n", ret);
}

int main(){
    Test();
    return 0;
}

#endif
