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

void bubble_sort(int a[],int n)
{
	if(n<=1)
		return;
	for(int i=0;i<n;++i)
	{
		int flag = 0;//设定是否提前退出冒泡排序操作的flag
		for(int j=0;j<n-1;++j)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1; //flag = 1表示有数据交换
			}					
		}
		if(!flag)
			break;
	}
}

void inseration_sort(int a[],int n)
{
	if(n<=1)
		return;
	for(int i=0;i<n;++i)
	{
		int value = a[i];	//待插入的元素
		int j = i-1;	//从后往前找
		//查找插入位置
		for(;j>=0;--j)
		{
			if(a[j]>value)
			{
				a[j+1] = a[j];	//移动数据
			}
			else
				break;
		}
		a[j+1]=value;
	}
}

void slection_sort(int a[],int n)
{
	int temp = 0;
	for(int i=0;i<n-1;++i)
		for(int j=i-1;j<n;++j)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
}

void merge(int*a,p,q,r)
{
	int *tmp = (int*)malloc((r - p + 1) * sizeof(int));
	if(!tmp)
		perror("malloc failed.")	
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
	else {
		for (; i <= q;)
			tmp[k++] = a[i++];
	}
	memcpy(a + p, tmp, (r - p + 1) * sizeof(int));
	free(tmp);	
}

void merge_sort(int *a, int p, int r)
{
	int q;

	if (p >= r)
		return;

	q = (p + r) / 2;
	merge_sort(a, p, q);
	merge_sort(a, q + 1, r);
	merge(a, p, q, r);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int get_q(int *a, int p, int r)
{
	int i, j;
	i = j = p;

	for (; j < r; ++j)
	{
		if (a[j] < a[r]) 
		{
			if(i != j)
			{
				swap(a + i, a + j);
			}
			++i;
		}
	}
	swap(a + i, a + r);
	return i;
}

void quick_sort(int *a, int p, int r)
{
	int q;
	if (p >= r)
		return;
	q = get_q(a, p, r);
	quick_sort(a, p, q-1);
	quick_sort(a, q+1, r);
}


#endif //SORT_H