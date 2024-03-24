#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h >
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#define ElemType void* //void*���ͱ��ڼ�������ʵ��
//��ʽ�ṹ
typedef  struct StackNode
{
	ElemType  data;
    struct StackNode* next;
}StackNode, * LinkStackPtr;

//��ջ��ʼ��
StackNode *InitStack()
{
	StackNode* s;
	s = (StackNode*)malloc(sizeof(StackNode));
	s->next = NULL;
	return s;
}

//��ջ����
void Push(StackNode* s, ElemType e)
{
	StackNode* t;
	//1.����һ���ڵ�t���洢Ԫ��ֵe 
	t = (StackNode*)malloc(sizeof(StackNode));
	t->data = e;
	//2.��t�ڵ���ӵ�ͷ�ڵ�ĺ��� 
	t->next = s->next;
	s->next = t;
}


//��ջ����
int Pop(StackNode* s, ElemType e)
{
	StackNode* t;
	if (s->next != NULL)//����
	{
		//1.��tָ��ջ��Ԫ�ؽڵ�
		t = s->next;
		//2.��ջ��Ԫ��ֵ�洢��e��
		e = t->data;
		//3.ɾ��
		s->next = t->next;
		//4.�ͷŴ洢�ռ�
		free(t);
		return 1;
	}
	else
	{
		printf("ջ�գ����ܳ�ջ��\n");
		return 0;
	}
}

//ȡջ��Ԫ��
ElemType GetTop(StackNode* s, ElemType e)
{

	if (s->next != NULL)//����
	{
		e = s->next->data;
		return e;
	}
	else
	{
		printf("ջ�գ�����ȡջ��Ԫ�أ�\n");
		return NULL;
	}
}


//�ж��Ƿ�Ϊ��
int StackEmpty(StackNode* s)
{
	return (s->next == NULL);
}

//�����ջ
void display(StackNode* s)
{
	if (StackEmpty(s)) {
		printf("ջΪ�գ�");
		return;
	}
	while (s->next != NULL)
	{
		printf("%c ", *(char*)s->next->data);
		s = s->next;
	}
}


//������ջ
void DestroyStack(StackNode* s)
{
	ElemType m;
	while (s->next != NULL)//����
	{
		//��ջ
		Pop(s, &m);
	}
}
