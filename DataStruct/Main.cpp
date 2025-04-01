#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct List_ {
	int size;
	int (*match)(const void* key1, const void* key2);
	void (*destroy)(void* data);
} List;

void destroy_int(void* data);

void my_destroy(void* data);
int main() {
	int* num = (int*)malloc(sizeof(int));  // 动态分配一个 int
	*num = 42;  // 赋值
	void* data = num;  // 将 int* 转为 void* 存储
	destroy_int(data);  // 输出: Destroying int: 42
	//num = NULL;//防止指针空悬
	printf("%d\n", *num);
	return 0;
}


void destroy_int(void* data) {
	int* ptr = (int*)data;  // 将 void* 转回 int*
	printf("Destroying int: %d\n", *ptr);
	free(ptr);  // 释放内存
}