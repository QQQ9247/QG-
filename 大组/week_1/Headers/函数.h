#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h >
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#define LEN sizeof(struct node)
#define LEN2 sizeof(struct DuLNode)

int sel = 1;
char MenuText[14][100] = {//菜单
		"[A]  在单链表的尾部添加结点",
		"[B]  删除单链表的某一结点",
		"[C]  查找单链表某一结点的data",
		"[D]  修改单链表某一结点的data",
		"[E]  给双向链表添加结点",
		"[F]  删除双向表的某一结点",
		"[G]  查找双向链表某一节点的data",
		"[H]  修改双向链表某一节点的data",
		"[I]  单链表奇偶调换",
		"[J]  找到单链表的中点",
		"[K]  判断链表是否成环",
		"[L]  反转链表(递归)",
		"[M]  反转链表(非递归)",
		"[Q]  Exit",
};



struct node {//单链表
	int data;
	struct node* next;
};
struct DuLNode {//双向链表
	int data;
	struct DuLNode* next;
	struct DuLNode* pre;
};
//单链表函数功能
struct node* AddNewNode(struct node* head, struct node* newNode)//单链表
{
	struct node* p = head;
	if (head == NULL) {
		head = newNode;
		newNode->next = NULL;
		return head;
	}
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
	newNode->next = NULL;
	return head;
}
struct node* DeleteNode(struct node* head, int thenum)
{
	struct  node* p1, * p2;
	if (head == NULL) { printf("\n  list  null ! \n"); return NULL; }
	p1 = head; p2 = p1;
	int j = 1;
	while (thenum != j && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		j++;
	}
	if (j == thenum)
	{
		if (p1 == head)
			head = p1->next;  //就在链表头
		else
			p2->next = p1->next;    //就在链表中, 表尾
		free(p1);
	}
	else {
		printf("未找到第%d节点!\n", thenum);
		system("pause");
	}
	return(head);
}
void PrintNode(struct  node* head)
{
	struct  node* p = head;
	int n = 0;
	system("cls");
	if (head == NULL) {
		printf("\n List is NULL\n");
		return;
	}
	printf("当前单链表为：");
	do {
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}
struct node* AddNewNodeFromKeyboard(struct node* head)
{
	struct node* p;
	p = (struct node*)malloc(LEN);
	while (1)
	{
		p = (struct node*)malloc(LEN);
		printf("input new datas (input 0 to end):\n");
		scanf_s("%d", &p->data);
		if (p->data == 0) {
			free(p);
			break;
		}
		head = AddNewNode(head, p);
	}
	return (head);
}
void search(struct  node* head, int thenum)
{
	struct  node* p = head;
	int n = 0;
	system("cls");
	if (head == NULL) {
		printf("\n List is NULL\n");
		return;
	}
	int j = 1;
	do {
		if (j == thenum) printf("%d\n", p->data);
		p = p->next;
		++j;
	} while (p != NULL);
}
struct node* modify(struct  node* head, int thenum, int data)
{
	struct  node* p = head;
	int n = 0;
	system("cls");
	if (head == NULL) {
		printf("\n List is NULL\n");
		return NULL;
	}
	int j = 1;
	do {
		if (j == thenum) { p->data = data; return head; }
		p = p->next;
		++j;
	} while (p != NULL);
}

//双链表函数功能
struct DuLNode* AddNewNode_D(struct DuLNode* head, struct DuLNode* newNode)//双向链表
{
	struct DuLNode* p = head;
	if (head == NULL) {
		head = newNode;
		newNode->next = NULL;
		return head;
	}
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
	newNode->pre = p;
	newNode->next = NULL;
	return head;
}
struct DuLNode* AddNewNodeFromKeyboard_D(struct DuLNode* head)
{
	struct DuLNode* p;
	p = (struct DuLNode*)malloc(LEN2);
	while (1)
	{
		p = (struct DuLNode*)malloc(LEN2);
		printf("input new datas (input 0 to end):\n");
		scanf_s("%d", &p->data);
		if (p->data == 0) {
			free(p);
			break;
		}
		head = AddNewNode_D(head, p);
	}
	return (head);
}
void PrintNode_D(struct  DuLNode* head)
{
	struct  DuLNode* p = head;
	int n = 0;
	system("cls");
	if (head == NULL) {
		printf("\n List is NULL\n");
		return;
	}
	printf("当前双向链表为：");
	do {
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}
struct DuLNode* DeleteNode_D(struct DuLNode* head, int thenum)
{
	struct  DuLNode* p1, * p2;
	if (head == NULL) { printf("\n  list  null ! \n"); return NULL; }
	p1 = head; p2 = p1;
	int j = 1;
	while (thenum != j && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		j++;
	}
	if (j == thenum)
	{
		if (p1 == head)
			head = p1->next;  //就在链表头
		else
		{
			p1->pre->next = p1->next;
			p1->next->pre = p1->pre;
			//p2->next = p1->next;
		}   //就在链表中、表尾
		free(p1);
	}
	else {
		printf("未找到第%d节点!\n", thenum);
		system("pause");
	}
	return(head);
}
void search_D(struct  DuLNode* head, int thenum)
{
	struct  DuLNode* p = head;
	int n = 0;
	system("cls");
	if (head == NULL) {
		printf("\n List is NULL\n");
		return;
	}
	int j = 1;
	do {
		if (j == thenum) printf("%d\n", p->data);
		p = p->next;
		++j;
	} while (p != NULL);
}
struct DuLNode* modify_D(struct  DuLNode* head, int thenum, int data)
{
	struct  DuLNode* p = head;
	int n = 0;
	system("cls");
	if (head == NULL) {
		printf("\n List is NULL\n");
		return NULL;
	}
	int j = 1;
	do {
		if (j == thenum) { p->data = data; return head; }
		p = p->next;
		++j;
	} while (p != NULL);
}

//选做功能函数
struct node* change(struct node* head)
{
	//先交换头结点
	struct node* p1 = head, * p2, * p;
	p2 = head->next;
	head = p2;
	p1->next = p2->next;
	p2->next = p1;

	p = p1;//标记

	while (p1->next != NULL && p1->next->next != NULL) {
		p1 = p->next;
		p2 = p1->next;

		p->next = p2;
		p1->next = p2->next;
		p2->next = p1;
		p = p1;
	}
	return head;
}
int findmiddle(struct node* head)
{
	struct node* fast = head;
	struct node* slow = head;
	while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}
int is_circle(struct node* head)
{
	struct node* fast = head;
	struct node* slow = head;
	while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return 1;
	}
	return 0;
}
struct node* reverse1(struct node* pre, struct node* cur) {//递归
	if (cur == NULL)
		return pre;
	struct node* t = cur->next;
	cur->next = pre;
	return reverse1(cur, t);
}
struct node* reverse2(struct node* head)//非递归
{
	struct node* pre = NULL;
	struct node* cur = head;
	while (cur != NULL)
	{
		struct node* t = cur->next;
		cur->next = pre;
		pre = cur;
		cur = t;
	}
	return pre;
}



//辅助函数
void ColorChoose(int color)   //颜色选择函数
{
	switch (color)
	{
	case 1:               //天蓝色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 2:               //绿色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case 3:               //黄色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 4:               //红色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 5:               //紫色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 6:               //白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	case 7:               //深蓝色(∵颜色深难与黑色背景辨识度不高 ∴坦克颜色不选用此颜色),只用在字体颜色闪烁中
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	}
}
void GoToxy(int x, int y)  //光标移动函数，X表示横坐标，Y表示纵坐标。
{
	COORD  coord;         //使用头文件自带的坐标结构
	coord.X = x;            //这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
	coord.Y = y;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);  //获得标准输出句柄
	SetConsoleCursorPosition(a, coord);         //以标准输出的句柄为参数设置控制台光标坐标
}
void displaymenu(int hilight)
{
	system("mode con cols=112 lines=42");
	int j = 6;
	GoToxy(36, j);
	ColorChoose(2);
	int i;
	printf("==================================\n");
	for (i = 0; i < 14; i++) {
		GoToxy(36, ++j);
		if (i == hilight - 1)
			printf("<<%s>>\n", MenuText[i]);
		else
			printf("  %s\n", MenuText[i]);
	}
	GoToxy(36, ++j);
	printf("==================================\n");
}
void clear() {
	printf("\n按回车确认!");
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
	getchar();
	displaymenu(sel);
}
