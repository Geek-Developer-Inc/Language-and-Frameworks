/*
 *  堆排序(Heap Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  7.heap_sort.c
 */


#include <stdio.h>



/*
 *  函数名：static int _heap_sink(int *buffer, int start, int end)
 *  功  能：循环实现元素下沉，被 heap_sort 调用
 *  参  数：buffer 数据缓冲区，start 待处理元素的下标，end 待排序数组最后一个元素的下标
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
 */

static int _heap_sink(int *buffer, int start, int end)
{
	if (buffer == NULL)
	{
		return -1;
	}
	else
	{
		int par_node = start;                                                                                /*  确定父节点和左子节点的数组下标  */
		int left_chi_node = par_node * 2 + 1;

		while (left_chi_node <= end)                                                                         /*  如果子节点的下表没有超出范围，循环继续  */
		{
			if (((left_chi_node + 1) <= end) && (buffer[left_chi_node] < buffer[left_chi_node + 1]))         /*  先比较两个子节点大小，选择最大的  */
			{
				left_chi_node++;
			}
			if (buffer[par_node] > buffer[left_chi_node])                                                    /*  如果父节点大于子节点，则调整完毕，直接退出  */
			{
				return 0;
			}
			else                                                                                             /*  否则，交换父子内容，再继续子节点和孙节点的比较  */
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
 *  函数名：static int heap_sort(int *buffer, unsigned int size)
 *  功  能：冒泡排序算法
 *  参  数：buffer 数据缓冲区，size 缓冲区大小
 *  返回值：传入参数错误返回-1，完成排序返回0
 *  头文件：无
 *  版  本：V1.0.0
 *  时  间：2021-9-5
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
		for (i = (size - 1) / 2; i >= 0; i--)                                                                /*  初始化堆，从最后一个父节点开始调整  */
		{
			_heap_sink(buffer, i, size - 1);
		}
		for (i = size - 1; i > 0; i--)                                                                       /*  把第一个元素和堆最后一个元素交换，然后重新调整，直到排序完毕  */
		{
			buffer[0] ^= buffer[i];
			buffer[i] ^= buffer[0];
			buffer[0] ^= buffer[i];
			_heap_sink(buffer, 0, i - 1);
		}
	}
	return 0;
}


/*  测试程序  */
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