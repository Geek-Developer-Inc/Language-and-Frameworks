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
 *  ����ԭ�ͣ�int singly_linked_list_create(struct singly_linked_list** list_haed)
 *  �������ܣ����������������Ķ���
 *  ����������**list_haed ��������ͷ�ڵ��ĵ�ַ(����ָ��)
 *  �� �� ֵ���������ɹ����� 0�� ����������󷵻� -1�� ��̬�ڴ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��ͷ�ڵ������򲻱�������
 */

int singly_linked_list_create(struct singly_linked_list** list_haed)
{
	if (NULL == list_haed)
	{
		return -1;
	}
	else
	{
		/*  Ϊ����ṹ�� struct singly_linked_list �����ڴ�ռ�  */
		*list_haed = (struct singly_linked_list*)malloc(sizeof(struct singly_linked_list));
		if (NULL == *list_haed)
		{
			/*  ������䶯̬�ڴ�ʧ��  */
			return -2;
		}
		else
		{
			/*  ������ɹ����ڴ�ռ�����  */
			memset(*list_haed, 0, sizeof(struct singly_linked_list));
			(*list_haed)->size = 0;
			/*  ����ͷ�ڵ㣬Ϊͷ�ڵ������ڴ�ռ�  */
			(*list_haed)->head = (struct singly_linked_list_node *)malloc(sizeof(struct singly_linked_list_node));
			if (NULL == (*list_haed)->head)
			{
				return -2;
			}
			else
			{
				memset((*list_haed)->head, 0, sizeof(struct singly_linked_list_node));
				/*  ͷ�ڵ㲻�����κ����ݣ���ͷ�ڵ�������Ϊ��  */
				(*list_haed)->head->data = NULL;
				/*  ͷ�ڵ��ָ������ʱָ�� NULL  */
				(*list_haed)->head->next = NULL;
			}
		}
	}
	return 0;  /*  �����ʼ�����  */
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_insert(struct singly_linked_list* list_haed, int list_pos, void* list_value)
 *  �������ܣ������������ڵ�����ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 list_pos Ҫ�����λ��,����ͷ�巨����β�巨�� *list_value �½ڵ��������ֵ
 *  �� �� ֵ������ڵ����ɹ����� 0�� ����������󷵻� -1�� ��̬�ڴ����ʧ�ܷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��list_pos = 0������ͷ�巨�� list_pos < list_ptr->size��  list_pos >= 0
 *  ��    ����(1) �����½ڵ㲢Ϊ������ֵ���½ڵ��ָ������ʱָ�� NULL
 *            (2) �ҵ�Ҫ����λ�õĽڵ�
 *            (3) ���ڵ���벢�Խ�ǰ��Ľڵ�
 */

int singly_linked_list_insert(struct singly_linked_list* list_haed, int list_pos, void* list_value)
{
	if ((NULL == list_haed) || (NULL == list_value))
	{
		return -1;
	}
	else
	{
		if ((list_pos < 0) || (list_pos > list_haed->size))
		{
			/*  list_pos ҪС�� size��list_pos = 0 ����ͷ�巨��list_pos = size ����β�巨  */
			list_pos = list_haed->size;
		}
		/*  ����һ���½ڵ㣬��Ϊ����������ֵ��ָ����ָ�� NULL  */
		struct singly_linked_list_node* new_node_ptr = (struct singly_linked_list_node *)malloc(sizeof(struct singly_linked_list_node));
		if (NULL == new_node_ptr)
		{
			/*  Ϊ�½ڵ���䶯̬�ڴ�ʧ��  */
			return -2;
		}
		else
		{
			memset(new_node_ptr, 0, sizeof(struct singly_linked_list_node));
			/*  Ϊ�½ڵ��������ֵ  */
			new_node_ptr->data = list_value;
			/*  �½ڵ��ָ������ʱָ�� NULL  */
			new_node_ptr->next = NULL;
			/*  current_ptr ����ָ�룬Ѱ���½ڵ�Ĳ���λ��  */
			struct singly_linked_list_node* current_ptr = list_haed->head;
			for (int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
			{
				current_ptr = current_ptr->next;
			}
			/*  �½ڵ�����������������  */
			new_node_ptr->next = current_ptr->next;
			current_ptr->next = new_node_ptr;
				
			list_haed->size++;
		}
	}
	return 0;  /*  �������ɹ�  */
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos)
 *  �������ܣ�����λ��ɾ������ڵ�ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 list_pos Ҫɾ���ڵ��λ��
 *  �� �� ֵ��ɾ���ɹ����� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��list_pos ����Ϊ >= 0 �� list_pos < list_haed->size ����Чֵ
 */

int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos)
{
	if ((NULL == list_haed) || (list_pos >= list_haed->size))
	{
		return -1;
	}
	else
	{
		/*  ����Ҫɾ���ڵ��ǰһ���ڵ�  */
		struct singly_linked_list_node* current_ptr = list_haed->head;
		for (int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}
		/*  �����ɾ���Ľڵ�  */
		struct singly_linked_list_node* temp_ptr = current_ptr->next;
		current_ptr->next = temp_ptr->next;
		free(temp_ptr);
		temp_ptr = NULL;
		list_haed->size--;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*))
 *  �������ܣ�����ֵɾ������ڵ�ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 *list_value Ҫɾ���ڵ��ֵ�� compare_call_back �Ƚϻص�����
 *  �� �� ֵ��ɾ���ɹ����� 0�� ����������󷵻� -1�� Ҫ���ҵĽڵ㲻���ڷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��ompare_call_back  �ص��������Լ�ʵ�� int compare_call_back(void* value1, void* value2); ���ҳɹ����� 0
 */

int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*))
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back))
	{
		return -1;
	}
	else
	{
		/*  ����Ѱ��Ҫɾ��ֵ��Ӧ�Ľڵ�ڵ�  */
		struct singly_linked_list_node* current_ptr = list_haed->head->next;
		for (int i = 0; ((i < list_haed->size) && (NULL != current_ptr)); i++)
		{
			if (0 == compare_call_back(current_ptr->data, list_value))
			{
				singly_linked_list_by_pos_remove(list_haed, i);
				return 0;
			}
			current_ptr = current_ptr->next;
		}
	}
	return -2;
}

