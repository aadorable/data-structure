#include <stdio.h>
#include "seqstack.h"

typedef SeqStackType MinStackType;

#if 0
//方法一
typedef struct MinStack{
    SeqStack data;      //保存栈中的元素
    SeqStack min;       //保存当前栈的最小元素
}MinStack;

void MinStackInit(MinStack* min_stack){
    if(min_stack == NULL){
        //非法输入
        return;
    }
    SeqStackInit(&min_stack->data);
    SeqStackInit(&min_stack->min);
}

void MinStackPush(MinStack* min_stack, MinStackType value){
    if(min_stack == NULL){
        //非法输入
        return;
    }
    MinStackType tmp;
    int ret = SeqStackTop(&min_stack->min, &tmp);
    if(ret == 0){
        //本来的栈为空
        SeqStackPush(&min_stack->data, value);
        SeqStackPush(&min_stack->min, value);
        return;
    }
    //本来的栈非空
    //先比较要插入元素和 min 栈顶元素大小
    MinStackType min = value < tmp ? value : tmp;
    SeqStackPush(&min_stack->data, value);
    SeqStackPush(&min_stack->min, min);
}

void MinStackPop(MinStack* min_stack){
    if(min_stack == NULL){
        //非法输入
        return;
    }
    SeqStackPop(&min_stack->data);
    SeqStackPop(&min_stack->min);
}

int MinStackMinTop(MinStack* min_stack, MinStackType* value){
    if(min_stack == NULL){
        //非法输入
        return 0;
    }
    return SeqStackTop(&min_stack->min, value);
}
#endif

//方法二
typedef struct MinStack{
    SeqStack data;
}MinStack;

void MinStackInit(MinStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    SeqStackInit(&stack->data);
}

void MinStackPush(MinStack* stack, MinStackType value){
    if(stack == NULL){
        //非法输入
        return;
    } 
    MinStackType tmp;
    int ret = SeqStackTop(&stack->data, &tmp);
    if(ret == 0){
        SeqStackPush(&stack->data, value);
        SeqStackPush(&stack->data, value);
        return;
    }
    MinStackType min = value < tmp ? value : tmp;
    SeqStackPush(&stack->data, value);
    SeqStackPush(&stack->data, min);
    return;
}

void MinStackPop(MinStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    SeqStackPop(&stack->data);
    SeqStackPop(&stack->data);
    return;
}

int MinStackMinTop(MinStack* stack, MinStackType* value){
    if(stack == NULL){
        //非法输入
        return 0;
    }
    return SeqStackTop(&stack->data, value);
}

/////////////////////////////////////////////////////////////////////
//以下为测试代码
/////////////////////////////////////////////////////////////////////
#if 1
void Test(){
    MinStack stack;
    MinStackInit(&stack);
    MinStackPush(&stack, 'b');
    MinStackPush(&stack, 'c');
    MinStackPush(&stack, 'd');
    MinStackPush(&stack, 'a');

    MinStackType tmp;
    MinStackMinTop(&stack, &tmp);
    printf("tmp expect a, actual %c\n", tmp);

    MinStackPop(&stack);
    MinStackMinTop(&stack, &tmp);
    printf("tmp expect b, actual %c\n", tmp);

    MinStackPop(&stack);
    MinStackMinTop(&stack, &tmp);
    printf("tmp expect b, actual %c\n", tmp);

    MinStackPop(&stack);
    MinStackMinTop(&stack, &tmp);
    printf("tmp expect b, actual %c\n", tmp);
}

int main(){
    Test();
    return 0;
}
#endif
