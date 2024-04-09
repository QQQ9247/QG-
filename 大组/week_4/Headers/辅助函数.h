#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h >
#include <Windows.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")
int sel = 1;
char MenuText[12][100] = {//菜单
		"[A]  构建平衡二叉树",
		"[B]  插入操作",
		"[C]  查找操作",
		"[D]  删除操作",
		"[E]  前序遍历（递归版）",
		"[F]  中序遍历（递归版）",
		"[G]  后序遍历（递归版）",
		"[H]  前序遍历（非递归版）",
		"[I]  中序遍历（非递归版）",
		"[J]  后序遍历（非递归版）",
		"[K]  层序遍历",
		/*"[L]  反转链表(递归)",
		"[M]  反转链表(非递归)",*/
		"[Q]  Exit",
};
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
	int j = 10;
	GoToxy(36, j);
	ColorChoose(2);
	int i;
	printf("=======================================\n");
	for (i = 0; i < 12; i++) {
		GoToxy(36, ++j);
		if (i == hilight - 1)
			printf("<<%s>>\n", MenuText[i]);
		else
			printf("  %s\n", MenuText[i]);
	}
	GoToxy(36, ++j);
	printf("=======================================\n");
}
void clear() {
	printf("\n按回车确认!");
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
	getchar();
	displaymenu(sel);
}
