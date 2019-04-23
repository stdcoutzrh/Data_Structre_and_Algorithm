#include"linked_list_stack.h"

 
linked_list_stack* ll_createStack(void)
{
	linked_list_stack* stack = (linked_list_stack*)malloc(sizeof(linked_list_stack));
	if(!stack)
	{
		perror("malloc:");
		exit(-1);
	}
	stack->size = 0;
	stack->base = stack->top = NULL;
	return stack;
}

void ll_destoryStack(linked_list_stack* linked_list_stack)
{
	if(linked_list_stack->top!=NULL)
		free(linked_list_stack->top);
	if(linked_list_stack->base!=NULL)
		free(linked_list_stack->base);
	
	free(linked_list_stack);
}


bool ll_isEmpty(linked_list_stack*linked_list_stack)
{
	return linked_list_stack->size == 0;
}

int ll_getSize(linked_list_stack*linked_list_stack)
{
	return linked_list_stack->size;
}

void ll_print(linked_list_stack*linked_list_stack)
{
	if(ll_isEmpty(linked_list_stack))
		printf("no elements in stack!\n");
	else
	{
		node*p=linked_list_stack->base;
		for(int i=0;i<linked_list_stack->size;++i)
		{
			printf("stack[%d]：%d.\n",i,p->data);
			p=p->next;
		}
		printf("current size : %d.\n",linked_list_stack->size);
	}
}
	

int ll_push(linked_list_stack*linked_list_stack,int element)
{
	node* node =(struct node*)malloc(sizeof(node));
	if(!node)
	{
		perror("malloc:");
		exit(-1);
	}
	node->data = element;
	node->next = NULL;
	if(ll_isEmpty(linked_list_stack))
	{
		linked_list_stack->top = linked_list_stack->base =node;
		++linked_list_stack->size;
		return element;
	}
	else
	{
		linked_list_stack->top->next=node;
		linked_list_stack->top = node;
		++linked_list_stack->size;
		return element;
	}
}	

int ll_pop(linked_list_stack*linked_list_stack)
{
	if(ll_isEmpty(linked_list_stack))
	{
		printf("pop failed! no elements in stack!\n");
		return -1;
	}
	int value =linked_list_stack->top->data,i=2;
	node*p = linked_list_stack->base;
	node*q = linked_list_stack->top;
	while(i<linked_list_stack->size)
	{
		p=p->next;
		++i;
	}
	linked_list_stack->top = p;
	free(q);
	--linked_list_stack->size;
	printf("pop value:%d.\n",value);
	return value;	
}
	