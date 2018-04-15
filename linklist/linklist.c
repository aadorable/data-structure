
#include "linklist.h"

#include <stdlib.h>

void LinkListInit(LinkNode** head)    //初始化
{
	if (head == NULL)    //非法操作
	{
		return;
	}
	*head = NULL;
}

LinkNode* LinkListCreateNode(LinkType value)    //创建结点
{
	LinkNode* ptr = (LinkNode *)malloc(sizeof(LinkNode));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}

void LinkListDestroyNode(LinkNode* ptr)         //销毁结点
{
	free(ptr);
}


void LinkListPrintChar(LinkNode* head, const char* msg)    //打印链表
{
	printf("[%s]:", msg);
	LinkNode* cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		printf("[%c:%p] -> ", cur->data, cur);
	}
	printf("[NULL]\n\n");
}


LinkNode* LinkListPushBack(LinkNode** head, LinkType value)   //尾插
{
	if (head == NULL)    //非法输入
	{
		return NULL;
	}
	if (*head == NULL)    //空链表，直接插在头结点上
	{
		*head = LinkListCreateNode(value);
		return *head;
	}
	LinkNode* cur = *head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = LinkListCreateNode(value);
	return cur->next;
}

void LinkListPopBack(LinkNode** head)        //尾删
{
	if (head == NULL)
	{
		return;        //非法输入
	}
	if (*head == NULL)
	{
		return;     //空链表，什么也不干
	}
	LinkNode* cur = *head;
	if (cur->next == NULL)
	{
		//只有一个结点，直接删除当前头结点
		LinkListDestroyNode(cur);
		*head = NULL;
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
		{
			//找到倒数第二个结点
			LinkNode* to_delete = cur->next;
			cur->next = NULL;
			LinkListDestroyNode(to_delete);
		}
		else
		{
			cur = cur->next;
		}
	}
	return;
}

void LinkListPushFront(LinkNode** head, LinkType value)   //头插
{
	if (head == NULL)
	{
		return;    //非法输入
	}
	if (*head == NULL)    //空链表，直接插在头结点上
	{
		*head = LinkListCreateNode(value);
		return;
	}
	LinkNode* new_node = LinkListCreateNode(value);
	new_node->next = *head;
	*head = new_node;
	return;
}

void LinkListPopFront(LinkNode** head)     //头删
{
	if (head == NULL)
	{
		return;   //非法输入
	}
	if (*head == NULL)
	{
		return;     //空链表，什么也不干
	}
	LinkNode* to_delete = *head;
	*head = (*head)->next;
	LinkListDestroyNode(to_delete);
}

LinkNode* LinkListFind(LinkNode* head, LinkType to_find)     //查找元素在链表中的位置
{
	LinkNode* cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->data == to_find)
		{
			return cur;
		}
	}
	return NULL;
}

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value)       //在pos之前插入元素
{
	if (head == NULL)
	{
		return;        //非法输入
	}
	if (*head == NULL)
	{
		//对于空链表来说，pos无意义，只能把这个元素作为唯一的节点，并让头结点指针指向这个节点
		*head = LinkListCreateNode(value);
		return;
	}
	if (*head == pos)
	{
		//pos指向头结点，无法找到pos之前结点，处理成头插
		LinkListPushFront(head, value);
		return;
	}
	if (pos == NULL)
	{
		LinkListPushBack(head, value);
		return;
	}
	LinkNode* cur = *head;
	while(cur->next != NULL)
	{
		if (cur->next == pos)
		{
			//找到pos的前一个位置cur，插入
			LinkNode* new_node = LinkListCreateNode(value);
			new_node->next = pos;
			cur->next = new_node;
			return;
		}
		else
		{
			cur = cur->next;
		}
	}
	//未找到pos，直接返回
	return;
}

