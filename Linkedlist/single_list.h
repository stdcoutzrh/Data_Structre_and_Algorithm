/*single_list.h:This is an implemention of single list in C language.
 *Characteristic:
 *	1.Give an head pointer when defining an single list.
 *	2.Support for reversing list and judging if the list is cyclic.
 *  3.Support for adding and deleting operations.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H
 
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//node
typedef struct snode
{
	int data;
	struct snode*next;
}snode;

//single linked list
typedef struct single_list
{
	snode* head;
	int size ;
}single_list;

single_list* si_createSingleList(void);
bool si_isEmpty(single_list*single_list);
int si_getSize(single_list*single_list);
void si_print(single_list*single_list);

int si_appendEnd(single_list*single_list,int element);
int si_insertIndex(single_list*single_list,int index,int element);
int si_deleteIndex(single_list*single_list,int index);
void si_reverse(single_list**d_single_list);
bool si_isCyclic(single_list*single_list);

#endif	//SINGLE_LIST_H