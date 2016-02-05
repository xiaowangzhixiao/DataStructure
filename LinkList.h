#pragma once

typedef struct 	//可根据情况设计数据
{
	int a;
}ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode;

typedef struct
{
	int length;
	LNode *next;
	LNode *last;
}LHead, *LinkList;

Status InitList_L(LinkList L);//构造一个空的线性表

Status DestroyList_L(LinkList L);//销毁线性表

Status ClearList_L(LinkList L);//清空线性表

Status ListEmpty_L(LinkList L);//检查是否为空表

Status ListLength_L(LinkList L);//返回线性表的长度

Status GetElem_L(LinkList L, int i, ElemType &e);//取到第i个元素

Status LocateElem_L(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));//返回L中第一个与e满足关系compare()的数据元素的位序。若不存在，返回0;

Status PriorElem_L(LinkList L, ElemType cur_e, ElemType &pre_e);//返回cur_c的前驱

Status NextElem_L(LinkList L, ElemType cur_e, ElemType &next_e);//返回cur_c的的后驱

Status ListInsert_L(LinkList L, int i, ElemType e);//在第i个元素之前插入e

Status ListDelete_L(LinkList L, int i, ElemType &e);//删除相应位置的元素

Status ListTraverse_L(LinkList L, Status (*visit)(ElemType));//依次对L的每个元素调用函数visit，一旦visit失败操作失败结束函数

Status ListAdd_L(LinkList L, ElemType e);//在尾部增加e