void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value)       //在pos之后插入元素
{
	if (head == NULL)
	{
		return;     //非法输入
	}
	if (*head == NULL)
	{
		//对于空链表来说，pos无意义，只能把这个元素作为唯一的节点，并让头结点指针指向这个节点
		*head = LinkListCreateNode(value);
		return;
	}
	if (pos == NULL)
	{
		return;    //非法输入
	}
	LinkNode* new_node = LinkListCreateNode(value);
	new_node->next = pos->next;
	pos->next = new_node;
}

void LinkListErase1(LinkNode** head, LinkNode* pos)           //删除指定位置的元素
{
	if (head == NULL || pos == NULL)
	{
		return;     //非法输入
	}
	if (*head == NULL)
	{
		return;     //空链表，删除失败
	}
	if (*head == pos)
	{
		//要删除的刚好是头结点，修改head指向即可
		LinkNode* to_delete = *head;
		*head = (*head)->next;
		LinkListDestroyNode(to_delete);
		return;
	}
	//pos指向任何位置，此时需要找到pos的前一个位置
	LinkNode* cur = *head;
	while (cur->next != NULL)
	{
		if (cur->next == pos)
		{
			//进行删除动作
			cur->next = pos->next;
			LinkListDestroyNode(pos);
			return;
		}
		else
		{
			cur = cur->next;
		}
	}
	return;   //pos在链表上不存在
}

void LinkListErase2(LinkNode** head, LinkNode** pos)
{
	if (head == NULL)
	{
		return;    //非法输入
	}
	if (*head == NULL)
	{
		return;    //空链表，删除失败
	}
	if (*pos != NULL && (*pos)->next != NULL)
	{
		(*pos)->data = (*pos)->next->data;
		LinkNode* to_delete = (*pos)->next;
		(*pos)->next = to_delete->next;
		LinkListDestroyNode(to_delete);
		return;
	}
	if ((*pos)->next == NULL)
	{
		LinkNode* to_delete = *pos;
		*pos = NULL;
		LinkListDestroyNode(to_delete);
		return;
	}
}

void LinkListRemove1(LinkNode** head, LinkType value)          //删除指定值的元素
{
	if (head == NULL)
	{
		return;    //非法输入
	}
	if (*head == NULL)
	{
		return;       //空链表，删除失败
	}
	LinkNode* pos = LinkListFind(*head, value);
	LinkListErase1(head, pos);
}

void LinkListRemove2(LinkNode** head, LinkType value)
{
	if (head == NULL)
	{
		return;      //非法输入
	}
	if (*head == NULL)
	{
		return;       //空链表，删除失败
	}
	if ((*head)->data == value)      //要删除的是头结点
	{
		LinkNode* to_delete = *head;
		*head = (*head)->next;
		LinkListDestroyNode(to_delete);
		return;
	}
	LinkNode* pre = *head;
	LinkNode* cur = (*head)->next;
	while (cur != NULL)
	{
		if (cur->data == value)
		{
			pre->next = cur->next;
			LinkListDestroyNode(cur);
			return;
		}
		else
		{
			pre = pre->next;
			cur = cur->next;
		}
	}
	//要删除的元素不存在，直接返回
	return;     
}

void LinkListRemoveAll(LinkNode** head, LinkType value)          //删除指定值的所有元素
{
	if (head == NULL)
	{
		return;    //非法输入
	}
	if (*head == NULL)
	{
		return;     //空链表，删除失败
	}
	while (1)
	{
		LinkNode* pos = LinkListFind(*head, value);
		if (pos == NULL)
		{
			break;
		}
		LinkListErase1(head, pos);
	}
	return;
}

int LinkListEmpty(LinkNode* head)          //判断链表是否为空，为空返回1，否则返回0
{
	return head == NULL ? 1 : 0;
}

