/*
 *  选择排序(Selection Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  2.selection_sort.c
 */


#include <stdio.h>


/*
 *  函数名：static int selection_sort(int *buffer, unsigned int size)
 *  功  能：选择排序算法(Selection Sort)
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int selection_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			index = i;
			for (int j = i + 1; j < size; j++)
			{
				if (buffer[index] > buffer[j])
				{
					index = j;
				}
			}
			if (index != i)
			{
				buffer[index] ^= buffer[i];
				buffer[i] ^= buffer[index];
				buffer[index] ^= buffer[i];
			}
		}
	}
	return 0;
}


/*
 *  函数名：static int selection_sort_major(int *buffer, unsigned int size)
 *  功  能：选择排序算法(Selection Sort)，优化方法
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int selection_sort_major(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int left_pos = 0;                                    /*  每趟排序最左边的位置，从 0 开始  */
		int right_pos = size-1;                              /*  每趟排序最右边的位置，从 size-1 开始  */
		int max_pos = 0;                                     /*  每趟循环选出最大值的位置(数组下标)  */
		int min_pos = 0;                                     /*  每趟循环选出最小值的位置(数组下标)  */
		while (left_pos < right_pos)
		{
			min_pos = left_pos;
			max_pos = left_pos;
			for (int i = left_pos; i <= right_pos; i++)      /*  每趟循环从 left_pos 到 right_pos 之间选取元素  */
			{
				if (buffer[i] < buffer[min_pos])             /*  找出值更小的元素，记下它的位置  */
				{
					min_pos = i;
				}
				if (buffer[i] > buffer[max_pos])             /*  找出值更大的元素，记下它的位置  */
				{
					max_pos = i;
				}
			}
			if (min_pos != left_pos)                         /*  如果本趟循环的最小的值不是最左边的位置，则交换位置  */
			{
				buffer[min_pos] ^= buffer[left_pos];
				buffer[left_pos] ^= buffer[min_pos];
				buffer[min_pos] ^= buffer[left_pos];
			}
			if (max_pos == left_pos)                         /*  如果 max_pos 的位置是 left_pos，在上面的代码中 left_pos 已被交换到 min_pos 的位置  */
			{                                                /*  所以 max_pos 的位置要修改为 min_pos  */
				max_pos = min_pos;
			}
			if (max_pos != right_pos)                        /*  如果本趟循环的最大的值不是最左右的位置，则交换位置  */
			{
				buffer[max_pos] ^= buffer[right_pos];
				buffer[right_pos] ^= buffer[max_pos];
				buffer[max_pos] ^= buffer[right_pos];
			}
			left_pos++;
			right_pos--;
		}

	}
	return 0;
}


/*  测试程序  */
#include <stdlib.h>
int main(void)
{
	printf("=========== [Selection Sort] ===========\n");
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
	selection_sort(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	printf("=========== [selection_sort_major] ===========\n");
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
	selection_sort_major(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}