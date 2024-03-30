#define _CRT_SECURE_NO_WARNINGS
#include "辅助函数.h"
#include <math.h>
// 插入排序：
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
                //如果不用调整，则表示已经找到了该放的位置了
                //因为前面都有序了
                break;
            }
        }
        //当j循环走完以后，要么就是走完了所有，要么就是找到了最小位置
        //所以走完以后直接把j+1的位置赋值为temp即可
        array[j + 1] = temp;
	}
}

// 归并排序
void MergeSort(int* array, int left, int right, int* temp) //分割区间为左闭右闭
{
	//分解：
	//分割数组只有一个元素时停止递归
	if (right-left < 2)
	{
		return;
	}

	int mid = (left + right) / 2;

	MergeSort(array, left, mid, temp);		//分割并排序数组左半边
	MergeSort(array, mid, right, temp);	//分割并排序数组右半边

	//合并：
	int begin1 = left, end1 = mid;			//数组1的左右区间
	int begin2 = mid, end2 = right;		//数组2的左右区间
	int i = begin1;

	//排序两个有序数组
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

	//拷贝临时数组的内容到原数组
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
	temp = array[high]; // 这是挖的第一个"坑" 把原来"坑"里的值用temp保存一份 原来的数据不会丢失 覆盖了也没啥事
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
			array[low] = array[high]; // 再填"坑"
		}

	}
	array[low] = temp; // 最后把最后一个"坑"填上

	QuickSort(array, left, low);
	QuickSort(array, low + 1, right);
}


//快速排序
/*int PartSort1(int* array, int left, int right)
{
	int begin = left;
	int end = right;
	int key = array[left];
	int pivot = left;
	while (begin < end)
	{
		//找小
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		array[pivot] = array[end];
		pivot = end;
		//找大
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
	int keyindex = PartSort1(array, left, right-1);//左闭右开区间排序
	QuickSort(array, left, keyindex);//对key的左边进行递归排序
	QuickSort(array, keyindex + 1, right);//对key的右边进行递归排序
}*/



/*int PartSort1(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int key = a[left];
	int pivot = left;
	while (begin < end)
	{
		//找小
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		//找大
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
	QuickSort(a, left, keyindex - 1);//对key的左边进行递归排序
	QuickSort(a, keyindex + 1, right);//对key的右边进行递归排序
}*/


//计数排序
void CountSort(int* array, int size)
{
	//找最大最小值
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

	//计数
	int range = max - min + 1;
	int* temp = (int*)calloc(range, sizeof(int));
	if (temp == NULL)
	{
		perror("calloc fail!\n");
		return;
	}

	for (i = 0; i < size; i++)
	{
		temp[array[i] - min]++;	//记录每个元素出现的次数
	}

	//排序
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (temp[i] > 0)
		{
			array[j] = i + min;	//将元素下标还原并写入原数组
			j++;
			temp[i]--;
		}
	}

	free(temp);
	temp = NULL;
}

//基数计数排序
int maxbaits(int* array, int right)//求数位函数
{
	int max = INT_MIN;//设置最小值
	for (int i = 0; i < right; i++)
	{
		if (max < array[i])
			max = array[i];//找出最大值
	}
	int res = 0;
	while (max != 0)//计算最大值位数
	{
		res++;
		max /= 10;
	}
	return res;
}

int getDigit(int x, int d)//获取当前数 位数 函数
{
	return ((x / (int)pow(10, d - 1)) % 10);//计算当前位数值 
}

void RadixSort(int* arr, int L, int R, int digit)
{
	int radix = 10;//限制 累加
	int i, j, d;
	int* bucket = (int*)malloc((R - L + 1) * sizeof(int));//申请bucket
	if (bucket == NULL)
		return;
	for (d = 1; d <= digit; d++)//多少位就循环多少次
	{
		int* count = (int*)calloc(radix,sizeof(int));//长度十的计数器
		if (count == NULL)
			return;
		for (int i = L; i <= R; i++)
		{
			j = getDigit(arr[i], d);//求当前位数
			count[j]++;//对应索引值加1
		}
		for (i = 1; i < radix; i++)
		{
			count[i] += count[i - 1];//累加
		}
		for (i = R; i >= L; i--)//倒着放
		{
			j = getDigit(arr[i], d);//求当前位数
			if(count[j]-1>=0&&j>=0) bucket[count[j] - 1] = arr[i];//bucket存放位置为 当前位数对应计数器索引的值减1
			count[j]--;//让对应索引的值减一
		}
		for (i = L; i <= R; i++)
		{
			arr[i] = bucket[i];//写入原数组
		}
		free(count);//释放count空间
		count = NULL;
	}
	free(bucket);//释放bucket空间
	bucket = NULL;
}

void RadixCountSort(int* arr, int L, int R)
{
	if (arr == NULL || R < 2)
		return;
	RadixSort(arr, L, R - 1, maxbaits(arr, R));
}

//颜色排序
void SortColors(int array[], int numCount)
{
	//检测数据是否符合要求
	for (int i = 0; i < numCount; i++) if (array[i] != 1 && array[i] != 2 && array[i] != 0) { printf("数据只能包含0 1 2！"); return; }
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
	printf("\n排序后的数据为：\n");
	for (int i = 0; i < numCount; i++) printf("%d ", array[i]);
}

//在无序数组中O(n)找到第k小的数
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
	//快排后数组被划分为三块： l<=j<=i<=r
	if (k <= j) qsort(array,l, j, k);//在左区间只需要搜左区间
	else if (i <= k) qsort(array,i, r, k);//在右区间只需要搜右区间
	else //如果在中间区间直接输出
	{
		printf("第%d小的数为：%d", k,array[j + 1]);
		return;
	}
}