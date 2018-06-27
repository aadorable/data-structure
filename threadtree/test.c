#include <stdio.h>
#include <string.h>

#include "ThreadTree.h"

#define TEST_HEADER printf("=============%s==============\n", __FUNCTION__)

void TestCreate(){
    TEST_HEADER;
    ThreadType array[] = "ABD##EG###C#F##";
    ThreadNode* root = ThreadTreeCreate(array, strlen(array), '#');
    (void) root;
    return;
}

int main(){
    TestCreate();
    return 0;
}
