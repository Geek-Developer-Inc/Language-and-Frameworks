/*
 *  单向链表的声明(Singly linked list)，头文件
 *  SPDX-License-Identifier: GPL-2.0  
 *  singly_linked_list.h
 */


#ifndef  __SINGLY_LINKED_LIST_H
#define  __SINGLY_LINKED_LIST_H


/*
 *  定义链表节点 link_list
 *  void *data 链表节点的数据域；指向任何类型的数据
 *  struct link_list_node *next 链表节点的指针域
 */

struct link_list_node
{
	void *data;                                                                            /*  数据域：通用定义为 void *data  */
	struct link_list_node *next;                                                           /*  指针域  */
};


/*
 *  定义链表结构体 struct link_list
 *  struct link_list_node *head 指向链表头节点的指针
 *  unsigned int size 链表节点的个数
 */

struct link_list
{
	struct link_list_node *head;                                                           /*  指向链表头节点的指针  */
	unsigned int size;                                                                     /*  链表节点的个数 = 链表长度  */
};


/*  链表操作相关函数声明：链表的初始化、插入、删除、查找、修改 、销毁  */

struct link_list *link_list_init(void);                                                    /*  链表初始化操作的函数声明  */
int link_list_insert(struct link_list *list_ptr, unsigned int list_pos, void *value);      /*  链表插入节点操作的函数声明  */
int link_list_pos_remove(struct link_list *list_ptr, unsigned int list_pos);               /*  根据位置删除链表节点的函数声明  */
int link_list_search(struct link_list *list_ptr, void *list_value, int(*call_back)(void*, void*), int *ret_val);         /*  链表查找节点操作的函数声明  */
int link_list_modify(struct link_list *list_ptr, unsigned int list_pos, void *value);      /*  链表修改操作的函数声明  */
int link_list_get_size(struct link_list *list_ptr, unsigned int *ret_len);                 /*  获取链表节点个数的函数声明  */
int link_list_destroy(struct link_list *list_ptr);                                         /*  销毁链表  */
int link_list_print(struct link_list *list_ptr,void (*call_back)(void*));                  /*  打印链表内容  */

/*  返回链表第一个节点  */
void *link_list_get_first(struct link_list *list_ptr);

#endif // ! __SINGLY_LINKED_LIST_H
