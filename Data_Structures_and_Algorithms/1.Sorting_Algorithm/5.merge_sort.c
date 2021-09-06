/*
 *  �鲢����(Merge Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  5.merge_sort.c
 */

#include <stdio.h>
#include <string.h>    /*  void *memcpy(void *dest, const void *src, size_t n)  */
#include <stdlib.h>    /*  void *malloc(size_t size)   void free(void *ptr)  */


/*
 *  ��������static int merge_sort(int *buffer, unsigned int size)
 *  ��  �ܣ��鲢����(Merge Sort)
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ���<string.h>  <stdlib.h>
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-6
 */

static int merge_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int *buff_ptr = buffer;                                     /*  buff_ptr ָ������������  */
		int *complete_ptr = (int*)malloc(size * sizeof(int));       /*  complete_ptr ָ�������������  */
		int sect_counter = 0;                                       /*  ����ֶεļ�������1��2��4��8��16...  */
		int start_counter = 0;                                      /*  ������ʼλ�õļ�����  */
		int start_flag = 0;                                         /*  start_flag ��ʼλ��  */
		int middle_flag = 0;                                        /*  middle_flag �м�λ��  */
		int end_flag = 0;                                           /*  end_flag ����λ��  */
		int complete_sort_count = 0;                                /*  complete_sort_count ���������������  */
		int await_sort_left_start = 0;                              /*  await_sort_left_start ������������е���ʼλ��  */
		int await_sort_left_end = 0;                                /*  await_sort_left_end ������������еĽ���λ��  */
		int await_sort_right_start = 0;                             /*  await_sort_right_start �������ұ����е���ʼλ��  */
		int await_sort_right_end = 0;                               /*  await_sort_right_end �������ұ����еĽ���λ��  */
		int *temp_ptr = NULL;

		/*  ����������ѭ��  */
		for (sect_counter = 1; sect_counter < size; sect_counter = sect_counter * 2)
		{   
			/*  ÿ������ѡȡ�����ѭ��  */
			for(start_counter = 0; start_counter<size; start_counter= start_counter+ sect_counter*2)
			{   
				/*  ��ÿ������ֳ������֣�start_flag ��ʼλ�ã�middle_flag �м�λ�ã�end_flag ����λ��  */
				start_flag = start_counter;
				/*  ���Ƿֶβ����������middle_flag ���ܳ��� size  */
				middle_flag = (((start_counter + sect_counter) < size) ? (start_counter + sect_counter) : (size));
				/*  ���Ƿֶβ����������end_flag Ҳ���ܳ��� size  */
				end_flag = (((start_counter + sect_counter * 2) < size) ? (start_counter + sect_counter * 2) : (size));
				/*  complete_sort_count ���������������  */
				complete_sort_count = start_flag;
				/*  await_sort_left_start ������������е���ʼλ��  */
				await_sort_left_start = start_flag;
				/*  await_sort_left_end ������������еĽ���λ��  */
				await_sort_left_end = middle_flag;
				/*  await_sort_right_start �������ұ����е���ʼλ��  */
				await_sort_right_start = middle_flag;
				/*  await_sort_right_end �������ұ����еĽ���λ��  */
				await_sort_right_end = end_flag;
				/*  �Ѵ����������������кͲ���������������  */
				while ((await_sort_left_start < await_sort_left_end) && (await_sort_right_start < await_sort_right_end))
				{
					complete_ptr[complete_sort_count++] = buff_ptr[await_sort_left_start] < buff_ptr[await_sort_right_start] ? buff_ptr[await_sort_left_start++] : buff_ptr[await_sort_right_start++];
				}
				/*  ���������������Ԫ��׷�ӵ�������������  */
				while (await_sort_left_start < await_sort_left_end)
				{
					complete_ptr[complete_sort_count++] = buff_ptr[await_sort_left_start++];
				}
				/*  ���ұ�����������Ԫ��׷�ӵ�������������  */
				while (await_sort_right_start < await_sort_right_end)
				{
					complete_ptr[complete_sort_count++] = buff_ptr[await_sort_right_start++];
				}
			}
			/*  ����һ�����������ָ�룬׼����һ������  */
			temp_ptr = buff_ptr;
			buff_ptr = complete_ptr;
			complete_ptr = temp_ptr;
		}
		/*  ��� buff_ptr ָ��ָ��Ĳ���ԭʼ���飬�� buff_ptr �е����ݸ��Ƶ� buffer ��  */
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



/*  ���Գ���  */

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