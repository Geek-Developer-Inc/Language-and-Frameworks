/*
 *  ������(Heap Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  7.heap_sort.c
 */


#include <stdio.h>



/*
 *  ��������static int _heap_sink(int *buffer, int start, int end)
 *  ��  �ܣ�ѭ��ʵ��Ԫ���³����� heap_sort ����
 *  ��  ����buffer ���ݻ�������start ������Ԫ�ص��±꣬end �������������һ��Ԫ�ص��±�
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
 */

static int _heap_sink(int *buffer, int start, int end)
{
	if (buffer == NULL)
	{
		return -1;
	}
	else
	{
		int par_node = start;                                                                                /*  ȷ�����ڵ�����ӽڵ�������±�  */
		int left_chi_node = par_node * 2 + 1;

		while (left_chi_node <= end)                                                                         /*  ����ӽڵ���±�û�г�����Χ��ѭ������  */
		{
			if (((left_chi_node + 1) <= end) && (buffer[left_chi_node] < buffer[left_chi_node + 1]))         /*  �ȱȽ������ӽڵ��С��ѡ������  */
			{
				left_chi_node++;
			}
			if (buffer[par_node] > buffer[left_chi_node])                                                    /*  ������ڵ�����ӽڵ㣬�������ϣ�ֱ���˳�  */
			{
				return 0;
			}
			else                                                                                             /*  ���򣬽����������ݣ��ټ����ӽڵ����ڵ�ıȽ�  */
			{
				buffer[par_node] ^= buffer[left_chi_node];
				buffer[left_chi_node] ^= buffer[par_node];
				buffer[par_node] ^= buffer[left_chi_node];
				par_node = left_chi_node;
				left_chi_node = par_node * 2 + 1;
			}
		}

	}
	return 0;
}


/*
 *  ��������static int heap_sort(int *buffer, unsigned int size)
 *  ��  �ܣ�ð�������㷨
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-5
 */

static int heap_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int i = 0;
		for (i = (size - 1) / 2; i >= 0; i--)                                                                /*  ��ʼ���ѣ������һ�����ڵ㿪ʼ����  */
		{
			_heap_sink(buffer, i, size - 1);
		}
		for (i = size - 1; i > 0; i--)                                                                       /*  �ѵ�һ��Ԫ�غͶ����һ��Ԫ�ؽ�����Ȼ�����µ�����ֱ���������  */
		{
			buffer[0] ^= buffer[i];
			buffer[i] ^= buffer[0];
			buffer[0] ^= buffer[i];
			_heap_sink(buffer, 0, i - 1);
		}
	}
	return 0;
}


/*  ���Գ���  */
#include <stdlib.h>


int main(void)
{
	int arr[] = { -10,10,-9,9,8,-8,-7,7,6,6,-5,-5,-4,4,-3,-2,1,-1,0,5,2,3 };

	int len = sizeof(arr) / sizeof(arr[0]);
	printf("=========== [heap_sort] ===========\n");
	printf("Before sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	heap_sort(arr, len);
	printf("\nAfter sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}