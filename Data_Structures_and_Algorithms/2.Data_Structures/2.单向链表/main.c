#define _CRT_SECURE_NO_WARNINGS
#define LINK_LIST 1

#include <stdio.h>
#include <string.h>

#if LINK_LIST
/*  测试单向链表普通版  */
#include "singly_linked_list.h"

struct person
{
	char name[64];
	int age;
	int id_card;
};

void print_call_back(void *value)
{
	struct person*per_ptr = (struct person*)value;
	printf("Name: %s\t  Age: %d\t  ID card: %d\n", per_ptr->name, per_ptr->age, per_ptr->id_card);
}

int compare_call_back(void *value1, void *value2)
{
	struct person*per_ptr1 = (struct person*)value1;
	struct person*per_ptr2 = (struct person*)value2;
	if ((0 == strcmp(per_ptr1->name, per_ptr2->name)) && (per_ptr1->age == per_ptr2->age) && (per_ptr1->id_card == per_ptr2->id_card))
	{
		return 0;
	}
	return -1;
}

#else
/*  测试单向链表企业版  */
#include "singly_linked_list_major.h"
struct person
{
	struct link_list_major_node head;
	char name[64];
	int age;
};

void print_call_back(struct link_list_major_node *value)
{
	struct person*per_ptr = (struct person*)value;
	printf("Name:%s\tAge:%d\n", per_ptr->name, per_ptr->age);
}

int compare_call_back(struct link_list_major_node *value1, struct link_list_major_node *value2)
{
	struct person*per_ptr1 = (struct person*)value1;
	struct person*per_ptr2 = (struct person*)value2;
	if ((0 == strcmp(per_ptr1->name, per_ptr2->name)) && (per_ptr1->age == per_ptr2->age))
	{
		return 0;
	}
	return -1;
}

#endif

int main(void)
{
	/***********************************[单向链表普通版]********************************************/
#if LINK_LIST
	/*  测试单向链表普通版  */
	int ret_val = 0;
	/*  创建链表  */
	struct link_list *list = link_list_init();
	if (list == NULL)
	{
		printf("link list init fail\n");
	}
	/*  链表插入节点  */
	struct person per0 = { "per 0",20,111111110 };
	struct person per1 = { "per 1",21,111111111 };
	struct person per2 = { "per 2",22,111111112 };
	struct person per3 = { "per 3",23,111111113 };
	struct person per4 = { "per 4",24,111111114 };
	struct person per5 = { "per 5",25,111111115 };
	struct person per6 = { "per 6",26,111111116 };
	link_list_insert(list, 0, &per0);  // 0 头插
	link_list_insert(list, 0, &per1);
	link_list_insert(list, 0, &per2);
	link_list_insert(list, 0, &per3);
	link_list_insert(list, 0, &per4);
	link_list_insert(list, 0, &per5);
	link_list_insert(list, 0, &per6);
	/*  打印链表内容  */
	link_list_print(list, print_call_back);
	/*  搜素链表  */
	printf("search link list\n");
	struct person find = { "per 3",23,111111113 };
	link_list_search(list, (struct link_list_node *)&find, compare_call_back,&ret_val);
	printf("search per 3 is: %d\n", ret_val);
	unsigned int ret_val1 = 0;
	link_list_get_size(list, &ret_val1);
	printf("link list size:%d\n", ret_val1);
	printf("Del pos 3\n");
	link_list_pos_remove(list, 3);
	link_list_print(list, print_call_back);
	//link_list_modify(list, 5, 88);
	link_list_print(list, print_call_back);
	// 返回链表第一个节点
	printf("=============================================\n");
	struct person *ret=(struct person*)link_list_get_first(list);
	printf("first node; Name: %s\t Age: %d\t ID: %d\n", ret->name, ret->age, ret->id_card);

	//修改某个节点的值
	printf("Modify node 2 value\n");
	struct person per4_1 = { "per 4",245,1110002 };
	link_list_modify(list, 2, (struct person*)&per4_1);
	link_list_print(list, print_call_back);
	link_list_destroy(list);

#else
		/***********************************[单向链表企业版]********************************************/
	/*  测试单向链表企业版  */
	struct link_list_major*list = link_list_major_init();

	struct person per0, per1, per2, per3, per4, per5, per6;
	strcpy(per0.name, "per 0");
	per0.age = 20;

	strcpy(per1.name, "per 1");
	per1.age = 21;

	strcpy(per2.name, "per 2");
	per2.age = 22;

	strcpy(per3.name, "per 3");
	per3.age = 23;

	strcpy(per4.name, "per 4");
	per4.age = 24;

	strcpy(per5.name, "per 5");
	per5.age = 25;

	strcpy(per6.name, "per 6");
	per6.age = 26;

	/*  添加节点1、2、3  */
	printf("add node 0、1、2、3、4、5、6\n");
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per0);
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per1);
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per2);
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per3);
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per4);
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per5);
	link_list_major_insert(list, 0, (struct link_list_major_node*)&per6);
	/*  打印节点1、2、3  */
	link_list_major_print(list, print_call_back);

	/*  查找节点2  */
	struct person find;
	strcpy(find.name, "per 3");
	find.age = 23;
	int ret_val = -1;
	link_list_major_search(list, (struct link_list_major_node*)&find, compare_call_back, &ret_val);
	printf("search %d is ok\n", ret_val);
	/*  删除节点 1  */
	printf("Del node 1\n");
	link_list_major_pos_remove(list, 1);
	/*  打印节点1、3  */
	link_list_major_print(list, print_call_back);
	printf("Del list\n");
	link_list_major_destroy(list);
#endif

	return 0;
}