#pragma once

#include <stddef.h>

#define NAME_SIZE 200   //����
#define PHONE_SIZE 200   //�绰����
#define ADDR_SIZE 200    //סַ

//��ϵ��
typedef struct PersonInfo
{
	char name[NAME_SIZE];
	char phone[PHONE_SIZE];
	char addr[ADDR_SIZE];
}PersonInfo;
