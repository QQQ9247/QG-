#define _CRT_SECURE_NO_WARNINGS
#include "���Գ���.h"
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
				printf("command is [%c] ���س�ȷ��!", c);
			}
			else if (c == '\r') {
				if (sel == 12) return 0;
				displaymenu(sel);
				printf("command is [%c]\n", 'A' + sel - 1);
				system("cls");
				switch (sel)
				{
				case 1:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d�����ݣ�", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					InsertSort(a, n);
					printf("\n����������Ϊ��\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 2:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d�����ݣ�", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					MergeSort(a,0,n,t);
					printf("\n����������Ϊ��\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 3:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d������:", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					QuickSort(a, 0, n);
					printf("\n����������Ϊ��\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 4:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d������:", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					CountSort(a, n);
					printf("\n����������Ϊ��\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 5:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d�����ݣ�", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					RadixCountSort(a,n);
					printf("\n����������Ϊ��\n");
					for (int i = 0; i < n; i++) printf("%d ", a[i]);
					clear();
					break;
				case 6:
					printf("��������������С��");
					scanf("%d", &n);
					printf("\n������Ϊ%d��������ʱ�С���\n", n);
					testSortingTime1(n);
					clear();
					break;
				case 7:
					printf("��������������С��");
					scanf("%d", &n);
					printf("���������������");
					scanf("%d", &m);
					testSortingTime2(n, m);
					clear();
					break;
				case 8:
					printf("�����뱣���Ŀ��·����");
					scanf("%s", savename);
					printf("�������������������ֵ����Сֵ���ÿո��������");
					scanf("%d %d %d", &n, &max, &min);
					generateTestDataToFile(savename,n,min,max);
					clear();
					break;
				case 9:
					printf("�������ȡ�ļ���·����");
					scanf("%s", filename);
					readDataAndSort(filename);
					clear();
					break;
				case 10:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d�����ݣ�", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					SortColors(a, n);
					clear();
					break;
				case 11:
					printf("���������ݸ���(��С��500)��");
					scanf("%d", &n);
					printf("\n������%d�����ݣ�", n);
					for (int i = 0; i < n; i++) scanf("%d", &a[i]);
					printf("\n������kֵ��");
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
