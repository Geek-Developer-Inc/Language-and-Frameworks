/*
 *  ѡ������(Selection Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  2.selection_sort.c
 */


#include <stdio.h>


/*
 *  ��������static int selection_sort(int *buffer, unsigned int size)
 *  ��  �ܣ�ѡ�������㷨(Selection Sort)
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
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
 *  ��������static int selection_sort_major(int *buffer, unsigned int size)
 *  ��  �ܣ�ѡ�������㷨(Selection Sort)���Ż�����
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
 */

static int selection_sort_major(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int left_pos = 0;                                    /*  ÿ����������ߵ�λ�ã��� 0 ��ʼ  */
		int right_pos = size-1;                              /*  ÿ���������ұߵ�λ�ã��� size-1 ��ʼ  */
		int max_pos = 0;                                     /*  ÿ��ѭ��ѡ�����ֵ��λ��(�����±�)  */
		int min_pos = 0;                                     /*  ÿ��ѭ��ѡ����Сֵ��λ��(�����±�)  */
		while (left_pos < right_pos)
		{
			min_pos = left_pos;
			max_pos = left_pos;
			for (int i = left_pos; i <= right_pos; i++)      /*  ÿ��ѭ���� left_pos �� right_pos ֮��ѡȡԪ��  */
			{
				if (buffer[i] < buffer[min_pos])             /*  �ҳ�ֵ��С��Ԫ�أ���������λ��  */
				{
					min_pos = i;
				}
				if (buffer[i] > buffer[max_pos])             /*  �ҳ�ֵ�����Ԫ�أ���������λ��  */
				{
					max_pos = i;
				}
			}
			if (min_pos != left_pos)                         /*  �������ѭ������С��ֵ��������ߵ�λ�ã��򽻻�λ��  */
			{
				buffer[min_pos] ^= buffer[left_pos];
				buffer[left_pos] ^= buffer[min_pos];
				buffer[min_pos] ^= buffer[left_pos];
			}
			if (max_pos == left_pos)                         /*  ��� max_pos ��λ���� left_pos��������Ĵ����� left_pos �ѱ������� min_pos ��λ��  */
			{                                                /*  ���� max_pos ��λ��Ҫ�޸�Ϊ min_pos  */
				max_pos = min_pos;
			}
			if (max_pos != right_pos)                        /*  �������ѭ��������ֵ���������ҵ�λ�ã��򽻻�λ��  */
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


/*  ���Գ���  */
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