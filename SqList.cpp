#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "SqList.h"

Status InitList_Sq(SqList &L){
	//构造一个空的线性表
	L.elem = (ElemType * )malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (L.elem == NULL)
	{
		exit(OVERFLOW);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList_Sq(SqList &L){
	//销毁线性表
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

Status ClearList_Sq(SqList &L){
	//清空线性表
	memset(L.elem, 0 ,sizeof(L.elem));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListEmpty_Sq(SqList L){
	//检查是否为空表
	if (L.length == 0)
	{
		return TRUE;
	}else{
		return FALSE;
	}
}

Status ListLength_Sq(SqList L){
	//返回线性表的长度
	return L.length;
}

Status GetElem_Sq(SqList L, int i, ElemType &e){
	//取到第i个元素
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i-1];
	return OK;
}

Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)){
	//返回L中第一个与e满足关系compare()的数据元素的位序。若不存在，返回0;
	for (int i = 0; i < L.length; ++i)
	{
		if((*compare)(L.elem[i], e)){
			return i + 1;
		}
	}

	return 0;
}

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e){
	//返回cur_c的前驱

	for (int i = 0; i < L.length; ++i)
	{
		if (L.elem[i] == cur_e && i != 0)
		{
			pre_e = L.elem[i-1];
			return OK;
		}
	}

	return ERROR;
}

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e){
	//返回cur_c的的后驱
	for (int i = 0; i < L.length; ++i)
	{
		if (L.elem[i] == cur_e && i != L.length-1)
		{
			next_e = L.elem[i+1];
			return OK;
		}
	}

	return ERROR;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e){
	//在第i个元素之前插入e
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	if (L.length >= L.listsize)
	{
		//增加存储空间
		ElemType *newbase = (ElemType *)realloc(L.elem, 
					(L.listsize + LISTINCRETMENT) * sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCRETMENT;
	}

	ElemType *p = &(L.elem[i-1]);
	for (ElemType *q = &(L.elem[L.length-1]); q >= p; --q)
	{
		*(q+1) = *q;
	}
	*p = e;
	L.length++;
	return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	//删除相应位置的元素
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	e = L.elem[i-1];
	for (int j = i-1; j < L.length-1; ++j)
	{
		L.elem[j] = L.elem[j+1];
	}
	L.length--;

	return OK;
}

Status ListTraverse_Sq(SqList L, Status (*visit)(ElemType)){
	//依次对L的每个元素调用函数visit，一旦visit失败操作失败结束函数
	for (int i = 0; i < L.length; ++i)
	{
		if(!(*visit)(L.elem[i]))
			return ERROR;
	}
	return Ok;
}


Status ListAdd_Sq(SqList &L, ElemType e){
	//在尾部增加e
	if(!ListInsert_Sq(L, L.length+1, e))
		return ERROR;
	return Ok;
}
