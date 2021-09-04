/* linear search
 * 线性查找
 */

#include <stdio.h>

 /* 函数名：static int linear_search(int buffer[], int index)
  * 函数功能：线性查找
  * 参数：buffer 要查找的数据缓冲区，index 要查找的元素，size 数据缓冲区 buffer 的长度(元素个数)
  * 返回值：int 类型，成功返回要查找的元素，参数有误返回 -1，查找失败返回 0
  */
static int linear_search(int buffer[], int index, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		printf("linear_search(),函数参数有误\n");
		return -1;
	}
	for (int i = 0; i < size; i++)
	{
		if (index == buffer[i])
		{
			printf("Find index is %d\n", buffer[i]);
			return i;
		}
	}
	printf("Find failed\n");
	return 0;
}

/* 测试用例 */

int main(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", linear_search(arr, 6, len));
	return 0;
}