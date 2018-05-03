#pragma once

typedef char LinkQueueType;

typedef struct LinkQueueNode{
    LinkQueueType data;
    struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue{
    LinkQueueNode* head;
    LinkQueueNode* tail;
}LinkQueue;

void LinkQueueInit(LinkQueue* q);

void LinkQueueDestroy(LinkQueue* q);

void LinkQueuePush(LinkQueue* q, LinkQueueType value);

void LinkQueuePop(LinkQueue* q);

int LinkQueueFront(LinkQueue* q, LinkQueueType* value);
