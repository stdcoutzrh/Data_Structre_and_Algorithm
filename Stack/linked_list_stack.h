/*linked_list_stack.h:This is an implemention of linked_list_stack in C language.
 *Characteristic:
 *	1.Give an base pointer and top pointer when defining an linked_list_stack.
 *  2.Support for push and pop operations.
 *  3.no size limits.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */
 
 #ifndef LINKED_LIST_STACK_H
 #define LINKED_LIST_STACK_H
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>
 #include<string.h>
 
 typedef struct node
 {
	 int data;
	 struct node*next;
 }node;
 
 typedef struct linked_list_stack
 {	
	 int size;	
	 struct node* base;
	 struct node* top;
 }linked_list_stack;
 
linked_list_stack* ll_createStack(void);
void ll_destoryStack(linked_list_stack* linked_list_stack);

bool ll_isEmpty(linked_list_stack*linked_list_stack);
bool ll_isFull(linked_list_stack*linked_list_stack);
int ll_getSize(linked_list_stack*linked_list_stack);
void ll_print(linked_list_stack*linked_list_stack);

int ll_push(linked_list_stack*linked_list_stack,int element);	
int ll_pop(linked_list_stack*linked_list_stack);

 #endif //LINKED_LIST_STACK_H