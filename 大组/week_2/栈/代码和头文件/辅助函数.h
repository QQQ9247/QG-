#pragma once
int sel = 1;
char MenuText[9][100] = {//�˵�
		"[A]  ��ʼ����ջ",
		"[B]  ������ջ",
		"[C]  �ж�ջ�Ƿ�Ϊ��",
		"[D]  ��ջ����",
		"[E]  ��ջ����",
		"[F]  ȡջ��Ԫ��",
		"[G]  ���ջ",
		"[H]  ����������ֵ",
		/*"[I]  ��������ż����",
		"[J]  �ҵ���������е�",
		"[K]  �ж������Ƿ�ɻ�",
		"[L]  ��ת����(�ݹ�)",
		"[M]  ��ת����(�ǵݹ�)",*/
		"[Q]  Exit",
};
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
	int j = 10;
	GoToxy(36, j);
	ColorChoose(2);
	int i;
	printf("==================================\n");
	for (i = 0; i < 9; i++) {
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