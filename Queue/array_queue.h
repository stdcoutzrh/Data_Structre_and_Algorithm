/*array_queue.h:This is an implemention of array_queue in C language.
 *Characteristic:
 *	1.Give an initial length when defining an array_queue
 *	2.Support for dynamic expansion
 *  3.Support for push and pop operations
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */
 
 #ifndef ARRAY_QUEUE_H
 #define ARRAY_QUEUE_H
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<stdbool.h>
 #include<string.h>
 
 typedef struct array_queue
 {
	 int length;	
	 int size;	
	 int head;	//head指向头元素
	 int tail;	//tail指向尾元素下一个位置
	 int* arr;
 }array_queue;
 
array_queue* aq_createQueue(int length);
void aq_destoryQueue(array_queue* array_queue);

bool aq_isEmpty(array_queue*array_queue);
bool aq_isFull(array_queue*array_queue);
int aq_getSize(array_queue*array_queue);
void aq_print(array_queue*array_queue);

int aq_enqueue(array_queue*array_queue,int element);	//if queue is full ,enqueue failed.
int aq_dequeue(array_queue*array_queue);

 #endif //ARRAY_QUEUE_H