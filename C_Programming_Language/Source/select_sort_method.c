/* Selection sort method
 * 选择排序算法
 */

#include <stdio.h>

/* 函数名：static int select_sort_method(int buffer[], unsigned int size)
 * 函数功能：选择排序算法
 * 参数：buffer 要排序的数据缓冲区，size 数据缓冲区 buffer 的长度(元素个数)
 * 返回值：int 类型，成功返回 0，传入参数错误返回 -1
 */
static int select_sort_method(int buffer[], unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		printf("select_sort_method(),函数参数有误\n");
		return -1;
	}
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
	return 0;
}

/* 测试用例 */
#include <stdlib.h>
int main(void)
{
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
	select_sort_method(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++) 
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}