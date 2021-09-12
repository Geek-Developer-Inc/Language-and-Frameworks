/*
 *  ��̬����(Dynamic array)
 *  SPDX-License-Identifier: GPL-2.0
 *  dynamic_array.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"


/*  
 *  ����ԭ�ͣ�struct dync_arr *dynamic_array_init(unsigned int number)
 *  �������ܣ���̬�����ʼ��
 *  ����������number ���ó�ʼ���� capacity �Ĵ�С
 *  �� �� ֵ���������������׵�ַ��ָ�룻 �쳣���綯̬�ڴ����ʧ�ܷ��� NULL
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

struct dync_arr *dynamic_array_init(unsigned int number)
{
	struct dync_arr *arr_ptr = (struct dync_arr *)malloc(sizeof(struct dync_arr));       /*  Ϊ�ṹ�������ڴ�ռ�  */
	if (NULL == arr_ptr)
	{
		return NULL;                                                                     /*  ��̬�ڴ����ʧ��  */
	}
	else
	{
		memset(arr_ptr, 0, sizeof(struct dync_arr));                                     /*  �¿��ٵ��ڴ�ռ�����  */
		arr_ptr->addr_ptr = (int *)malloc((sizeof(int)*number));                         /*  Ϊ���������ڴ�ռ䣬����������ݵ��ڴ�ռ�  */
		if (NULL == arr_ptr->addr_ptr)
		{
			return NULL;
		}
		else
		{
			memset(arr_ptr->addr_ptr, 0, (sizeof(int)*number));
			arr_ptr->size = 0;                                                           /*  ��ʼ���׶�����δ����κ�����  */
			arr_ptr->capacity = number;                                                  /*  ���ö�̬����Ĭ�ϵ��������  */
			return arr_ptr;
		}
	}
	return NULL;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_insert(struct dync_arr *arr, int value, unsigned char multiple)
 *  �������ܣ���̬�������Ԫ��
 *  ����������arr ָ��̬�����׵�ַ��ָ�룬����Ԫ�ص�ֵ�� multiple ����������㣬���·���ռ�Ĵ�С���¿���ԭ���� multiple ���ռ�
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1����̬�ռ�����ʧ�ܷ���-2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��multiple = 2
 */

