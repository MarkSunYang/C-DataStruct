#include "List.h"
#include <stdlib.h>
#include <string.h>

/*list_init*/
void list_init(List *list,void (*destroy)(void *data)) {
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
	return;
}

/* list_destroy */
//void list_destroy(List *list) {
//	void* data;
//	/*Remove each element*/
//	while (list_size(list)>0) {
//
//	}
//}

/* list_ins_next */
int list_ins_next(List* list,ListElmt *element,const void *data) {
	ListElmt* new_element;

	/*Allocate storage for the element*/
	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL)return -1;

	/*Insert element into the list */
	new_element->data = (void*)data; 
	if (element == NULL) {
		/*Handle insertion at the head of the list*/
		if (list_size(list) == 0)
			list->tail = new_element;
					
		new_element->next = list->head;
			list->head = new_element;
	}
	else
	{
		/*Handle insertion somewhere other than at the head */
		if (element->next == NULL)
			list->tail = new_element;

		new_element->next = element->next;
			element->next = new_element;
	}
	list->size++;
	return 0;
}

/* list_rem_next */
int list_rem_next(List *list,ListElmt,void **data) {
	ListElmt* new_element;
}

/* Remove the emlent from the list */

/* Free the storage allocated by the abstract datatype  */

/* Adjust the size of the list to account for the removed element */


int main() {

	return 0;
}