/*
 *  ��������(Insertion Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  3.insertion_sort.c
 */


#include <stdio.h>


/*
 *  ��������static int insertion_sort(int *buffer, unsigned int size)
 *  ��  �ܣ���������(Insertion Sort)
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
 */

static int insertion_sort(int *buffer, unsigned int size)
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
		for (j = 1; j < size; j++)
		{
			current = buffer[j];               /*  �������Ԫ��  */
			for (i = j - 1; ((i >= 0) && (buffer[i] > current)); i--)
			{
				buffer[i + 1] = buffer[i];     /*  ���Ԫ�غ���  */
			}
			buffer[i + 1] = current;           /*  ���뵱ǰ����Ԫ��  */
		}
	}
	return 0;
}


/*  ���Գ���  */
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