/*
 *  ����ԭ�ͣ�int singly_linked_list_for_earch(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), int* ret_value)
 *  �������ܣ�������ҽڵ�����ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 *list_value Ҫ���ҽڵ���������ֵ�� compare_call_back �Ƚϻص������� *ret_value ���ز��ҵ��Ľ��
 *  �� �� ֵ�������� 0�� ����������󷵻� -1�� Ҫ���ҵĽڵ㲻���ڷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��compare_call_back  �ص��������Լ�ʵ�� int compare_call_back(void* value1, void* value2); ���ҳɹ����� 0
 */

int singly_linked_list_for_earch(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), int* ret_value)
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back) || (NULL == ret_value))
	{
		return -1;
	}
	else
	{
		*ret_value = -1;
		/*  ͷ�ڵ㲻����ʵ������  */
		struct singly_linked_list_node* current_ptr = (list_haed->head)->next;
		/*  ��������  */
		for(int i = 0; (i<list_haed->size)&&(NULL != current_ptr);i++)
		{
			if (0 == compare_call_back(current_ptr->data, list_value))
			{
				*ret_value = i;
				return 0;
			}
			/*  �ڵ�����ƶ�������ж�  */
			current_ptr = current_ptr->next;
		}
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_modify(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), void* new_value)
 *  �������ܣ������޸Ĳ����ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 *list_value Ҫ�޸Ľڵ���������ֵ�� modify_call_back �Ƚϻص������� *new_value ���������ֵ
 *  �� �� ֵ���޸ĳɹ����� 0�� ����������󷵻� -1�� Ҫ�޸ĵĽڵ㲻���ڷ��� -2
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int singly_linked_list_modify(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), void* new_value)
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back)||(NULL == new_value))
	{
		return -1;
	}
	else
	{
		/*  ����Ѱ��Ҫ�޸Ľڵ�ֵ��Ӧ�Ľڵ�ڵ�  */
		struct singly_linked_list_node* current_ptr = list_haed->head->next;
		for (int i = 0; ((i < list_haed->size) && (NULL != current_ptr)); i++)
		{
			if (0 == compare_call_back(current_ptr->data, list_value))
			{
				current_ptr->data = new_value;
				return 0;
			}
			current_ptr = current_ptr->next;
		}
	}
	return -2;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_get_size(struct singly_linked_list* list_haed, int* ret_size)
 *  �������ܣ���ȡ����ڵ�����ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 ret_size ���ز��ҵ�������ڵ����ֵ
 *  �� �� ֵ���ɹ����� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int singly_linked_list_get_size(struct singly_linked_list* list_haed, int* ret_size)
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
 *  ����ԭ�ͣ�int singly_linked_list_get_front(struct singly_linked_list* list_haed, void** ret_value)
 *  �������ܣ���ȡ�����һ���ڵ�
 *  ����������*list_haed ָ������ͷ�ڵ��ָ��; **ret_value ����ͷ�ڵ��ֵ(����ָ��)
 *  �� �� ֵ���ɹ����� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע�������һ�ڵ�ʵ�ʾ���ͷ�ڵ����һ���ڵ�
 */

