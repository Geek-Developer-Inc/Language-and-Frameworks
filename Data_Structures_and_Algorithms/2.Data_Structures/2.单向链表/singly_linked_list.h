/*
 *  单向链表的声明(Singly linked list)，头文件
 *  SPDX-License-Identifier: GPL-2.0  
 *  singly_linked_list.h
 */


#ifndef __SINGLY_LINKED_LIST_H
#define __SINGLY_LINKED_LIST_H


/*
 *  定义链表节点 struct singly_linked_list_node
 *  void *data 链表节点的数据域；指向任何类型的数据
 *  struct singly_linked_list_node* next 链表节点的指针域
 */

struct singly_linked_list_node
{
	void* data;                              /*  链表的数据域：通用定义为 void *data  */
	struct singly_linked_list_node* next;    /*  链表的指针域  */
};


/*
 *  定义链表结构体 struct singly_linked_list
 *  struct singly_linked_list_node* head 指向链表头节点的指针
 *  int size 链表节点的个数
 */

struct singly_linked_list
{
	struct singly_linked_list_node* head;    /*  指向链表头节点的指针  */
	int size;                                /*  链表节点的个数 = 链表长度  */
};


/*  链表操作相关函数声明：链表的初始化、插入、删除、查找、修改 、销毁  */

/*  链表创建函数的声明  */
int singly_linked_list_create(struct singly_linked_list** list_haed);

/*  链表插入节点操作的函数声明  */
int singly_linked_list_insert(struct singly_linked_list* list_haed, int list_pos, void* list_value);

/*  根据位置删除链表节点的函数声明  */
int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos);

/*  根据值删除链表节点的函数声明  */
int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*));

/*  链表查找节点操作的函数声明  */
int singly_linked_list_for_earch(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), int* ret_value);

/*  链表修改操作的函数声明  */
int singly_linked_list_modify(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), void* new_value);

/*  获取链表节点个数的函数声明  */
int singly_linked_list_get_size(struct singly_linked_list* list_haed, int* ret_size);

/*  返回链表第一个节点  */
int singly_linked_list_get_front(struct singly_linked_list* list_haed, void** ret_value);

/*  销毁链表函数声明  */
int singly_linked_list_destroy(struct singly_linked_list* list_haed);

/*  打印链表内容  */
int singly_linked_list_print_value(struct singly_linked_list* list_haed, void(*print_call_back)(void*));


#endif    /*  END __SINGLY_LINKED_LIST_H  */
