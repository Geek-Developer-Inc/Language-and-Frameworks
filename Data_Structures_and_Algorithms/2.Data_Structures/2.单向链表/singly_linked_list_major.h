/*
 *  单向链表企业版的声明(Singly linked list major)，仿照 Linux 内核链表，头文件
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list_major.h
 */


#ifndef  __SINGLY_LINKED_LIST_MAJOR_H
#define  __SINGLY_LINKED_LIST_MAJOR_H


/*
 *  定义链表节点 struct singly_linked_list_major_node
 *  仿照 Linux 内核链表，只包含指针域
 *  struct singly_linked_list_major_node* next 链表节点的指针域
 */

struct singly_linked_list_major_node
{
	struct singly_linked_list_major_node* next;    /*  指针域  */
};


/*
 *  定义链表结构体 struct singly_linked_list_major
 *  struct singly_linked_list_major_node head 指向链表头节点的指针
 *  int size 链表节点的个数
 */

struct singly_linked_list_major
{
	struct singly_linked_list_major_node head;     /*  指向链表头节点的指针  */
	int size;                                      /*  链表节点的个数 = 链表长度  */
};


/*  链表操作相关函数声明：链表的初始化、插入、删除、查找、修改 、销毁  */

/*  链表创建函数的声明  */
int singly_linked_list_major_create(struct singly_linked_list_major** list_haed);

/*  链表插入节点操作的函数声明  */
int singly_linked_list_major_insert(struct singly_linked_list_major* list_haed, int list_pos, struct singly_linked_list_major_node* list_value);

/*  根据位置删除链表节点的函数声明  */
int singly_linked_list_major_by_pos_remove(struct singly_linked_list_major* list_haed, int list_pos);

/*  根据值删除链表节点的函数声明  */
int intsingly_linked_list_major_by_value_remove(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*));

/*  链表查找节点操作的函数声明  */
int singly_linked_list_major_for_earch(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*), int* ret_value);


/*  获取链表节点个数的函数声明  */
int singly_linked_list_major_get_size(struct singly_linked_list_major* list_haed, int* ret_size);

/*  返回链表第一个节点  */
int singly_linked_list_major_get_front(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node** ret_value);

/*  销毁链表函数声明  */
int singly_linked_list_major_destroy(struct singly_linked_list_major* list_haed);

/*  打印链表内容  */
int singly_linked_list_major_print_value(struct singly_linked_list_major* list_haed, void(*print_call_back)(struct singly_linked_list_major_node*));


#endif    /*  END __SINGLY_LINKED_LIST_MAJOR_H  */
