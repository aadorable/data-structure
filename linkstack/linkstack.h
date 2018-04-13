#pragma once

#include <stddef.h>

typedef char LinkStackType;

typedef struct LinkStackNode{
	LinkStackType data;
	struct LinkStackNode* next;
}LinkStackNode;

void LinkStackInit(LinkStackNode** bottom);		//初始化栈

void LinkStackDestroy(LinkStackNode** bottom);		//销毁栈

void LinkStackPush(LinkStackNode** bottom, LinkStackType value);		//入栈

void LinkStackPop(LinkStackNode** bottom);		//出栈

int LinkStackTop(LinkStackNode** bottom, LinkStackType* value);		//取栈顶元素

