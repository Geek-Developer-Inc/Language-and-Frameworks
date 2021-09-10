/*
 *  计数排序(Counting Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  1.counting_sort.c
 */


#include <stdio.h>
#include <stdlib.h>


/*
 *  函数名：static int counting_sort(int *buffer, unsigned int size)
 *  功  能：计数排序算法
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0，动态内存分配失败返回-2
 *  头文件：#include <stdlib.h>
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int counting_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int min = buffer[0];
		int max = buffer[0];
		int i = 0;
		
		for (i = 0; i < size; i++)                                   /*  找出数组中的最大值和最小值，确定哈希表的大小  */
		{
			if (buffer[i] < min) { min = buffer[i]; }
			if (buffer[i] > max) { max = buffer[i]; }
		}
		int count_size = max - min + 1;
		int *count_ptr = (int *)malloc(sizeof(int) * count_size);    /*  创建一个用于计数的数组  */
		if (NULL == count_ptr)                                       /*  动态内存分配失败  */
		{
			count_ptr = NULL;
			return -2;
		}
		for (i = 0; i < count_size; i++)                             /*  清空申请的动态内存块  */
		{
			count_ptr[i] = 0;
		}
		int *temp_ptr = (int *)malloc(sizeof(int) * size);
		if (NULL == temp_ptr)
		{
			temp_ptr = NULL;
			return -2;
		}
		for (i = 0; i < size; i++)
		{
			temp_ptr[i] = 0;
		}
	
		for (i = 0; i < size; i++)
		{
			count_ptr[buffer[i] - min]++;                            /*  统计数组A中各元素出现的次数，并放在对应的位置上  */
		}
		for (i = 1; i < count_size; i++)
		{
			count_ptr[i] += count_ptr[i - 1];                        /*  储存自己数组下标数值在目标数组对应的位置，保证稳定性  */
		}
		for (i = size - 1; i >= 0; i--)
		{
			temp_ptr[count_ptr[buffer[i] - min] - 1] = buffer[i];    /*  将原数组按大小顺序储存到另一个数组  */
			count_ptr[buffer[i] - min]--;
		}
		for (i = 0; i < size; i++)
		{
			buffer[i] = temp_ptr[i];
		}
		if (NULL != count_ptr)
		{
			free(count_ptr);
			count_ptr = NULL;
		}
		if (NULL != temp_ptr)
		{
			free(temp_ptr);
			temp_ptr = NULL;
		}
	}
	return 0;
}


/*  测试用例  */
int main(void)
{
	int arr[] = { -10,10,-9,9,8,-8,-7,7,6,6,-5,-5,-4,4,-3,-2,1,-1,0,5,2,3 };

	int len = sizeof(arr) / sizeof(arr[0]);
	printf("=========== [counting_sort] ===========\n");
	printf("Before sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	counting_sort(arr, len);
	printf("\nAfter sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}