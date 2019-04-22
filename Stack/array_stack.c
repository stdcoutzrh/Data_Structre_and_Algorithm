#include"array_stack.h"

array_stack* as_createStack(int length)
{
	array_stack* stack = (array_stack*)malloc(sizeof(array_stack));
	if(!stack)
	{
		perror("malloc:");
		exit(-1);
	}
	stack->length = length;
	stack->size = 0;
	stack->arr = (int*)malloc(sizeof(int)*length);
	if(!stack->arr)
	{
		perror("malloc:");
		exit(-1);
	}
	printf("current stack size:%d.\n",stack->size);
	printf("current stack length:%d.\n",stack->length);
	return stack;
}

void as_destoryStack(array_stack* array_stack)
{
	if (array_stack->arr != NULL)
	{
		free(array_stack->arr);
	}
	free(array_stack);	
}

bool as_isEmpty(array_stack*array_stack)
{
	return array_stack->size == 0;
}

bool as_isFull(array_stack*array_stack)
{
	return array_stack->size == array_stack->length;
}

int as_getSize(array_stack*array_stack)
{
	return array_stack->size;
}

void as_print(array_stack*array_stack)
{
	if(as_isEmpty(array_stack))
	{
		printf("no elements in stack\n");
	}
	else
	{
		for(int i=0;i<array_stack->size;++i)
			printf("stack[%d]:%d,\n",i,array_stack->arr[i]);
		printf("current stack size:%d.\n",array_stack->size);
		printf("current stack length:%d.\n",array_stack->length);
	}
	printf("\n");
}

int as_push(array_stack*array_stack,int element)
{
	if(as_isFull(array_stack))
	{
		printf("push failed,stack is full.\n");
		return -1;
	}
	else
	{
		array_stack->arr[array_stack->size] = element;
		++array_stack->size;		
		return element;
	}
}

int as_pushAppend(array_stack*array_stack,int element)
{
	if(as_isFull(array_stack))
	{
		int *p = array_stack->arr;
		printf("stack is full,expand stack now!.\n");
		array_stack->length *=2;
		array_stack->arr = (int*)malloc(sizeof(int)*array_stack->length);
		if(!array_stack->arr)
		{
			perror("malloc:");
			exit(-1);
		}
		memmove(array_stack->arr,p,array_stack->size*sizeof(int));
		array_stack->arr[array_stack->size] = element;
		++array_stack->size;
		free(p);
		return element;				
	}
	else
	{
		array_stack->arr[array_stack->size] = element;
		++array_stack->size;		
		return element;
	}
}

int as_pop(array_stack*array_stack)
{
	int value;
	if(as_isEmpty(array_stack))
	{
		printf("pop failed,stack is empty.\n");
		return -1;
	}
	else
	{
		value = array_stack->arr[array_stack->size-1];
		--array_stack->size;
		printf("pop value:%d\n",value);
		return value;
	}
}
