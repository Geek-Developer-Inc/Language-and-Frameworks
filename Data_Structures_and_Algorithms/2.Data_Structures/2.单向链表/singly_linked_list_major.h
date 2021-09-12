/*
 *  ����������ҵ�������(Singly linked list major)������ Linux �ں�����ͷ�ļ�
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list_major.h
 */


#ifndef  __SINGLY_LINKED_LIST_MAJOR_H
#define  __SINGLY_LINKED_LIST_MAJOR_H


/*
 *  ��������ڵ� struct link_list_major_node
 *  ���� Linux �ں�����ֻ����ָ����
 *  struct link_list_major_node *next ����ڵ��ָ����
 */

struct link_list_major_node
{
	struct link_list_major_node *next;                                                                 /*  ָ����  */
};


/*
 *  ��������ṹ�� struct link_list_major
 *  struct link_list_major_node head ָ������ͷ�ڵ��ָ��
 *  unsigned int size ����ڵ�ĸ���
 */

struct link_list_major
{
	struct link_list_major_node head;                                                                  /*  ָ������ͷ�ڵ��ָ��  */
	unsigned int size;                                                                                 /*  ����ڵ�ĸ��� = ������  */
};


/*  ��������ָ�붨��  */
typedef void(*pri_type_def) (struct link_list_major_node*);


/*  �ȽϺ���ָ�붨��  */
typedef int(*comparre_type_def) (struct link_list_major_node*, struct link_list_major_node*);


/*  ���������غ�������������ĳ�ʼ�������롢ɾ�������ҡ��޸� ������  */

struct link_list_major *link_list_major_init(void);                                                    /*  �����ʼ�������ĺ�������  */
int link_list_major_insert(struct link_list_major *list_ptr, unsigned int list_pos, struct link_list_major_node *value);                         /*  �������ڵ�����ĺ�������  */
int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos);               /*  ����λ��ɾ������ڵ�ĺ�������  */
int link_list_major_search(struct link_list_major *list_ptr, struct link_list_major_node *list_value, comparre_type_def compare, int *ret_val);  /*  ������ҽڵ�����ĺ�������  */
int link_list_major_get_size(struct link_list_major *list_ptr, unsigned int *ret_len);                 /*  ��ȡ����ڵ�����ĺ�������  */
int link_list_major_destroy(struct link_list_major *list_ptr);                                         /*  ��������  */
int link_list_major_print(struct link_list_major *list_ptr, pri_type_def call_back);                   /*  ��ӡ��������  */


#endif // !__SINGLY_LINKED_LIST_MAJOR_H
