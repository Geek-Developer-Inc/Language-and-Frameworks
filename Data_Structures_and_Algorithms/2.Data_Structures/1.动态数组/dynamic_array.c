/*
 *  动态数组(Dynamic array)
 *  SPDX-License-Identifier: GPL-2.0
 *  dynamic_array.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"


/*  
 *  函数原型：int dynamic_array_create(int capacit, struct dynamic_array** ret_array)
 *  函数功能：创建动态数组
 *  函数参数：capacit 设置动态数组的初始容量，capacit > 0； **ret_array 返回动态数组首地址
 *  返 回 值：正常返回 0； 传入参数有误返回 -1； 动态内存分配失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：capacit 的值要大于 0
 */

int dynamic_array_create(int capacit, struct dynamic_array** ret_array)
{
	if (NULL == ret_array)
	{
		return -1;
	}
	else
	{
		*ret_array = (struct dynamic_array *)malloc(sizeof(struct dynamic_array));       /*  为结构体申请内存空间  */
		if (NULL == *ret_array)
		{
			return -2;/*  动态内存分配失败  */
		}
		else
		{
			memset(*ret_array, 0, sizeof(struct dynamic_array));                         /*  新开辟的内存空间清零  */
			(*ret_array)->size = 0;                                                      /*  初始化阶段数组未存放任何数组  */
			if (capacit <= 0)
			{
				capacit = 10;
			}
			(*ret_array)->capacity = capacit;                                            /*  设置动态数组默认的最大容量  */
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
 *  函数原型：int dynamic_array_insert(struct dynamic_array* arr, int pos, void* arr_value)
 *  函数功能：向动态数组插入元素
 *  函数参数：*arr 指向动态数组首地址的指针， pos 插入的位置，头插或尾插； *arr_value 赋给插入元素的值
 *  返 回 值：正常返回 0； 传入参数有误返回 -1； 动态内存分配失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
			pos = arr->size;                                                             /*  设置默认为尾插法  */
		}
		if (arr->size >= arr->capacity)
		{
			int new_capact = (arr->capacity) * 2;
			void** new_ptr = malloc(sizeof(void*) * new_capact);
			if (NULL == new_ptr)
			{
				return -2;                                                               /*  动态空间申请失败，直接返回  */
			}
			else
			{
				memset(new_ptr, 0, (sizeof(void*) * new_capact));                        /*  新开辟的内存空间清零  */
				memcpy(new_ptr, arr->array, sizeof(void*)*(arr->capacity));              /*  拷贝数据到新内存空间  */
				free(arr->array);                                                        /*  释放旧内存空间  */
				arr->array = new_ptr;
				arr->capacity = new_capact;                                              /*  更新动态数组的容量  */
			}
		}
		for (int i = arr->size - 1; (i >= pos) && (NULL != arr->array[i]); i--)          /*  寻找插入的位置  */
		{
			arr->array[i + 1] = arr->array[i];
		}
		arr->array[pos] = arr_value;                                                     /*  插入元素  */
		arr->size++;
	}
	return 0;
}


/*
 *  函数原型：int dynamic_array_by_pos_remove(struct dynamic_array* arr, int pos)
 *  函数功能：动态数组删除元素，根据位置
 *  函数参数：*arr 指向动态数组首地址的指针； pos 删除元素的位置值 pos < size 且 pos >= 0
 *  返 回 值：正常返回 0； 函数传参错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int dynamic_array_by_value_remove(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*))
 *  函数功能：根据元素值删除动态数组的元素
 *  函数参数：*arr 指向动态数组首地址的指针； *value 要删除元素的值； *compare_call_back 对比回调函数
 *  返 回 值：正常返回0； 函数传参错误返回-1； 元素查找失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：*compare_call_back 元素对比回调函数须自行实现，如：int compare_call_back(void* value1, void* value2) 相等返回 1
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
 *  函数原型：int dynamic_array_for_earch(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*), int* ret_pos)
 *  函数功能：动态数组查找元素，数组的遍历
 *  函数参数：*arr 指向动态数组首地址的指针； *value 查找元素的值； *ret_pos 指针用于返回查找元素的位置值
 *  返 回 值：正常返回0； 函数传参错误返回-1； 查找失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：compare_call_back 元素对比回调函数须自行实现，如：int compare_call_back(void* value1, void* value2) 相等返回 1
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
 *  函数原型：void dynamic_array_clear(struct dynamic_array* arr)
 *  函数功能：清空动态数组的元素
 *  函数参数：*arr 指向动态数组首地址的指针
 *  返 回 值：无
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int dynamic_array_get_value(struct dynamic_array* arr, int pos, void** ret_value)
 *  函数功能：获取动态数组，根据位置查找值
 *  函数参数：*arr 指向动态数组首地址的指针； pos 某元素的位置值； **ret_value 指针用于返回获取动态数组某位置元素的值
 *  返 回 值：正常返回 0； 函数传参错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int dynamic_array_get_capacity(struct dynamic_array* arr, int* ret_capacity)
 *  函数功能：获取动态数组容量值
 *  函数参数：*arr 指向动态数组首地址的指针； *ret_capacity 指针用于返回动态数组的容量
 *  返 回 值：正常返回 0； 函数传参错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int dynamic_array_get_size(struct dynamic_array* arr, int* ret_size)
 *  函数功能：获取动态数组的元素个数
 *  函数参数：*arr 指向动态数组首地址的指针； *ret_size 指针用于返回获取到的动态数组数组元素个数
 *  返 回 值：正常返回 0； 函数传参错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：void dynamic_array_destroy(struct dynamic_array* arr)
 *  函数功能：销毁动态数组
 *  函数参数：*arr 指向动态数组首地址的指针
 *  返 回 值：无
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：void dynamic_array_print_value(struct dynamic_array *arr, void(*print_call_back)(void*))
 *  函数功能：打印动态数组的元素值
 *  函数参数：*arr 指向动态数组首地址的指针； *print_call_back 打印回调函数
 *  返 回 值：无
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：*print_call_back 回调函数须自行实现，如：void print_call_back_value(void *value)
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

