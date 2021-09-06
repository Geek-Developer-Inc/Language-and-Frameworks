/*
 *  快速排序(Quick Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  6.quick_sort.c
 */

#include <stdio.h>


/*
 *  函数名：static int quick_sort(int *buffer, unsigned int size)
 *  功  能：快速排序(Quick Sort)，递归实现
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-6
 */

static int quick_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int center_axis = buffer[0];                                   /*  选取最左边的数作为中心轴  */
		int left_tag = 0;                                              /*  左下标  */
		int right_tag = size - 1;                                      /*  右下标  */
		int move_tag = 2;                                              /*  当前应该移动的下标  */

		while (left_tag < right_tag)
		{
			if (2 == move_tag)                                         /*  移动右下标的情况  */
			{
				if (buffer[right_tag] >= center_axis)                  /*  如果右下标位置的元素值大于或等于中心轴，继续移动右下标  */
				{
					right_tag--;
					continue;
				}
				buffer[left_tag] = buffer[right_tag];                  /*  如果右下标位置的元素值小于中心轴，把它填到左下标的坑中  */
				left_tag++;                                            /*  左下标向右移动  */
				move_tag = 1;                                          /*  下次循环将移动左下标  */
				continue;
			}
			else if (1 == move_tag)                                    /*  移动左下标的情况  */
			{
				if (buffer[left_tag] <= center_axis)                   /*  如果左下标位置的元素值小于或等于中心轴，继续移动左下标  */
				{
					left_tag++;
					continue;
				}
				buffer[right_tag] = buffer[left_tag];                  /*  如果左下标位置的元素值大于中心轴，把它填到右下标的坑中  */
				right_tag--;                                           /*  右下标向右移动  */
				move_tag = 2;                                          /*  下次循环将移动右下标  */
			}
		}
		buffer[left_tag] = center_axis;                                /*  如果循环结束，左右下标重合，把中心轴的值填进去  */
		quick_sort(buffer, left_tag);                                  /*  对中心轴左边的序列进行排序  */
		quick_sort(buffer+ left_tag+1, size-left_tag-1);               /*  对中心轴右边的序列进行排序  */
	}
	return 0;
}


/*
 *  函数名：static int quick_sort__major(int *buffer, unsigned int size)
 *  功  能：快速排序(Quick Sort)，优化版
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-6
 */

#define SWITCH_CASE1  (1U)
#define SWITCH_CASE2  (2U)
static int quick_sort__major(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int center_axis = buffer[0];                                   /*  选取最左边的数作为中心轴  */
		int left_tag = 0;                                              /*  左下标  */
		int right_tag = size - 1;                                      /*  右下标  */
		unsigned char move_tag = SWITCH_CASE2;                         /*  当前应该移动的下标  */

		while (left_tag < right_tag)
		{
			switch (move_tag)
			{
			case SWITCH_CASE1:
				if (buffer[left_tag] <= center_axis)                   /*  如果左下标位置的元素值小于或等于中心轴，继续移动左下标  */
				{
					left_tag++;
					continue;
				}
				buffer[right_tag] = buffer[left_tag];                  /*  如果左下标位置的元素值大于中心轴，把它填到右下标的坑中  */
				right_tag--;                                           /*  右下标向右移动  */
				move_tag = SWITCH_CASE2;                               /*  下次循环将移动右下标  */
				break;
			case SWITCH_CASE2:
				if (buffer[right_tag] >= center_axis)                  /*  如果右下标位置的元素值大于或等于中心轴，继续移动右下标  */
				{
					right_tag--;
					continue;
				}
				buffer[left_tag] = buffer[right_tag];                  /*  如果右下标位置的元素值小于中心轴，把它填到左下标的坑中  */
				left_tag++;                                            /*  左下标向右移动  */
				move_tag = SWITCH_CASE1;                               /*  下次循环将移动左下标  */
				break;
			default:
				break;
			}
		}
		buffer[left_tag] = center_axis;                                /*  如果循环结束，左右下标重合，把中心轴的值填进去  */
		quick_sort(buffer, left_tag);                                  /*  对中心轴左边的序列进行排序  */
		quick_sort(buffer + left_tag + 1, size - left_tag - 1);        /*  对中心轴右边的序列进行排序  */
	}
	return 0;
}



/*  测试程序  */
#include <stdlib.h>


int main(void)
{
	printf("=========== [quick_sort] ===========\n");
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
	quick_sort__major(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}