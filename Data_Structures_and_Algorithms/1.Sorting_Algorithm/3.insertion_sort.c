/*
 *  插入排序(Insertion Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  3.insertion_sort.c
 */


#include <stdio.h>


/*
 *  函数名：static int insertion_sort(int *buffer, unsigned int size)
 *  功  能：插入排序(Insertion Sort)
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int insertion_sort(int *buffer, unsigned int size)
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
		for (j = 1; j < size; j++)
		{
			current = buffer[j];               /*  待排序的元素  */
			for (i = j - 1; ((i >= 0) && (buffer[i] > current)); i--)
			{
				buffer[i + 1] = buffer[i];     /*  逐个元素后移  */
			}
			buffer[i + 1] = current;           /*  插入当前排序元素  */
		}
	}
	return 0;
}


/*  测试程序  */
#include <stdlib.h>

int main(void)
{
	printf("=========== [insertion_sort] ===========\n");
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
	insertion_sort(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;
}