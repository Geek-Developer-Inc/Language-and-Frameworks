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
 *  函数原型：struct link_list_major *link_list_major_init(void)
 *  函数功能：链表初始化操作的函数定义
 *  函数参数：无
 *  返 回 值：正常返链表头节点指针； 如动态内存分配失败返回 NULL
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：不创建头节点，只创建链表节点
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
 *  函数原型：struct link_list_major *link_list_major_init(void)
 *  函数功能：链表插入节点操作的函数定义
 *  函数参数：*list_ptr 链表首地址； list_pos 头插法、尾插法控制； *value 插入节点的数据域
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：不创建实际节点，节点在外部定义
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
			/*  强制尾插法  */
			list_pos = list_ptr->size;
		}
		/*  寻找要插入节点的位置  */
		struct link_list_major_node *current_ptr = &(list_ptr->head);
		for (unsigned int i = 0; (i < list_pos) && (NULL != current_ptr); i++)
		{
			current_ptr = current_ptr->next;
		}
		/*  插入节点  */
		value->next = current_ptr->next;
		current_ptr->next = value;

		list_ptr->size++;
	}
	return 0;
}


/*
 *  函数原型：int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos)
 *  函数功能：根据位置删除链表节点的函数定义
 *  函数参数：list_ptr 链表首地址； list_pos 要删除节点的位置
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无需释放节点空间
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
 *  函数原型：int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos)
 *  函数功能：链表查找节点操作的函数定义
 *  函数参数：list_ptr 链表首地址； *list_value 要查找节点的数据域； compare 查找回调函数； *ret_val 返回查找到节点的位置，-1 查找失败
 *  返 回 值：正常返回 0； 传入参数错误返回 -1； 查找失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：需自定义查找回调函数
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
 *  函数原型：int link_list_major_get_size(struct link_list_major *list_ptr, unsigned int *ret_len)
 *  函数功能：获取链表节点个数的函数定义
 *  函数参数：list_ptr 链表首地址； *ret_len 返回查找到节点个数
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int link_list_major_destroy(struct link_list_major *list_ptr)
 *  函数功能：销毁链表的函数定义
 *  函数参数：list_ptr 链表首地址
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int link_list_major_print(struct link_list_major *list_ptr, pri_type_def call_back)
 *  函数功能：打印链表内容的函数定义
 *  函数参数：list_ptr 链表首地址； call_back 回调函数
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：需要自定义回调函数 call_back
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
