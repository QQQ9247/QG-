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
char MenuText[14][100] = {//�˵�
		"[A]  �ڵ������β����ӽ��",
		"[B]  ɾ���������ĳһ���",
		"[C]  ���ҵ�����ĳһ����data",
		"[D]  �޸ĵ�����ĳһ����data",
		"[E]  ��˫��������ӽ��",
		"[F]  ɾ��˫����ĳһ���",
		"[G]  ����˫������ĳһ�ڵ��data",
		"[H]  �޸�˫������ĳһ�ڵ��data",
		"[I]  ��������ż����",
		"[J]  �ҵ���������е�",
		"[K]  �ж������Ƿ�ɻ�",
		"[L]  ��ת����(�ݹ�)",
		"[M]  ��ת����(�ǵݹ�)",
		"[Q]  Exit",
};



struct node {//������
	int data;
	struct node* next;
};
struct DuLNode {//˫������
	int data;
	struct DuLNode* next;
	struct DuLNode* pre;
};
//������������
struct node* AddNewNode(struct node* head, struct node* newNode)//������
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
			head = p1->next;  //��������ͷ
		else
			p2->next = p1->next;    //����������, ��β
		free(p1);
	}
	else {
		printf("δ�ҵ���%d�ڵ�!\n", thenum);
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
	printf("��ǰ������Ϊ��");
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

//˫����������
struct DuLNode* AddNewNode_D(struct DuLNode* head, struct DuLNode* newNode)//˫������
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
	printf("��ǰ˫������Ϊ��");
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
			head = p1->next;  //��������ͷ
		else
		{
			p1->pre->next = p1->next;
			p1->next->pre = p1->pre;
			//p2->next = p1->next;
		}   //���������С���β
		free(p1);
	}
	else {
		printf("δ�ҵ���%d�ڵ�!\n", thenum);
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

//ѡ�����ܺ���
struct node* change(struct node* head)
{
	//�Ƚ���ͷ���
	struct node* p1 = head, * p2, * p;
	p2 = head->next;
	head = p2;
	p1->next = p2->next;
	p2->next = p1;

	p = p1;//���

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
struct node* reverse1(struct node* pre, struct node* cur) {//�ݹ�
	if (cur == NULL)
		return pre;
	struct node* t = cur->next;
	cur->next = pre;
	return reverse1(cur, t);
}
struct node* reverse2(struct node* head)//�ǵݹ�
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



//��������
void ColorChoose(int color)   //��ɫѡ����
{
	switch (color)
	{
	case 1:               //����ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case 2:               //��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case 3:               //��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 4:               //��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 5:               //��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 6:               //��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	case 7:               //����ɫ(����ɫ�������ɫ������ʶ�Ȳ��� ��̹����ɫ��ѡ�ô���ɫ),ֻ����������ɫ��˸��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	}
}
void GoToxy(int x, int y)  //����ƶ�������X��ʾ�����꣬Y��ʾ�����ꡣ
{
	COORD  coord;         //ʹ��ͷ�ļ��Դ�������ṹ
	coord.X = x;            //���ｫint����ֵ����short,�����������漰������ֵ�����ᳬ��short��Χ
	coord.Y = y;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);  //��ñ�׼������
	SetConsoleCursorPosition(a, coord);         //�Ա�׼����ľ��Ϊ�������ÿ���̨�������
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
	printf("\n���س�ȷ��!");
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
	getchar();
	displaymenu(sel);
}
