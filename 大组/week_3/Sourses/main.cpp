#define _CRT_SECURE_NO_WARNINGS
#include "测试程序.h"
int a[505];
int t[505];
int main()
{
	int n,m,k;
	int min, max;
	int numCounts[] = { 100,10000, 50000, 200000 };
	char c;
	char savename[1000] = " ";
	char filename[1000] = " ";
	displaymenu(sel);
	for (;;) {
		memset(a, 0, 505);
		memset(t, 0, 505);
		if (_kbhit) {
			if (GetAsyncKeyState((VK_UP))) {
				sel = (sel > 1) ? sel - 1 : sel;
				displaymenu(sel);
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				sel = (sel < 12) ? sel + 1 : sel;
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
				if (sel == 12) return 0;
				displaymenu(sel);
				printf("command is [%c]\n", 'A' + sel - 1);
				system("cls");
				switch (sel)
				{
				case 1:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据：", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					InsertSort(a, n);
					printf("\n排序后的数据为：\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 2:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据：", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					MergeSort(a,0,n,t);
					printf("\n排序后的数据为：\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 3:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据:", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					QuickSort(a, 0, n);
					printf("\n排序后的数据为：\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 4:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据:", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					CountSort(a, n);
					printf("\n排序后的数据为：\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 5:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据：", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					RadixCountSort(a,n);
					printf("\n排序后的数据为：\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 6:
					printf("请输入数据量大小：");
					scanf("%d", &n);
					printf("\n数据量为%d，计算用时中……\n", n);
					testSortingTime1(n);
					clear();
					break;
				case 7:
					printf("请输入数据量大小：");
					scanf("%d", &n);
					printf("请输入排序次数：");
					scanf("%d", &m);
					testSortingTime2(n, m);
					clear();
					break;
				case 8:
					printf("请输入保存的目标路径：");
					scanf("%s", savename);
					printf("请输入数据数量、最大值与最小值（用空格隔开）：");
					scanf("%d %d %d", &n, &max, &min);
					generateTestDataToFile(savename,n,min,max);
					clear();
					break;
				case 9:
					printf("请输入读取文件的路径：");
					scanf("%s", filename);
					readDataAndSort(filename);
					clear();
					break;
				case 10:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据：", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					SortColors(a, n);
					clear();
					break;
				case 11:
					printf("请输入数据个数(需小于500)：");
					scanf("%d", &n);
					printf("\n请输入%d个数据：", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					printf("\n请输入k值：");
					scanf("%d", &k);
					qsort(a, 0, n, k);
					clear();
					break;
				/*case 12:
					
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