size_t LinkListSize(LinkNode* head)        //求链表元素个数
{
	if (head == NULL)
	{
		return 0;    //空链表
	}
	size_t count = 0;
	LinkNode* cur = head;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

//经典面试题

void LinkListReversePrint(LinkNode* head)      //逆序打印单链表
{
	if (head == NULL)
	{
		return;
	}
	LinkListReversePrint(head->next);
	printf("[%c:%p] ", head->data, head);
}

void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value)   //不允许遍历链表, 在 pos之前插入
{
	if (head == NULL || pos == NULL)
	{
		return;     //非法输入
	}
	LinkNode* new_node = LinkListCreateNode(pos->data);
	pos->data = value;
	new_node->next = pos->next;
	pos->next = new_node;
	return;
}

LinkNode* JosephCycle(LinkNode* head, size_t food)     //约瑟夫环
{
	if (head == NULL)
	{
		return NULL;
	}
	if (food == 0)
	{
		return NULL;
	}
	LinkNode* cur = head;
	while (cur != cur->next)
	{
		size_t i = 0;
		for (; i < food - 1; ++i)
		{
			cur = cur->next;
		}
		printf("food：[%c]\n", cur->data);
		cur->data = cur->next->data;
		LinkNode* to_delete = cur->next;
		cur->next = to_delete->next;
		LinkListDestroyNode(to_delete);
	}
	return cur;
}

void LinkListReverse(LinkNode** head)     //单链表逆置
{
	if (head == NULL)
	{
		return;   //非法输入
	}
	if (*head == NULL)
	{
		return;		//空链表
	}
	if ((*head)->next == NULL)
	{
		return;		//只有一个元素
	}
	LinkNode* cur = *head;
	while (cur->next != NULL)
	{
		LinkNode* to_delete = cur->next;
		//将当前结点删除
		cur->next = to_delete->next;
		//将这个被删除的结点插入到链表头部
		to_delete->next = *head;
		*head = to_delete;
	}
	return;
}

void LinkListReverse2(LinkNode** head)
{
	if (head == NULL)
	{
		return;   //非法输入
	}
	if (*head == NULL)
	{
		return;		//空链表
	}
	if ((*head)->next == NULL)
	{
		return;		//只有一个元素
	}
	LinkNode* pre = *head;
	LinkNode* cur = (*head)->next;
	pre->next = NULL;
	while (cur != NULL)
	{
		LinkNode* next = cur->next;
		cur->next = pre;        //重置了当前结点的next
		pre = cur;
		cur = next;
	}
	*head = pre;
	return;
}

void Swap(LinkType* a, LinkType* b)
{
	LinkType tmp = *a;
	*a = *b;
	*b = tmp;
}
void LinkListBubbleSort(LinkNode* head)     //单链表的冒泡排序(升序)
{
	if (head == NULL)
	{
		return;
	}
	LinkNode* count = head;
	LinkNode* tail = NULL;
	for (; count != NULL; count = count->next)
	{
		LinkNode* cur = head;
		for (; cur->next != tail; cur = cur->next)
		{
			if (cur->data > cur->next->data)
			{
				Swap(&cur->data, &cur->next->data);
			}
		}
		tail = cur;
	}
}

LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2)     //将两个有序链表, 合并成一个有序链表
{
	LinkNode* cur1 = head1;
	LinkNode* cur2 = head2;
	LinkNode* new_head = NULL;
	LinkNode* new_tail = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			if (new_head == NULL)
			{
				new_head = new_tail = cur1;
			}
			else
			{
				new_tail->next = cur1;
				new_tail = new_tail->next;
			}
			cur1 = cur1->next;
		}
		else if (cur1->data >= cur2->data)
		{
			if (new_head == NULL)
			{
				new_head = new_tail = cur2;
			}
			else
			{
				new_tail->next = cur2;
				new_tail = new_tail->next;
			}
			cur2 = cur2->next;
		}
	}
	if (cur1 != NULL)
	{
		new_tail->next = cur1;
	}
	else
	{
		new_tail->next = cur2;
	}
	return new_head;
}

