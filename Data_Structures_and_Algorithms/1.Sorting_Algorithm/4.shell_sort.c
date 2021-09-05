/*
 *  希尔排序(Shell Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  4.shell_sort.c
 */


#include <stdio.h>



/*
 *  函数名：static inline int shell_group_sort(int *buffer, int size, int start, int step)
 *  功  能：对希尔排序中的单个组进行排序，和插入排序相似
 *  参  数：buffer 数据缓冲区，size 缓冲区大小，start 分组的起始位置，step 分组的步长(增量)
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static inline int shell_group_sort(int *buffer, int size, int start, int step)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int current = 0;                       /*  当前需要排序的元素的值  */
		int j = 0;
		int i = 0;
		for (j = start + step; j < size; j += step)
		{
			current = buffer[j];
			for (i = j - step; ((i >= 0) && (buffer[i] > current)); i -= step)
			{
				buffer[i + step] = buffer[i];
			}
			buffer[i + step] = current;
		}
	}
	return 0;
}


/*
 *  函数名：static int shell_sort(int *buffer, unsigned int size)
 *  功  能：希尔排序(Shell Sort),需要调用 shell_group_sort()
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int shell_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		for (int step = size / 2; step > 0; step= step/2)
		{
			for (int i = 0; i < step; i++)
			{
				shell_group_sort(buffer, size, i, step);
			}
		}
	}
	return 0;
}


/*
 *  函数名：static int shell_sort_major(int *buffer, unsigned int size)
 *  功  能：希尔排序(Shell Sort),单函数实现
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int shell_sort_major(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int temp = 0;
		int i = 0, j = 0, k = 0;
		for (k = size >> 1; k > 0; k >>= 1)
		{
			for (j = k; j < size; j++)
			{
				temp = buffer[j];
				for (i = j - k; ((i >= 0) && (buffer[i] > temp)); i -= k)
				{
					buffer[i + k] = buffer[i];
				}
				buffer[i + k] = temp;
			}
		}
	}
	return 0;
}


/*  测试程序  */
#include <stdlib.h>

static int shell_sort_major(int *buffer, unsigned int size);
int main(void)
{
	printf("=========== [shell_sort] ===========\n");
	int arr[30] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		arr[i] = rand() % 100;
	}
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	shell_sort(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	printf("=========== [shell_sort_major] ===========\n");
	for (int i = 0; i < 30; i++)
	{
		arr[i] = rand() % 100;
	}
	len = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	shell_sort_major(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}