#include "seqqueue.h"
#include <stdio.h>

void SeqQueueInit(SeqQueue* q){
    if(q == NULL){
        //非法输入
        return;
    }
    q->head = q->tail = 0;
    q->size = 0;
}

void SeqQueueDestory(SeqQueue* q){
    if(q == NULL){
        //非法输入
        return;
    }
    q->head = q->tail = 0;
    q->size = 0;
}

void SeqQueuePush(SeqQueue* q, SeqQueueType value){
    if(q == NULL){
        //非法输入
        return;
    }
    if(q->size == SeqQueueMaxSize){
        //队列已满
        return;
    }
    q->data[q->tail++] = value;
    q->tail %= SeqQueueMaxSize;
    //q->tail = (q->tail) & (SeqQueueMaxSize - 1);
    ++q->size;
}

void SeqQueuePop(SeqQueue* q){
    if(q == NULL){
        //非法输入
        return;
    }
    if(q->size == 0){
        //空队列
        return;
    }
    ++q->head;
    q->head %= SeqQueueMaxSize;
    --q->size;
}

int SeqQueueFront(SeqQueue* q, SeqQueueType* value){
    if(q == NULL || value == NULL){
        //非法输入
        return 0;
    }
    if(q->size == 0){
        //空队列
        return 0;
    }
    *value = q->data[q->head];
    return 1;
}

size_t SeqQueueSize(SeqQueue* q){
    if(q == NULL){
        //非法输入
        return (size_t)-1;
    } 
    return q->size;
}

//////////////////////////////////////////////////////////////////////////////
//以下是测试代码
/////////////////////////////////////////////////////////////////////////////
#if 0
void Test(){
    SeqQueue q;
    SeqQueueInit(&q);
    SeqQueuePush(&q, 'a');
    SeqQueuePush(&q, 'b');
    SeqQueuePush(&q, 'c');
    SeqQueuePush(&q, 'd');

    SeqQueueType tmp;
    SeqQueueFront(&q, &tmp);
    printf("tmp expect a, actual %c\n", tmp);

    SeqQueuePop(&q);
    SeqQueueFront(&q, &tmp);
    printf("tmp expect b, actual %c\n", tmp);

    SeqQueuePop(&q);
    SeqQueueFront(&q, &tmp);
    printf("tmp expect c, actual %c\n", tmp);

    SeqQueuePop(&q);
    SeqQueueFront(&q, &tmp);
    printf("tmp expect d, actual %c\n", tmp);
}

int main(){
    Test();
    return 0;
}
#endif
