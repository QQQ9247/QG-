#define _CRT_SECURE_NO_WARNINGS
#include "����.h"
int main() {
	struct node* nodehead = NULL;
	struct DuLNode* Dnodehead = NULL;
	char c = ' ';
	int i, e;
	displaymenu(sel);
	for (;;) {
		if (_kbhit) {
			if (GetAsyncKeyState(VK_UP)) {
				sel = (sel > 1) ? sel - 1 : sel;
				displaymenu(sel);
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				sel = (sel < 14) ? sel + 1 : sel;
				displaymenu(sel);
			}
			c = _getch();
			if (c <= 'z' && c >= 'a') c = c - ('a' - 'A');
			if (c <= 'C' && c >= 'A') {
				sel = c - 'A' + 1;
				displaymenu(sel);
				GoToxy(36, 22);
				printf("command is [%c] ���س�ȷ��!", c);
			}
			else if (c == '\r') {
				if (sel == 14) return 0;
				displaymenu(sel);
				printf("command is [%c]\n", 'A' + sel - 1);
				switch (sel)
				{
				case 1:
					system("cls");
					nodehead = AddNewNodeFromKeyboard(nodehead);
					PrintNode(nodehead);
					clear();
					break;
				case 2:
					system("cls");
					printf("������ɾ���ڵ����ţ�");
					scanf("%d", &i);
					nodehead=DeleteNode(nodehead, i);
					PrintNode(nodehead);
					clear();
					break;
				case 3:
					system("cls");
					printf("��������ҽڵ����ţ�");
					scanf("%d", &i);
					search(nodehead, i);
					clear();
					break;
				case 4:
					system("cls");
					printf("�������޸Ľڵ����ţ�");
					scanf("%d", &i);
					printf("�������޸ĵ�ֵ��");
					scanf("%d", &e);
					nodehead = modify(nodehead, i, e);
					PrintNode(nodehead);
					clear();
					break;
				case 5:
					system("cls");
					Dnodehead = AddNewNodeFromKeyboard_D(Dnodehead);
					PrintNode_D(Dnodehead);
					clear();
					break;
				case 6:
					system("cls");
					printf("������ɾ���ڵ����ţ�");
					scanf("%d", &i);
					Dnodehead = DeleteNode_D(Dnodehead, i);
					PrintNode_D(Dnodehead);
					clear();
					break;
				case 7:
					system("cls");
					printf("��������ҽڵ����ţ�");
					scanf("%d", &i);
					search_D(Dnodehead, i);
					clear();
					break;
				case 8:
					system("cls");
					printf("�������޸Ľڵ����ţ�");
					scanf("%d", &i);
					printf("�������޸ĵ�ֵ��");
					scanf("%d", &e);
					Dnodehead = modify_D(Dnodehead, i, e);
					PrintNode_D(Dnodehead);
					clear();
					break;
				case 9:
					system("cls");
					nodehead=change(nodehead);
					PrintNode(nodehead);
					clear();
					break;
				case 10:
					system("cls");
					printf("�м�ڵ��ֵΪ��%d", findmiddle(nodehead));
					clear();
					break;
				case 11:
					system("cls");
					is_circle(nodehead) ? printf("��") : printf("��");
					clear();
					break;
				case 12:
					system("cls");
					nodehead=reverse1(NULL, nodehead);
					PrintNode(nodehead);
					clear();
					break;
				case 13:
					system("cls");
					nodehead=reverse2(nodehead);
					PrintNode(nodehead);
					clear();
					break;
				}
			}
			else if (c == 'Q')
				return 0;
			Sleep(100);
		}
	}
	return 0;
}
