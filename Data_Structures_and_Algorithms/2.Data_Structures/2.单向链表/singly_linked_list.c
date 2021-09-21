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
 *  函数原型：int singly_linked_list_create(struct singly_linked_list** list_haed)
 *  函数功能：创建单向链表函数的定义
 *  函数参数：**list_haed 返回链表头节点表的地址(二级指针)
 *  返 回 值：链表创建成功返回 0； 传入参数错误返回 -1； 动态内存分配失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：头节点数据域不保存数据
 */

int singly_linked_list_create(struct singly_linked_list** list_haed)
{
	if (NULL == list_haed)
	{
		return -1;
	}
	else
	{
		/*  为链表结构体 struct singly_linked_list 分配内存空间  */
		*list_haed = (struct singly_linked_list*)malloc(sizeof(struct singly_linked_list));
		if (NULL == *list_haed)
		{
			/*  申请分配动态内存失败  */
			return -2;
		}
		else
		{
			/*  将申请成功的内存空间清零  */
			memset(*list_haed, 0, sizeof(struct singly_linked_list));
			(*list_haed)->size = 0;
			/*  创建头节点，为头节点申请内存空间  */
			(*list_haed)->head = (struct singly_linked_list_node *)malloc(sizeof(struct singly_linked_list_node));
			if (NULL == (*list_haed)->head)
			{
				return -2;
			}
			else
			{
				memset((*list_haed)->head, 0, sizeof(struct singly_linked_list_node));
				/*  头节点不保存任何数据，即头节点数据域为空  */
				(*list_haed)->head->data = NULL;
				/*  头节点的指针域暂时指向 NULL  */
				(*list_haed)->head->next = NULL;
			}
		}
	}
	return 0;  /*  链表初始化完成  */
}


/*
 *  函数原型：int singly_linked_list_insert(struct singly_linked_list* list_haed, int list_pos, void* list_value)
 *  函数功能：向单向链表插入节点操作的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； list_pos 要插入的位置,控制头插法还是尾插法； *list_value 新节点数据域的值
 *  返 回 值：链表节点插入成功返回 0； 传入参数错误返回 -1； 动态内存分配失败返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：list_pos = 0，代表头插法； list_pos < list_ptr->size；  list_pos >= 0
 *  其    它：(1) 创建新节点并为数据域赋值，新节点的指针域暂时指向 NULL
 *            (2) 找到要插入位置的节点
 *            (3) 将节点插入并对接前面的节点
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
			/*  list_pos 要小于 size，list_pos = 0 代表头插法；list_pos = size 代表尾插法  */
			list_pos = list_haed->size;
		}
		/*  创建一个新节点，并为数据数据域赋值，指针域指向 NULL  */
		struct singly_linked_list_node* new_node_ptr = (struct singly_linked_list_node *)malloc(sizeof(struct singly_linked_list_node));
		if (NULL == new_node_ptr)
		{
			/*  为新节点分配动态内存失败  */
			return -2;
		}
		else
		{
			memset(new_node_ptr, 0, sizeof(struct singly_linked_list_node));
			/*  为新节点的数据域赋值  */
			new_node_ptr->data = list_value;
			/*  新节点的指针域暂时指向 NULL  */
			new_node_ptr->next = NULL;
			/*  current_ptr 辅助指针，寻找新节点的插入位置  */
			struct singly_linked_list_node* current_ptr = list_haed->head;
			for (int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
			{
				current_ptr = current_ptr->next;
			}
			/*  新节点入链表，经典插入操作  */
			new_node_ptr->next = current_ptr->next;
			current_ptr->next = new_node_ptr;
				
			list_haed->size++;
		}
	}
	return 0;  /*  链表插入成功  */
}


/*
 *  函数原型：int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos)
 *  函数功能：根据位置删除链表节点的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； list_pos 要删除节点的位置
 *  返 回 值：删除成功返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：list_pos 必须为 >= 0 且 list_pos < list_haed->size 的有效值
 */

