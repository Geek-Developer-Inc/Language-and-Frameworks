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
 *  ����ԭ�ͣ�int dynamic_array_create(int capacit, struct dynamic_array** ret_array)
 *  �������ܣ�������̬����
 *  ����������capacit ���ö�̬����ĳ�ʼ������capacit > 0�� **ret_array ���ض�̬�����׵�ַ
 *  �� �� ֵ���������� 0�� ����������󷵻� -1�� ��̬�ڴ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��capacit ��ֵҪ���� 0
 */

int dynamic_array_create(int capacit, struct dynamic_array** ret_array)
{
	if (NULL == ret_array)
	{
		return -1;
	}
	else
	{
		*ret_array = (struct dynamic_array *)malloc(sizeof(struct dynamic_array));       /*  Ϊ�ṹ�������ڴ�ռ�  */
		if (NULL == *ret_array)
		{
			return -2;/*  ��̬�ڴ����ʧ��  */
		}
		else
		{
			memset(*ret_array, 0, sizeof(struct dynamic_array));                         /*  �¿��ٵ��ڴ�ռ�����  */
			(*ret_array)->size = 0;                                                      /*  ��ʼ���׶�����δ����κ�����  */
			if (capacit <= 0)
			{
				capacit = 10;
			}
			(*ret_array)->capacity = capacit;                                            /*  ���ö�̬����Ĭ�ϵ��������  */
			(*ret_array)->array = malloc(sizeof(void*) * ((*ret_array)->capacity));
			if (NULL == ((*ret_array)->array))
			{
				free(*ret_array);
				*ret_array = NULL;
				return -2;
			}
			memset((*ret_array)->array, 0, sizeof(void*) * ((*ret_array)->capacity));
		}
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_insert(struct dynamic_array* arr, int pos, void* arr_value)
 *  �������ܣ���̬�������Ԫ��
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룬 pos �����λ�ã�ͷ���β�壻 *arr_value ��������Ԫ�ص�ֵ
 *  �� �� ֵ���������� 0�� ����������󷵻� -1�� ��̬�ڴ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_insert(struct dynamic_array* arr, int pos, void* arr_value)
{
	if ((NULL == arr) || (NULL == arr_value))
	{
		return -1;
	}
	else
	{
		if ((pos < 0) || (pos > arr->size))
		{
			pos = arr->size;                                                             /*  ����Ĭ��Ϊβ�巨  */
		}
		if (arr->size >= arr->capacity)
		{
			int new_capact = (arr->capacity) * 2;
			void** new_ptr = malloc(sizeof(void*) * new_capact);
			if (NULL == new_ptr)
			{
				return -2;                                                               /*  ��̬�ռ�����ʧ�ܣ�ֱ�ӷ���  */
			}
			else
			{
				memset(new_ptr, 0, (sizeof(void*) * new_capact));                        /*  �¿��ٵ��ڴ�ռ�����  */
				memcpy(new_ptr, arr->array, sizeof(void*)*(arr->capacity));              /*  �������ݵ����ڴ�ռ�  */
				free(arr->array);                                                        /*  �ͷž��ڴ�ռ�  */
				arr->array = new_ptr;
				arr->capacity = new_capact;                                              /*  ���¶�̬���������  */
			}
		}
		for (int i = arr->size - 1; (i >= pos) && (NULL != arr->array[i]); i--)          /*  Ѱ�Ҳ����λ��  */
		{
			arr->array[i + 1] = arr->array[i];
		}
		arr->array[pos] = arr_value;                                                     /*  ����Ԫ��  */
		arr->size++;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_by_pos_remove(struct dynamic_array* arr, int pos)
 *  �������ܣ���̬����ɾ��Ԫ�أ�����λ��
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 pos ɾ��Ԫ�ص�λ��ֵ pos < size �� pos >= 0
 *  �� �� ֵ���������� 0�� �������δ��󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_by_pos_remove(struct dynamic_array* arr, int pos)
{
	if ((NULL == arr) || (pos < 0) || (pos >= arr->size))
	{
		return -1;
	}
	else
	{
		for (int i = pos; (i < arr->size - 1) && (NULL != arr->array[i]); i++)
		{
			arr->array[i] = arr->array[i + 1];
		}
		arr->size--;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_by_value_remove(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*))
 *  �������ܣ�����Ԫ��ֵɾ����̬�����Ԫ��
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 *value Ҫɾ��Ԫ�ص�ֵ�� *compare_call_back �ԱȻص�����
 *  �� �� ֵ����������0�� �������δ��󷵻�-1�� Ԫ�ز���ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��*compare_call_back Ԫ�ضԱȻص�����������ʵ�֣��磺int compare_call_back(void* value1, void* value2) ��ȷ��� 1
 */

int dynamic_array_by_value_remove(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*))
{
	if ((NULL == arr) || (NULL == value) || (NULL == compare_call_back))
	{
		return -1;
	}
	else
	{
		for (int i = 0; (i < arr->size) && (NULL != arr->array[i]); i++)
		{
			if (1 == compare_call_back(arr->array[i], value))
			{
				dynamic_array_by_pos_remove(arr, i);
				return 0;
			}
		}
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_for_earch(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*), int* ret_pos)
 *  �������ܣ���̬�������Ԫ�أ�����ı���
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 *value ����Ԫ�ص�ֵ�� *ret_pos ָ�����ڷ��ز���Ԫ�ص�λ��ֵ
 *  �� �� ֵ����������0�� �������δ��󷵻�-1�� ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��compare_call_back Ԫ�ضԱȻص�����������ʵ�֣��磺int compare_call_back(void* value1, void* value2) ��ȷ��� 1
 */

int dynamic_array_for_earch(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*), int* ret_pos)
{
	if ((NULL == arr) || (NULL == value) || (NULL == compare_call_back) || (NULL == ret_pos))
	{
		return -1;
	}
	else
	{
		for (int i = 0; (i < arr->size) && (NULL != arr->array[i]); i++)
		{
			if (1 == compare_call_back(arr->array[i], value))
			{
				*ret_pos = i;
				return 0;
			}
		}
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�void dynamic_array_clear(struct dynamic_array* arr)
 *  �������ܣ���ն�̬�����Ԫ��
 *  ����������*arr ָ��̬�����׵�ַ��ָ��
 *  �� �� ֵ����
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

void dynamic_array_clear(struct dynamic_array* arr)
{
	if (NULL == arr)
	{
		return;
	}
	else
	{
		memset(arr->array, 0, (sizeof(void*) * arr->size));
		arr->size = 0;
	}
}


/*
 *  ����ԭ�ͣ�int dynamic_array_get_value(struct dynamic_array* arr, int pos, void** ret_value)
 *  �������ܣ���ȡ��̬���飬����λ�ò���ֵ
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 pos ĳԪ�ص�λ��ֵ�� **ret_value ָ�����ڷ��ػ�ȡ��̬����ĳλ��Ԫ�ص�ֵ
 *  �� �� ֵ���������� 0�� �������δ��󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_get_value(struct dynamic_array* arr, int pos, void** ret_value)
{
	if ((NULL == arr) || (pos < 0) || (pos >= arr->size) || (NULL == ret_value))
	{
		return -1;
	}
	else
	{
		*ret_value = (arr->array[pos]);
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_get_capacity(struct dynamic_array* arr, int* ret_capacity)
 *  �������ܣ���ȡ��̬��������ֵ
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 *ret_capacity ָ�����ڷ��ض�̬���������
 *  �� �� ֵ���������� 0�� �������δ��󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_get_capacity(struct dynamic_array* arr, int* ret_capacity)
{
	if ((NULL == arr) || (NULL == ret_capacity))
	{
		return -1;
	}
	else
	{
		*ret_capacity = (arr->capacity);
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int dynamic_array_get_size(struct dynamic_array* arr, int* ret_size)
 *  �������ܣ���ȡ��̬�����Ԫ�ظ���
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 *ret_size ָ�����ڷ��ػ�ȡ���Ķ�̬��������Ԫ�ظ���
 *  �� �� ֵ���������� 0�� �������δ��󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

int dynamic_array_get_size(struct dynamic_array* arr, int* ret_size)
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
 *  ����ԭ�ͣ�void dynamic_array_destroy(struct dynamic_array* arr)
 *  �������ܣ����ٶ�̬����
 *  ����������*arr ָ��̬�����׵�ַ��ָ��
 *  �� �� ֵ����
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע����
 */

void dynamic_array_destroy(struct dynamic_array* arr)
{
	if (NULL == arr)
	{
		return;
	}
	else
	{
		if (NULL != arr->array)
		{
			free(arr->array);
			arr->array = NULL;
		}
		arr->capacity = 0;
		arr->size = 0;
		free(arr);
		arr = NULL;
	}
}


/*
 *  ����ԭ�ͣ�void dynamic_array_print_value(struct dynamic_array *arr, void(*print_call_back)(void*))
 *  �������ܣ���ӡ��̬�����Ԫ��ֵ
 *  ����������*arr ָ��̬�����׵�ַ��ָ�룻 *print_call_back ��ӡ�ص�����
 *  �� �� ֵ����
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-10
 *  ��    ע��*print_call_back �ص�����������ʵ�֣��磺void print_call_back_value(void *value)
 */

void dynamic_array_print_value(struct dynamic_array *arr, void(*print_call_back)(void*))
{
	if ((NULL == arr) || (NULL == print_call_back))
	{
		return;
	}
	else
	{
		for (int i = 0; (i < arr->size) && (NULL != arr->array[i]); i++)
		{
			print_call_back(arr->array[i]);
		}
	}
}

