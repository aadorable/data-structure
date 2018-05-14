#pragma once

#include <stddef.h>

typedef char SeqStackType;

#define SEQ_STACK_SIZE 100

typedef struct SeqStack{
	SeqStackType data[SEQ_STACK_SIZE];
	size_t size;
}SeqStack;

void SeqStackInit(SeqStack* stack);		//初始化

void SeqStackDestroy(SeqStack* stack);		//销毁栈

void SeqStackPush(SeqStack* stack, SeqStackType value);		//入栈

void SeqStackPop(SeqStack* stack);		//出栈

int SeqStackTop(SeqStack* stack, SeqStackType* value);		//取栈顶元素

size_t SeqStackSize(SeqStack* stack);      //栈的大小
