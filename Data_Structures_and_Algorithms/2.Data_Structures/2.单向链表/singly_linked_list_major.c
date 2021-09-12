/*
 *  ����������ҵ��Ķ���(Singly linked list major)
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list_major.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list_major.h"


/*  
 *  ����ԭ�ͣ�struct link_list_major *link_list_major_init(void)
 *  �������ܣ������ʼ�������ĺ�������
 *  ������������
 *  �� �� ֵ������������ͷ�ڵ�ָ�룻 �綯̬�ڴ����ʧ�ܷ��� NULL
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��������ͷ�ڵ㣬ֻ��������ڵ�
 */

struct link_list_major *link_list_major_init(void)
{
	struct link_list_major *head_ptr = (struct link_list_major *)malloc(sizeof(struct link_list_major));
	if (NULL == head_ptr)
	{
		return NULL;
	}
	else
	{
		memset(head_ptr, 0, sizeof(struct link_list_major));
		head_ptr->size = 0;
		head_ptr->head.next = NULL;
	}
	return head_ptr;
}


/*
 *  ����ԭ�ͣ�struct link_list_major *link_list_major_init(void)
 *  �������ܣ��������ڵ�����ĺ�������
 *  ����������*list_ptr �����׵�ַ�� list_pos ͷ�巨��β�巨���ƣ� *value ����ڵ��������
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��������ʵ�ʽڵ㣬�ڵ����ⲿ����
 */

int link_list_major_insert(struct link_list_major *list_ptr, unsigned int list_pos, struct link_list_major_node *value)
{
	if ((NULL == list_ptr) || (NULL == value))
	{
		return -1;
	}
	else
	{
		if (list_pos > list_ptr->size)
		{
			/*  ǿ��β�巨  */
			list_pos = list_ptr->size;
		}
		/*  Ѱ��Ҫ����ڵ��λ��  */
		struct link_list_major_node *current_ptr = &(list_ptr->head);
		for (unsigned int i = 0; (i < list_pos) && (NULL != current_ptr); i++)
		{
			current_ptr = current_ptr->next;
		}
		/*  ����ڵ�  */
		value->next = current_ptr->next;
		current_ptr->next = value;

		list_ptr->size++;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos)
 *  �������ܣ�����λ��ɾ������ڵ�ĺ�������
 *  ����������list_ptr �����׵�ַ�� list_pos Ҫɾ���ڵ��λ��
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע�������ͷŽڵ�ռ�
 */

int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos)
{
	if ((NULL == list_ptr) || (list_pos >= list_ptr->size))
	{
		return -1;
	}
	else
	{
		struct link_list_major_node *current_ptr = &(list_ptr->head);
		for (unsigned int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}
		current_ptr->next = current_ptr->next->next;

		list_ptr->size--;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos)
 *  �������ܣ�������ҽڵ�����ĺ�������
 *  ����������list_ptr �����׵�ַ�� *list_value Ҫ���ҽڵ�������� compare ���һص������� *ret_val ���ز��ҵ��ڵ��λ�ã�-1 ����ʧ��
 *  �� �� ֵ���������� 0�� ����������󷵻� -1�� ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע�����Զ�����һص�����
 */

int link_list_major_search(struct link_list_major *list_ptr, struct link_list_major_node *list_value, comparre_type_def compare, int *ret_val)
{
	if ((NULL == list_ptr) || (NULL == list_value) || (ret_val == NULL))
	{
		return -1;
	}
	else
	{
		*ret_val = -1;
		int flage = 0;
		struct link_list_major_node *current_ptr = list_ptr->head.next;
		while (NULL != current_ptr)
		{
			if (0 == compare(current_ptr, list_value))
			{
				*ret_val = flage;
				return 0;
			}
			current_ptr = current_ptr->next;
			flage++;
		}

	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int link_list_major_get_size(struct link_list_major *list_ptr, unsigned int *ret_len)
 *  �������ܣ���ȡ����ڵ�����ĺ�������
 *  ����������list_ptr �����׵�ַ�� *ret_len ���ز��ҵ��ڵ����
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int link_list_major_get_size(struct link_list_major *list_ptr, unsigned int *ret_len)
{
	if ((NULL == list_ptr) || (NULL == ret_len))
	{
		return -1;
	}
	else
	{
		*ret_len = list_ptr->size;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_major_destroy(struct link_list_major *list_ptr)
 *  �������ܣ���������ĺ�������
 *  ����������list_ptr �����׵�ַ
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int link_list_major_destroy(struct link_list_major *list_ptr)
{
	if (NULL == list_ptr)
	{
		return -1;
	}
	else
	{
		free(list_ptr);
		list_ptr = NULL;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int link_list_major_print(struct link_list_major *list_ptr, pri_type_def call_back)
 *  �������ܣ���ӡ�������ݵĺ�������
 *  ����������list_ptr �����׵�ַ�� call_back �ص�����
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����Ҫ�Զ���ص����� call_back
 */

int link_list_major_print(struct link_list_major *list_ptr, pri_type_def call_back)
{
	if (NULL == list_ptr)
	{
		return -1;
	}
	else
	{
		struct link_list_major_node *current_ptr = list_ptr->head.next;

		while (NULL != current_ptr)
		{
			call_back(current_ptr);
			current_ptr = current_ptr->next;
		}
	}
	return 0;
}
