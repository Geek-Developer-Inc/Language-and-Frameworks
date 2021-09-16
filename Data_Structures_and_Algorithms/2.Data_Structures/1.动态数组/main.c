#include <stdio.h>
#include <string.h>
#include "dynamic_array.h"


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
	struct persion* per_ptr = value;
	printf("Name: %s\tAge: %d\tID: %d\n", per_ptr->name, per_ptr->age, per_ptr->id_card);
}


int compare_call_back(void* value1, void* value2)
{
	if ((NULL == value1) || (NULL == value2))
	{
		return -1;
	}
	struct persion* per_ptr1 = value1;
	struct persion* per_ptr2 = value2;
	if ((0 == strcmp(per_ptr1->name, per_ptr2->name)) && (per_ptr1->age == per_ptr2->age) && (per_ptr1->id_card == per_ptr2->id_card))
	{
		return 1;
	}
	return 0;
}


static void dynamic_array_test(void)
{
	// 测试创建函数 dynamic_array_create(int capacit, struct dynamic_array** ret_array)
	struct dynamic_array *array = NULL;
	printf("dynamic array create, capacity: 5  size: 0\n");
	dynamic_array_create(5, &array);
	printf("capacity: %d\tsize: %d\n", array->capacity, array->size);

	struct persion presion0 = { "presion 0",20,22661 };
	struct persion presion1 = { "presion 1",21,22662 };
	struct persion presion2 = { "presion 2",22,22663 };
	struct persion presion3 = { "presion 3",23,22664 };
	struct persion presion4 = { "presion 4",24,22665 };
	struct persion presion5 = { "presion 5",25,22666 };
	struct persion presion6 = { "presion 6",26,22667 };
	struct persion presion7 = { "presion 7",27,22668 };

	// 测试插入函数 int dynamic_array_insert(struct dynamic_array* arr, int pos, void* arr_value)
	printf("\ndynamic array insert\n");
	dynamic_array_insert(array, 0, &presion0);
	dynamic_array_insert(array, 0, &presion1);
	dynamic_array_insert(array, 0, &presion2);
	dynamic_array_insert(array, 0, &presion3);
	dynamic_array_insert(array, 2, &presion4);
	dynamic_array_insert(array, 10, &presion5);

	// 测试获取数组长度和获取数组容量的函数
	// 获取数组容量的函数 dynamic_array_get_capacity(struct dynamic_array* arr, int* ret_capacity)
	// 测试自动扩容
	int ret_value = 0;
	dynamic_array_get_capacity(array, &ret_value);
	printf("\ndynamic array get capacity : %d\n", ret_value);
	// 测试获取数组长度 dynamic_array_get_size(struct dynamic_array* arr, int* ret_size)
	ret_value = 0;
	dynamic_array_get_size(array, &ret_value);
	printf("dynamic array get size : %d\n", ret_value);

	dynamic_array_insert(array, 1, &presion6);
	dynamic_array_insert(array, 0, &presion7);

	// 测试打印 dynamic_array_print_value(struct dynamic_array *arr, void(*print_call_back)(void*))
	// 正确顺序为: presion7 presion3 presion6 presion2 presion4 presion1 presion0 presion5
	printf("\npresion7 presion3 presion6 presion2 presion4 presion1 presion0 presion5\n");
	dynamic_array_print_value(array, print_call_back);

	printf("\nget capacity and size\n");
	ret_value = 0;
	dynamic_array_get_capacity(array, &ret_value);
	printf("\ndynamic array get capacity : %d\n", ret_value);
	// 测试获取数组长度 dynamic_array_get_size(struct dynamic_array* arr, int* ret_size)
	ret_value = 0;
	dynamic_array_get_size(array, &ret_value);
	printf("dynamic array get size : %d\n", ret_value);

	// 测试按位置删除  dynamic_array_by_pos_remove(struct dynamic_array* arr, int pos)
	printf("\ndynamic array by pos remove, pos 2 del presion6\n");
	dynamic_array_by_pos_remove(array, 2);
	dynamic_array_print_value(array, print_call_back);

	// 测试按值删除 dynamic_array_by_value_remove(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*))
	printf("\ndynamic array by value remove, del presion4\n");
	struct persion del = { "presion 4",24,22665 };
	dynamic_array_by_value_remove(array, &del, compare_call_back);
	dynamic_array_print_value(array, print_call_back);

	ret_value = 0;
	dynamic_array_get_capacity(array, &ret_value);
	printf("\ndynamic array get capacity : %d\n", ret_value);
	// 测试获取数组长度 dynamic_array_get_size(struct dynamic_array* arr, int* ret_size)
	ret_value = 0;
	dynamic_array_get_size(array, &ret_value);
	printf("dynamic array get size : %d\n", ret_value);

	// 测试遍历函数 dynamic_array_for_earch(struct dynamic_array* arr, void* value, int(*compare_call_back)(void*, void*), int* ret_pos)
	printf("\ndynamic array for earch presion 3\n");
	struct persion per_search = { "presion 3",23,22664 };
	ret_value = 0;
	dynamic_array_for_earch(array, &per_search, compare_call_back, &ret_value);
	printf("presion 3 is %d\n", ret_value);

	//int dynamic_array_get_value(struct dynamic_array* arr, int pos, void** ret_value)
	printf("\ndynamic array get value, pos 2\n");
	struct persion *ret_per = NULL;
	dynamic_array_get_value(array, 2, (void**)&ret_per);
	printf("Name: %s\tAge: %d\tID: %d\n", ret_per->name, ret_per->age, ret_per->id_card);

	// void dynamic_array_clear(struct dynamic_array* arr)
	dynamic_array_clear(array);
	printf("\nclear end capacity: %d\tsize: %d\n", array->capacity, array->size);
	// 测试销毁数组 dynamic_array_destroy(struct dynamic_array* arr)
	printf("\ndynamic array destroy\n");
	dynamic_array_destroy(array);
	array = NULL;
}


int main(void)
{
	dynamic_array_test();
	return 0;
}
