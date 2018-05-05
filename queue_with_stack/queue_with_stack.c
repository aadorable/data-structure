#include <stdio.h>
#include "seqstack.h"

typedef SeqStackType QueueType;

typedef struct Queue{
    SeqStack entry;
    SeqStack exitus;
}Queue;

void QueueInit(Queue* q){
    if(q == NULL){
        //非法输入
        return;
    }
    SeqStackInit(&q->entry);
    SeqStackInit(&q->exitus);
}

void QueuePush(Queue* q, QueueType value){
    if(q == NULL){
        //非法输入
        return;
    }
    QueueType tmp;
    while(SeqStackTop(&q->exitus, &tmp)){
        SeqStackPop(&q->exitus);
        SeqStackPush(&q->entry, tmp);
    }
    SeqStackPush(&q->entry, value);
}

void QueuePop(Queue* q){
    if(q == NULL){
        //非法输入
        return;
    }
    QueueType tmp;
    while(SeqStackTop(&q->entry, &tmp)){
        SeqStackPop(&q->entry);
        SeqStackPush(&q->exitus, tmp);
    }
    SeqStackPop(&q->exitus);
}

int QueueFront(Queue* q, QueueType* value){
    if(q == NULL || value == NULL){
        //非法输入
        return 0;
    } 
    QueueType tmp;
    while(SeqStackTop(&q->entry, &tmp)){
        SeqStackPop(&q->entry);
        SeqStackPush(&q->exitus, tmp);
    }
    int ret = SeqStackTop(&q->exitus, value);
    return ret;
}

////////////////////////////////////////////////////////////
//以下是测试函数
////////////////////////////////////////////////////////////
void Test(){
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 'a');
    QueuePush(&q, 'b');
    QueuePush(&q, 'c');
    QueuePush(&q, 'd');

    QueueType tmp;
    QueueFront(&q, &tmp);
    printf("tmp expect a, actual %c\n", tmp);

    QueuePop(&q);
    QueueFront(&q, &tmp);
    printf("tmp expect b, actual %c\n", tmp);

    QueuePop(&q);
    QueueFront(&q, &tmp);
    printf("tmp expect c, actual %c\n", tmp);

    QueuePop(&q);
    QueueFront(&q, &tmp);
    printf("tmp expect d, actual %c\n", tmp);
}

int main(){
    Test();
    return 0;
}
