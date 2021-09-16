/*
 *  动态数组(Dynamic array)，头文件
 *  SPDX-License-Identifier: GPL-2.0
 *  dynamic_array.h
 */


#ifndef __DYNAMIC_ARRAY_H
#define __DYNAMIC_ARRAY_H


/*  
 *  动态增长内存，动态申请堆区空间
 *  容量 capacity 表示这块内存空间一共可以存放多少个元素
 *  size 表示当前数组中实际存放的元素个数
 */

struct dynamic_array
{
	void** array;                                                                                                          /*  array 指向动态数组存放数据的地址  */
	int size;                                                                                                              /*  当前实际存放的元素个数  */
	int capacity;                                                                                                          /*  容器当前最大能存放的元素个数  */
};


/*  对动态数组操作的函数声明  */
int dynamic_array_create(int capacit, struct dynamic_array** ret_array);                                                   /*  动态数组初始化  */
int dynamic_array_insert(struct dynamic_array* arr, int pos, void* arr_value);                                             /*  动态数组插入元素  */
int dynamic_array_by_pos_remove(struct dynamic_array* arr, int pos);                                                       /*  动态数组删除元素，根据位置  */
int dynamic_array_by_value_remove(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*));          /*  动态数组删除元素，根据元素值  */
int dynamic_array_for_earch(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*), int* ret_pos);  /*  动态数组(遍历)查找元素  */
void dynamic_array_clear(struct dynamic_array* arr);                                                                       /*  清空动态数组  */
int dynamic_array_get_value(struct dynamic_array* arr, int pos, void** ret_value);                                         /*  获取动态数组某位置元素的值，根据位置查找值  */
int dynamic_array_get_capacity(struct dynamic_array* arr, int* ret_capacity);                                              /*  获取动态数组容量  */
int dynamic_array_get_size(struct dynamic_array* arr, int* ret_size);                                                      /*  获取动态数组元素个数  */
void dynamic_array_destroy(struct dynamic_array* arr);                                                                     /*  动态数组销毁  */
void dynamic_array_print_value(struct dynamic_array *arr, void(*print_call_back)(void*));                                  /*  打印动态数组的元素  */


#endif  /*  END __DYNAMIC_ARRAY_H  */