int dynamic_array_insert(struct dync_arr *arr, int value, unsigned char multiple)
{
	if ((NULL == arr) || (NULL == arr->addr_ptr))
	{
		return -1;
	}
	else
	{
		if ((arr->size) == (arr->capacity))
		{
			int *new_ptr = (int*)malloc((sizeof(int)*arr->capacity*multiple));
			if (NULL == new_ptr)
			{
				return -2;                                                               /*  ��̬�ռ�����ʧ�ܣ�ֱ�ӷ���  */
			}
			else
			{
				memset(new_ptr, 0, (sizeof(int)*arr->capacity*multiple));                /*  �¿��ٵ��ڴ�ռ�����  */
				memcpy(new_ptr, arr->addr_ptr, (sizeof(int)*arr->capacity));             /*  �������ݵ����ڴ�ռ�  */
				free(arr->addr_ptr);                                                     /*  �ͷž��ڴ�ռ�  */
				arr->addr_ptr = new_ptr;
				arr->capacity = arr->capacity * 2;                                       /*  ���¶�̬���������  */
			}
		}
		arr->addr_ptr[arr->size] = value;                                                /*  ����Ԫ��  */
		arr->size++;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_pos_remove(struct dync_arr *arr, unsigned int pos)
 *  �������ܣ���̬����ɾ��Ԫ�أ�����λ��
 *  ����������arr ָ��̬�����׵�ַ��ָ�룻 pos ɾ��Ԫ�ص�λ��ֵ pos < size
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��multiple = 2
 */

int dynamic_array_pos_remove(struct dync_arr *arr, unsigned int pos)
{
	if ((NULL == arr) || (pos >= arr->size))
	{
		return -1;
	}
	else
	{
		for (unsigned int i = pos; i < arr->size - 1; i++)
		{
			arr->addr_ptr[i] = arr->addr_ptr[i + 1];
		}
		arr->size--;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_value_remove(struct dync_arr *arr, int value)
 *  �������ܣ���̬����ɾ��Ԫ�أ�����Ԫ��ֵ
 *  ����������arr ָ��̬�����׵�ַ��ָ�룻 value ɾ��Ԫ�ص�ֵ
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1��Ԫ�ز���ʧ�ܷ���-2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��multiple = 2
 */

int dynamic_array_value_remove(struct dync_arr *arr, int value)
{
	if (NULL == arr)
	{
		return -1;
	}
	else
	{
		unsigned int temp_pos = 0;
		if (0 == dynamic_array_search(arr, value, &temp_pos))
		{
			dynamic_array_pos_remove(arr, temp_pos);
		}
		else
		{
			return -2;
		}
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_search(struct dync_arr *arr, int value, unsigned int *ret_pos)
 *  �������ܣ���̬�������Ԫ��
 *  ����������arr ָ��̬�����׵�ַ��ָ�룻 value ����Ԫ�ص�ֵ�� *ret_pos ָ�����ڷ��ز���Ԫ�ص�λ��ֵ
 *  �� �� ֵ����������0�� �������δ��󷵻�-1�� ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��multiple = 2
 */

int dynamic_array_search(struct dync_arr *arr, int value, unsigned int *ret_pos)
{
	if ((NULL == arr) || (NULL == arr->addr_ptr) || (NULL == ret_pos))
	{
		return -1;
	}
	else
	{
		for (unsigned int i = 0; i < arr->size; i++)
		{
			if (arr->addr_ptr[i] == value)
			{
				*ret_pos = i;
				return 0;
			}
		}
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_clear(struct dync_arr *arr)
 *  �������ܣ���ն�̬����
 *  ����������arr ָ��̬�����׵�ַ��ָ��
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_clear(struct dync_arr *arr)
{
	if (NULL == arr)
	{
		return -1;
	}
	else
	{
		memset(arr->addr_ptr, 0, (sizeof(int)*arr->size));
		arr->size = 0;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int get_dynamic_array_value(struct dync_arr *arr, unsigned int pos, int *ret_val)
 *  �������ܣ���ȡ��̬���飬����λ�ò���ֵ
 *  ����������arr ָ��̬�����׵�ַ��ָ�룻 pos ĳԪ�ص�λ��ֵ��*ret_val ָ�����ڷ��ػ�ȡ��̬����ĳλ��Ԫ�ص�ֵ
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int get_dynamic_array_value(struct dync_arr *arr, unsigned int pos, int *ret_val)
{
	if ((NULL == arr) || (NULL == arr->addr_ptr) || (NULL == ret_val))
	{
		return -1;
	}
	else
	{
		*ret_val = (arr->addr_ptr[pos]);
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int get_dynamic_array_capacity(struct dync_arr *arr, unsigned int *ret_capt)
 *  �������ܣ���ȡ��̬��������
 *  ����������arr ָ��̬�����׵�ַ��ָ�룻ret_capt ָ�����ڷ��ض�̬���������
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int get_dynamic_array_capacity(struct dync_arr *arr, unsigned int *ret_capt)
{
	if ((NULL == arr) || (NULL == ret_capt))
	{
		return -1;
	}
	else
	{
		*ret_capt = (arr->capacity);
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int get_dynamic_array_size(struct dync_arr *arr, unsigned int *ret_size)
 *  �������ܣ���ȡ��̬����Ԫ�ظ���
 *  ����������arr ָ��̬�����׵�ַ��ָ�룻 *ret_size ָ�����ڷ��ػ�ȡ���Ķ�̬��������Ԫ�ظ���
 *  �� �� ֵ����������0�� �쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int get_dynamic_array_size(struct dync_arr *arr, unsigned int *ret_size)
{
	if ((NULL == arr) || (NULL == ret_size))
	{
		return -1;
	}
	else
	{
		*ret_size = (arr->size);
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_destroy(struct dync_arr *arr)
 *  �������ܣ���̬��������
 *  ����������arr ָ��̬�����׵�ַ��ָ��
 *  �� �� ֵ����������0���쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_destroy(struct dync_arr *arr)
{
	if ((NULL == arr) || (NULL == arr->addr_ptr))
	{
		return -1;
	}
	else
	{
		if (NULL != arr->addr_ptr)
		{
			free(arr->addr_ptr);
			arr->addr_ptr = NULL;
		}
		free(arr);
		arr = NULL;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_print(struct dync_arr *arr)
 *  �������ܣ���ӡ��̬�����Ԫ��
 *  ����������arr ָ��̬�����׵�ַ��ָ��
 *  �� �� ֵ����������0���쳣���纯�����δ��󷵻�-1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_print(struct dync_arr *arr)
{
	if ((NULL == arr) || (NULL == arr->addr_ptr))
	{
		return -1;
	}
	else
	{
		for (unsigned int i = 0; i < arr->size; i++)
		{
			printf("%d\t", arr->addr_ptr[i]);
		}
		printf("\n");
	}
	return 0;
}
