#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h >
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#define ElemType void* //void*类型便于计算器的实现
//链式结构
typedef  struct StackNode
{
	ElemType  data;
    struct StackNode* next;
}StackNode, * LinkStackPtr;

//链栈初始化
StackNode *InitStack()
{
	StackNode* s;
	s = (StackNode*)malloc(sizeof(StackNode));
	s->next = NULL;
	return s;
}

//入栈操作
void Push(StackNode* s, ElemType e)
{
	StackNode* t;
	//1.构造一个节点t，存储元素值e 
	t = (StackNode*)malloc(sizeof(StackNode));
	t->data = e;
	//2.把t节点添加到头节点的后面 
	t->next = s->next;
	s->next = t;
}


//出栈操作
int Pop(StackNode* s, ElemType e)
{
	StackNode* t;
	if (s->next != NULL)//不空
	{
		//1.让t指向栈顶元素节点
		t = s->next;
		//2.把栈顶元素值存储到e中
		e = t->data;
		//3.删除
		s->next = t->next;
		//4.释放存储空间
		free(t);
		return 1;
	}
	else
	{
		printf("栈空，不能出栈！\n");
		return 0;
	}
}

//取栈顶元素
ElemType GetTop(StackNode* s, ElemType e)
{

	if (s->next != NULL)//不空
	{
		e = s->next->data;
		return e;
	}
	else
	{
		printf("栈空，不能取栈顶元素！\n");
		return NULL;
	}
}


//判断是否为空
int StackEmpty(StackNode* s)
{
	return (s->next == NULL);
}

//输出链栈
void display(StackNode* s)
{
	if (StackEmpty(s)) {
		printf("栈为空！");
		return;
	}
	while (s->next != NULL)
	{
		printf("%c ", *(char*)s->next->data);
		s = s->next;
	}
}


//销毁链栈
void DestroyStack(StackNode* s)
{
	ElemType m;
	while (s->next != NULL)//不空
	{
		//出栈
		Pop(s, &m);
	}
}
