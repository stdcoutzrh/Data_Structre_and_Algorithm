/*double_list.h:This is an implemention of double linked list in C language.
 *Characteristic:
 *	1.Give an head pointer  when defining an double linked list.
 *	2.Support for reversing list.
 *	3.Support for adding and deleting operations.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct dnode
{
	int data;
	struct dnode* prior;
	struct dnode* next;
}dnode;

typedef struct double_list
{
	struct dnode* head;
	int size;
}double_list;

double_list* dou_createList(void);
void dou_destoryList(double_list* double_list);

int dou_getSize(double_list* double_list);
bool dou_isEmpty(double_list* double_list);

int dou_append(double_list*double_list,int element);
void dou_print(double_list* double_list);
int dou_insertIndex(double_list* double_list,int index ,int element);
int dou_deleteIndex(double_list* double_list,int index);

int dou_getIndex(double_list*double_list,int index);
void dou_reverseList(double_list*double_list);

#endif //DOUBLE_LIST_H