int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos)
{
	if ((NULL == list_haed) || (list_pos >= list_haed->size))
	{
		return -1;
	}
	else
	{
		/*  查找要删除节点的前一个节点  */
		struct singly_linked_list_node* current_ptr = list_haed->head;
		for (int i = 0; ((i < list_pos) && (NULL != current_ptr)); i++)
		{
			current_ptr = current_ptr->next;
		}
		/*  保存待删除的节点  */
		struct singly_linked_list_node* temp_ptr = current_ptr->next;
		current_ptr->next = temp_ptr->next;
		free(temp_ptr);
		temp_ptr = NULL;
		list_haed->size--;
	}
	return 0;
}


/*
 *  函数原型：int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*))
 *  函数功能：根据值删除链表节点的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； *list_value 要删除节点的值； compare_call_back 比较回调函数
 *  返 回 值：删除成功返回 0； 传入参数错误返回 -1； 要查找的节点不存在返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：ompare_call_back  回调函数需自己实现 int compare_call_back(void* value1, void* value2); 查找成功返回 0
 */

int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*))
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back))
	{
		return -1;
	}
	else
	{
		/*  遍历寻找要删除值对应的节点节点  */
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
 *  函数原型：int singly_linked_list_for_earch(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), int* ret_value)
 *  函数功能：链表查找节点操作的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； *list_value 要查找节点的数据域的值； compare_call_back 比较回调函数； *ret_value 返回查找到的结果
 *  返 回 值：正常返 0； 传入参数错误返回 -1； 要查找的节点不存在返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：compare_call_back  回调函数需自己实现 int compare_call_back(void* value1, void* value2); 查找成功返回 0
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
		/*  头节点不保存实际数据  */
		struct singly_linked_list_node* current_ptr = (list_haed->head)->next;
		/*  遍历查找  */
		for(int i = 0; (i<list_haed->size)&&(NULL != current_ptr);i++)
		{
			if (0 == compare_call_back(current_ptr->data, list_value))
			{
				*ret_value = i;
				return 0;
			}
			/*  节点向后移动，逐个判断  */
			current_ptr = current_ptr->next;
		}
	}
	return -2;
}


/*
 *  函数原型：int singly_linked_list_modify(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), void* new_value)
 *  函数功能：链表修改操作的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； *list_value 要修改节点的数据域的值； modify_call_back 比较回调函数； *new_value 新数据域的值
 *  返 回 值：修改成功返回 0； 传入参数错误返回 -1； 要修改的节点不存在返回 -2
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
 */

int singly_linked_list_modify(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), void* new_value)
{
	if ((NULL == list_haed) || (NULL == list_value) || (NULL == compare_call_back)||(NULL == new_value))
	{
		return -1;
	}
	else
	{
		/*  遍历寻找要修改节点值对应的节点节点  */
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
 *  函数原型：int singly_linked_list_get_size(struct singly_linked_list* list_haed, int* ret_size)
 *  函数功能：获取链表节点个数的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； ret_size 返回查找到的链表节点个数值
 *  返 回 值：成功返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
 *  函数原型：int singly_linked_list_get_front(struct singly_linked_list* list_haed, void** ret_value)
 *  函数功能：获取链表第一个节点
 *  函数参数：*list_haed 指向链表头节点的指针; **ret_value 返回头节点的值(二级指针)
 *  返 回 值：成功返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：链表第一节点实际就是头节点的下一个节点
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
 *  函数原型：int singly_linked_list_destroy(struct singly_linked_list* list_haed)
 *  函数功能：销毁链表的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针
 *  返 回 值：链表销毁完成返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：无
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
		/*  遍历删除节点  */
		while (NULL != current_ptr)
		{
			/*  先保存该节点指向的下一个节点  */
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
 *  函数原型：int singly_linked_list_print_value(struct singly_linked_list* list_haed, void(*print_call_back)(void*))
 *  函数功能：打印链表的内容的函数定义
 *  函数参数：*list_haed 指向链表头节点的指针； print_call_back 打印回调函数
 *  返 回 值：正常返回 0； 传入参数错误返回 -1
 *  版    本：V1.2.0
 *  时    间：2021-9-11
 *  备    注：print_call_back 打印回调函数需自定义;  void print_call_back(void* value);
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
