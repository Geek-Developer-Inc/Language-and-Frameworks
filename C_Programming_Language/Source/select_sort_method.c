/* Selection sort method
 * ѡ�������㷨
 */

#include <stdio.h>

/* ��������static int select_sort_method(int buffer[], unsigned int size)
 * �������ܣ�ѡ�������㷨
 * ������buffer Ҫ��������ݻ�������size ���ݻ����� buffer �ĳ���(Ԫ�ظ���)
 * ����ֵ��int ���ͣ��ɹ����� 0������������󷵻� -1
 */
static int select_sort_method(int buffer[], unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		printf("select_sort_method(),������������\n");
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

/* �������� */
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