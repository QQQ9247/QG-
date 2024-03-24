#pragma once
#include "链栈.h"
#include <string>
#include <iostream>

using namespace std;
StackNode optr;//运算符栈
StackNode _data;//数据栈
int empty() {
	if (StackEmpty(&_data)) {
		printf("表达式错误！\n"); 
		return 1; }
	return 0;
}

string TransExpToPostexp(string& exp)
{
	char e = ' ';
	optr = *InitStack();
	string postexp;//用于存放数字
	for (int i = 0; i < exp.size(); i++)
	{
		if ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.')//是数字直接进字符串
		{
			postexp += exp[i];
			while ((exp[i + 1] >= '0' && exp[i + 1] <= '9') || exp[i + 1] == '.')
				postexp += exp[++i];//放入整个数字

			postexp += ' ';//分隔
		}
		else
		{
			if (exp[i] == '(')//是左括号进栈
				Push(&optr, &exp[i]);
			else if (exp[i] == ')')//遇到右括号则出栈到左括号出栈
			{
				while (!StackEmpty(&optr))
				{
					if (*(char*)(GetTop(&optr, &e)) == '(')//遇到左括号则出栈并退出
					{
						Pop(&optr, &e);
						break;
					}
					else//遇到其他操作符则添加到后缀表达式中并出栈
					{
						postexp += *(char*)(GetTop(&optr, &e));
						postexp += ' ';//分隔
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
				while (!StackEmpty(&optr) && (*(char*)(GetTop(&optr, &e))!= '('))//小于等于栈顶操作符数据,则出栈*
				{
					postexp += *(char*)(GetTop(&optr, &e));
					postexp += ' ';//分隔
					Pop(&optr, &e);
				}
				//进栈
				Push(&optr, &exp[i]);
			}
			else//表达式错误
			{
				printf("表达式错误！无法计算！\n");
				return "0";
			}
		}
	}
	//遍历结束，剩余操作符出栈
	while (!StackEmpty(&optr))
	{
		postexp += *(char*)(GetTop(&optr, &e));
		postexp += ' ';//分隔
		Pop(&optr, &e);
	}
	cout << "后缀表达式为：" << postexp << endl;
	return postexp;
}


double Calculate(string postexp)
{
	if (postexp == "0") return 0;
	_data = *InitStack();
	int n=0;
	double *e,*num;
	for (int i = 0; i < postexp.size(); i++)
	{
		if (postexp[i] >= '0' && postexp[i] <= '9')//是数字则入栈
		{
			int left = i, right = i;
			while (postexp[right] != ' ')
				right++;
			num = (double *)malloc(sizeof(double));
			*num = atof(postexp.substr(left, right).c_str());//字符串转浮点

			//cout << num << endl;
			Push(&_data, num);
			i = right;
		}
		else//遇到操作符
		{
			printf("计算过程 %d：", ++n);
			//取栈顶两数据，注意先后顺序，后一个才是左操作数
			if (empty()) return 0;
			double right = *(double*)(GetTop(&_data, &e));
			Pop(&_data, &e);
			if (empty()) return 0;
			double left = *(double*)(GetTop(&_data, &e));
			Pop(&_data, &e);
			//判断操作符，得到数据再入栈
			char optr = postexp[i];
			double *sum,*cha,*ji,*shang;
			switch (optr)
			{
			case '+':
				sum = (double*)malloc(sizeof(double));
				*sum = left + right;
				Push(&_data, sum);
				break;
			case '-':
				cha = (double*)malloc(sizeof(double));
				*cha = left - right;
				Push(&_data, cha);
				break;
			case '*':
				ji = (double*)malloc(sizeof(double));
				*ji = left * right;
				Push(&_data, ji);
				break;
			case '/':
				if (!right) {
					printf("除数为0！无法计算\n");
					return 0;
				}
				shang = (double*)malloc(sizeof(double));
				*shang = left / right;
				Push(&_data, shang);
				break;
			default:
				printf("表达式出错！无法计算！\n");
				break;
			}
			cout << *(double*)(GetTop(&_data, e)) << endl;
			i++;
		}
	}
	if (empty()) return 0;
	cout << "最终结果为：" << *(double*)(GetTop(&_data, &e))<< endl;
	return 0;
}

