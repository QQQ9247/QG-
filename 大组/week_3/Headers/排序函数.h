#define _CRT_SECURE_NO_WARNINGS
#include "��������.h"
#include <math.h>
// ��������
void InsertSort(int* array, int count)
{
	int temp;
	int i,j;
	for (i = 0; i < count; i++)
	{
		temp = array[i];
        j = i - 1;
        for (; j >= 0; j--) {
            if (array[j] > temp) {
                array[j + 1] = array[j];
            }
            else {
                //������õ��������ʾ�Ѿ��ҵ��˸÷ŵ�λ����
                //��Ϊǰ�涼������
                break;
            }
        }
        //��jѭ�������Ժ�Ҫô�������������У�Ҫô�����ҵ�����Сλ��
        //���������Ժ�ֱ�Ӱ�j+1��λ�ø�ֵΪtemp����
        array[j + 1] = temp;
	}
}

// �鲢����
void MergeSort(int* array, int left, int right, int* temp) //�ָ�����Ϊ����ұ�
{
	//�ֽ⣺
	//�ָ�����ֻ��һ��Ԫ��ʱֹͣ�ݹ�
	if (right-left < 2)
	{
		return;
	}

	int mid = (left + right) / 2;

	MergeSort(array, left, mid, temp);		//�ָ������������
	MergeSort(array, mid, right, temp);	//�ָ���������Ұ��

	//�ϲ���
	int begin1 = left, end1 = mid;			//����1����������
	int begin2 = mid, end2 = right;		//����2����������
	int i = begin1;

	//����������������
	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
		{
			temp[i] = array[begin1];
			begin1++;
		}
		else
		{
			temp[i] = array[begin2];
			begin2++;
		}
		i++;
	}

	while (begin1 < end1)
	{
		temp[i] = array[begin1];
		begin1++;
		i++;
	}

	while (begin2 < end2)
	{
		temp[i] = array[begin2];
		begin2++;
		i++;
	}

	//������ʱ��������ݵ�ԭ����
	for (i = left; i < right; i++)
	{
		array[i] = temp[i];
	}
}

void QuickSort(int* array, int left, int right)
{
	int mid = 0;
	int low = left;
	int high = right - 1;
	int temp = 0;

	if (!(left < right))  
	{                        
		return;           
	}					 

	mid = left + (right - left) / 2;
	if (mid != right - 1)
	{
		temp = array[mid];
		array[mid] = array[right - 1];
		array[right - 1] = temp;
	}
	temp = array[high]; // �����ڵĵ�һ��"��" ��ԭ��"��"���ֵ��temp����һ�� ԭ�������ݲ��ᶪʧ ������Ҳûɶ��
	while (low < high)
	{
		while (temp >= array[low] && low < high) 
		{
			low++;
		}
		if (low < high)
		{
			array[high] = array[low]; 
		}

		while (temp <= array[high] && low < high)
		{
			high--;
		}
		if (low < high)
		{
			array[low] = array[high]; // ����"��"
		}

	}
	array[low] = temp; // �������һ��"��"����

	QuickSort(array, left, low);
	QuickSort(array, low + 1, right);
}




//��������
void CountSort(int* array, int size)
{
	//�������Сֵ
	int i = 0;
	int max = array[0], min = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	//����
	int range = max - min + 1;
	int* temp = (int*)calloc(range, sizeof(int));
	if (temp == NULL)
	{
		perror("calloc fail!\n");
		return;
	}
	int* out = (int*)calloc(size, sizeof(int));
	for (i = 0; i < size; i++)
	{
		temp[array[i] - min]++;	//��¼ÿ��Ԫ�س��ֵĴ���
	}
	for (int i = 1; i < range; i++) temp[i] += temp[i - 1];
	//����
	int j = 0;
	for (j = size; j > 0; j--)  out[--temp[array[j - 1]-min]] = array[j - 1];
	for (int i = 0; i < size; i++) array[i] = out[i];
	free(out);
	out = NULL;
	free(temp);
	temp = NULL;
}

//������������

int maxbaits(int* array, int right)//����λ����
{
	int max = INT_MIN;//������Сֵ
	for (int i = 0; i < right; i++)
	{
		if (max < array[i])
			max = array[i];//�ҳ����ֵ
	}
	int res = 0;
	while (max != 0)//�������ֵλ��
	{
		res++;
		max /= 10;
	}
	return res;
}

void RadixCountSort(int data[], int n) //��������
{
	int d = maxbaits(data, n);
	int* tmp = new int[n];
	int* count = new int[10]; //������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
			data[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}



//��ɫ����
void SortColors(int array[], int numCount)
{
	//��������Ƿ����Ҫ��
	for (int i = 0; i < numCount; i++) if (array[i] != 1 && array[i] != 2 && array[i] != 0) { printf("����ֻ�ܰ���0 1 2��"); return; }
	int p0 = 0;
	int p2 = numCount;
	for (int i = 0; i < p2; ++i)
	{
		if (array[i] == 0)
		{
			int tmp = array[p0];
			array[p0] = array[i];
			array[i] = tmp;
			++p0;
		}
		else if (array[i] == 2)
		{
			--p2;
			int tmp = array[p2];
			array[p2] = array[i];
			array[i] = tmp;
			--i;
		}
	}
	printf("\n����������Ϊ��\n");
	for (int i = 0; i < numCount; i++) printf("%d ", array[i]);
}

//������������O(n)�ҵ���kС����
void qsort(int *array,int l, int r,int k)
{
	int i = l, j = r, mid = array[(l + r) / 2],t;
	do
	{
		while (array[j] > mid)
			j--;
		while (array[i] < mid)
			i++;
		if (i <= j)
		{
			t = array[i];
			array[i] = array[j];
			array[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	//���ź����鱻����Ϊ���飺 l<=j<=i<=r
	if (k <= j) qsort(array,l, j, k);//��������ֻ��Ҫ��������
	else if (i <= k) qsort(array,i, r, k);//��������ֻ��Ҫ��������
	else //������м�����ֱ�����
	{
		printf("��%dС����Ϊ��%d", k,array[j + 1]);
		return;
	}
}