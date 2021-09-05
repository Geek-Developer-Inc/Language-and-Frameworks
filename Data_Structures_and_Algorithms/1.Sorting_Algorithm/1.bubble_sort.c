/*  
 *  ð������(Bubble Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  1.bubble_sort.c
 */


#include <stdio.h>
#include <stdbool.h>



/*
 *  ��������static int bubble_sort(int *buffer, unsigned int size)
 *  ��  �ܣ�ð�������㷨
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
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
 *  ��������static int bubble_sort_major(int *buffer, unsigned int size)
 *  ��  �ܣ�ð�������㷨��������ֱ���˳�����
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ���#include <stdbool.h>
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
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


/*  ���Գ���  */
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