LinkNode* FindMidNode(LinkNode* head)      //找到中间节点
{
	LinkNode* slow = head;
	LinkNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

LinkNode* FindLastKNode(LinkNode* head, size_t K)       //找到倒数第 K 个节点
{
	LinkNode* slow = head;
	LinkNode* fast = head;
	size_t i = 0;
	for (; i < K && fast != NULL; ++i)
	{
		fast = fast->next;
	}
	if (i < K)
	{
		//这种情况表示链表结点小于K，直接返回NULL
		return NULL;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void EraseLastKNode(LinkNode** head, size_t K)      //删除倒数第K个节点
{
	if (head == NULL)
	{
		return;   //非法输入
	}
	if (*head == NULL)
	{
		return;		//空链表
	}
	size_t size = LinkListSize(*head);
	if (size < K)
	{
		//要删除的结点不存在
		return;
	}
	if (size == K)
	{
		//要删除的是头结点
		LinkNode* to_delete = *head;
		*head = (*head)->next;
		LinkListDestroyNode(to_delete);
		return;
	}
	LinkNode* cur = *head;
	size_t i = 0;
	for (; i < size - (K + 1); ++i)
	{
		cur = cur->next;
	}
	LinkNode* to_delete = cur->next;
	cur->next = to_delete->next;
	LinkListDestroyNode(to_delete);
	return;
}

LinkNode* HasCycle(LinkNode* head)      //判定单链表是否带环. 如果带环返回1
{
	LinkNode* slow = head;
	LinkNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}

size_t GetCycleLen(LinkNode* head)       //如果链表带环, 求出环的长度
{
	LinkNode* meet_node = HasCycle(head);
	if (meet_node == NULL)
	{
		return 0;    //链表无环
	}
	size_t count = 1;
	LinkNode* cur = meet_node;
	for (; cur->next != meet_node; cur = cur->next)
	{
		++count;
	}
	return count;
}

LinkNode* GetCycleEntry(LinkNode* head)       //如果链表带环, 求出环的入口
{
	LinkNode* meet_node = HasCycle(head);
	if (meet_node == NULL)
	{
		return NULL;		//无环，直接返回
	}
	LinkNode* cur1 = head;
	LinkNode* cur2 = meet_node;
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

LinkNode* HasCross(LinkNode* head1, LinkNode* head2)       //判定两个链表是否相交, 并求出交点
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	size_t size1 = LinkListSize(head1);
	size_t size2 = LinkListSize(head2);
	LinkNode* cur1 = head1;
	LinkNode* cur2 = head2;
	if (size1 < size2)
	{
		size_t i = 0;
		for (; i < size2 - size1; ++i)
		{
			cur2 = cur2->next;
		}
	}
	else
	{
		size_t i = 0;
		for (; i < size1 - size2; ++i)
		{
			cur1 = cur1->next;
		}
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

int HasCrossWithCycle(LinkNode* head1, LinkNode* head2)       //判定两个链表是否相交(假设链表可能带环)
{
	if (head1 == NULL || head2 == NULL)
	{
		return 0;
	}
	LinkNode* entry1 = GetCycleEntry(head1);
	LinkNode* entry2 = GetCycleEntry(head2);
	if (entry1 == NULL && entry2 == NULL)
	{
		//1.两个链表都不带环
		return HasCross(head1, head2) != NULL ? 1 : 0;
	}
	else if (entry1 != NULL && entry2 != NULL)
	{
		//2.两链表都带环
		if (entry1 == entry2)
		{
			//相交在环外
			return 1;
		}
		LinkNode* cur = entry1;
		while (cur->next != entry1)
		{
			//相交在环上
			if (cur == entry2)
			{
				return 1;
			}
			cur = cur->next;
		}
		return 0;	//不相交
	}
	else
	{
		//3.一个带环，一个不带环，一定不相交
		return 0;
	}
	return 0;
}

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2)			//求两个已排序单链表中相同的数据
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	LinkNode* cur1 = head1;
	LinkNode* cur2 = head2;
	LinkNode* new_head = NULL;
	LinkNode* new_tail = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data > cur2->next)
		{
			cur2 = cur2->next;
		}
		else
		{
			//cur1的值与cur2的值相等，将这个元素放到结果中去
			LinkNode* new_node = LinkListCreateNode(cur1->data);
			if (new_head == NULL)
			{
				new_head = new_tail = new_node;
			}
			else
			{
				new_tail->next = new_node;
				new_tail = new_tail->next;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	return new_head;
}

ComplexNode* CreateComplexNode(LinkType value)
{
	ComplexNode* ptr = (ComplexNode*)malloc(sizeof(ComplexNode));
	ptr->data = value;
	ptr->next = NULL;
	ptr->random = NULL;
	return ptr;
}

size_t Diff(ComplexNode* src, ComplexNode* dest)
{
	if (src == NULL || dest == NULL)
	{
		return (size_t)-1;
	}
	size_t count = 0;
	while (src != NULL)
	{
		if (src == dest)
		{
			return count;
		}
		++count;
		src = src->next;
	}
	return (size_t)-1;
}
ComplexNode* Step(ComplexNode* pos, size_t offset)
{
	size_t i = 0;
	for (; i < offset; ++i)
	{
		if (pos == NULL)
		{
			return NULL;
		}
		pos = pos->next;
	}
	return pos;
}
ComplexNode* CopyComplex(ComplexNode* head)          //拷贝复杂链表
{
	if (head == NULL)
	{
		return NULL;		//空链表
	}
	//1.先把链表进行简单复制
	ComplexNode* new_head = NULL;
	ComplexNode* new_tail = NULL;
	ComplexNode* cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		ComplexNode* new_node = CreateComplexNode(cur->data);
		if (new_head == NULL)
		{
			new_head = new_tail = new_node;
		}
		else
		{
			new_tail->next = new_node;
			new_tail = new_tail->next;
		}
	}
	//2.再去依次求每个random指针相对头结点的偏移量
	ComplexNode* new_cur = new_head;
	for (cur = head; cur != NULL && new_cur != NULL; cur = cur->next, new_cur = new_cur->next)
	{
		if (cur->random == NULL)
		{
			new_cur->random = NULL;
			continue;
		}
		//3.根据偏移量，修改每个新链表结点的random指针
		size_t offset = Diff(head, cur->random);
		new_cur->random = Step(head, offset);
	}
	return new_head;
}

ComplexNode* CopyComplex2(ComplexNode* head)          //拷贝复杂链表
{
	//1.遍历旧链表，给每一个结点都创建一个对应的新结点
	//   并将新结点插入到旧结点之后
	ComplexNode* cur = head;
	for (; cur != NULL; cur = cur->next->next)
	{
		ComplexNode* new_node = CreateComplexNode(cur->data);
		new_node->next = cur->next;
		cur->next = new_node;
	}
	//2.再遍历链表，更新每个新结点的random指针
	for (cur = head; cur != NULL; cur = cur->next->next)
	{
		ComplexNode* cur_next = cur->next;
		cur_next->random = cur->random->next;
	}
	//3.再遍历链表，把新结点依次拆下来，组成一个新的链表
	ComplexNode* new_head = NULL;
	ComplexNode* new_tail = NULL;
	for (cur = head; cur != NULL; cur = cur->next)
	{
		ComplexNode* to_delete = cur->next;
		//将结点拆下来
		cur->next = to_delete->next;
		//将这个结点安装到新链表的末尾
		if (new_head == NULL)
		{
			new_head = new_tail = to_delete;
		}
		else
		{
			new_tail->next = to_delete;
			new_tail = new_tail->next;
		}
	}
	return new_head;
}

void LinkListDestroy(LinkNode** head)        //销毁链表
{
	if (head == NULL)
	{
		return;		//非法输入
	}
	if (*head == NULL)
	{
		return;		//空链表
	}
	LinkNode* cur = *head;
	while (cur != NULL)
	{
		LinkNode* to_delete = cur;
		LinkNode* next = cur->next;
		LinkListDestroyNode(to_delete);
		cur = next;
	}
	*head = NULL;
	return;
}
