#pragma once
#include "辅助函数.h"
typedef void* ElemType;

//值节点--多个 
typedef struct Node
{
	ElemType data;//存储队列的元素值 
	struct Node* next;//存储下一个元素节点的地址 
}DataNode;

typedef struct
{
	DataNode* front;//存储队头元素节点的地址 （队首指针） 
	DataNode* rear;//存储队尾元素节点的地址 （队尾指针）
}LinkQueue;


//链队初始化
LinkQueue* InitQueue()
{
	LinkQueue* q;
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

//销毁链队
void DestroyQueue(LinkQueue* q)
{
	int deQueue(LinkQueue * q, ElemType e);
	ElemType m;

	while (q->front != NULL || q->rear != NULL)//非空
	{
		//出队
		deQueue(q, &m);
	}
}

//判断队列是否为空
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

//入队操作
void enQueue(LinkQueue* q, ElemType e)
{
	DataNode* t;
	//1.构造一个节点t，data域存储e，next域存储NULL
	t = (DataNode*)malloc(sizeof(DataNode));
	t->data = e;
	t->next = NULL;
	//2.添加 
	if (q->front != NULL || q->rear != NULL)//非空
	{
		/*队非空*/
		q->rear->next = t;
		q->rear = t;
	}
	else
	{
		/*队空 */
		q->front = t;
		q->rear = t;
	}
}

//出队操作
int deQueue(LinkQueue* q, ElemType e)
{
	DataNode* t;

	if (q->front != NULL || q->rear != NULL)//非空
	{
		//1.让t指向队头元素节点
		t = q->front;
		//2.把队头元素存储到e中
		e = t->data;
		//3.删除队头元素节点
		if (q->front->next == NULL)//只有1个元素
		{
			/*只有1个元素*/
			q->front = NULL;
			q->rear = NULL;
		}
		else
		{
			/*多于1个元素*/
			q->front = t->next;
		}
		//4.释放t所占的存储空间
		free(t);
		return 1;
	}
	else
	{
		printf("队空，不能出队！\n");
		return 0;
	}
}

//求队列长度
int lenghtLinkQueue(LinkQueue* q)
{
	int len;
	if (QueueEmpty(q))
	{
		len = 0;
		return len;
	}
	DataNode* t;
	//1.构造一个节点t，让它指向队首元素front 
	t = (DataNode*)malloc(sizeof(DataNode));
	t = q->front;
	len = 1;
	while (t->next != NULL)
	{
		len++;
		t = t->next;
	}
	printf("队列长度为%d\n", len);

}

//输出队列
void DispQueue(LinkQueue* q)
{
	DataNode* p;
	p = q->front;
	if (QueueEmpty) { printf("队列为空！"); return; }
	else printf("队列元素为：");
	while (p != NULL)
	{
		printf("%c ", *(char*)p->data);
		p = p->next;
	}
	printf("\n");
}