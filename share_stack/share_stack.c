#include <stdio.h>

#define ShareStackMaxSize 1000
typedef char ShareStackType;

//[0, top1)区间表示第一个栈
//[top2, ShareStackMaxSize)区间表示第二个栈
typedef struct ShareStack{
    ShareStackType data[ShareStackMaxSize];
    size_t top1;
    size_t top2;
}ShareStack;

void ShareStackInit(ShareStack* stack){
    if(stack == NULL){
        return;     //非法输入
    }
    stack->top1 = 0;
    stack->top2 = ShareStackMaxSize;
}

void ShareStackPush1(ShareStack* stack, ShareStackType value){
    if(stack == NULL){
        return;    //非法输入
    }
    if(stack->top1 >= stack->top2){
        return;     //栈已满
    }
    stack->data[stack->top1++] = value;
    return;
}

void ShareStackPush2(ShareStack* stack, ShareStackType value){
    if(stack == NULL){
        return;     //非法输入
    }
    if(stack->top1 >= stack->top2){
        return;    //栈已满
    }
    stack->data[--stack->top2] = value;
    return;
}

void ShareStackPop1(ShareStack* stack){
    if(stack == NULL){
        return;     //非法输入
    }
    if(stack->top1 == 0){
        return;     //空栈
    }
    --stack->top1;
    return;
}

void ShareStackPop2(ShareStack* stack){
    if(stack == NULL){
        return;     //非法输入
    }
    if(stack->top2 == ShareStackMaxSize){
        return;     //空栈
    }
    ++stack->top2;
    return;
}

int ShareStackTop1(ShareStack* stack, ShareStackType* value){
    if(stack == NULL || value == NULL){
        return 0;    //非法输入
    }
    if(stack->top1 == 0){
        return 0;   //空栈
    }
    *value = stack->data[stack->top1 - 1];
    return 1;
}

int ShareStackTop2(ShareStack* stack, ShareStackType* value){
    if(stack == NULL || value == NULL){
        return 0;     //非法输入
    }
    if(stack->top2 == ShareStackMaxSize){
        return 0;     //空栈
    }
    *value = stack->data[stack->top2];
    return 1;
}



////////////////////////////////////////////////////////////////////////////////
//以下是测试代码
///////////////////////////////////////////////////////////////////////////////

#if 1
#define TEST_HEAD printf("\n==================%s=================\n", __FUNCTION__)

void ShareStackPrint(ShareStack* stack,const char* msg){
    if(stack == NULL){
        return;   //非法输入
    }
    printf("【******%s******】\n", msg);
    printf("共享栈一：\n");
    printf("[栈底]：");
    size_t i = 0;
    for(;i < stack->top1; ++i){
        printf("[%c] ",stack->data[i]);
    }
    printf("[栈顶]\n");
    printf("共享栈二：\n");
    printf("[栈底]：");
    size_t j = ShareStackMaxSize;
    for(; j > stack->top2; --j){
        printf("[%c] ",stack->data[j - 1]);
    }
    printf("[栈顶]\n");
}

void TestInit(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackPrint(&stack, "初始化栈");
    printf("stack->top1 expect 0, actual %lu\n", stack.top1);
    printf("stack->top2 expect 1000, actual %lu\n", stack.top2);
}

void TestPush1(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackPush1(&stack, 'a');
    ShareStackPush1(&stack, 'b');
    ShareStackPush1(&stack, 'c');
    ShareStackPush1(&stack, 'd');
    ShareStackPrint(&stack, "向共享栈一中入栈四个元素");
}

void TestPush2(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackPush2(&stack, 'e');
    ShareStackPush2(&stack, 'f');
    ShareStackPush2(&stack, 'g');
    ShareStackPush2(&stack, 'h');
    ShareStackPrint(&stack, "向共享栈二中入栈四个元素");
}

void TestPop1(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackPop1(&stack);
    ShareStackPrint(&stack, "尝试对空栈出栈");

    ShareStackPush1(&stack, 'a');
    ShareStackPush1(&stack, 'b');
    ShareStackPush1(&stack, 'c');
    ShareStackPush1(&stack, 'd');
    ShareStackPrint(&stack, "向共享栈一中入栈四个元素");
    ShareStackPop1(&stack);
    ShareStackPrint(&stack, "对共享栈一出栈一个元素");

    ShareStackPop1(&stack);
    ShareStackPop1(&stack);
    ShareStackPrint(&stack, "对共享栈一再出栈两个元素");
}

void TestPop2(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackPop2(&stack);
    ShareStackPrint(&stack, "尝试对空栈出栈");

    ShareStackPush2(&stack, 'e');
    ShareStackPush2(&stack, 'f');
    ShareStackPush2(&stack, 'g');
    ShareStackPush2(&stack, 'h');
    ShareStackPrint(&stack, "向共享栈二中入栈四个元素");
    ShareStackPop2(&stack);
    ShareStackPrint(&stack, "对共享栈二出栈一个元素");

    ShareStackPop2(&stack);
    ShareStackPop2(&stack);
    ShareStackPrint(&stack, "对共享栈二再出栈两个元素");
}

void TestTop1(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackType value = 0;
    int ret = ShareStackTop1(&stack, &value);
    ShareStackPrint(&stack, "尝试对空栈取栈顶元素");
    printf("ret except 0, expect %d\n", ret);
    printf("value expect  , actual %c\n", value);

    ShareStackPush1(&stack, 'a');
    ShareStackPush1(&stack, 'b');
    ShareStackPush1(&stack, 'c');
    ShareStackPush1(&stack, 'd');
    ret = ShareStackTop1(&stack, &value);
    ShareStackPrint(&stack, "对共享栈一取栈顶元素");
    printf("ret except 1, expect %d\n", ret);
    printf("value expect d, actual %c\n", value);
}

void TestTop2(){
    TEST_HEAD;
    ShareStack stack;
    ShareStackInit(&stack);
    ShareStackType value = 0;
    int ret = ShareStackTop2(&stack, &value);
    ShareStackPrint(&stack, "尝试对空栈取栈顶元素");
    printf("ret except 0, expect %d\n", ret);
    printf("value expect  , actual %c\n", value);

    ShareStackPush2(&stack, 'e');
    ShareStackPush2(&stack, 'f');
    ShareStackPush2(&stack, 'g');
    ShareStackPush2(&stack, 'h');
    ret = ShareStackTop2(&stack, &value);
    ShareStackPrint(&stack, "对共享栈二取栈顶元素");
    printf("ret except 1, expect %d\n", ret);
    printf("value expect h, actual %c\n", value);
}

int main(){
    TestInit();
    TestPush1();
    TestPush2();
    TestPop1();
    TestPop2();
    TestTop1();
    TestTop2();
    return 0;
}

#endif
