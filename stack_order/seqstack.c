#include "seqstack.h"

//初始化
void SeqStackInit(SeqStack* stack){
	if(stack == NULL){
		return;		//非法输入
	}
	stack->size = 0;
}

//销毁栈
void SeqStackDestroy(SeqStack* stack){
	if(stack == NULL){
		return;		//非法输入
	}
	stack->size = 0;
}

//入栈
void SeqStackPush(SeqStack* stack, SeqStackType value){
	if(stack == NULL){
		return;		//非法输入
	}
	if(stack->size >= SEQ_STACK_SIZE){
		return;		//栈已满
	}
	stack->data[stack->size++] = value;
}

//出栈
void SeqStackPop(SeqStack* stack){
	if(stack == NULL){
		return;		//非法输入
	}
	if(stack->size == 0){
		return;		//空栈
	}
	--stack->size;
}

//取栈顶元素
int SeqStackTop(SeqStack* stack, SeqStackType* value){
	if(stack == NULL || value == NULL){
		return 0;		//非法输入
	}
	if(stack->size == 0){
		return 0;		//空栈
	}
	*value = stack->data[stack->size - 1];
	return 1;
}

size_t SeqStackSize(SeqStack* stack){
    return stack->size;
}

////////////////////////////////////////////////////////////
//以下是测试函数
////////////////////////////////////////////////////////////

#if 0
#include <stdio.h>

#define TEST_HEADER printf("\n=============================%s=======================\n",__FUNCTION__)

void SeqStackPrintChar(SeqStack* stack, const char* msg){
	if(stack == NULL){
		printf("stack = NULL\n");
	}
	printf("[%s]：\n",msg);
	printf("[栈底] ");
	size_t i = 0;
	for(; i < stack->size; ++i){
		printf("[%c] ", stack->data[i]);
	}
	printf("[栈顶]\n");
}

void TestInit(){
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPrintChar(&stack, "初始化空栈");
	printf("stack->size expect 0, actual %lu\n",stack.size);
}

void TestDestroy(){
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack, 'a');
	SeqStackPush(&stack, 'b');
	SeqStackPush(&stack, 'c');
	SeqStackPush(&stack, 'd');
	SeqStackPrintChar(&stack, "入栈四个元素");
	SeqStackDestroy(&stack);
	SeqStackPrintChar(&stack, "销毁栈");
}

void TestPush(){
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack, 'a');
	SeqStackPush(&stack, 'b');
	SeqStackPush(&stack, 'c');
	SeqStackPush(&stack, 'd');
	SeqStackPrintChar(&stack, "入栈四个元素");
}

void TestPop(){
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack, 'a');
	SeqStackPush(&stack, 'b');
	SeqStackPush(&stack, 'c');
	SeqStackPush(&stack, 'd');
	SeqStackPrintChar(&stack, "入栈四个元素");
	SeqStackPop(&stack);
	SeqStackPrintChar(&stack, "出栈一个元素");
	SeqStackPop(&stack);
	SeqStackPrintChar(&stack, "再出栈一个元素");
	SeqStackPop(&stack);
	SeqStackPop(&stack);
	SeqStackPrintChar(&stack, "再出栈两个元素");
	SeqStackPop(&stack);
	SeqStackPrintChar(&stack, "尝试对空栈出栈");
}

void TestTop(){
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack, 'a');
	SeqStackPush(&stack, 'b');
	SeqStackPush(&stack, 'c');
	SeqStackPush(&stack, 'd');
	SeqStackPrintChar(&stack, "入栈四个元素");
	char tmp = '\0';
	int ret = SeqStackTop(&stack, &tmp);
	printf("ret expect 1, actual %d\n",ret);
	printf("tmp expect d, actual %c\n",tmp);
}

int main(){
	TestInit();
	TestDestroy();
	TestPush();
	TestPop();
	TestTop();
	return 0;
}

#endif
