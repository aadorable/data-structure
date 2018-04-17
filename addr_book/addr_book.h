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
	size_t size;           //��ϵ�˸���
	size_t capacity;        //����
}AddrBook;

void AddrBookInit(AddrBook* addr_book);          //��ʼ��ͨѶ¼

void AddrBookDisplay(AddrBook* addr_book);       //��ӡͨѶ¼������Ϣ
 
void AddrBookAdd(AddrBook* addr_book);           //��ͨѶ¼��������Ŀ

void AddrBookErase(AddrBook* addr_book);         //ɾ��ͨѶ¼��ָ����Ŀ

void AddrBookFind(AddrBook* addr_book);          //����ָ����Ŀ
 
void AddrBookModify(AddrBook* addr_book);        //�޸�ָ����Ŀ

void AddrBookDestroy(AddrBook* addr_book);       //����ͨѶ¼

void AddrBookSave(AddrBook* addr_book);          //����ͨѶ¼

void AddrBookLoad(AddrBook* addr_book);          //���ػ��ڴ�



