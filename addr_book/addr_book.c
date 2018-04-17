#define _CRT_SECURE_NO_WARNINGS 1

#include "addr_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʼ��ͨѶ¼
void AddrBookInit(AddrBook* addr_book)
{
	if (addr_book == NULL)                  //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	addr_book->size = 0;
	addr_book->capacity = 1;
	addr_book->data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
}

//��ӡͨѶ¼������Ϣ
void AddrBookDisplay(AddrBook* addr_book)
{
	if (addr_book == NULL)                     //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	printf("|----------------|------------------|-----------------|\n");
	printf("|     ��  ��     |      ��  ��      |      ��  ַ     |\n");
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
	if (addr_book == NULL)                    //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	addr_book->capacity = addr_book->capacity * 2 + 1;
	PersonInfo* new_data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		new_data[i] = addr_book->data[i];              //��ԭ���ռ�����ݿ������µĿռ���
	}
	free(addr_book->data);         //�ͷ�ԭ���ռ�
	addr_book->data = new_data;
}
//��ͨѶ¼��������Ŀ
void AddrBookAdd(AddrBook* addr_book)
{
	if (addr_book == NULL)            //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	if (addr_book->size >= addr_book->capacity)           //����������������
	{
		AddrBookRelloc(addr_book);
	}
	size_t cur = addr_book->size;
	++addr_book->size;
	printf("��ʼ�������ݣ�\n");                   //����������
	printf("������������");
	scanf("%s", addr_book->data[cur].name);
	printf("������绰���룺");
	scanf("%s", addr_book->data[cur].phone);
	printf("�������ַ��");
	scanf("%s", addr_book->data[cur].addr);
	printf("����ɹ���\n");
	return;
}

//����ͨѶ¼
void AddrBookSave(AddrBook* addr_book)               //�п�
{
	if (addr_book == NULL)
	{
		printf("addr_book is null\n");
		return;
	}
	FILE* fp = fopen(FILE_PATH, "w");                //���ı���ʽ����
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�%s\n", FILE_PATH);
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

//���ػ��ڴ�
void AddrBookLoad(AddrBook* addr_book)
{
	if (addr_book == NULL)                    //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	FILE* fp = fopen(FILE_PATH, "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�%s\n", FILE_PATH);
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

//ɾ��ͨѶ¼��ָ����Ŀ
void AddrBookErase(AddrBook* addr_book)       
{
	if (addr_book == NULL)                    //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	char to_delete[200] = { 0 };
	printf("������Ҫɾ������ϵ�����֣�");          //������ϵ������ɾ��
	scanf("%s", &to_delete);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		if (strcmp(addr_book->data[i].name, to_delete) == 0)
		{
			free(addr_book->data);
			addr_book->size--;
			printf("ɾ���ɹ���\n");
			return;
		}
	}
	if (i == addr_book->size)
	{
		printf("�޴��ˣ�ɾ��ʧ�ܣ�\n");
		return;
	}
}

//����ָ����Ŀ
void AddrBookFind(AddrBook* addr_book)
{
	if (addr_book == NULL)                    //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	char name[200] = { 0 };
	printf("������Ҫ���ҵ���ϵ�����֣�");             //ͨ����������
	scanf("%s", &name);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		if (strcmp(addr_book->data[i].name, name) == 0)
		{
			printf("�ҵ��ˣ�\n");
			printf("������ϢΪ��\n ������%s ,�绰��%s ,��ַ��%s\n",
				addr_book->data[i].name,
				addr_book->data[i].phone,
				addr_book->data[i].addr);
			return;
		}
	}
	if (i == addr_book->size)
	{
		printf("�޴��ˣ�\n");
		return;
	}
}

//�޸�ָ����Ŀ
void AddrBookModify(AddrBook* addr_book)
{
	if (addr_book == NULL)
	{
		printf("addr_book is null\n");
		return;
	}
	char name[200] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ�����֣�");
	scanf("%s", &name);
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		if (strcmp(addr_book->data[i].name, name) == 0)
		{
			printf("���ǵ�%lu����ϵ�ˣ�\n", i + 1);                    //���ж��ǵڼ�����ϵ��
			printf("������ϢΪ��\n ������%s ,�绰��%s ,��ַ��%s\n",
				addr_book->data[i].name,
				addr_book->data[i].phone,
				addr_book->data[i].addr);
		}
	}
	size_t num = 0;
	printf("��������Ҫ�޸ĵ���ϵ�˱�ţ�");             //ͨ����ϵ�˱���޸�
	scanf("%lu", &num);
	char name2[200];
	char phone[200];
	char addr[200];
	printf("�������µ�������");
	scanf("%s", name2);
	strcpy(addr_book->data[num - 1].name, name2);
	printf("�������µĵ绰���룺");
	scanf("%s", phone);
	strcpy(addr_book->data[num - 1].phone, phone);
	printf("�������µĵ�ַ��");
	scanf("%s", addr);
	strcpy(addr_book->data[num - 1].addr, addr);
	printf("�޸ĳɹ���\n");
	return;
}

//����ͨѶ¼
void AddrBookDestroy(AddrBook* addr_book)
{
	if (addr_book == NULL)                        //�п�
	{
		printf("addr_book is null\n");
		return;
	}
	else
	{
		addr_book->size = 0;
		addr_book->capacity = 0;
		free(addr_book->data);
		printf("�ѳɹ����٣�\n");
	}
}
