#pragma once
#include "��ջ.h"
#include <string>
#include <iostream>
using namespace std;

string TransExpToPostexp(string& exp)
{
	char e = ' ';
	StackNode optr;//�����ջ
	optr = *InitStack();
	string postexp;//���ڴ������
	for (int i = 0; i < exp.size(); i++)
	{
		if ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.')//������ֱ�ӽ��ַ���
		{
			postexp += exp[i];
			while ((exp[i + 1] >= '0' && exp[i + 1] <= '9') || exp[i + 1] == '.')
				postexp += exp[++i];//������������

			postexp += ' ';//�ָ�
		}
		else
		{
			if (exp[i] == '(')//�������Ž�ջ
				Push(&optr, &exp[i]);
			else if (exp[i] == ')')//�������������ջ�������ų�ջ
			{
				while (!StackEmpty(&optr))
				{
					if (*(char*)(GetTop(&optr, &e)) == '(')//�������������ջ���˳�
					{
						Pop(&optr, &e);
						break;
					}
					else//������������������ӵ���׺���ʽ�в���ջ
					{
						postexp += *(char*)(GetTop(&optr, &e));
						postexp += ' ';//�ָ�
						Pop(&optr, &e);
					}
				}
			}
			else if (exp[i] == '*' || exp[i] == '/')
			{
				Push(&optr, &exp[i]);
			}
			else if (exp[i] == '-' || exp[i] == '+')
			{
				while (!StackEmpty(&optr) && (*(char*)(GetTop(&optr, &e))!= '('))//С�ڵ���ջ������������,���ջ*
				{
					postexp += *(char*)(GetTop(&optr, &e));
					postexp += ' ';//�ָ�
					Pop(&optr, &e);
				}
				//��ջ
				Push(&optr, &exp[i]);
			}
			else//���ʽ����
			{
				printf("���ʽ����");
				return "0";
			}
		}
	}
	//����������ʣ���������ջ
	while (!StackEmpty(&optr))
	{
		postexp += *(char*)(GetTop(&optr, &e));
		postexp += ' ';//�ָ�
		Pop(&optr, &e);
	}
	return postexp;
}


double Calculate(string postexp)
{
	StackNode data;//����ջ
	data = *InitStack();
	int n=0;
	double e,*num;
	for (int i = 0; i < postexp.size(); i++)
	{
		if (postexp[i] >= '0' && postexp[i] <= '9')//����������ջ
		{
			int left = i, right = i;
			while (postexp[right] != ' ')
				right++;
			num = (double *)malloc(sizeof(double));
			*num = atof(postexp.substr(left, right).c_str());//�ַ���ת����

			//cout << num << endl;
			Push(&data, num);
			i = right;
		}
		else//����������
		{
			printf("������� %d��", ++n);
			//ȡջ�������ݣ�ע���Ⱥ�˳�򣬺�һ�������������
			double right = *(double*)(GetTop(&data, &e));
			Pop(&data, &e);
			double left = *(double*)(GetTop(&data, &e));
			Pop(&data, &e);
			//�жϲ��������õ���������ջ
			char optr = postexp[i];
			double *sum,*cha,*ji,*shang;
			switch (optr)
			{
			case '+':
				sum = (double*)malloc(sizeof(double));
				*sum = left + right;
				Push(&data, sum);
				break;
			case '-':
				cha = (double*)malloc(sizeof(double));
				*cha = left - right;
				Push(&data, cha);
				break;
			case '*':
				ji = (double*)malloc(sizeof(double));
				*ji = left * right;
				Push(&data, ji);
				break;
			case '/':
				if (right == 0.0) {
					printf("����Ϊ0���޷�����\n");
					return 0;
				}
				shang = (double*)malloc(sizeof(double));
				*shang = left / right;
				Push(&data, shang);
				break;
			default:
				printf("���ʽ�����޷����㣡\n");
				return 0;
			}
			cout << *(double*)(GetTop(&data, &e)) << endl;
			i++;
		}
	}
	return *(double*)(GetTop(&data, &e));
}
