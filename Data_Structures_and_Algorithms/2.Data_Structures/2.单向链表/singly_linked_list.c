/*
 *  ����������(Singly linked list)
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"


/*  
 *  ����ԭ�ͣ�struct link_list *link_list_init(void)
 *  �������ܣ������ʼ�������ĺ�������
 *  ������������
 *  �� �� ֵ������������ͷ�ڵ�ָ�룻 �綯̬�ڴ����ʧ�ܷ��� NULL
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��ͷ�ڵ������򲻱�������
 */

struct link_list *link_list_init(void)
{
    struct link_list *head_ptr = (struct link_list *)malloc(sizeof(struct link_list));                                  /*  Ϊ����ṹ�� struct link_list �����ڴ�ռ�  */
	if (NULL == head_ptr)
	{
	    return NULL;                                                                                                    /*  ��̬�ڴ����ʧ��  */
	}
	else
	{
		memset(head_ptr, 0, sizeof(struct link_list));                                                                  /*  ������ɹ����ڴ�ռ�����  */
		head_ptr->size = 0;
		head_ptr->head = (struct link_list_node *)malloc(sizeof(struct link_list_node));                                /*  ����ͷ�ڵ㣬Ϊͷ�ڵ������ڴ�ռ�  */
		if (NULL == head_ptr->head)
		{
			return NULL;
		}
		else
		{
			memset(head_ptr->head, 0, sizeof(struct link_list_node));
			head_ptr->head->data = NULL;                                                                                   /*  ͷ�ڵ㲻�����κ����ݣ���ͷ�ڵ�������Ϊ��  */
			head_ptr->head->next = NULL;                                                                                /*  ͷ�ڵ��ָ������ʱָ��NULL  */
		}
	}
	return head_ptr;                                                                                                    /*  ��������ṹ��ָ��  */
}


/*
 *  ����ԭ�ͣ�int link_list_insert(struct link_list *list_ptr, unsigned int list_pos, void *value)
 *  �������ܣ��������ڵ�����ĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ�룻 list_pos Ҫ�����λ��,����ͷ�巨����β�巨�� value �������ֵ
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1���綯̬�ڴ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��list_pos = 0������ͷ�巨�� list_pos ����ܳ��� list_ptr->size
 *  ��    ����(1) �����½ڵ㲢Ϊ������ֵ���½ڵ��ָ������ʱָ�� NULL
 *            (2) �ҵ�Ҫ����λ�õĽڵ�
 *            (3) ���ڵ���벢�Խ�ǰ��Ľڵ�
 */

