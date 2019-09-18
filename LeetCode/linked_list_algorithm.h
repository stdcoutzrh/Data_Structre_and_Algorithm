#include<stdio.h>
#include<stdlib.h>

/******************测试用**********************/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* init_n(int n)
{
	ListNode*head = NULL;
	ListNode* current = head;
	int x;
	while (n-- > 0)
	{
		scanf("%d", &x);
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->val = x;
		p->next = NULL;

		if (head == NULL)
		{
			head = p;
			current = p;
		}
		else
		{
			current->next = p;
			current = p;
		}

	}
	return head;
}

void print(struct ListNode*head)
{
	if (head == NULL)
		printf("qqq");
	ListNode* current = head;
	while (current != NULL)
	{
		printf("%d ", current->val);
		current = current->next;
	}
}

/*********************************************/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


//160.相交链表
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode*p = headA;
	struct ListNode*q = headB;

	int lena = 0;
	int lenb = 0;
	while (p != NULL)
	{
		++lena;
		p = p->next;
	}
	while (q != NULL)
	{
		++lenb;
		q = q->next;
	}

	int delta = lena >= lenb ? lena - lenb : lenb - lena;
	p = headA;
	q = headB;

	if (lena >= lenb)
	{
		for (int i = 0; i < delta; ++i)
		{
			p = p->next;
		}
	}
	else
	{
		for (int i = 0; i < delta; ++i)
		{
			q = q->next;
		}
	}

	while (q != NULL&&p != NULL)
	{
		if ((q->val == p->val) && (p == q))
			return q;
		q = q->next;
		p = p->next;
	}
	return NULL;
}

//206.翻转链表
struct ListNode* reverseList(struct ListNode* head){
	//如果只有0个或1个节点，直接返回head
	if (head == NULL || head->next == NULL)
		return head;

	//如果只有2个或者3个，直接翻转
	if (head->next->next == NULL)
	{
		struct ListNode*pp = head->next;
		pp->next = head;
		head->next = NULL;
		head = pp;
		return head;
	}
	if (head->next->next->next == NULL)
	{
		struct ListNode*pp = head->next;
		struct ListNode*qq = head->next->next;
		pp->next = head;
		qq->next = pp;
		head->next = NULL;
		head = qq;
		return head;
	}

	//大于3个迭代翻转
	struct ListNode*p;
	struct ListNode*q;
	struct ListNode*r;
	p = head;
	q = p->next;
	r = q->next;

	while (r->next != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	r->next = q;
	head->next = NULL;
	head = r;

	return head;
}

