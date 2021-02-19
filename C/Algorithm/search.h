#include<stdio.h>

//二分查找 O(logn)
int binary_search(int a[], int n,int value)
{
	/*
		二分查找依赖的是顺序表结构，简单点说就是数组,
		其次，二分查找针对的是有序数据。
	*/

	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);//这里注意括号，+优先级高于>>
		if (a[mid] == value)
		{
			return mid;
		}
		else if (a[mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}