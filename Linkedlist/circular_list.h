/*circular_list.h:This is an implemention of circular linked list in C language.
 *Characteristic:
 *	1.Give an head pointer and tail pointer when defining an circular linked list.
 *  2.Support for adding and deleting operations.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct cnode
{
	int data;
	struct cnode* next;
}cnode;

typedef struct circular_list
{
	struct cnode* head;
	struct cnode* tail;
	int size;
}circular_list;

circular_list* ci_createList(void);
int ci_getSize(circular_list* circular_list);
bool ci_isEmpty(circular_list* circular_list);

int ci_append(circular_list*circular_list,int element);
void ci_print(circular_list* circular_list);
int ci_insertIndex(circular_list* circular_list,int index ,int element);
int ci_deleteIndex(circular_list* circular_list,int index);

#endif //CIRCULAR_LIST_H
	