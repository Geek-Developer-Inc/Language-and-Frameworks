/*
 *  单向链表企业版的定义(Singly linked list major)
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list_major.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list_major.h"


/*  
 *  函数原型：int singly_linked_list_major_create(struct singly_linked_list_major** list_haed)
 *  函数功能：创建链表
 *  函数参数：** list_haed 返回链表的头节点指针
 *  返 回 值：创建成功返回 0； 传入参数错误返回 -1； 分配动态内存失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：不创建头节点，只创建链表节点
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
 *  函数原型：int singly_linked_list_major_insert(struct singly_linked_list_major* list_haed, int list_pos, struct singly_linked_list_major_node* list_value)
 *  函数功能：向链表插入节点
 *  函数参数：*list_haed 链表首地址； list_pos 头插法、尾插法控制； *list_value 插入节点的数据域
 *  返 回 值：节点插入成功返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：不创建实际节点，节点在外部定义
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
			/*  强制尾插法  */
			list_pos = list_haed->size;
		}
		/*  寻找要插入节点的位置  */
		struct singly_linked_list_major_node* current_ptr = &(list_haed->head);
		for (int i = 0; (i < list_pos) && (NULL != current_ptr); i++)
		{
			current_ptr = current_ptr->next;
		}
		/*  插入节点  */
		list_value->next = current_ptr->next;
		current_ptr->next = list_value;
		list_haed->size++;
	}
	return 0;
}


/*
 *  函数原型：int singly_linked_list_major_by_pos_remove(struct singly_linked_list_major* list_haed, int list_pos)
 *  函数功能：根据位置删除链表节点的函数定义
 *  函数参数：*list_haed 链表首地址； list_pos 要删除节点的位置
 *  返 回 值：删除成功返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无需释放节点空间
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
 *  函数原型：int intsingly_linked_list_major_by_value_remove(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*))
 *  函数功能：根据值删除链表节点的函数定义
 *  函数参数：*list_haed 链表首地址； *list_value 要删除节点的值； compare_call_back 比较回调函数
 *  返 回 值：删除成功返回 0； 传入参数错误返回 -1； 查找失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：需自定义查找回调函数  int compare_call_back(singly_linked_list_major_node* value1, singly_linked_list_major_node* value2)  返回 0
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
 *  函数原型：int singly_linked_list_major_for_earch(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*), int* ret_value)
 *  函数功能：链表查找节点操作的函数定义
 *  函数参数：*list_haed 链表首地址； *list_value 要查找节点的数据域； compare_call_back 查找回调函数； *ret_value 返回查找到节点的位置，-1 查找失败
 *  返 回 值：正常返回 0； 传入参数错误返回 -1； 查找失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：需自定义查找回调函数  int compare_call_back(singly_linked_list_major_node* value1, singly_linked_list_major_node* value2)
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
 *  函数原型：int singly_linked_list_major_get_size(struct singly_linked_list_major* list_haed, int* ret_size)
 *  函数功能：获取链表节点个数的函数定义
 *  函数参数：*list_haed 链表首地址； *ret_size 返回查找到节点个数
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int singly_linked_list_major_get_front(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node** ret_value)
 *  函数功能：获取链表首个有值节点的数据
 *  函数参数：*list_haed 链表首地址； *ret_value 返回查找到节点的值
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int singly_linked_list_major_destroy(struct singly_linked_list_major* list_haed)
 *  函数功能：销毁链表的函数定义
 *  函数参数：*list_haed 链表首地址
 *  返 回 值：销毁成功返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int singly_linked_list_major_print_value(struct singly_linked_list_major* list_haed, void(*print_call_back)(struct singly_linked_list_major_node*))
 *  函数功能：打印链表内容的函数定义
 *  函数参数：*list_haed 链表首地址； print_call_back 回调函数
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：需要自定义回调函数 print_call_back    void print_call_back(struct singly_linked_list_major_node* value)
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
