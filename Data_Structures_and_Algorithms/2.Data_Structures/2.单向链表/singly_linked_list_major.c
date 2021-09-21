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
 *  ����ԭ�ͣ�int singly_linked_list_major_create(struct singly_linked_list_major** list_haed)
 *  �������ܣ���������
 *  ����������** list_haed ���������ͷ�ڵ�ָ��
 *  �� �� ֵ�������ɹ����� 0�� ����������󷵻� -1�� ���䶯̬�ڴ�ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��������ͷ�ڵ㣬ֻ��������ڵ�
 */

int singly_linked_list_major_create(struct singly_linked_list_major** list_haed)
{
	if (NULL == list_haed)
	{
		return -1;
	}
	else 
	{
		*list_haed = (struct singly_linked_list_major *)malloc(sizeof(struct singly_linked_list_major));
		if (NULL == (*list_haed))
		{
			return -2;
		}
		else
		{
			memset((*list_haed), 0, sizeof(struct singly_linked_list_major));
			(*list_haed)->size = 0;
			(*list_haed)->head.next = NULL;
		}
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_major_insert(struct singly_linked_list_major* list_haed, int list_pos, struct singly_linked_list_major_node* list_value)
 *  �������ܣ����������ڵ�
 *  ����������*list_haed �����׵�ַ�� list_pos ͷ�巨��β�巨���ƣ� *list_value ����ڵ��������
 *  �� �� ֵ���ڵ����ɹ����� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��������ʵ�ʽڵ㣬�ڵ����ⲿ����
 */

int singly_linked_list_major_insert(struct singly_linked_list_major* list_haed, int list_pos, struct singly_linked_list_major_node* list_value)
{
	if ((NULL == list_haed) || (NULL == list_value))
	{
		return -1;
	}
	else
	{
		if ((list_pos < 0) || (list_pos > list_haed->size))
		{
			/*  ǿ��β�巨  */
			list_pos = list_haed->size;
		}
		/*  Ѱ��Ҫ����ڵ��λ��  */
		struct singly_linked_list_major_node* current_ptr = &(list_haed->head);
		for (int i = 0; (i < list_pos) && (NULL != current_ptr); i++)
		{
			current_ptr = current_ptr->next;
		}
		/*  ����ڵ�  */
		list_value->next = current_ptr->next;
		current_ptr->next = list_value;
		list_haed->size++;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_major_by_pos_remove(struct singly_linked_list_major* list_haed, int list_pos)
 *  �������ܣ�����λ��ɾ������ڵ�ĺ�������
 *  ����������*list_haed �����׵�ַ�� list_pos Ҫɾ���ڵ��λ��
 *  �� �� ֵ��ɾ���ɹ����� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע�������ͷŽڵ�ռ�
 */

int singly_linked_list_major_by_pos_remove(struct singly_linked_list_major* list_haed, int list_pos)
{
	if ((NULL == list_haed) || (list_pos < 0) || (list_pos >= list_haed->size))
	{
		return -1;
	}
	else
	{
		struct singly_linked_list_major_node* current_ptr = &(list_haed->head);
		for (int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}
		current_ptr->next = current_ptr->next->next;

		list_haed->size--;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int intsingly_linked_list_major_by_value_remove(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*))
 *  �������ܣ�����ֵɾ������ڵ�ĺ�������
 *  ����������*list_haed �����׵�ַ�� *list_value Ҫɾ���ڵ��ֵ�� compare_call_back �Ƚϻص�����
 *  �� �� ֵ��ɾ���ɹ����� 0�� ����������󷵻� -1�� ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע�����Զ�����һص�����  int compare_call_back(singly_linked_list_major_node* value1, singly_linked_list_major_node* value2)  ���� 0
 */

int intsingly_linked_list_major_by_value_remove(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*))
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back))
	{
		return -1;
	}
	else
	{
		struct singly_linked_list_major_node* current_ptr = list_haed->head.next;
		for (int i = 0; (i < list_haed->size) && (NULL != current_ptr); i++)
		{
			if (0 == compare_call_back(current_ptr, list_value))
			{
				singly_linked_list_major_by_pos_remove(list_haed, i);
				return 0;
			}
			current_ptr = current_ptr->next;
		}
	}
	return -2;
}

/*
 *  ����ԭ�ͣ�int singly_linked_list_major_for_earch(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*), int* ret_value)
 *  �������ܣ�������ҽڵ�����ĺ�������
 *  ����������*list_haed �����׵�ַ�� *list_value Ҫ���ҽڵ�������� compare_call_back ���һص������� *ret_value ���ز��ҵ��ڵ��λ�ã�-1 ����ʧ��
 *  �� �� ֵ���������� 0�� ����������󷵻� -1�� ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע�����Զ�����һص�����  int compare_call_back(singly_linked_list_major_node* value1, singly_linked_list_major_node* value2)
 */

int singly_linked_list_major_for_earch(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*), int* ret_value)
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back) || (NULL == ret_value))
	{
		return -1;
	}
	else
	{
		*ret_value = -1;
		struct singly_linked_list_major_node* current_ptr = list_haed->head.next;
		for (int i = 0; (i < list_haed->size) && (NULL != current_ptr); i++)
		{
			if (0 == compare_call_back(current_ptr, list_value))
			{
				*ret_value = i;
				return 0;
			}
			current_ptr = current_ptr->next;
		}
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_major_get_size(struct singly_linked_list_major* list_haed, int* ret_size)
 *  �������ܣ���ȡ����ڵ�����ĺ�������
 *  ����������*list_haed �����׵�ַ�� *ret_size ���ز��ҵ��ڵ����
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int singly_linked_list_major_get_size(struct singly_linked_list_major* list_haed, int* ret_size)
{
	if ((NULL == list_haed) || (NULL == ret_size))
	{
		return -1;
	}
	else
	{
		*ret_size = list_haed->size;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_major_get_front(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node** ret_value)
 *  �������ܣ���ȡ�����׸���ֵ�ڵ������
 *  ����������*list_haed �����׵�ַ�� *ret_value ���ز��ҵ��ڵ��ֵ
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int singly_linked_list_major_get_front(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node** ret_value)
{
	if ((NULL == list_haed) || (NULL == ret_value))
	{
		return -1;
	}
	else
	{
		*ret_value = list_haed->head.next;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_major_destroy(struct singly_linked_list_major* list_haed)
 *  �������ܣ���������ĺ�������
 *  ����������*list_haed �����׵�ַ
 *  �� �� ֵ�����ٳɹ����� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int singly_linked_list_major_destroy(struct singly_linked_list_major* list_haed)
{
	if (NULL == list_haed)
	{
		return -1;
	}
	else
	{
		free(list_haed);
		list_haed = NULL;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_major_print_value(struct singly_linked_list_major* list_haed, void(*print_call_back)(struct singly_linked_list_major_node*))
 *  �������ܣ���ӡ�������ݵĺ�������
 *  ����������*list_haed �����׵�ַ�� print_call_back �ص�����
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����Ҫ�Զ���ص����� print_call_back    void print_call_back(struct singly_linked_list_major_node* value)
 */

int singly_linked_list_major_print_value(struct singly_linked_list_major* list_haed, void(*print_call_back)(struct singly_linked_list_major_node*))
{
	if ((NULL == list_haed) || (NULL == print_call_back))
	{
		return -1;
	}
	else
	{
		struct singly_linked_list_major_node* current_ptr = list_haed->head.next;

		while (NULL != current_ptr)
		{
			print_call_back(current_ptr);
			current_ptr = current_ptr->next;
		}
	}
	return 0;
}
