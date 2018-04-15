
#include "linklist.h"

#include <stdlib.h>

void LinkListInit(LinkNode** head)    //��ʼ��
{
	if (head == NULL)    //�Ƿ�����
	{
		return;
	}
	*head = NULL;
}

LinkNode* LinkListCreateNode(LinkType value)    //�������
{
	LinkNode* ptr = (LinkNode *)malloc(sizeof(LinkNode));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}

void LinkListDestroyNode(LinkNode* ptr)         //���ٽ��
{
	free(ptr);
}


void LinkListPrintChar(LinkNode* head, const char* msg)    //��ӡ����
{
	printf("[%s]:", msg);
	LinkNode* cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		printf("[%c:%p] -> ", cur->data, cur);
	}
	printf("[NULL]\n\n");
}


LinkNode* LinkListPushBack(LinkNode** head, LinkType value)   //β��
{
	if (head == NULL)    //�Ƿ�����
	{
		return NULL;
	}
	if (*head == NULL)    //������ֱ�Ӳ���ͷ�����
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

void LinkListPopBack(LinkNode** head)        //βɾ
{
	if (head == NULL)
	{
		return;        //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;     //������ʲôҲ����
	}
	LinkNode* cur = *head;
	if (cur->next == NULL)
	{
		//ֻ��һ����㣬ֱ��ɾ����ǰͷ���
		LinkListDestroyNode(cur);
		*head = NULL;
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
		{
			//�ҵ������ڶ������
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

void LinkListPushFront(LinkNode** head, LinkType value)   //ͷ��
{
	if (head == NULL)
	{
		return;    //�Ƿ�����
	}
	if (*head == NULL)    //������ֱ�Ӳ���ͷ�����
	{
		*head = LinkListCreateNode(value);
		return;
	}
	LinkNode* new_node = LinkListCreateNode(value);
	new_node->next = *head;
	*head = new_node;
	return;
}

void LinkListPopFront(LinkNode** head)     //ͷɾ
{
	if (head == NULL)
	{
		return;   //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;     //������ʲôҲ����
	}
	LinkNode* to_delete = *head;
	*head = (*head)->next;
	LinkListDestroyNode(to_delete);
}

LinkNode* LinkListFind(LinkNode* head, LinkType to_find)     //����Ԫ���������е�λ��
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

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value)       //��pos֮ǰ����Ԫ��
{
	if (head == NULL)
	{
		return;        //�Ƿ�����
	}
	if (*head == NULL)
	{
		//���ڿ�������˵��pos�����壬ֻ�ܰ����Ԫ����ΪΨһ�Ľڵ㣬����ͷ���ָ��ָ������ڵ�
		*head = LinkListCreateNode(value);
		return;
	}
	if (*head == pos)
	{
		//posָ��ͷ��㣬�޷��ҵ�pos֮ǰ��㣬�����ͷ��
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
			//�ҵ�pos��ǰһ��λ��cur������
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
	//δ�ҵ�pos��ֱ�ӷ���
	return;
}

void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value)       //��pos֮�����Ԫ��
{
	if (head == NULL)
	{
		return;     //�Ƿ�����
	}
	if (*head == NULL)
	{
		//���ڿ�������˵��pos�����壬ֻ�ܰ����Ԫ����ΪΨһ�Ľڵ㣬����ͷ���ָ��ָ������ڵ�
		*head = LinkListCreateNode(value);
		return;
	}
	if (pos == NULL)
	{
		return;    //�Ƿ�����
	}
	LinkNode* new_node = LinkListCreateNode(value);
	new_node->next = pos->next;
	pos->next = new_node;
}

void LinkListErase1(LinkNode** head, LinkNode* pos)           //ɾ��ָ��λ�õ�Ԫ��
{
	if (head == NULL || pos == NULL)
	{
		return;     //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;     //������ɾ��ʧ��
	}
	if (*head == pos)
	{
		//Ҫɾ���ĸպ���ͷ��㣬�޸�headָ�򼴿�
		LinkNode* to_delete = *head;
		*head = (*head)->next;
		LinkListDestroyNode(to_delete);
		return;
	}
	//posָ���κ�λ�ã���ʱ��Ҫ�ҵ�pos��ǰһ��λ��
	LinkNode* cur = *head;
	while (cur->next != NULL)
	{
		if (cur->next == pos)
		{
			//����ɾ������
			cur->next = pos->next;
			LinkListDestroyNode(pos);
			return;
		}
		else
		{
			cur = cur->next;
		}
	}
	return;   //pos�������ϲ�����
}

void LinkListErase2(LinkNode** head, LinkNode** pos)
{
	if (head == NULL)
	{
		return;    //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;    //������ɾ��ʧ��
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

void LinkListRemove1(LinkNode** head, LinkType value)          //ɾ��ָ��ֵ��Ԫ��
{
	if (head == NULL)
	{
		return;    //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;       //������ɾ��ʧ��
	}
	LinkNode* pos = LinkListFind(*head, value);
	LinkListErase1(head, pos);
}

void LinkListRemove2(LinkNode** head, LinkType value)
{
	if (head == NULL)
	{
		return;      //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;       //������ɾ��ʧ��
	}
	if ((*head)->data == value)      //Ҫɾ������ͷ���
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
	//Ҫɾ����Ԫ�ز����ڣ�ֱ�ӷ���
	return;     
}

void LinkListRemoveAll(LinkNode** head, LinkType value)          //ɾ��ָ��ֵ������Ԫ��
{
	if (head == NULL)
	{
		return;    //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;     //������ɾ��ʧ��
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

int LinkListEmpty(LinkNode* head)          //�ж������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
{
	return head == NULL ? 1 : 0;
}

size_t LinkListSize(LinkNode* head)        //������Ԫ�ظ���
{
	if (head == NULL)
	{
		return 0;    //������
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

//����������

void LinkListReversePrint(LinkNode* head)      //�����ӡ������
{
	if (head == NULL)
	{
		return;
	}
	LinkListReversePrint(head->next);
	printf("[%c:%p] ", head->data, head);
}

void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value)   //�������������, �� pos֮ǰ����
{
	if (head == NULL || pos == NULL)
	{
		return;     //�Ƿ�����
	}
	LinkNode* new_node = LinkListCreateNode(pos->data);
	pos->data = value;
	new_node->next = pos->next;
	pos->next = new_node;
	return;
}

LinkNode* JosephCycle(LinkNode* head, size_t food)     //Լɪ��
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
		printf("food��[%c]\n", cur->data);
		cur->data = cur->next->data;
		LinkNode* to_delete = cur->next;
		cur->next = to_delete->next;
		LinkListDestroyNode(to_delete);
	}
	return cur;
}

void LinkListReverse(LinkNode** head)     //����������
{
	if (head == NULL)
	{
		return;   //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;		//������
	}
	if ((*head)->next == NULL)
	{
		return;		//ֻ��һ��Ԫ��
	}
	LinkNode* cur = *head;
	while (cur->next != NULL)
	{
		LinkNode* to_delete = cur->next;
		//����ǰ���ɾ��
		cur->next = to_delete->next;
		//�������ɾ���Ľ����뵽����ͷ��
		to_delete->next = *head;
		*head = to_delete;
	}
	return;
}

void LinkListReverse2(LinkNode** head)
{
	if (head == NULL)
	{
		return;   //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;		//������
	}
	if ((*head)->next == NULL)
	{
		return;		//ֻ��һ��Ԫ��
	}
	LinkNode* pre = *head;
	LinkNode* cur = (*head)->next;
	pre->next = NULL;
	while (cur != NULL)
	{
		LinkNode* next = cur->next;
		cur->next = pre;        //�����˵�ǰ����next
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
void LinkListBubbleSort(LinkNode* head)     //�������ð������(����)
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

LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2)     //��������������, �ϲ���һ����������
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

LinkNode* FindMidNode(LinkNode* head)      //�ҵ��м�ڵ�
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

LinkNode* FindLastKNode(LinkNode* head, size_t K)       //�ҵ������� K ���ڵ�
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
		//���������ʾ������С��K��ֱ�ӷ���NULL
		return NULL;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void EraseLastKNode(LinkNode** head, size_t K)      //ɾ��������K���ڵ�
{
	if (head == NULL)
	{
		return;   //�Ƿ�����
	}
	if (*head == NULL)
	{
		return;		//������
	}
	size_t size = LinkListSize(*head);
	if (size < K)
	{
		//Ҫɾ���Ľ�㲻����
		return;
	}
	if (size == K)
	{
		//Ҫɾ������ͷ���
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

LinkNode* HasCycle(LinkNode* head)      //�ж��������Ƿ����. �����������1
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

size_t GetCycleLen(LinkNode* head)       //����������, ������ĳ���
{
	LinkNode* meet_node = HasCycle(head);
	if (meet_node == NULL)
	{
		return 0;    //�����޻�
	}
	size_t count = 1;
	LinkNode* cur = meet_node;
	for (; cur->next != meet_node; cur = cur->next)
	{
		++count;
	}
	return count;
}

LinkNode* GetCycleEntry(LinkNode* head)       //����������, ����������
{
	LinkNode* meet_node = HasCycle(head);
	if (meet_node == NULL)
	{
		return NULL;		//�޻���ֱ�ӷ���
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

LinkNode* HasCross(LinkNode* head1, LinkNode* head2)       //�ж����������Ƿ��ཻ, ���������
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

int HasCrossWithCycle(LinkNode* head1, LinkNode* head2)       //�ж����������Ƿ��ཻ(����������ܴ���)
{
	if (head1 == NULL || head2 == NULL)
	{
		return 0;
	}
	LinkNode* entry1 = GetCycleEntry(head1);
	LinkNode* entry2 = GetCycleEntry(head2);
	if (entry1 == NULL && entry2 == NULL)
	{
		//1.��������������
		return HasCross(head1, head2) != NULL ? 1 : 0;
	}
	else if (entry1 != NULL && entry2 != NULL)
	{
		//2.����������
		if (entry1 == entry2)
		{
			//�ཻ�ڻ���
			return 1;
		}
		LinkNode* cur = entry1;
		while (cur->next != entry1)
		{
			//�ཻ�ڻ���
			if (cur == entry2)
			{
				return 1;
			}
			cur = cur->next;
		}
		return 0;	//���ཻ
	}
	else
	{
		//3.һ��������һ����������һ�����ཻ
		return 0;
	}
	return 0;
}

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2)			//��������������������ͬ������
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
			//cur1��ֵ��cur2��ֵ��ȣ������Ԫ�طŵ������ȥ
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
ComplexNode* CopyComplex(ComplexNode* head)          //������������
{
	if (head == NULL)
	{
		return NULL;		//������
	}
	//1.�Ȱ�������м򵥸���
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
	//2.��ȥ������ÿ��randomָ�����ͷ����ƫ����
	ComplexNode* new_cur = new_head;
	for (cur = head; cur != NULL && new_cur != NULL; cur = cur->next, new_cur = new_cur->next)
	{
		if (cur->random == NULL)
		{
			new_cur->random = NULL;
			continue;
		}
		//3.����ƫ�������޸�ÿ�����������randomָ��
		size_t offset = Diff(head, cur->random);
		new_cur->random = Step(head, offset);
	}
	return new_head;
}

ComplexNode* CopyComplex2(ComplexNode* head)          //������������
{
	//1.������������ÿһ����㶼����һ����Ӧ���½��
	//   �����½����뵽�ɽ��֮��
	ComplexNode* cur = head;
	for (; cur != NULL; cur = cur->next->next)
	{
		ComplexNode* new_node = CreateComplexNode(cur->data);
		new_node->next = cur->next;
		cur->next = new_node;
	}
	//2.�ٱ�����������ÿ���½���randomָ��
	for (cur = head; cur != NULL; cur = cur->next->next)
	{
		ComplexNode* cur_next = cur->next;
		cur_next->random = cur->random->next;
	}
	//3.�ٱ����������½�����β����������һ���µ�����
	ComplexNode* new_head = NULL;
	ComplexNode* new_tail = NULL;
	for (cur = head; cur != NULL; cur = cur->next)
	{
		ComplexNode* to_delete = cur->next;
		//����������
		cur->next = to_delete->next;
		//�������㰲װ���������ĩβ
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

void LinkListDestroy(LinkNode** head)        //��������
{
	if (head == NULL)
	{
		return;		//�Ƿ�����
	}
	if (*head == NULL)
	{
		return;		//������
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
