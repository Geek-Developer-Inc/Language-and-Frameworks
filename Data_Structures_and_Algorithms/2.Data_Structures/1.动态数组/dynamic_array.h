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

struct dync_arr
{
	int*addr_ptr;                                                                                    /*  addr_ptr ָ��̬���������ݵĵ�ַ  */
	unsigned int size;                                                                               /*  ��ǰʵ�ʴ�ŵ�Ԫ�ظ���  */
	unsigned int capacity;                                                                           /*  ������ǰ����ܴ�ŵ�Ԫ�ظ���  */
};


/*  �Զ�̬��������ĺ�������  */
struct dync_arr *dynamic_array_init(unsigned int number);                                             /*  ��̬�����ʼ��  */
int dynamic_array_insert(struct dync_arr *arr, int value, unsigned char multiple);                    /*  ��̬�������Ԫ��  */
int dynamic_array_pos_remove(struct dync_arr *arr, unsigned int pos);                                 /*  ��̬����ɾ��Ԫ�أ�����λ��  */
int dynamic_array_value_remove(struct dync_arr *arr, int value);                                      /*  ��̬����ɾ��Ԫ�أ�����Ԫ��ֵ  */
int dynamic_array_search(struct dync_arr *arr, int value, unsigned int *ret_pos);                     /*  ��̬�������Ԫ��  */
int dynamic_array_clear(struct dync_arr *arr);                                                        /*  ��ն�̬����  */
int get_dynamic_array_value(struct dync_arr *arr, unsigned int pos, int *ret_val);                    /*  ��ȡ��̬����ĳλ��Ԫ�ص�ֵ������λ�ò���ֵ  */
int get_dynamic_array_capacity(struct dync_arr *arr, unsigned int *ret_capt);                         /*  ��ȡ��̬��������  */
int get_dynamic_array_size(struct dync_arr *arr, unsigned int *ret_size);                             /*  ��ȡ��̬����Ԫ�ظ���  */
int dynamic_array_destroy(struct dync_arr *arr);                                                      /*  ��̬��������  */
int dynamic_array_print(struct dync_arr *arr);                                                        /*  ��ӡ��̬�����Ԫ��  */


#endif // END __DYNAMIC_ARRAY_H
