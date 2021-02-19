#include"array_queue.h"

array_queue* aq_createQueue(int length)
{
	array_queue* queue = (array_queue*)malloc(sizeof(array_queue));
	if(!queue)
	{
		perror("malloc:");
		exit(-1);
	}
	queue->arr = (int*)malloc(sizeof(int)*length);
	if(!queue->arr)
	{
		perror("malloc:");
		exit(-1);
	}
	queue->length = length;
	queue->head = queue->tail = queue->size = 0;
	return queue;
}
		
void aq_destoryQueue(array_queue* array_queue)
{
	if(array_queue->arr!=NULL)
		free(array_queue->arr);
	free(array_queue);
}

bool aq_isEmpty(array_queue*array_queue)
{
	return array_queue->size == 0;
}

bool aq_isFull(array_queue*array_queue)
{
	return array_queue->size == array_queue->length;
}

int aq_getSize(array_queue*array_queue)
{
	return array_queue->size;
}

void aq_print(array_queue*array_queue)
{
	for(int i=0;i<array_queue->size;++i)
		printf("queue [%d]:%d.\n",i,array_queue->arr[i]);
	printf("current size is %d .\n",array_queue->size);
}

int aq_enqueue(array_queue*array_queue,int element)
{
	if(aq_isFull(array_queue))
	{
		printf("enqueue failed,queue is full!\n");
		return -1;
	}
	else
	{		
		array_queue->arr[array_queue->tail] = element;
		++array_queue->size;
		array_queue->tail = (array_queue->tail + 1) % array_queue->length;
		return element;
	}
	return -1;
}

int aq_dequeue(array_queue*array_queue)
{
	int value;
	if(aq_isEmpty(array_queue))
	{
		printf("dequeue failed,no elements in queue!\n");
		return -1;
	}
	else
	{
		value = array_queue->arr[array_queue->head];
		--array_queue->size;
		array_queue->head = (array_queue->head + 1) % array_queue->length;
		return value;
	}
}
