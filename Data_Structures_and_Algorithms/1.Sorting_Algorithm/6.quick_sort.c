/*
 *  ��������(Quick Sort)
 *  SPDX-License-Identifier: GPL-2.0
 *  6.quick_sort.c
 */

#include <stdio.h>


/*
 *  ��������static int quick_sort(int *buffer, unsigned int size)
 *  ��  �ܣ���������(Quick Sort)���ݹ�ʵ��
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-6
 */

static int quick_sort(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int center_axis = buffer[0];                                   /*  ѡȡ����ߵ�����Ϊ������  */
		int left_tag = 0;                                              /*  ���±�  */
		int right_tag = size - 1;                                      /*  ���±�  */
		int move_tag = 2;                                              /*  ��ǰӦ���ƶ����±�  */

		while (left_tag < right_tag)
		{
			if (2 == move_tag)                                         /*  �ƶ����±�����  */
			{
				if (buffer[right_tag] >= center_axis)                  /*  ������±�λ�õ�Ԫ��ֵ���ڻ���������ᣬ�����ƶ����±�  */
				{
					right_tag--;
					continue;
				}
				buffer[left_tag] = buffer[right_tag];                  /*  ������±�λ�õ�Ԫ��ֵС�������ᣬ��������±�Ŀ���  */
				left_tag++;                                            /*  ���±������ƶ�  */
				move_tag = 1;                                          /*  �´�ѭ�����ƶ����±�  */
				continue;
			}
			else if (1 == move_tag)                                    /*  �ƶ����±�����  */
			{
				if (buffer[left_tag] <= center_axis)                   /*  ������±�λ�õ�Ԫ��ֵС�ڻ���������ᣬ�����ƶ����±�  */
				{
					left_tag++;
					continue;
				}
				buffer[right_tag] = buffer[left_tag];                  /*  ������±�λ�õ�Ԫ��ֵ���������ᣬ��������±�Ŀ���  */
				right_tag--;                                           /*  ���±������ƶ�  */
				move_tag = 2;                                          /*  �´�ѭ�����ƶ����±�  */
			}
		}
		buffer[left_tag] = center_axis;                                /*  ���ѭ�������������±��غϣ����������ֵ���ȥ  */
		quick_sort(buffer, left_tag);                                  /*  ����������ߵ����н�������  */
		quick_sort(buffer+ left_tag+1, size-left_tag-1);               /*  ���������ұߵ����н�������  */
	}
	return 0;
}


/*
 *  ��������static int quick_sort__major(int *buffer, unsigned int size)
 *  ��  �ܣ���������(Quick Sort)���Ż���
 *  ��  ����buffer ���ݻ�������size ��������С
 *  ����ֵ������������󷵻�-1��������򷵻�0
 *  ͷ�ļ�����
 *  ��  ����V1.0.0
 *  ʱ  �䣺2021-9-6
 */

#define SWITCH_CASE1  (1U)
#define SWITCH_CASE2  (2U)
static int quick_sort__major(int *buffer, unsigned int size)
{
	if ((buffer == NULL) || (size < 2))
	{
		return -1;
	}
	else
	{
		int center_axis = buffer[0];                                   /*  ѡȡ����ߵ�����Ϊ������  */
		int left_tag = 0;                                              /*  ���±�  */
		int right_tag = size - 1;                                      /*  ���±�  */
		unsigned char move_tag = SWITCH_CASE2;                         /*  ��ǰӦ���ƶ����±�  */

		while (left_tag < right_tag)
		{
			switch (move_tag)
			{
			case SWITCH_CASE1:
				if (buffer[left_tag] <= center_axis)                   /*  ������±�λ�õ�Ԫ��ֵС�ڻ���������ᣬ�����ƶ����±�  */
				{
					left_tag++;
					continue;
				}
				buffer[right_tag] = buffer[left_tag];                  /*  ������±�λ�õ�Ԫ��ֵ���������ᣬ��������±�Ŀ���  */
				right_tag--;                                           /*  ���±������ƶ�  */
				move_tag = SWITCH_CASE2;                               /*  �´�ѭ�����ƶ����±�  */
				break;
			case SWITCH_CASE2:
				if (buffer[right_tag] >= center_axis)                  /*  ������±�λ�õ�Ԫ��ֵ���ڻ���������ᣬ�����ƶ����±�  */
				{
					right_tag--;
					continue;
				}
				buffer[left_tag] = buffer[right_tag];                  /*  ������±�λ�õ�Ԫ��ֵС�������ᣬ��������±�Ŀ���  */
				left_tag++;                                            /*  ���±������ƶ�  */
				move_tag = SWITCH_CASE1;                               /*  �´�ѭ�����ƶ����±�  */
				break;
			default:
				break;
			}
		}
		buffer[left_tag] = center_axis;                                /*  ���ѭ�������������±��غϣ����������ֵ���ȥ  */
		quick_sort(buffer, left_tag);                                  /*  ����������ߵ����н�������  */
		quick_sort(buffer + left_tag + 1, size - left_tag - 1);        /*  ���������ұߵ����н�������  */
	}
	return 0;
}



/*  ���Գ���  */
#include <stdlib.h>


int main(void)
{
	printf("=========== [quick_sort] ===========\n");
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
	quick_sort__major(arr, len);
	printf("After sorting:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}