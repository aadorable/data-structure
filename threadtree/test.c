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

void TestPreThreading(){
    TEST_HEADER;
    ThreadType array[] = "ABD##EG###C#F##";
    ThreadNode* root = ThreadTreeCreate(array, strlen(array), '#');
    PreThreading(root);
    return;
}

void TestPreOrderByThreading(){
    TEST_HEADER;
    ThreadType array[] = "ABD##EG###C#F##";
    ThreadNode* root = ThreadTreeCreate(array, strlen(array), '#');
    PreThreading(root);
    PreOrderByThreading(root);
    return;
}

void TestInThreading(){
    TEST_HEADER;
    ThreadType array[] = "ABD##EG###C#F##";
    ThreadNode* root = ThreadTreeCreate(array, strlen(array), '#');
    InThreading(root);
    return;
}

void TestInOrderByThreading(){
    TEST_HEADER;
    ThreadType array[] = "ABD##EG###C#F##";
    ThreadNode* root = ThreadTreeCreate(array, strlen(array), '#');
    InThreading(root);
    InOrderByThreading(root);
    return;
}

void TestPostThreading(){
    TEST_HEADER;
    ThreadType array[] = "ABD##EG###C#F##";
    ThreadNode* root = ThreadTreeCreate(array, strlen(array), '#');
    PostThreading(root);
    return;
}

int main(){
    TestCreate();
    TestPreThreading();
    TestPreOrderByThreading();
    TestInThreading();
    TestInOrderByThreading();
    TestPostThreading();
    return 0;
}
