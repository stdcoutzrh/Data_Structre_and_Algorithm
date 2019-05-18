/*sort.h:This is an implemention of sort algorithms in C language.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef SORT_H
#define SORT_H

#include<stdio.h>

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



#endif //SORT_H