#include <stdio.h>
#include "seqstack.h"

int IsStackOrder(char input[], size_t input_size, char output[], size_t output_size){
    SeqStack stack;
    SeqStackInit(&stack);
    size_t output_index = 0;
    size_t input_index = 0;
    for(; input_index < input_size; ++input_index){
        SeqStackPush(&stack,input[input_index]);
        SeqStackType top;
        while(SeqStackTop(&stack, &top)){
            if(output_index >= output_size){
                break;
            }
            if(top == output[output_index]){
                ++output_index;
                SeqStackPop(&stack);
            }
            else{
                break;
            }
        }
    }
    if(output_index == output_size && SeqStackSize(&stack) == 0){
        return 1;
    }
    return 0;
}

void Test1(){
    char input[] = {'a','b','c','d','e'};
    size_t input_size = sizeof(input)/sizeof(input[0]);
    char output[] = {'a','b','e','d','c'};
    size_t output_size = sizeof(output)/sizeof(output[0]);
    int ret = IsStackOrder(input, input_size, output, output_size);
    printf("ret expect 1, actual %d\n",ret);
}

void Test2(){
    char input[] = {'a','b','c','d','e'};
    size_t input_size = sizeof(input)/sizeof(input[0]);
    char output[] = {'a','b','e','c','d'};
    size_t output_size = sizeof(output)/sizeof(output[0]);
    int ret = IsStackOrder(input, input_size, output, output_size);
    printf("ret expect 0, actual %d\n",ret);
}
int main(){
    Test1();
    Test2();
    return 0;
}
