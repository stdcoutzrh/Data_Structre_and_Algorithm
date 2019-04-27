/*array_queue.h:This is an implemention of linked_list_queue in C language.
 *Characteristic:
 *	1.Give an initial length when defining an linked_list_queue
 *  2.Support for enqueue and dequeue operations
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */
 
#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _list_queue_node
{
	int data;
	struct _list_queue_node *next;
}queue_node;

typedef struct _list_queue
{
	int num;
	queue_node *head;
	queue_node *tail;
}list_queue;

#define list_queue_is_empty(queue) ((queue->num) == 0)
list_queue *list_queue_create();
void list_queue_destroy(list_queue*queue);
int list_queue_enqueue(list_queue *queue,int data);
int list_queue_dequeue(list_queue *queue,int *data);
void list_queue_dump(list_queue*queue);

#endif //LINKED_LIST_QUEUE_H