int singly_linked_list_get_front(struct singly_linked_list* list_haed, void** ret_value)
{
	if ((NULL == list_haed) || (NULL == ret_value))
	{
		return -1;
	}
	*ret_value = list_haed->head->next->data;
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_destroy(struct singly_linked_list* list_haed)
 *  �������ܣ���������ĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ��
 *  �� �� ֵ������������ɷ��� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע����
 */

int singly_linked_list_destroy(struct singly_linked_list* list_haed)
{
	if ((NULL == list_haed) || (list_haed->head == NULL))
	{
		return -1;
	}
	else
	{
		struct singly_linked_list_node* current_ptr = list_haed->head;
		struct singly_linked_list_node* temp_ptr = current_ptr->next;
		/*  ����ɾ���ڵ�  */
		while (NULL != current_ptr)
		{
			/*  �ȱ���ýڵ�ָ�����һ���ڵ�  */
			temp_ptr = current_ptr->next;
			free(current_ptr);
			current_ptr = temp_ptr;
		}
		list_haed->size = 0;
		free(list_haed);
		current_ptr = NULL;
		temp_ptr = NULL;
		list_haed = NULL;
	}
	return 0;
}


/*
 *  ����ԭ�ͣ�int singly_linked_list_print_value(struct singly_linked_list* list_haed, void(*print_call_back)(void*))
 *  �������ܣ���ӡ��������ݵĺ�������
 *  ����������*list_haed ָ������ͷ�ڵ��ָ�룻 print_call_back ��ӡ�ص�����
 *  �� �� ֵ���������� 0�� ����������󷵻� -1
 *  ��    ����V1.2.0
 *  ʱ    �䣺2021-9-11
 *  ��    ע��print_call_back ��ӡ�ص��������Զ���;  void print_call_back(void* value);
 */

int singly_linked_list_print_value(struct singly_linked_list* list_haed, void(*print_call_back)(void*))
{
	if ((NULL == list_haed) || (NULL == print_call_back))
	{
		return -1;
	}
	else
	{
		struct singly_linked_list_node* current_ptr = (list_haed->head)->next;
		while (NULL != current_ptr)
		{
			print_call_back(current_ptr->data);
			current_ptr = current_ptr->next;
		}
	}
	return 0;
}
