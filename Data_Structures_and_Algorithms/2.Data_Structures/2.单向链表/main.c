#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "singly_linked_list.h"

struct persion
{
	char name[16];
	int age;
	int id_card;
};

void print_call_back(void* value)
{
	if (NULL == value)
	{
		return;
	}
	struct persion *per_ptr = value;
	printf("Name: %s   Age: %d   ID:%d\n", per_ptr->name, per_ptr->age, per_ptr->id_card);
}

int compare_call_back(void* value1, void* value2)
{
	if ((NULL == value1) || (NULL == value2))
	{
		return -1;
	}
	struct persion *per_ptr1 = value1;
	struct persion *per_ptr2 = value2;
	if ((0 == strcmp(per_ptr1->name, per_ptr2->name)) && (per_ptr1->age == per_ptr2->age) && (per_ptr1->id_card == per_ptr2->id_card))
	{
		return 0;
	}
	return -2;
}

static void singly_linked_list_test(void)
{

	printf("singly linked list create\n");
	struct singly_linked_list* list_haed = NULL;
	/*  链表创建 int singly_linked_list_create(struct singly_linked_list** list_haed)  */
	singly_linked_list_create((struct singly_linked_list**)&list_haed);

	struct persion persion0 = { "persion 0",20,88881 };
	struct persion persion1 = { "persion 1",21,88882 };
	struct persion persion2 = { "persion 2",22,88883 };
	struct persion persion3 = { "persion 3",23,88884 };
	struct persion persion4 = { "persion 4",24,88885 };
	struct persion persion5 = { "persion 5",25,88886 };

	printf("\nsingly linked list insert\n");
	/*  链表插入 int singly_linked_list_insert(struct singly_linked_list* list_haed, int list_pos, void* list_value)  */
	singly_linked_list_insert(list_haed, 0, &persion0);
	singly_linked_list_insert(list_haed, 0, &persion1);
	singly_linked_list_insert(list_haed, 0, &persion2);
	singly_linked_list_insert(list_haed, 10, &persion3);
	singly_linked_list_insert(list_haed, 2, &persion4);
	singly_linked_list_insert(list_haed, 3, &persion5);

	/*  获取链表节点个数 int singly_linked_list_get_size(struct singly_linked_list* list_haed, int* ret_size)  */
	int ret_size = 0;
	singly_linked_list_get_size(list_haed, &ret_size);
	printf("singly linked list size: %d\n", ret_size);


	/*  返回链表第一个节点 int singly_linked_list_get_front(struct singly_linked_list* list_haed, void** ret_value)  */
	struct persion *front = NULL;
	singly_linked_list_get_front(list_haed, (void**)&front);
	printf("[front] Name: %s;  Age: %d  ID: %d\n", front->name, front->age, front->id_card);
	/*  persion2  persion1  persion4  persion5  persion0  persion3  */
	/*  打印链表内容 int singly_linked_list_print_value(struct singly_linked_list* list_haed, void(*print_call_back)(void*))  */
	singly_linked_list_print_value(list_haed, print_call_back);

	int ret_value = 0;
	struct persion for_earch = { "persion 4",24,88885 };
	/*  链表查找节点操作的函数声明 int singly_linked_list_for_earch(struct singly_linked_list* list_haed, void* list_value, int(*compare_call_back)(void*, void*), int* ret_value)  */
	singly_linked_list_for_earch( list_haed, &for_earch, compare_call_back, &ret_value);
	printf("persion 4,24,88885  is %d\n", ret_value);

	/*  根据位置删除链表节点 int singly_linked_list_by_pos_remove(struct singly_linked_list* list_haed, int list_pos)  */
	printf("\nsingly linked list by pos 3 remove\n");
	singly_linked_list_by_pos_remove(list_haed, 3);
	singly_linked_list_print_value(list_haed, print_call_back);

	/*  根据值删除链表节点的函数声明 int singly_linked_list_by_value_remove(struct singly_linked_list* list_haed, void* list_data, int(*compare_call_back)(void*, void*))  */
	struct persion del = { "persion 3",23,88884 };
	singly_linked_list_by_value_remove(list_haed, &del, compare_call_back);
	printf("\nsingly linked list by value_remove persion 3 \n");
	singly_linked_list_print_value(list_haed, print_call_back);

	ret_size = 0;
	singly_linked_list_get_size(list_haed, &ret_size);
	printf("\nremove end singly linked list size: %d\n", ret_size);


	struct persion modify = { "ge bi lao wang" ,66,11111 };
	singly_linked_list_insert(list_haed, 3, &modify);
	printf("\nsingly linked list modify front\n");
	singly_linked_list_print_value(list_haed, print_call_back);
	struct persion persion6 = { "persion 6" ,26,88887 };
	/*  链表修改操作的函数声明 int singly_linked_list_modify(struct singly_linked_list* list_haed, void** list_value, int(*compare_call_back)(void*, void*), void* new_value)  */
	singly_linked_list_modify(list_haed, &modify, compare_call_back, &persion6);
	printf("\nsingly linked list modify end\n");
	singly_linked_list_print_value(list_haed, print_call_back);
	

	/*  销毁链表函数声明 int singly_linked_list_destroy(struct singly_linked_list* list_haed)  */
	singly_linked_list_destroy(list_haed);
	list_haed = NULL;

}


int main(void)
{
	singly_linked_list_test();
	return 0;
}