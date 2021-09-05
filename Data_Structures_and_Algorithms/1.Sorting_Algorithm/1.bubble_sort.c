/*  
 *  冒泡排序(Bubble Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  1.bubble_sort.c
 */


#include <stdio.h>
#include <stdbool.h>



/*
 *  函数名：static int bubble_sort(int *buffer, unsigned int size)
 *  功  能：冒泡排序算法
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int bubble_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1 - j; i++)
			{
				if (buffer[i] > buffer[i + 1])
				{
					buffer[i] ^= buffer[i + 1];
					buffer[i + 1] ^= buffer[i];
					buffer[i] ^= buffer[i + 1];
				}
			}
		}
	}
	return 0;
}


/*
 *  函数名：static int bubble_sort_major(int *buffer, unsigned int size)
 *  功  能：冒泡排序算法，正序则直接退出排序
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：#include <stdbool.h>
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int bubble_sort_major(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		bool swaip_flag = false;
		for (int j = size - 1; j > 0; j--)
		{
			swaip_flag = false;
			for (int i = 0; i < j; i++)
			{
				if (buffer[i] > buffer[i + 1])
				{
					buffer[i] ^= buffer[i + 1];
					buffer[i + 1] ^= buffer[i];
					buffer[i] ^= buffer[i + 1];
					swaip_flag = true;
				}
			}
			if (!swaip_flag)
			{
				break;
			}
		}
	}
	return 0;
}


/*  测试程序  */
#include <stdlib.h>


int main(void)
{
	printf("=========== [bubble_sort] ===========\n");
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
	bubble_sort(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	printf("=========== [bubble_sort_major] ===========\n");
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
	bubble_sort_major(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}
