#define _CRT_SECURE_NO_WARNINGS 1

#include "addr_book.h"
#include <windows.h>
#include <stdio.h>

void Menu()
{
	AddrBook addr_book;
	AddrBookInit(&addr_book);
	AddrBookLoad(&addr_book);
	while (1)
	{
		printf("****************************************\n");
		printf("*************1.显示所有条目*************\n");
		printf("*************2.新增条目*****************\n");
		printf("*************3.删除条目*****************\n");
		printf("*************4.查找条目*****************\n");
		printf("*************5.修改条目*****************\n");
		printf("*************6.销毁通讯录***************\n");
		printf("*************0.退出通讯录***************\n");
		int choice = 0;
		printf("请选择：");
		scanf("%d", &choice);
		switch (choice)
		{
		case DISPLAY:
			AddrBookDisplay(&addr_book);
			break;
		case ADD:
			AddrBookAdd(&addr_book);
			AddrBookSave(&addr_book);
			break;
		case ERASE:
			AddrBookErase(&addr_book);
			break;
		case FIND:
			AddrBookFind(&addr_book);
			break;
		case MODIFY:
			AddrBookModify(&addr_book);
			break;
		case DESTROY:
			AddrBookDestroy(&addr_book);
			break;
		case EXIT:
			printf("成功退出！\n");
			return 0;
			break;
		default:
			printf("非法输入，请重新输入！\n");
			break;
		}
	}
}

int main()
{
	Menu();
	system("pause");
	return 0;
}