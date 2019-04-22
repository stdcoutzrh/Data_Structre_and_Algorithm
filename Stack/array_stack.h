/*array_stack.h:This is an implemention of array_stack in C language.
 *Characteristic:
 *	1.Give an initial length when defining an array_stack.
 *	2.Support for dynamic expansion.
 *  3.Support for push and pop operations.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */
 
 #ifndef ARRAY_STACK_H
 #define ARRAY_STACK_H
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>
 #include<string.h>
 
 typedef struct array_stack
 {
	 int length;	
	 int size;	
	 int* arr;
 }array_stack;
 
array_stack* as_createStack(int length);
void as_destoryStack(array_stack* array_stack);

bool as_isEmpty(array_stack*array_stack);
bool as_isFull(array_stack*array_stack);
int as_getSize(array_stack*array_stack);
void as_print(array_stack*array_stack);

int as_push(array_stack*array_stack,int element);	//if stack is full ,push failed.
int as_pushAppend(array_stack*array_stack,int element);		//if stack is full,stack will expand 2 times as before.
int as_pop(array_stack*array_stack);

 #endif //ARRAY_STACK_H