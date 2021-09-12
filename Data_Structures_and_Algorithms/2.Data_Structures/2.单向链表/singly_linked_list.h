/*
 *  �������������(Singly linked list)��ͷ�ļ�
 *  SPDX-License-Identifier: GPL-2.0  
 *  singly_linked_list.h
 */


#ifndef  __SINGLY_LINKED_LIST_H
#define  __SINGLY_LINKED_LIST_H


/*
 *  ��������ڵ� link_list
 *  void *data ����ڵ��������ָ���κ����͵�����
 *  struct link_list_node *next ����ڵ��ָ����
 */

struct link_list_node
{
	void *data;                                                                            /*  ������ͨ�ö���Ϊ void *data  */
	struct link_list_node *next;                                                           /*  ָ����  */
};


/*
 *  ��������ṹ�� struct link_list
 *  struct link_list_node *head ָ������ͷ�ڵ��ָ��
 *  unsigned int size ����ڵ�ĸ���
 */

struct link_list
{
	struct link_list_node *head;                                                           /*  ָ������ͷ�ڵ��ָ��  */
	unsigned int size;                                                                     /*  ����ڵ�ĸ��� = ������  */
};


/*  ���������غ�������������ĳ�ʼ�������롢ɾ�������ҡ��޸� ������  */

struct link_list *link_list_init(void);                                                    /*  �����ʼ�������ĺ�������  */
int link_list_insert(struct link_list *list_ptr, unsigned int list_pos, void *value);      /*  �������ڵ�����ĺ�������  */
int link_list_pos_remove(struct link_list *list_ptr, unsigned int list_pos);               /*  ����λ��ɾ������ڵ�ĺ�������  */
int link_list_search(struct link_list *list_ptr, void *list_value, int(*call_back)(void*, void*), int *ret_val);         /*  ������ҽڵ�����ĺ�������  */
int link_list_modify(struct link_list *list_ptr, unsigned int list_pos, void *value);      /*  �����޸Ĳ����ĺ�������  */
int link_list_get_size(struct link_list *list_ptr, unsigned int *ret_len);                 /*  ��ȡ����ڵ�����ĺ�������  */
int link_list_destroy(struct link_list *list_ptr);                                         /*  ��������  */
int link_list_print(struct link_list *list_ptr,void (*call_back)(void*));                  /*  ��ӡ��������  */

/*  ���������һ���ڵ�  */
void *link_list_get_first(struct link_list *list_ptr);

#endif // ! __SINGLY_LINKED_LIST_H
