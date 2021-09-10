/*
 *  ��������(Counting Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  1.counting_sort.c
 */


#include <stdio.h>
#include <stdlib.h>


/*
 *  ��������static int counting_sort(int *buffer, unsigned int size)
 *  ��  �ܣ����������㷨
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0����̬�ڴ����ʧ�ܷ���-2
 *  ͷ�ļ���#include <stdlib.h>
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
 */

static int counting_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int min = buffer[0];
		int max = buffer[0];
		int i = 0;
		
		for (i = 0; i < size; i++)                                   /*  �ҳ������е����ֵ����Сֵ��ȷ����ϣ��Ĵ�С  */
		{
			if (buffer[i] < min) { min = buffer[i]; }
			if (buffer[i] > max) { max = buffer[i]; }
		}
		int count_size = max - min + 1;
		int *count_ptr = (int *)malloc(sizeof(int) * count_size);    /*  ����һ�����ڼ���������  */
		if (NULL == count_ptr)                                       /*  ��̬�ڴ����ʧ��  */
		{
			count_ptr = NULL;
			return -2;
		}
		for (i = 0; i < count_size; i++)                             /*  �������Ķ�̬�ڴ��  */
		{
			count_ptr[i] = 0;
		}
		int *temp_ptr = (int *)malloc(sizeof(int) * size);
		if (NULL == temp_ptr)
		{
			temp_ptr = NULL;
			return -2;
		}
		for (i = 0; i < size; i++)
		{
			temp_ptr[i] = 0;
		}
	
		for (i = 0; i < size; i++)
		{
			count_ptr[buffer[i] - min]++;                            /*  ͳ������A�и�Ԫ�س��ֵĴ����������ڶ�Ӧ��λ����  */
		}
		for (i = 1; i < count_size; i++)
		{
			count_ptr[i] += count_ptr[i - 1];                        /*  �����Լ������±���ֵ��Ŀ�������Ӧ��λ�ã���֤�ȶ���  */
		}
		for (i = size - 1; i >= 0; i--)
		{
			temp_ptr[count_ptr[buffer[i] - min] - 1] = buffer[i];    /*  ��ԭ���鰴��С˳�򴢴浽��һ������  */
			count_ptr[buffer[i] - min]--;
		}
		for (i = 0; i < size; i++)
		{
			buffer[i] = temp_ptr[i];
		}
		if (NULL != count_ptr)
		{
			free(count_ptr);
			count_ptr = NULL;
		}
		if (NULL != temp_ptr)
		{
			free(temp_ptr);
			temp_ptr = NULL;
		}
	}
	return 0;
}


/*  ��������  */
int main(void)
{
	int arr[] = { -10,10,-9,9,8,-8,-7,7,6,6,-5,-5,-4,4,-3,-2,1,-1,0,5,2,3 };

	int len = sizeof(arr) / sizeof(arr[0]);
	printf("=========== [counting_sort] ===========\n");
	printf("Before sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	counting_sort(arr, len);
	printf("\nAfter sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}