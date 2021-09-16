/*
 *  ��̬����(Dynamic array)��ͷ�ļ�
 *  SPDX-License-Identifier: GPL-2.0
 *  dynamic_array.h
 */


#ifndef __DYNAMIC_ARRAY_H
#define __DYNAMIC_ARRAY_H


/*  
 *  ��̬�����ڴ棬��̬��������ռ�
 *  ���� capacity ��ʾ����ڴ�ռ�һ�����Դ�Ŷ��ٸ�Ԫ��
 *  size ��ʾ��ǰ������ʵ�ʴ�ŵ�Ԫ�ظ���
 */

struct dynamic_array
{
	void** array;                                                                                                          /*  array ָ��̬���������ݵĵ�ַ  */
	int size;                                                                                                              /*  ��ǰʵ�ʴ�ŵ�Ԫ�ظ���  */
	int capacity;                                                                                                          /*  ������ǰ����ܴ�ŵ�Ԫ�ظ���  */
};


/*  �Զ�̬��������ĺ�������  */
int dynamic_array_create(int capacit, struct dynamic_array** ret_array);                                                   /*  ��̬�����ʼ��  */
int dynamic_array_insert(struct dynamic_array* arr, int pos, void* arr_value);                                             /*  ��̬�������Ԫ��  */
int dynamic_array_by_pos_remove(struct dynamic_array* arr, int pos);                                                       /*  ��̬����ɾ��Ԫ�أ�����λ��  */
int dynamic_array_by_value_remove(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*));          /*  ��̬����ɾ��Ԫ�أ�����Ԫ��ֵ  */
int dynamic_array_for_earch(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*), int* ret_pos);  /*  ��̬����(����)����Ԫ��  */
void dynamic_array_clear(struct dynamic_array* arr);                                                                       /*  ��ն�̬����  */
int dynamic_array_get_value(struct dynamic_array* arr, int pos, void** ret_value);                                         /*  ��ȡ��̬����ĳλ��Ԫ�ص�ֵ������λ�ò���ֵ  */
int dynamic_array_get_capacity(struct dynamic_array* arr, int* ret_capacity);                                              /*  ��ȡ��̬��������  */
int dynamic_array_get_size(struct dynamic_array* arr, int* ret_size);                                                      /*  ��ȡ��̬����Ԫ�ظ���  */
void dynamic_array_destroy(struct dynamic_array* arr);                                                                     /*  ��̬��������  */
void dynamic_array_print_value(struct dynamic_array *arr, void(*print_call_back)(void*));                                  /*  ��ӡ��̬�����Ԫ��  */


#endif  /*  END __DYNAMIC_ARRAY_H  */
