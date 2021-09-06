/*
 *  归并排序(Merge Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  5.merge_sort.c
 */

#include <stdio.h>
#include <string.h>    /*  void *memcpy(void *dest, const void *src, size_t n)  */
#include <stdlib.h>    /*  void *malloc(size_t size)   void free(void *ptr)  */


/*
 *  函数名：static int merge_sort(int *buffer, unsigned int size)
 *  功  能：归并排序(Merge Sort)
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：<string.h>  <stdlib.h>
 *  版  本：V1.0.0
 *  时  间：2021-9-6
 */

static int merge_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int *buff_ptr = buffer;                                     /*  buff_ptr 指向待排序的数组  */
		int *complete_ptr = (int*)malloc(size * sizeof(int));       /*  complete_ptr 指向已排序的数组  */
		int sect_counter = 0;                                       /*  区间分段的计数器，1、2、4、8、16...  */
		int start_counter = 0;                                      /*  区间起始位置的计数器  */
		int start_flag = 0;                                         /*  start_flag 起始位置  */
		int middle_flag = 0;                                        /*  middle_flag 中间位置  */
		int end_flag = 0;                                           /*  end_flag 结束位置  */
		int complete_sort_count = 0;                                /*  complete_sort_count 已排序数组计数器  */
		int await_sort_left_start = 0;                              /*  await_sort_left_start 待排序左边数列的起始位置  */
		int await_sort_left_end = 0;                                /*  await_sort_left_end 待排序左边数列的结束位置  */
		int await_sort_right_start = 0;                             /*  await_sort_right_start 待排序右边数列的起始位置  */
		int await_sort_right_end = 0;                               /*  await_sort_right_end 待排序右边数列的结束位置  */
		int *temp_ptr = NULL;

		/*  排序趟数的循环  */
		for (sect_counter = 1; sect_counter < size; sect_counter = sect_counter * 2)
		{   
			/*  每趟排序选取区间的循环  */
			for(start_counter = 0; start_counter<size; start_counter= start_counter+ sect_counter*2)
			{   
				/*  把每个区间分成两部分，start_flag 起始位置，middle_flag 中间位置，end_flag 结束位置  */
				start_flag = start_counter;
				/*  考虑分段不均的情况，middle_flag 不能超出 size  */
				middle_flag = (((start_counter + sect_counter) < size) ? (start_counter + sect_counter) : (size));
				/*  考虑分段不均的情况，end_flag 也不能超出 size  */
				end_flag = (((start_counter + sect_counter * 2) < size) ? (start_counter + sect_counter * 2) : (size));
				/*  complete_sort_count 已排序数组计数器  */
				complete_sort_count = start_flag;
				/*  await_sort_left_start 待排序左边数列的起始位置  */
				await_sort_left_start = start_flag;
				/*  await_sort_left_end 待排序左边数列的结束位置  */
				await_sort_left_end = middle_flag;
				/*  await_sort_right_start 待排序右边数列的起始位置  */
				await_sort_right_start = middle_flag;
				/*  await_sort_right_end 待排序右边数列的结束位置  */
				await_sort_right_end = end_flag;
				/*  把待排序左右两边数列和并到已排序数组中  */
				while ((await_sort_left_start < await_sort_left_end) && (await_sort_right_start < await_sort_right_end))
				{
					complete_ptr[complete_sort_count++] = buff_ptr[await_sort_left_start] < buff_ptr[await_sort_right_start] ? buff_ptr[await_sort_left_start++] : buff_ptr[await_sort_right_start++];
				}
				/*  把左边数列其它的元素追加到已排序数组中  */
				while (await_sort_left_start < await_sort_left_end)
				{
					complete_ptr[complete_sort_count++] = buff_ptr[await_sort_left_start++];
				}
				/*  把右边数列其它的元素追加到已排序数组中  */
				while (await_sort_right_start < await_sort_right_end)
				{
					complete_ptr[complete_sort_count++] = buff_ptr[await_sort_right_start++];
				}
			}
			/*  交换一下两个数组的指针，准备下一趟排序  */
			temp_ptr = buff_ptr;
			buff_ptr = complete_ptr;
			complete_ptr = temp_ptr;
		}
		/*  如果 buff_ptr 指针指向的不是原始数组，把 buff_ptr 中的内容复制到 buffer 中  */
		if (buff_ptr != buffer)
		{
			memcpy(buffer, buff_ptr, size * sizeof(int));
			complete_ptr = buff_ptr;
		}
		free(complete_ptr);
		complete_ptr = NULL;
	}
	return 0;
}



/*  测试程序  */

int main(void)
{
	printf("=========== [merge_sort] ===========\n");
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
	merge_sort(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}