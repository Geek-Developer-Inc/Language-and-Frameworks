/*
 *  �������������(Singly linked list)��ͷ�ļ�
 *  SPDX-License-Identifier: GPL-2.0  
 *  singly_linked_list.h
 */


#ifndef __SINGLY_LINKED_LIST_H
#define __SINGLY_LINKED_LIST_H


/*
 *  ��������ڵ� struct singly_linked_list_node
 *  void *data ����ڵ��������ָ���κ����͵�����
 *  struct singly_linked_list_node* next ����ڵ��ָ����
 */

struct singly_linked_list_node
{
	void* data;                              /*  �����������ͨ�ö���Ϊ void *data  */
	struct singly_linked_list_node* next;    /*  �����ָ����  */
};


/*
 *  ��������ṹ�� struct singly_linked_list
 *  struct singly_linked_list_node* head ָ������ͷ�ڵ��ָ��
 *  int size ����ڵ�ĸ���
 */

struct singly_linked_list
{
	struct singly_linked_list_node* head;    /*  ָ������ͷ�ڵ��ָ��  */
	int size;                                /*  ����ڵ�ĸ��� = ������  */
};


/*  ���������غ�������������ĳ�ʼ�������롢ɾ�������ҡ��޸� ������  */

/*  ����������������  */
int singly_linked_list_create(struct singly_linked_list** list_haed);

/*  �������ڵ�����ĺ�������  */
int singly_linked_list_insert(struct singly_linked_list* list_haed, int list_pos, void* list_value);

/*  ����λ��ɾ������ڵ�ĺ�������  */
int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos);

/*  ����ֵɾ������ڵ�ĺ�������  */
int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*));

/*  ������ҽڵ�����ĺ�������  */
int singly_linked_list_for_earch(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), int* ret_value);

/*  �����޸Ĳ����ĺ�������  */
int singly_linked_list_modify(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), void* new_value);

/*  ��ȡ����ڵ�����ĺ�������  */
int singly_linked_list_get_size(struct singly_linked_list* list_haed, int* ret_size);

/*  ���������һ���ڵ�  */
int singly_linked_list_get_front(struct singly_linked_list* list_haed, void** ret_value);

/*  ��������������  */
int singly_linked_list_destroy(struct singly_linked_list* list_haed);

/*  ��ӡ��������  */
int singly_linked_list_print_value(struct singly_linked_list* list_haed, void(*print_call_back)(void*));


#endif    /*  END __SINGLY_LINKED_LIST_H  */
