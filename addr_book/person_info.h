#pragma once

#include <stddef.h>

#define NAME_SIZE 200   //姓名
#define PHONE_SIZE 200   //电话号码
#define ADDR_SIZE 200    //住址

//联系人
typedef struct PersonInfo
{
	char name[NAME_SIZE];
	char phone[PHONE_SIZE];
	char addr[ADDR_SIZE];
}PersonInfo;
