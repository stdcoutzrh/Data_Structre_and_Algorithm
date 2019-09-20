/*sort.h:This is an implemention of sort algorithms in C language.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef SORT_H
#define SORT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//a是数组，n是数组中元素的个数

//冒泡排序	O(n^2)
void bubble_sort(int a[], int n)
{
	if (n <= 1)
		return;

	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (a[j]>a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

//直接插入排序	O(n^2)
void inseration_sort(int a[], int n)
{
	if (n <= 1)
		return;

	for (int i = 1; i<n; ++i)
	{
		int tmp = a[i];
		int j;
		for (j = i - 1; j >= 0; --j)
		{
			if (a[j]>tmp)
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j+1] = tmp;
	}
}

//折半插入排序	O(n^2)
void binary_inseration_sort(int a[], int n)
{
	if (n <= 1)
		return;

	for (int i = 1; i<n; ++i)
	{
		int tmp = a[i];
		//查找区间 0~i-1
		int low = 0, high = i - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid]>tmp)
			{
				high = mid-1;
			}
			else 
			{
				low = mid+1;
			}
		}

		//将插入处后面的值后移，然后插入该值
		int j;
		for (j = i - 1; j >= low; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}
}

//选择排序	O(n^2)
void selection_sort(int a[], int n)
{
	if (n <= 1)
		return;

	for (int i = 0; i < n - 1; ++i)
	{
		int tmp, index = i;
		//找到最小的index号
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[index])
				index = j;
		}

		//最小的就是当前i
		if (index == i)
			continue;

		//将最小的与i处的值交换
		tmp = a[i];
		a[i] = a[index];
		a[index] = tmp;
	}
}

//归并排序	O(nlogn)
void merge(int*a, int p,int q,int r)	
{
	//q把以p为起点，r为终点的序列分为两部分，即要合并的两部分
	//merge函数将这两个已有序的序列合并成一个有序序列
	
	//tmp数组申请来存放两个序列合并之后的结果
	int *tmp = (int*)malloc((r - p + 1) * sizeof(int));
	if (!tmp)
		perror("malloc failed.");
	
	//合并两个序列
	int i, j, k;
	for (i = p, j = q + 1, k = 0; i <= q && j <= r;)
	{
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	if (i == q + 1)
	{
		for (; j <= r;)
			tmp[k++] = a[j++];
	}
	else 
	{
		for (; i <= q;)
			tmp[k++] = a[i++];
	}

	//用tmp里已合并的的数据覆盖原始序列里的数据
	memcpy(a + p, tmp, (r - p + 1) * sizeof(int));
	free(tmp);
}

void merge_sort(int a[], int p, int r)
{
	int q;

	if (p >= r)
		return;

	q = (p + r) / 2;
	merge_sort(a, p, q);
	merge_sort(a, q + 1, r);
	merge(a, p, q, r);
}


//快速排序	O(nlogn)

void swap(int *a, int*b)	//交换两个数
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int get_q(int a[], int p, int r)
{
	int i, j;
	i = j = p;

	for (; j < r; ++j)
	{
		if (a[j] < a[r])
		{
			if (i != j)
			{
				swap(a + i, a + j);
			}
			++i;
		}
	}
	swap(a + i, a + r);
	return i;
}

void quick_sort(int a[], int p, int r)	//p...r为待排序区间
{
	int q;
	if (p >= r)
		return;
	q = get_q(a, p, r);
	quick_sort(a, p, q - 1);
	quick_sort(a, q + 1, r);
}

#endif //SORT_H