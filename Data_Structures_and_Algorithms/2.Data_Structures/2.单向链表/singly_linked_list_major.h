/*
 *  ����������ҵ�������(Singly linked list major)������ Linux �ں�����ͷ�ļ�
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list_major.h
 */


#ifndef  __SINGLY_LINKED_LIST_MAJOR_H
#define  __SINGLY_LINKED_LIST_MAJOR_H


/*
 *  ��������ڵ� struct singly_linked_list_major_node
 *  ���� Linux �ں�����ֻ����ָ����
 *  struct singly_linked_list_major_node* next ����ڵ��ָ����
 */

struct singly_linked_list_major_node
{
	struct singly_linked_list_major_node* next;    /*  ָ����  */
};


/*
 *  ��������ṹ�� struct singly_linked_list_major
 *  struct singly_linked_list_major_node head ָ������ͷ�ڵ��ָ��
 *  int size ����ڵ�ĸ���
 */

struct singly_linked_list_major
{
	struct singly_linked_list_major_node head;     /*  ָ������ͷ�ڵ��ָ��  */
	int size;                                      /*  ����ڵ�ĸ��� = ������  */
};


/*  ���������غ�������������ĳ�ʼ�������롢ɾ�������ҡ��޸� ������  */

/*  ����������������  */
int singly_linked_list_major_create(struct singly_linked_list_major** list_haed);

/*  �������ڵ�����ĺ�������  */
int singly_linked_list_major_insert(struct singly_linked_list_major* list_haed, int list_pos, struct singly_linked_list_major_node* list_value);

/*  ����λ��ɾ������ڵ�ĺ�������  */
int singly_linked_list_major_by_pos_remove(struct singly_linked_list_major* list_haed, int list_pos);

/*  ����ֵɾ������ڵ�ĺ�������  */
int intsingly_linked_list_major_by_value_remove(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*));

/*  ������ҽڵ�����ĺ�������  */
int singly_linked_list_major_for_earch(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*), int* ret_value);


/*  ��ȡ����ڵ�����ĺ�������  */
int singly_linked_list_major_get_size(struct singly_linked_list_major* list_haed, int* ret_size);

/*  ���������һ���ڵ�  */
int singly_linked_list_major_get_front(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node** ret_value);

/*  ��������������  */
int singly_linked_list_major_destroy(struct singly_linked_list_major* list_haed);

/*  ��ӡ��������  */
int singly_linked_list_major_print_value(struct singly_linked_list_major* list_haed, void(*print_call_back)(struct singly_linked_list_major_node*));


#endif    /*  END __SINGLY_LINKED_LIST_MAJOR_H  */
