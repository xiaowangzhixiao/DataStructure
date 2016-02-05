/*
*	带头结点的单向链式存储线性表
*/
#include <stdio.h>
#include <stdlib.h>

#include "LinkList.h"
#include "define.h"

Status InitList_L(LinkList L){
	//构造空的线性表
	L = (LinkList)malloc(sizeof(LHead));
	L->length = 0;
	L->last = NULL;
	L->next = NULL;
}

Status ClearList_L(LinkList L){
	//将线性表置空
	LNode *p;
	while(L->next != NULL){
		p = L->next;
		L->next = p->next;
		free(p);
	}

	L->length = 0;
	L->last = NULL;
	return OK;
}

Status DestroyList_L(LinkList L){
	//销毁线性表
	ClearList_L(L);
	free(L);
	return OK;
}

Status ListEmpty_L(LinkList L){
	//检查是否为空表
	if (L == NULL)
	{
		return INFEASIBLE;
	}else if(L->length == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

Status ListLength_L(LinkList L){
	//返回线性表的长度
	if (L == NULL)
	{
		return INFEASIBLE;
	}

	return L->length;
}

Status GetElem_L(LinkList L, int i, Elemtype &e){
	//取到第i个元素
	if (i < 1 || i > L->length)
	{
		return ERROR;
	}

	LNode *p = L->next;
	int n = 1;

	while(n < i && p != NULL){
		p = p->next;
		n++;
	}

	if (p == NULL)
	{
		return FALSE;
	}

	return p->data;
}

Status Locate_L(LinkList L, Elemtype e, Status (*compare)(Elemtype, Elemtype)){
	//返回L中第一个与e满足关系compare()的数据元素的位序。若不存在，返回0;
	LNode *p = L->next;
	int n = 0;
	while(p != NULL){
		n++;
		if ((*compare)(p->data, e))
		{
			return n;
		}
		p = p->next;
	}

	return 0;	
}

Status PriorElem_L(LinkList L, Elemtype cur_e, Elemtype &pre_e){
	//返回cur_e的前驱
	LNode *p = L->next;
	LNode *q = NULL;

	while(p != NULL){
		if (p->data == cur_e)
		{
			if(q == NULL)
				return ERROR;
			pre_e = q->data;
			return OK;
		}
		q = p;
		p = p->next;
	}

	return ERROR;
}

Status NextElem_L(LinkList L, Elemtype cur_e, Elemtype &next_e){
	//返回cur_e的后驱
	LNode *p = L->next;
	LNode *q = p->next;

	while(q != NULL){
		if (p->data == cur_e)
		{
			next_e = q->data;
			return OK;
		}
		p = q;
		q = q->next;
	}

	return ERROR;
}

Status ListInsert_L(LinkList L, int i, Elemtype e){
	//在第i个元素之前插入e
	if (i < 1 || i > L->length+1)return ERROR;
	LNode *ptr;
	if(i == 1)
	{
		ptr = (LNode *)malloc(sizeof(LNode));
		ptr->next = L->next;
		ptr->data = e;
		L->next = ptr;
		return OK;
	}

	LNode *p = L->next;
	int n = 1;

	while(n <= L->length+1){
		n++;
		if (n == i)
		{
			ptr = (LNode *)malloc(sizeof(LNode));
			ptr->next = p->next;
			p->next = ptr;
			ptr->data = e;
			return OK;
		}
	}
}

Status ListDelet_L(LinkList L, int i, Elemtype &e){
	//删除相应位置的元素
	LNode *ptr;
	if (i < 1 || i > L->length)
		return ERROR;
	if (i == 1)
	{
		ptr = L->next;
		L->next = ptr->next;
		e = ptr->data;
		free(ptr);
		return OK;
	}

	int n = 1;
	LNode *q = L->next;
	LNode *p = q->next;

	while(p != NULL){
		n++;
		if (n == i)
		{
			q->next = p->next;
			e = p->data;
			free(p);
			return OK;
		}
		q = p;
		p = p->next;
	}

	return ERROR;
}

Status ListTraverse_L(LinkList L, Status (*visit)(Elemtype)){
	//依次对L的每个元素调用函数visit，一旦visit失败操作失败结束函数
	LNode *p = L->next;

	while(p != NULL){
		if (!(*visit)(p->data))
			return ERROR;
		p = p->next;
	}

	return OK;
}

Status ListAdd_L(LinkList L, Elemtype e){
	//在尾部增加e
	LNode *p;
	p = (LNode *)malloc(sizeof(LNode));

	L->last->next = p;
	p->data = e;
	p->next = NULL;
	L->last = p;
	L->length++;

	return OK;
}
