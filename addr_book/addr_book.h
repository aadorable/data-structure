#pragma once

#include "person_info.h"

#define FILE_PATH "./data.txt"

enum{
	DISPLAY = 1,
	ADD = 2,
	ERASE = 3,
	FIND = 4,
	MODIFY = 5,
	DESTROY = 6,
	EXIT = 0
};

typedef struct AddrBook
{
	PersonInfo* data;
	size_t size;           //联系人个数
	size_t capacity;        //容量
}AddrBook;

void AddrBookInit(AddrBook* addr_book);          //初始化通讯录

void AddrBookDisplay(AddrBook* addr_book);       //打印通讯录所有信息
 
void AddrBookAdd(AddrBook* addr_book);           //在通讯录中增加条目

void AddrBookErase(AddrBook* addr_book);         //删除通讯录中指定条目

void AddrBookFind(AddrBook* addr_book);          //查找指定条目
 
void AddrBookModify(AddrBook* addr_book);        //修改指定条目

void AddrBookDestroy(AddrBook* addr_book);       //销毁通讯录

void AddrBookSave(AddrBook* addr_book);          //保存通讯录

void AddrBookLoad(AddrBook* addr_book);          //加载回内存



