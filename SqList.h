#pragma once
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCRETMENT 10   //线性表存储空间的分配增量

typedef struct 	//可根据情况设计数据
{
	int a;
}ElemType;

typedef struct 
{
	ElemType *elem;		//存储空间基址
	int length;			//当前长度
	int listsize;		//当前分配的存储容量（以sizeof（ElemType）为单位）
}SqList;

Status InitList_Sq(SqList &L);//构造一个空的线性表

Status DestroyList_Sq(SqList &L);//销毁线性表

Status ClearList_Sq(SqList &L);//清空线性表

Status ListEmpty_Sq(SqList L);//检查是否为空表

Status ListLength_Sq(SqList L);//返回线性表的长度

Status GetElem_Sq(SqList L, int i, ElemType &e);//取到第i个元素

Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));//返回L中第一个与e满足关系compare()的数据元素的位序。若不存在，返回0;

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e);//返回cur_c的前驱

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e);//返回cur_c的的后驱

Status ListInsert_Sq(SqList &L, int i, ElemType e);//在第i个元素之前插入e

Status ListDelete_Sq(SqList &L, int i, ElemType &e);//删除相应位置的元素

Status ListTraverse_Sq(SqList L, Status (*visit)(ElemType));//依次对L的每个元素调用函数visit，一旦visit失败操作失败结束函数

Status ListAdd_Sq(SqList &L, ElemType e);//在尾部增加e
