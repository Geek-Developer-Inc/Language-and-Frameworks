/*
 *  ϣ������(Shell Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  4.shell_sort.c
 */


#include <stdio.h>



/*
 *  ��������static inline int shell_group_sort(int *buffer, int size, int start, int step)
 *  ��  �ܣ���ϣ�������еĵ�����������򣬺Ͳ�����������
 *  ��  ����buffer ���ݻ�������size ��������С��start �������ʼλ�ã�step ����Ĳ���(����)
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
 */

static inline int shell_group_sort(int *buffer, int size, int start, int step)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int current = 0;                       /*  ��ǰ��Ҫ�����Ԫ�ص�ֵ  */
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
 *  ��������static int shell_sort(int *buffer, unsigned int size)
 *  ��  �ܣ�ϣ������(Shell Sort),��Ҫ���� shell_group_sort()
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
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
 *  ��������static int shell_sort_major(int *buffer, unsigned int size)
 *  ��  �ܣ�ϣ������(Shell Sort),������ʵ��
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
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


/*  ���Գ���  */
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