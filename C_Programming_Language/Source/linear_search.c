/* linear search
 * ���Բ���
 */

#include <stdio.h>

 /* ��������static int linear_search(int buffer[], int index)
  * �������ܣ����Բ���
  * ������buffer Ҫ���ҵ����ݻ�������index Ҫ���ҵ�Ԫ�أ�size ���ݻ����� buffer �ĳ���(Ԫ�ظ���)
  * ����ֵ��int ���ͣ��ɹ�����Ҫ���ҵ�Ԫ�أ��������󷵻� -1������ʧ�ܷ��� 0
  */
static int linear_search(int buffer[], int index, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		printf("linear_search(),������������\n");
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

/* �������� */

int main(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", linear_search(arr, 6, len));
	return 0;
}