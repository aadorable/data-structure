#pragma once
#include <stddef.h>

#define SeqQueueMaxSize 1000

typedef char SeqQueueType;

typedef struct SeqQueue{
    SeqQueueType data[SeqQueueMaxSize];
    //[head, tail)
    size_t head;
    size_t tail;
    //队列中元素个数
    size_t size;
}SeqQueue;

void SeqQueueInit(SeqQueue* q);

void SeqQueueDestory(SeqQueue* q);

void SeqQueuePush(SeqQueue* q, SeqQueueType value);

void SeqQueuePop(SeqQueue* q);

int SeqQueueFront(SeqQueue* q, SeqQueueType* value);

size_t SeqQueueSize(SeqQueue* q);
