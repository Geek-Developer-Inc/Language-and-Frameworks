#include <stdio.h>
#include "dynamic_array.h"


/*  动态数组测试用例  */

int main(void)
{
	struct dync_arr *ptr = dynamic_array_init(20);
	unsigned int capacity = 0;
	get_dynamic_array_capacity(ptr, &capacity);
	printf("arr capacity = %d\n", capacity);
	for (int i = 0; i < 21; i++)
	{
		dynamic_array_insert(ptr, i, 2);
	}
	unsigned int size = 0;
	get_dynamic_array_size(ptr, &size);
	printf("arr size = %d\n", size);
	capacity = 0;
	get_dynamic_array_capacity(ptr, &capacity);
	printf("arr capacity = %d\n", capacity);
	printf("print all\n");
	dynamic_array_print(ptr);
	printf("del val 8\n");
	dynamic_array_value_remove(ptr,8);
	printf("print all\n");
	dynamic_array_print(ptr);
	printf("del pos 0\n");
	dynamic_array_pos_remove(ptr, 0);
	printf("print all\n");
	dynamic_array_print(ptr);
	printf("clear all\n");
	dynamic_array_clear(ptr);
	dynamic_array_print(ptr);
	dynamic_array_destroy(ptr);

	return 0;
}
