/*
 *  单向链表定义(Singly linked list)
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"


/*  
 *  函数原型：struct link_list *link_list_init(void)
 *  函数功能：链表初始化操作的函数定义
 *  函数参数：无
 *  返 回 值：正常返链表头节点指针； 如动态内存分配失败返回 NULL
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：头节点数据域不保存数据
 */

struct link_list *link_list_init(void)
{
    struct link_list *head_ptr = (struct link_list *)malloc(sizeof(struct link_list));                                  /*  为链表结构体 struct link_list 分配内存空间  */
	if (NULL == head_ptr)
	{
	    return NULL;                                                                                                    /*  动态内存分配失败  */
	}
	else
	{
		memset(head_ptr, 0, sizeof(struct link_list));                                                                  /*  将申请成功的内存空间清零  */
		head_ptr->size = 0;
		head_ptr->head = (struct link_list_node *)malloc(sizeof(struct link_list_node));                                /*  创建头节点，为头节点申请内存空间  */
		if (NULL == head_ptr->head)
		{
			return NULL;
		}
		else
		{
			memset(head_ptr->head, 0, sizeof(struct link_list_node));
			head_ptr->head->data = 0;                                                                                   /*  头节点不保存任何数据，即头节点数据域为空  */
			head_ptr->head->next = NULL;                                                                                /*  头节点的指针域暂时指向NULL  */
		}
	}
	return head_ptr;                                                                                                    /*  返回链表结构体指针  */
}


/*
 *  函数原型：int link_list_insert(struct link_list *list_ptr, unsigned int list_pos, int value)
 *  函数功能：链表插入节点操作的函数定义
 *  函数参数：*list_ptr 指向链表头节点的指针； list_pos 要插入的位置,控制头插法还是尾插法； value 数据域的值
 *  返 回 值：正常返 0； 异常，函数传入参数有误返回 -1，如动态内存分配失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：list_pos = 0，代表头插法； list_pos 最大不能超过 list_ptr->size
 *  其    它：(1) 创建新节点并为数据域赋值，新节点的指针域暂时指向 NULL
 *            (2) 找到要插入位置的节点
 *            (3) 将节点插入并对接前面的节点
 */

int link_list_insert(struct link_list *list_ptr, unsigned int list_pos, int value)
{
	if (NULL == list_ptr)
	{
		return -1;
	}
	else
	{
		if (list_pos > list_ptr->size)                                                                                  /*  list_pos 要小于或等于 size，list_pos = 0 代表头插法；list_pos = size 代表尾插法  */
		{
			list_pos = list_ptr->size;
		}
		else
		{
			struct link_list_node *new_node_ptr = (struct link_list_node *)malloc(sizeof(struct link_list_node));       /*  创建一个新节点，并为数据数据域赋值，指针域指向 NULL  */
			if (NULL == new_node_ptr)
			{
				return -2;
			}
			else
			{
				memset(new_node_ptr, 0, sizeof(struct link_list_node));
				new_node_ptr->data = value;                                                                             /*  为新节点的数据域赋值  */
				new_node_ptr->next = NULL;                                                                              /*  新节点的指针域暂时指向 NULL  */

				struct link_list_node *current_ptr = list_ptr->head;                                                    /*  current_ptr 辅助指针，寻找新节点的插入位置  */
				for (unsigned int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
				{
					current_ptr = current_ptr->next;
				}

				new_node_ptr->next = current_ptr->next;                                                                 /*  新节点入链表  */
				current_ptr->next = new_node_ptr;
				
				list_ptr->size++;
			}
		}
	}
	return 0;
}


/*
 *  函数原型：int link_list_pos_remove(struct link_list *list_ptr, unsigned int list_pos)
 *  函数功能：根据位置删除链表节点的函数定义
 *  函数参数：*list_ptr 指向链表头节点的指针； list_pos 要删除节点的位置
 *  返 回 值：正常返 0； 异常，函数传入参数有误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
 */

int link_list_pos_remove(struct link_list *list_ptr, unsigned int list_pos)
{
	if ((NULL == list_ptr) || (list_pos >= list_ptr->size))
	{
		return -1;
	}
	else
	{
		struct link_list_node *current_ptr = list_ptr->head;                                                            /*  查找要删除节点的前一个节点  */
		for (unsigned int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}

		struct link_list_node *temp_ptr = current_ptr->next;                                                            /*  保存待删除的节点  */
		current_ptr->next = temp_ptr->next;
		free(temp_ptr);
		temp_ptr = NULL;
		
		list_ptr->size--;
	}
	return 0;
}


/*
 *  函数原型：int link_list_search(struct link_list *list_ptr, int list_value, int *ret_val)
 *  函数功能：链表查找节点操作的函数定义
 *  函数参数：*list_ptr 指向链表头节点的指针； list_value 要查找节点的数据域的值； ret_val 返回查找到的结果
 *  返 回 值：正常返 0； 异常，函数传入参数有误返回 -1； 要查找节点的节点不存在返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
 */

int link_list_search(struct link_list *list_ptr, int list_value, int *ret_val)
{
	if ((NULL == list_ptr) || (NULL == ret_val))
	{
		return -1;
	}
	else
	{
		struct link_list_node *current_ptr = (list_ptr->head)->next;                                                    /*  头节点不保存实际数据  */
		while (NULL != current_ptr)                                                                                     /*  遍历查找  */
		{
			if (current_ptr->data == list_value)
			{
				*ret_val = current_ptr->data;
				return 0;
			}
			current_ptr = current_ptr->next;                                                                            /*  节点向后移动，逐个判断  */
		}
		ret_val = NULL;
	}
	return -2;
}


/*
 *  函数原型：int link_list_modify(struct link_list *list_ptr, unsigned int list_pos, int value)
 *  函数功能：链表修改操作的函数定义
 *  函数参数：*list_ptr 指向链表头节点的指针； list_pos 要修改节点的数据域的值； value 新值
 *  返 回 值：正常返 0； 异常，函数传入参数有误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
 */

int link_list_modify(struct link_list *list_ptr, unsigned int list_pos, int value)
{
	if ((NULL == list_ptr) || (list_pos >= list_ptr->size))
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
 *  函数原型：int link_list_search(struct link_list *list_ptr, int list_value, int *ret_val)
 *  函数功能：获取链表节点个数的函数定义
 *  函数参数：*list_ptr 指向链表头节点的指针； ret_len 返回查找到的链表节点个数值
 *  返 回 值：正常返 0； 异常，函数传入参数有误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int link_list_destroy(struct link_list *list_ptr)
 *  函数功能：销毁链表的函数定义
 *  函数参数：*list_ptr 指向链表头节点的指针
 *  返 回 值：正常返 0； 异常，函数传入参数有误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
		while (NULL != current_ptr)                                                                                     /*  遍历删除节点  */
		{
			temp_ptr = current_ptr->next;                                                                               /*  先保存该节点指向的下一个节点  */
			free(current_ptr);
			current_ptr = temp_ptr;
		}
		free(list_ptr);
		current_ptr = NULL;
		temp_ptr = NULL;
		list_ptr = NULL;	
	}
	return 0;
}


/*  打印链表的内容  */
int link_list_print(struct link_list *list_ptr)
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
			printf("%d\t", current_ptr->data);
			current_ptr = current_ptr->next;
		}
		printf("\n");
	}
	return 0;
}
