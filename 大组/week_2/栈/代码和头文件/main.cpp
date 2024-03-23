#define _CRT_SECURE_NO_WARNINGS
#include "计算器.h"
#include "辅助函数.h"
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
				printf("command is [%c] 按回车确认!", c);
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
					printf("初始化成功！");
					clear();
					break;
				case 2:
					DestroyStack(&s);
					printf("销毁成功！");
					clear();
					break;
				case 3:
					StackEmpty(&s) ? printf("为空栈！") : printf("不为空栈！");
					clear();
					break;
				case 4:
					printf("请输入入栈的数据值（为字符型）：");
					i = (char*)malloc(sizeof(char));
					scanf("%c", i);
					Push(&s, i);
					printf("入栈成功！当前栈为：");
					display(&s);
					clear();
					break;
				case 5:
					if (Pop(&s, i))
					{
						printf("出栈成功！当前栈为：");
						display(&s);
					}
					clear();
					break;
				case 6:
					if (!StackEmpty(&s))
						printf("栈顶元素为：%c", *(char*)(GetTop(&s, &e)));
					else
						printf("栈为空，无法获取栈顶元素！");
					clear();
					break;
				case 7:
					printf("当前栈为：");
					display(&s);
					clear();
					break;
				case 8:
					printf("请输入中缀表达式：");
					cin >> str;
					postexp = TransExpToPostexp(str);
					cout <<"后缀表达式为：" << postexp << endl;
					cout << "最终结果为：" << Calculate(postexp) << endl;
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