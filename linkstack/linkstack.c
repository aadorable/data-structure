#include "linkstack.h"

#include <stdio.h>
#include <stdlib.h>

LinkStackNode* CreateLinkStackNode(LinkStackType value){
	LinkStackNode* ptr = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}

void DestroyLinkStackNode(LinkStackNode* ptr){
	free(ptr);
}

//初始化栈
void LinkStackInit(LinkStackNode** bottom){
	if(bottom == NULL){
		return;		//非法输入
	}
	*bottom = NULL;
}

//销毁栈
void LinkStackDestroy(LinkStackNode** bottom){
	if(bottom == NULL){
		return;		//非法输入
	}
	if(*bottom == NULL){
		return;		//空栈
	}
	LinkStackNode* cur = *bottom;
	while(cur != NULL){
		LinkStackNode* next = cur->next;
		DestroyLinkStackNode(cur);
		cur = next;
	}
	*bottom = NULL;
	return;
}

//入栈
void LinkStackPush(LinkStackNode** bottom, LinkStackType value){
	if(bottom == NULL){
		return;		//非法输入
	}
	if(*bottom == NULL){
		//空栈
		*bottom = CreateLinkStackNode(value);
		return;
	}
	LinkStackNode* cur = *bottom;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = CreateLinkStackNode(value);
	return;
}

//出栈
void LinkStackPop(LinkStackNode** bottom){
	if(bottom == NULL){
		return;		//非法输入
	}
	if(*bottom == NULL){
		return;		//空栈，出栈失败
	}
	LinkStackNode* cur = *bottom;
	if(cur->next == NULL){		//栈中只有一个元素
		DestroyLinkStackNode(cur);
		*bottom = NULL;
		return;
	}
	while(cur->next != NULL){
		if(cur->next->next == NULL){
			LinkStackNode* to_delete = cur->next;
			cur->next = NULL;
			DestroyLinkStackNode(to_delete);
		}
		else{
			cur = cur->next;
		}
	}
	return;
}

//取栈顶元素
int LinkStackTop(LinkStackNode** bottom, LinkStackType* value){
	if(bottom == NULL){
		return 0;		//非法输入
	}
	if(*bottom == NULL){
		return 0;		//空栈，取栈顶元素失败
	}
	LinkStackNode* cur = *bottom;
	if(cur->next == NULL){
		*value = cur->data;
		return 1;
	}
	while(cur->next != NULL){
		cur = cur->next;
	}
	*value = cur->data;
	return 1;
}



/////////////////////////////////////////////////////////////
//以下是测试函数
/////////////////////////////////////////////////////////////
#if 1

#define TEST_HEADER printf("\n===================================%s===================================\n",__FUNCTION__)

void LinkStackPrintChar(LinkStackNode* bottom, const char* msg){
	printf("[%s]：\n",msg);
	if(bottom == NULL){
		printf("bottom = NULL\n");
	}
	printf("[栈底]");
	LinkStackNode* cur = bottom;
	for(;cur != NULL; cur = cur->next){
		printf("[%c] ",cur->data);
	}
	printf("[栈顶]\n\n");
}

void TestInit(){
	TEST_HEADER;
	LinkStackNode* bottom;
	LinkStackInit(&bottom);
	LinkStackPrintChar(bottom,"初始化空栈");
}

void TestDestroy(){
	TEST_HEADER;
	LinkStackNode* bottom;
	LinkStackInit(&bottom);
	LinkStackPush(&bottom, 'a');
	LinkStackPush(&bottom, 'b');
	LinkStackPush(&bottom, 'c');
	LinkStackPush(&bottom, 'd');
	LinkStackPrintChar(bottom,"入栈四个元素");
	LinkStackDestroy(&bottom);
	LinkStackPrintChar(bottom,"销毁栈");
	printf("bottom expect NULL, actual %p\n",bottom);
}

void TestPush(){
	TEST_HEADER;
	LinkStackNode* bottom;
	LinkStackInit(&bottom);
	LinkStackPush(&bottom, 'a');
	LinkStackPush(&bottom, 'b');
	LinkStackPush(&bottom, 'c');
	LinkStackPush(&bottom, 'd');
	LinkStackPrintChar(bottom,"入栈四个元素");
}

void TestPop(){
	TEST_HEADER;
	LinkStackNode* bottom;
	LinkStackInit(&bottom);
	LinkStackPush(&bottom, 'a');
	LinkStackPush(&bottom, 'b');
	LinkStackPush(&bottom, 'c');
	LinkStackPush(&bottom, 'd');
	LinkStackPrintChar(bottom,"入栈四个元素");

	LinkStackPop(&bottom);
	LinkStackPrintChar(bottom,"出栈一个元素");
	LinkStackPop(&bottom);
	LinkStackPrintChar(bottom,"再出栈一个元素");
	LinkStackPop(&bottom);
	LinkStackPop(&bottom);
	LinkStackPrintChar(bottom,"出栈两个元素");
	LinkStackPop(&bottom);
	LinkStackPrintChar(bottom,"尝试对空栈出栈");
}

void TestTop(){
	TEST_HEADER;
	LinkStackNode* bottom;
	LinkStackInit(&bottom);

	printf("[对空栈取栈顶元素]：\n");
	char tmp = '\0';
	int ret = LinkStackTop(&bottom,&tmp);
	printf("ret expect 0, actual %d\n",ret);
	printf("tmp expect  , actual %c\n\n",tmp);

	LinkStackPush(&bottom, 'a');
	LinkStackPush(&bottom, 'b');
	LinkStackPush(&bottom, 'c');
	LinkStackPush(&bottom, 'd');
	LinkStackPrintChar(bottom,"入栈四个元素");

	printf("[取栈顶元素]：\n");
	ret = LinkStackTop(&bottom,&tmp);
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
