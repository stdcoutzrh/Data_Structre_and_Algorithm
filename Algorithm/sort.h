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
