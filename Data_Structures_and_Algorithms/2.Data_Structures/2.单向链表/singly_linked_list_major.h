/*
 *  单向链表企业版的声明(Singly linked list major)，仿照 Linux 内核链表，头文件
 *  SPDX-License-Identifier: GPL-2.0
 *  singly_linked_list_major.h
 */


#ifndef  __SINGLY_LINKED_LIST_MAJOR_H
#define  __SINGLY_LINKED_LIST_MAJOR_H


/*
 *  定义链表节点 struct link_list_major_node
 *  仿照 Linux 内核链表，只包含指针域
 *  struct link_list_major_node *next 链表节点的指针域
 */

struct link_list_major_node
{
	struct link_list_major_node *next;                                                                 /*  指针域  */
};


/*
 *  定义链表结构体 struct link_list_major
 *  struct link_list_major_node head 指向链表头节点的指针
 *  unsigned int size 链表节点的个数
 */

struct link_list_major
{
	struct link_list_major_node head;                                                                  /*  指向链表头节点的指针  */
	unsigned int size;                                                                                 /*  链表节点的个数 = 链表长度  */
};


/*  遍历函数指针定义  */
typedef void(*pri_type_def) (struct link_list_major_node*);


/*  比较函数指针定义  */
typedef int(*comparre_type_def) (struct link_list_major_node*, struct link_list_major_node*);


/*  链表操作相关函数声明：链表的初始化、插入、删除、查找、修改 、销毁  */

struct link_list_major *link_list_major_init(void);                                                    /*  链表初始化操作的函数声明  */
int link_list_major_insert(struct link_list_major *list_ptr, unsigned int list_pos, struct link_list_major_node *value);                         /*  链表插入节点操作的函数声明  */
int link_list_major_pos_remove(struct link_list_major *list_ptr, unsigned int list_pos);               /*  根据位置删除链表节点的函数声明  */
int link_list_major_search(struct link_list_major *list_ptr, struct link_list_major_node *list_value, comparre_type_def compare, int *ret_val);  /*  链表查找节点操作的函数声明  */
int link_list_major_get_size(struct link_list_major *list_ptr, unsigned int *ret_len);                 /*  获取链表节点个数的函数声明  */
int link_list_major_destroy(struct link_list_major *list_ptr);                                         /*  销毁链表  */
int link_list_major_print(struct link_list_major *list_ptr, pri_type_def call_back);                   /*  打印链表内容  */


#endif // !__SINGLY_LINKED_LIST_MAJOR_H
