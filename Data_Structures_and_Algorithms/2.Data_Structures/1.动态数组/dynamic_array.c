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
 *  函数原型：struct dync_arr *dynamic_array_init(unsigned int number)
 *  函数功能：动态数组初始化
 *  函数参数：number 设置初始容量 capacity 的大小
 *  返 回 值：正常返回数组首地址的指针； 异常，如动态内存分配失败返回 NULL
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
 */

struct dync_arr *dynamic_array_init(unsigned int number)
{
	struct dync_arr *arr_ptr = (struct dync_arr *)malloc(sizeof(struct dync_arr));       /*  为结构体申请内存空间  */
	if (NULL == arr_ptr)
	{
		return NULL;                                                                     /*  动态内存分配失败  */
	}
	else
	{
		memset(arr_ptr, 0, sizeof(struct dync_arr));                                     /*  新开辟的内存空间清零  */
		arr_ptr->addr_ptr = (int *)malloc((sizeof(int)*number));                         /*  为数组申请内存空间，真正存放数据的内存空间  */
		if (NULL == arr_ptr->addr_ptr)
		{
			return NULL;
		}
		else
		{
			memset(arr_ptr->addr_ptr, 0, (sizeof(int)*number));
			arr_ptr->size = 0;                                                           /*  初始化阶段数组未存放任何数组  */
			arr_ptr->capacity = number;                                                  /*  设置动态数组默认的最大容量  */
			return arr_ptr;
		}
	}
	return NULL;
}


/*
 *  函数原型：int dynamic_array_insert(struct dync_arr *arr, int value, unsigned char multiple)
 *  函数功能：动态数组插入元素
 *  函数参数：arr 指向动态数组首地址的指针，插入元素的值； multiple 如果容量不足，则新分配空间的大小，新开辟原来的 multiple 倍空间
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1，动态空间申请失败返回-2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：multiple = 2
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
				return -2;                                                               /*  动态空间申请失败，直接返回  */
			}
			else
			{
				memset(new_ptr, 0, (sizeof(int)*arr->capacity*multiple));                /*  新开辟的内存空间清零  */
				memcpy(new_ptr, arr->addr_ptr, (sizeof(int)*arr->capacity));             /*  拷贝数据到新内存空间  */
				free(arr->addr_ptr);                                                     /*  释放久内存空间  */
				arr->addr_ptr = new_ptr;
				arr->capacity = arr->capacity * 2;                                       /*  更新动态数组的容量  */
			}
		}
		arr->addr_ptr[arr->size] = value;                                                /*  插入元素  */
		arr->size++;
	}
	return 0;
}


/*
 *  函数原型：int dynamic_array_pos_remove(struct dync_arr *arr, unsigned int pos)
 *  函数功能：动态数组删除元素，根据位置
 *  函数参数：arr 指向动态数组首地址的指针； pos 删除元素的位置值 pos < size
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：multiple = 2
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
 *  函数原型：int dynamic_array_value_remove(struct dync_arr *arr, int value)
 *  函数功能：动态数组删除元素，根据元素值
 *  函数参数：arr 指向动态数组首地址的指针； value 删除元素的值
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1；元素查找失败返回-2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：multiple = 2
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
 *  函数原型：int dynamic_array_search(struct dync_arr *arr, int value, unsigned int *ret_pos)
 *  函数功能：动态数组查找元素
 *  函数参数：arr 指向动态数组首地址的指针； value 查找元素的值； *ret_pos 指针用于返回查找元素的位置值
 *  返 回 值：正常返回0； 函数传参错误返回-1； 查找失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：multiple = 2
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
 *  函数原型：int dynamic_array_clear(struct dync_arr *arr)
 *  函数功能：清空动态数组
 *  函数参数：arr 指向动态数组首地址的指针
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int get_dynamic_array_value(struct dync_arr *arr, unsigned int pos, int *ret_val)
 *  函数功能：获取动态数组，根据位置查找值
 *  函数参数：arr 指向动态数组首地址的指针； pos 某元素的位置值；*ret_val 指针用于返回获取动态数组某位置元素的值
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int get_dynamic_array_capacity(struct dync_arr *arr, unsigned int *ret_capt)
 *  函数功能：获取动态数组容量
 *  函数参数：arr 指向动态数组首地址的指针；ret_capt 指针用于返回动态数组的容量
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int get_dynamic_array_size(struct dync_arr *arr, unsigned int *ret_size)
 *  函数功能：获取动态数组元素个数
 *  函数参数：arr 指向动态数组首地址的指针； *ret_size 指针用于返回获取到的动态数组数组元素个数
 *  返 回 值：正常返回0； 异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int dynamic_array_destroy(struct dync_arr *arr)
 *  函数功能：动态数组销毁
 *  函数参数：arr 指向动态数组首地址的指针
 *  返 回 值：正常返回0，异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
 *  函数原型：int dynamic_array_print(struct dync_arr *arr)
 *  函数功能：打印动态数组的元素
 *  函数参数：arr 指向动态数组首地址的指针
 *  返 回 值：正常返回0，异常，如函数传参错误返回-1
 *  版    本：V1.2.0
 *  时    间：2021-9-10
 *  备    注：无
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
