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
/*int PartSort1(int* array, int left, int right)
{
	int begin = left;
	int end = right;
	int key = array[left];
	int pivot = left;
	while (begin < end)
	{
		//��С
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		array[pivot] = array[end];
		pivot = end;
		//�Ҵ�
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		array[pivot] = array[begin];
		pivot = begin;
	}
	pivot = begin;
	array[pivot] = key;

	return pivot;
}

void QuickSort(int* array, int left, int right)
{
	if (left >= right-1)
	{
		return;
	}
	int keyindex = PartSort1(array, left, right-1);//����ҿ���������
	QuickSort(array, left, keyindex);//��key����߽��еݹ�����
	QuickSort(array, keyindex + 1, right);//��key���ұ߽��еݹ�����
}*/



/*int PartSort1(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int key = a[left];
	int pivot = left;
	while (begin < end)
	{
		//��С
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		//�Ҵ�
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyindex = PartSort1(a, left, right);
	QuickSort(a, left, keyindex - 1);//��key����߽��еݹ�����
	QuickSort(a, keyindex + 1, right);//��key���ұ߽��еݹ�����
}*/


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

	for (i = 0; i < size; i++)
	{
		temp[array[i] - min]++;	//��¼ÿ��Ԫ�س��ֵĴ���
	}

	//����
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (temp[i] > 0)
		{
			array[j] = i + min;	//��Ԫ���±껹ԭ��д��ԭ����
			j++;
			temp[i]--;
		}
	}

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

int getDigit(int x, int d)//��ȡ��ǰ�� λ�� ����
{
	return ((x / (int)pow(10, d - 1)) % 10);//���㵱ǰλ��ֵ 
}

void RadixSort(int* arr, int L, int R, int digit)
{
	int radix = 10;//���� �ۼ�
	int i, j, d;
	int* bucket = (int*)malloc((R - L + 1) * sizeof(int));//����bucket
	if (bucket == NULL)
		return;
	for (d = 1; d <= digit; d++)//����λ��ѭ�����ٴ�
	{
		int* count = (int*)calloc(radix,sizeof(int));//����ʮ�ļ�����
		if (count == NULL)
			return;
		for (int i = L; i <= R; i++)
		{
			j = getDigit(arr[i], d);//��ǰλ��
			count[j]++;//��Ӧ����ֵ��1
		}
		for (i = 1; i < radix; i++)
		{
			count[i] += count[i - 1];//�ۼ�
		}
		for (i = R; i >= L; i--)//���ŷ�
		{
			j = getDigit(arr[i], d);//��ǰλ��
			if(count[j]-1>=0&&j>=0) bucket[count[j] - 1] = arr[i];//bucket���λ��Ϊ ��ǰλ����Ӧ������������ֵ��1
			count[j]--;//�ö�Ӧ������ֵ��һ
		}
		for (i = L; i <= R; i++)
		{
			arr[i] = bucket[i];//д��ԭ����
		}
		free(count);//�ͷ�count�ռ�
		count = NULL;
	}
	free(bucket);//�ͷ�bucket�ռ�
	bucket = NULL;
}

void RadixCountSort(int* arr, int L, int R)
{
	if (arr == NULL || R < 2)
		return;
	RadixSort(arr, L, R - 1, maxbaits(arr, R));
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