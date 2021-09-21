#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#if (1)
// 测试普通链表 Singly linked list
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

#else
// 测试企业链表 Singly linked list major
#include "singly_linked_list_major.h"

struct persion
{
	struct singly_linked_list_major_node* node;
	char name[16];
	int age;
	int id_card;
};

void print_call_back(struct singly_linked_list_major_node* value)
{
	if (NULL == value)
	{
		return;
	}
	struct persion *per_ptr = (struct persion*)value;
	printf("Name: %s   Age: %d   ID:%d\n", per_ptr->name, per_ptr->age, per_ptr->id_card);
}


int compare_call_back(struct singly_linked_list_major_node* value1, struct singly_linked_list_major_node* value2)
{
	if ((NULL == value1) || (NULL == value2))
	{
		return -1;
	}
	else
	{
		struct persion* per_ptr1 = (struct persion*)value1;
		struct persion* per_ptr2 = (struct persion*)value2;
		if ((0 == strcmp(per_ptr1->name, per_ptr2->name)) && (per_ptr1->age == per_ptr2->age) && (per_ptr1->id_card == per_ptr2->id_card))
		{
			return 0;
		}
	}
	return -2;
}

static void test_singly_linked_list_major(void)
{
	/*  int singly_linked_list_major_create(struct singly_linked_list_major** list_haed)  */
	printf("singly linked list major create\n");
	struct singly_linked_list_major* list_haed = NULL;
	singly_linked_list_major_create(&list_haed);

	struct persion person0, person1, person2, person3, person4, person5, person6;
	strcpy(person0.name, "person 0");
	person0.age = 20;
	person0.id_card = 88880;

	strcpy(person1.name, "person 1");
	person1.age = 21;
	person1.id_card = 88881;

	strcpy(person2.name, "person 2");
	person2.age = 22;
	person2.id_card = 88882;

	strcpy(person3.name, "person 3");
	person3.age = 23;
	person3.id_card = 88883;

	strcpy(person4.name, "person 4");
	person4.age = 24;
	person4.id_card = 88884;

	strcpy(person5.name, "person 5");
	person5.age = 25;
	person5.id_card = 88885;

	strcpy(person6.name, "person 6");
	person6.age = 26;
	person6.id_card = 88886;

	/*  int singly_linked_list_major_insert(struct singly_linked_list_major* list_haed, int list_pos, struct singly_linked_list_major_node* list_value)  */
	printf("\nsingly linked list major insert\n");
	singly_linked_list_major_insert(list_haed, 0, (struct singly_linked_list_major_node*)&person0);
	singly_linked_list_major_insert(list_haed, 0, (struct singly_linked_list_major_node*)&person1);
	singly_linked_list_major_insert(list_haed, 0, (struct singly_linked_list_major_node*)&person2);
	singly_linked_list_major_insert(list_haed, 3, (struct singly_linked_list_major_node*)&person3);
	singly_linked_list_major_insert(list_haed, 2, (struct singly_linked_list_major_node*)&person4);
	singly_linked_list_major_insert(list_haed, 1, (struct singly_linked_list_major_node*)&person5);
	singly_linked_list_major_insert(list_haed, 10, (struct singly_linked_list_major_node*)&person6);

	// person2  person5  person1  person0 person4  person3   person6
	/*  int singly_linked_list_major_print_value(struct singly_linked_list_major* list_haed, void(*print_call_back)(struct singly_linked_list_major_node*))  */
	singly_linked_list_major_print_value(list_haed, print_call_back);

	int ret_size = 0;
	singly_linked_list_major_get_size(list_haed, &ret_size);
	printf("\ninsert end size:%d\n\n", ret_size);

	/*  int singly_linked_list_major_by_pos_remove(struct singly_linked_list_major* list_haed, int list_pos)  */
	singly_linked_list_major_by_pos_remove(list_haed, 5);
	/*  int singly_linked_list_major_get_size(struct singly_linked_list_major* list_haed, int* ret_size)  */
	ret_size = 0;
	singly_linked_list_major_get_size(list_haed, &ret_size);
	printf("\nremove end size:%d\n\n", ret_size);
	singly_linked_list_major_print_value(list_haed, print_call_back);

	/*  int singly_linked_list_major_for_earch(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*), int* ret_value)  */
	int ret_value = 0;
	singly_linked_list_major_for_earch(list_haed, (struct singly_linked_list_major_node*)&person4, compare_call_back, &ret_value);
	printf("\nperson4 is %d\n", ret_value);


	/*  int intsingly_linked_list_major_by_value_remove(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node* list_value, int(*compare_call_back)(struct singly_linked_list_major_node*, struct singly_linked_list_major_node*))  */

	intsingly_linked_list_major_by_value_remove(list_haed, (struct singly_linked_list_major_node*)&person4, compare_call_back);
	singly_linked_list_major_print_value(list_haed, print_call_back);

	/*  int singly_linked_list_major_get_front(struct singly_linked_list_major* list_haed, struct singly_linked_list_major_node** ret_value);  */
	struct persion* new_value = NULL;
	singly_linked_list_major_get_front(list_haed, (struct singly_linked_list_major_node**)&new_value);
	printf("\n[Front] Name: %s  ,Age: %d  ,ID: %d\n", new_value->name, new_value->age, new_value->id_card);
	singly_linked_list_major_print_value(list_haed, print_call_back);
	
	/* int singly_linked_list_major_destroy(struct singly_linked_list_major* list_haed) */
	singly_linked_list_major_destroy(list_haed);
	list_haed = 0;
}


int main(void)
{
	test_singly_linked_list_major();
	return 0;
}


#endif
