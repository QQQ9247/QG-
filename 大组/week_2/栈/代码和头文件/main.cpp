#define _CRT_SECURE_NO_WARNINGS
#include "������.h"
#include "��������.h"
int main()
{
	StackNode s;
	string str;
	string postexp;
	char c = ' ';
	char *i=NULL,*e;
	displaymenu(sel);
	for (;;) {
		if (_kbhit) {
			if (GetAsyncKeyState((VK_UP))) {
				sel = (sel > 1) ? sel - 1 : sel;
				displaymenu(sel);
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				sel = (sel < 9) ? sel + 1 : sel;
				displaymenu(sel);
			}
			c = _getch();
			if (c <= 'z' && c >= 'a') c = c - ('a' - 'A');
			if (c <= 'G' && c >= 'A') {
				sel = c - 'A' + 1;
				displaymenu(sel);
				GoToxy(36, 22);
				printf("command is [%c] ���س�ȷ��!", c);
			}
			else if (c == '\r') {
				if (sel == 9) return 0;
				displaymenu(sel);
				printf("command is [%c]\n", 'A' + sel - 1);
				system("cls");
				switch (sel)
				{
				case 1:
					s = *InitStack();
					printf("��ʼ���ɹ���");
					clear();
					break;
				case 2:
					DestroyStack(&s);
					printf("���ٳɹ���");
					clear();
					break;
				case 3:
					StackEmpty(&s) ? printf("Ϊ��ջ��") : printf("��Ϊ��ջ��");
					clear();
					break;
				case 4:
					printf("��������ջ������ֵ��Ϊ�ַ��ͣ���");
					i = (char*)malloc(sizeof(char));
					scanf("%c", i);
					Push(&s, i);
					printf("��ջ�ɹ�����ǰջΪ��");
					display(&s);
					clear();
					break;
				case 5:
					if (Pop(&s, i))
					{
						printf("��ջ�ɹ�����ǰջΪ��");
						display(&s);
					}
					clear();
					break;
				case 6:
					if (!StackEmpty(&s))
						printf("ջ��Ԫ��Ϊ��%c", *(char*)(GetTop(&s, &e)));
					else
						printf("ջΪ�գ��޷���ȡջ��Ԫ�أ�");
					clear();
					break;
				case 7:
					printf("��ǰջΪ��");
					display(&s);
					clear();
					break;
				case 8:
					printf("��������׺���ʽ��");
					cin >> str;
					postexp = TransExpToPostexp(str);
					cout <<"��׺���ʽΪ��" << postexp << endl;
					cout << "���ս��Ϊ��" << Calculate(postexp) << endl;
					clear();
					break;
				/*case 9:
					
					clear();
					break;
				case 10:
					
					clear();
					break;
				case 11:
					
					clear();
					break;
				case 12:
					
					clear();
					break;
				case 13:
					clear();
					break;*/
				}
			}
			else if (c == 'Q')
				return 0;
			Sleep(100);
		}
	}
	return 0;
}