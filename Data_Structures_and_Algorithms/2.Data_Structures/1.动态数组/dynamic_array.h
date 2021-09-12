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

struct dync_arr
{
	int*addr_ptr;                                                                                    /*  addr_ptr 指向动态数组存放数据的地址  */
	unsigned int size;                                                                               /*  当前实际存放的元素个数  */
	unsigned int capacity;                                                                           /*  容器当前最大能存放的元素个数  */
};


/*  对动态数组操作的函数声明  */
struct dync_arr *dynamic_array_init(unsigned int number);                                             /*  动态数组初始化  */
int dynamic_array_insert(struct dync_arr *arr, int value, unsigned char multiple);                    /*  动态数组插入元素  */
int dynamic_array_pos_remove(struct dync_arr *arr, unsigned int pos);                                 /*  动态数组删除元素，根据位置  */
int dynamic_array_value_remove(struct dync_arr *arr, int value);                                      /*  动态数组删除元素，根据元素值  */
int dynamic_array_search(struct dync_arr *arr, int value, unsigned int *ret_pos);                     /*  动态数组查找元素  */
int dynamic_array_clear(struct dync_arr *arr);                                                        /*  清空动态数组  */
int get_dynamic_array_value(struct dync_arr *arr, unsigned int pos, int *ret_val);                    /*  获取动态数组某位置元素的值，根据位置查找值  */
int get_dynamic_array_capacity(struct dync_arr *arr, unsigned int *ret_capt);                         /*  获取动态数组容量  */
int get_dynamic_array_size(struct dync_arr *arr, unsigned int *ret_size);                             /*  获取动态数组元素个数  */
int dynamic_array_destroy(struct dync_arr *arr);                                                      /*  动态数组销毁  */
int dynamic_array_print(struct dync_arr *arr);                                                        /*  打印动态数组的元素  */


#endif // END __DYNAMIC_ARRAY_H
