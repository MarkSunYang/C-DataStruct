#ifndef LIST_H

#define LIST_H
#include <stdlib.h>

/*Define a structure for linked list elements*/
typedef struct ListElmt_ {
	void* data;
	struct ListElmt_* next;
} ListElmt;

/*Define a structure for linked lists*/
typedef struct List_ {
	int size;
	int (*match)(const void* key1, const void* key2);
	void (*destroy)(void* data);
	ListElmt* head;
	ListElmt* tail;
} List;

/*Public Interface*/
void list_init(List* list, void (*destroy)(void* data));
void list_destroy(List* list);
int list_ins_next(List* list, ListElmt* element, const void* data);
int list_rem_next(List* list, ListElmt* element, void** data);

/*
 ((list)->size)：这是宏的替换内容，
list 是传入的参数（通常是一个指向结构体的指针）
-> 是用于通过指针访问结构体成员的运算符
size 是结构体中表示大小的成员变量
最外层的括号用于确保运算优先级
*/
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)	
#define list_next(element) ((element)->next)

#endif LIST_H