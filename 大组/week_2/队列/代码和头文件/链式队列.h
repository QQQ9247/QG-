#pragma once
#include "��������.h"
typedef void* ElemType;

//ֵ�ڵ�--��� 
typedef struct Node
{
	ElemType data;//�洢���е�Ԫ��ֵ 
	struct Node* next;//�洢��һ��Ԫ�ؽڵ�ĵ�ַ 
}DataNode;

typedef struct
{
	DataNode* front;//�洢��ͷԪ�ؽڵ�ĵ�ַ ������ָ�룩 
	DataNode* rear;//�洢��βԪ�ؽڵ�ĵ�ַ ����βָ�룩
}LinkQueue;


//���ӳ�ʼ��
LinkQueue* InitQueue()
{
	LinkQueue* q;
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

//��������
void DestroyQueue(LinkQueue* q)
{
	int deQueue(LinkQueue * q, ElemType e);
	ElemType m;

	while (q->front != NULL || q->rear != NULL)//�ǿ�
	{
		//����
		deQueue(q, &m);
	}
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(LinkQueue* q)
{
	if (q->front == NULL && q->rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//��Ӳ���
void enQueue(LinkQueue* q, ElemType e)
{
	DataNode* t;
	//1.����һ���ڵ�t��data��洢e��next��洢NULL
	t = (DataNode*)malloc(sizeof(DataNode));
	t->data = e;
	t->next = NULL;
	//2.��� 
	if (q->front != NULL || q->rear != NULL)//�ǿ�
	{
		/*�ӷǿ�*/
		q->rear->next = t;
		q->rear = t;
	}
	else
	{
		/*�ӿ� */
		q->front = t;
		q->rear = t;
	}
}

//���Ӳ���
int deQueue(LinkQueue* q, ElemType e)
{
	DataNode* t;

	if (q->front != NULL || q->rear != NULL)//�ǿ�
	{
		//1.��tָ���ͷԪ�ؽڵ�
		t = q->front;
		//2.�Ѷ�ͷԪ�ش洢��e��
		e = t->data;
		//3.ɾ����ͷԪ�ؽڵ�
		if (q->front->next == NULL)//ֻ��1��Ԫ��
		{
			/*ֻ��1��Ԫ��*/
			q->front = NULL;
			q->rear = NULL;
		}
		else
		{
			/*����1��Ԫ��*/
			q->front = t->next;
		}
		//4.�ͷ�t��ռ�Ĵ洢�ռ�
		free(t);
		return 1;
	}
	else
	{
		printf("�ӿգ����ܳ��ӣ�\n");
		return 0;
	}
}

//����г���
int lenghtLinkQueue(LinkQueue* q)
{
	int len;
	if (QueueEmpty(q))
	{
		len = 0;
		return len;
	}
	DataNode* t;
	//1.����һ���ڵ�t������ָ�����Ԫ��front 
	t = (DataNode*)malloc(sizeof(DataNode));
	t = q->front;
	len = 1;
	while (t->next != NULL)
	{
		len++;
		t = t->next;
	}
	printf("���г���Ϊ%d\n", len);

}

//�������
void DispQueue(LinkQueue* q)
{
	DataNode* p;
	p = q->front;
	if (QueueEmpty) { printf("����Ϊ�գ�"); return; }
	else printf("����Ԫ��Ϊ��");
	while (p != NULL)
	{
		printf("%c ", *(char*)p->data);
		p = p->next;
	}
	printf("\n");
}