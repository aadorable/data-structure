#include <stdio.h>
#include "seqqueue.h"

typedef SeqQueueType StackType;

typedef struct Stack{
    SeqQueue queue1;
    SeqQueue queue2;
}Stack;

void StackInit(Stack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    SeqQueueInit(&stack->queue1);
    SeqQueueInit(&stack->queue2);
}

void StackPush(Stack* stack, StackType value){
    if(stack == NULL){
        //非法输入
        return;
    }
    SeqQueue* entry = SeqQueueSize(&stack->queue1) > 0 ? &stack->queue1 : &stack->queue2;
    SeqQueuePush(entry, value);   //直接对非空队列入栈即可
}

void StackPop(Stack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    size_t size1 = SeqQueueSize(&stack->queue1);
    size_t size2 = SeqQueueSize(&stack->queue2);
    if(size1 == 0 && size2 == 0){
        //空栈
        return;
    }
    SeqQueue* exitus = size1 > 0 ? &stack->queue1 : &stack->queue2;
    SeqQueue* backup = size1 == 0 ? &stack->queue1 : &stack->queue2;
    while(SeqQueueSize(exitus) > 1){      //进行搬运，将原来的队首搬运到另一个队列队尾
        StackType tmp;
        SeqQueueFront(exitus, &tmp);
        SeqQueuePop(exitus);
        SeqQueuePush(backup, tmp);
    }
    SeqQueuePop(exitus);     //最后进行出队列操作
}

int StackTop(Stack* stack, StackType* value){
    if(stack == NULL || value == NULL){
        //非法输入
        return 0;
    }
    size_t size1 = SeqQueueSize(&stack->queue1);
    size_t size2 = SeqQueueSize(&stack->queue2);
    if(size1 == 0 && size2 == 0){
        //空栈
        return 0;
    }
    SeqQueue* non_empty = size1 > 0 ? &stack->queue1 : &stack->queue2;
    SeqQueue* empty = size1 == 0 ? &stack->queue1 : &stack->queue2;
    StackType tmp;
    while(SeqQueueSize(non_empty) > 0){      //同样进行搬运操作
        SeqQueueFront(non_empty, &tmp);
        SeqQueuePop(non_empty);
        SeqQueuePush(empty, tmp);
    }
    *value = tmp;
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
//以下是测试代码
/////////////////////////////////////////////////////////////////////////////
void Test(){
    Stack stack;
    StackInit(&stack);
    StackPush(&stack, 'a');
    StackPush(&stack, 'b');
    StackPush(&stack, 'c');
    StackPush(&stack, 'd');

    StackType tmp;
    StackTop(&stack, &tmp);
    printf("tmp expect d, actual %c\n", tmp);

    StackPop(&stack);
    StackTop(&stack, &tmp);
    printf("tmp expect c, actual %c\n", tmp);

    StackPop(&stack);
    StackTop(&stack, &tmp);
    printf("tmp expect b, actual %c\n", tmp);

    StackPop(&stack);
    StackTop(&stack, &tmp);
    printf("tmp expect a, actual %c\n", tmp);
}

int main(){
    Test();
    return 0;
}