int link_list_insert(struct link_list *list_ptr, unsigned int list_pos, void *value)
{
	if ((NULL == list_ptr) || (NULL == value))
	{
		return -1;
	}
	else
	{
		if (list_pos > list_ptr->size)                                                                                  /*  list_pos ҪС�ڻ���� size��list_pos = 0 ����ͷ�巨��list_pos = size ����β�巨  */
		{
			list_pos = list_ptr->size;
		}
		else
		{
			struct link_list_node *new_node_ptr = (struct link_list_node *)malloc(sizeof(struct link_list_node));       /*  ����һ���½ڵ㣬��Ϊ����������ֵ��ָ����ָ�� NULL  */
			if (NULL == new_node_ptr)
			{
				return -2;
			}
			else
			{
				memset(new_node_ptr, 0, sizeof(struct link_list_node));
				new_node_ptr->data = value;                                                                             /*  Ϊ�½ڵ��������ֵ  */
				new_node_ptr->next = NULL;                                                                              /*  �½ڵ��ָ������ʱָ�� NULL  */

				struct link_list_node *current_ptr = list_ptr->head;                                                    /*  current_ptr ����ָ�룬Ѱ���½ڵ�Ĳ���λ��  */
				for (unsigned int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
				{
					current_ptr = current_ptr->next;
				}

				new_node_ptr->next = current_ptr->next;                                                                 /*  �½ڵ�������  */
				current_ptr->next = new_node_ptr;
				
				list_ptr->size++;
			}
		}
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_pos_remove(struct link_list *list_ptr, unsigned int list_pos)
 *  �������ܣ�����λ��ɾ������ڵ�ĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ�룻 list_pos Ҫɾ���ڵ��λ��
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int link_list_pos_remove(struct link_list *list_ptr, unsigned int list_pos)
{
	if ((NULL == list_ptr) || (list_pos >= list_ptr->size))
	{
		return -1;
	}
	else
	{
		struct link_list_node *current_ptr = list_ptr->head;                                                            /*  ����Ҫɾ���ڵ��ǰһ���ڵ�  */
		for (unsigned int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}

		struct link_list_node *temp_ptr = current_ptr->next;                                                            /*  �����ɾ���Ľڵ�  */
		current_ptr->next = temp_ptr->next;
		free(temp_ptr);
		temp_ptr = NULL;
		
		list_ptr->size--;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_search(struct link_list *list_ptr, struct link_list_node *list_value, comparre_type_def call_back, int *ret_val)
 *  �������ܣ�������ҽڵ�����ĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ�룻 *list_value Ҫ���ҽڵ���������ֵ�� *ret_val ���ز��ҵ��Ľ����-1 ��ʾ����ʧ��
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1�� Ҫ���ҽڵ�Ľڵ㲻���ڷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��call_back �ص��������Լ�ʵ��
 */

int link_list_search(struct link_list *list_ptr, void *list_value, int(*call_back)(void*, void*), int *ret_val)
{
	if ((NULL == list_ptr) || (NULL == list_value) || (NULL == ret_val))
	{
		return -1;
	}
	else
	{
		unsigned int count = 0;
		*ret_val = -1;
		struct link_list_node *current_ptr = (list_ptr->head)->next;                                                    /*  ͷ�ڵ㲻����ʵ������  */
		while (NULL != current_ptr)                                                                                     /*  ��������  */
		{
			if (0 == call_back(current_ptr->data, list_value))
			{
				*ret_val = count;
				return 0;
			}
			count++;
			current_ptr = current_ptr->next;                                                                            /*  �ڵ�����ƶ�������ж�  */
		}
		ret_val = NULL;
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int link_list_modify(struct link_list *list_ptr, unsigned int list_pos, void *value)
 *  �������ܣ������޸Ĳ����ĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ�룻 list_pos Ҫ�޸Ľڵ���������ֵ�� *value ���������ֵ
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int link_list_modify(struct link_list *list_ptr, unsigned int list_pos, void *value)
{
	if ((NULL == list_ptr) || (list_pos >= list_ptr->size) || (NULL == value))
	{
		return -1;
	}
	else
	{
		struct link_list_node *current_ptr = (list_ptr->head)->next;
		for (unsigned int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}
		current_ptr->data = value;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_search(struct link_list *list_ptr, int list_value, int *ret_val)
 *  �������ܣ���ȡ����ڵ�����ĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ�룻 ret_len ���ز��ҵ�������ڵ����ֵ
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int link_list_get_size(struct link_list *list_ptr, unsigned int *ret_len)
{
	if ((NULL == list_ptr) || (NULL == ret_len))
	{
		ret_len = NULL;
		return -1;
	}
	else
	{
		*ret_len = list_ptr->size;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_destroy(struct link_list *list_ptr)
 *  �������ܣ���������ĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ��
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int link_list_destroy(struct link_list *list_ptr)
{
	if ((NULL == list_ptr) || (list_ptr->head == NULL))
	{
		return -1;
	}
	else
	{
		struct link_list_node *current_ptr = list_ptr->head;
		struct link_list_node *temp_ptr = current_ptr->next;
		while (NULL != current_ptr)                                                                                     /*  ����ɾ���ڵ�  */
		{
			temp_ptr = current_ptr->next;                                                                               /*  �ȱ���ýڵ�ָ�����һ���ڵ�  */
			free(current_ptr);
			current_ptr = temp_ptr;
		}
		list_ptr->size = 0;
		free(list_ptr);
		current_ptr = NULL;
		temp_ptr = NULL;
		list_ptr = NULL;	
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_print(struct link_list *list_ptr, print_type_def call_back)
 *  �������ܣ���ӡ��������ݵĺ�������
 *  ����������*list_ptr ָ������ͷ�ڵ��ָ�룻 call_back ��ӡ�ص�����
 *  �� �� ֵ�������� 0�� �쳣����������������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����ӡ�ص��������Զ���
 */

int link_list_print(struct link_list *list_ptr, void(*call_back)(void*))
{
	if (NULL == list_ptr)
	{
		return -1;
	}
	else
	{
		struct link_list_node *current_ptr = (list_ptr->head)->next;
		while (NULL != current_ptr)
		{
			call_back(current_ptr->data);
			current_ptr = current_ptr->next;
		}
	}
	return 0;
}


/*  ���������һ���ڵ�  */
void *link_list_get_first(struct link_list *list_ptr)
{
	if (NULL == list_ptr)
	{
		return NULL;
	}
	return (list_ptr->head->next->data);
}
