#define _CRT_SECURE_NO_WARNINGS 1

#include "addr_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化通讯录
void AddrBookInit(AddrBook* addr_book)
{
	if (addr_book == NULL)                  //判空
	{
		printf("addr_book is null\n");
		return;
	}
	addr_book->size = 0;
	addr_book->capacity = 1;
	addr_book->data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
}

//打印通讯录所有信息
void AddrBookDisplay(AddrBook* addr_book)
{
	if (addr_book == NULL)                     //判空
	{
		printf("addr_book is null\n");
		return;
	}
	printf("|----------------|------------------|-----------------|\n");
	printf("|     姓  名     |      电  话      |      地  址     |\n");
	printf("|----------------|------------------|-----------------|\n");
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		printf("|      %s      |    %s   |       %s      |\n",
				addr_book->data[i].name,
				addr_book->data[i].phone,
				addr_book->data[i].addr);
		printf("|----------------|------------------|-----------------|\n");
	}
}

void AddrBookRelloc(AddrBook* addr_book)
{
	if (addr_book == NULL)                    //判空
	{
		printf("addr_book is null\n");
		return;
	}
	addr_book->capacity = addr_book->capacity * 2 + 1;
	PersonInfo* new_data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		new_data[i] = addr_book->data[i];              //将原来空间的内容拷贝到新的空间中
	}
	free(addr_book->data);         //释放原来空间
	addr_book->data = new_data;
}
//在通讯录中增加条目
void AddrBookAdd(AddrBook* addr_book)
{
	if (addr_book == NULL)            //判空
	{
		printf("addr_book is null\n");
		return;
	}
	if (addr_book->size >= addr_book->capacity)           //若容量不够需扩容
	{
		AddrBookRelloc(addr_book);
	}
	size_t cur = addr_book->size;
	++addr_book->size;
	printf("开始插入数据：\n");                   //插入新数据
	printf("请输入姓名：");
	scanf("%s", addr_book->data[cur].name);
	printf("请输入电话号码：");
	scanf("%s", addr_book->data[cur].phone);
	printf("请输入地址：");
	scanf("%s", addr_book->data[cur].addr);
	printf("插入成功！\n");
	return;
}

//保存通讯录
void AddrBookSave(AddrBook* addr_book)               //判空
{
	if (addr_book == NULL)
	{
		printf("addr_book is null\n");
		return;
	}
	FILE* fp = fopen(FILE_PATH, "w");                //以文本方式保存
	if (fp == NULL)
	{
		printf("打开文件失败！%s\n", FILE_PATH);
		return;
	}
	fprintf(fp, "|----------------|-------------------|-----------------|\n");
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		fprintf(fp, "|      %s      |    %s    |       %s      |\n",
			addr_book->data[i].name,
			addr_book->data[i].phone,
			addr_book->data[i].addr);
		fprintf(fp, "|----------------|-------------------|-----------------|\n");
	}
	fclose(fp);
}

//加载回内存
void AddrBookLoad(AddrBook* addr_book)
{
	if (addr_book == NULL)                    //判空
	{
		printf("addr_book is null\n");
		return;
	}
	FILE* fp = fopen(FILE_PATH, "r");
	if (fp == NULL)
	{
		printf("打开文件失败！%s\n", FILE_PATH);
		return;
	}
	while (!feof(fp))
	{
		if (addr_book->size >= addr_book->capacity)
		{
			AddrBookRelloc(addr_book);
		}
		size_t cur = addr_book->size;
		fscanf(fp, "%s%s%s\n",
			addr_book->data[cur].name,
			addr_book->data[cur].phone,
			addr_book->data[cur].addr);
		++addr_book->size;
	}
	fclose(fp);
}

//删除通讯录中指定条目
void AddrBookErase(AddrBook* addr_book)       
{
	if (addr_book == NULL)                    //判空
	{
		printf("addr_book is null\n");
		return;
	}
	char to_delete[200] = { 0 };
	printf("请输入要删除的联系人名字：");          //根据联系人姓名删除
	scanf("%s", &to_delete);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		if (strcmp(addr_book->data[i].name, to_delete) == 0)
		{
			free(addr_book->data);
			addr_book->size--;
			printf("删除成功！\n");
			return;
		}
	}
	if (i == addr_book->size)
	{
		printf("无此人，删除失败！\n");
		return;
	}
}

//查找指定条目
void AddrBookFind(AddrBook* addr_book)
{
	if (addr_book == NULL)                    //判空
	{
		printf("addr_book is null\n");
		return;
	}
	char name[200] = { 0 };
	printf("请输入要查找的联系人名字：");             //通过姓名查找
	scanf("%s", &name);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		if (strcmp(addr_book->data[i].name, name) == 0)
		{
			printf("找到了！\n");
			printf("此人信息为：\n 姓名：%s ,电话：%s ,地址：%s\n",
				addr_book->data[i].name,
				addr_book->data[i].phone,
				addr_book->data[i].addr);
			return;
		}
	}
	if (i == addr_book->size)
	{
		printf("无此人！\n");
		return;
	}
}

//修改指定条目
void AddrBookModify(AddrBook* addr_book)
{
	if (addr_book == NULL)
	{
		printf("addr_book is null\n");
		return;
	}
	char name[200] = { 0 };
	printf("请输入要修改的联系人名字：");
	scanf("%s", &name);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		if (strcmp(addr_book->data[i].name, name) == 0)
		{
			printf("这是第%lu个联系人：\n", i + 1);                    //先判断是第几个联系人
			printf("此人信息为：\n 姓名：%s ,电话：%s ,地址：%s\n",
				addr_book->data[i].name,
				addr_book->data[i].phone,
				addr_book->data[i].addr);
		}
	}
	size_t num = 0;
	printf("请输入需要修改的联系人编号：");             //通过联系人编号修改
	scanf("%lu", &num);
	char name2[200];
	char phone[200];
	char addr[200];
	printf("请输入新的姓名：");
	scanf("%s", name2);
	strcpy(addr_book->data[num - 1].name, name2);
	printf("请输入新的电话号码：");
	scanf("%s", phone);
	strcpy(addr_book->data[num - 1].phone, phone);
	printf("请输入新的地址：");
	scanf("%s", addr);
	strcpy(addr_book->data[num - 1].addr, addr);
	printf("修改成功！\n");
	return;
}

//销毁通讯录
void AddrBookDestroy(AddrBook* addr_book)
{
	if (addr_book == NULL)                        //判空
	{
		printf("addr_book is null\n");
		return;
	}
	else
	{
		addr_book->size = 0;
		addr_book->capacity = 0;
		free(addr_book->data);
		printf("已成功销毁！\n");
	}
}
