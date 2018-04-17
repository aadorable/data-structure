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
		printf("*************1.��ʾ������Ŀ*************\n");
		printf("*************2.������Ŀ*****************\n");
		printf("*************3.ɾ����Ŀ*****************\n");
		printf("*************4.������Ŀ*****************\n");
		printf("*************5.�޸���Ŀ*****************\n");
		printf("*************6.����ͨѶ¼***************\n");
		printf("*************0.�˳�ͨѶ¼***************\n");
		int choice = 0;
		printf("��ѡ��");
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
			printf("�ɹ��˳���\n");
			return 0;
			break;
		default:
			printf("�Ƿ����룬���������룡\n");
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