#define _CRT_SECURE_NO_WARNINGS
#include "链式队列.h"
#include "辅助函数.h"
int main()
{
	LinkQueue lq;
	lq = *InitQueue();
	char c = ' ';
	char* i = NULL, * e=NULL;
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
					lq = *InitQueue();
					printf("初始化成功！");
					clear();
					break;
				case 2:
					DestroyQueue(&lq);
					printf("销毁成功！");
					clear();
					break;
				case 3:
					QueueEmpty(&lq) ? printf("为空队列！") : printf("不为空队列！");
					clear();
					break;
				case 4:
					printf("请输入入队的数据值（为字符型）：");
					i = (char*)malloc(sizeof(char));
					scanf("%c", i);
					enQueue(&lq, i);
					printf("入栈成功！当前队列为：");
					DispQueue(&lq);
					clear();
					break;
				case 5:
					if (deQueue(&lq, i))
					{
						printf("出队成功！当前队列为：");
						DispQueue(&lq);
					}
					clear();
					break;
				case 6:
					lenghtLinkQueue(&lq);
					clear();
					break;
				case 7:
					DispQueue(&lq);
					clear();
					break;
				case 8:
					gethead(&lq);
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