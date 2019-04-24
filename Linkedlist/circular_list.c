#include"circular_list.h"

circular_list* ci_createList(void)
{
	circular_list* list = (circular_list*)malloc(sizeof(circular_list));
	if(!list)
	{
		perror("malloc:");
		exit(-1);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size =0;
	return list;
}
	
void ci_destoryList(circular_list* circular_list)
{
	if(circular_list->base!=NULL)
		free(circular_list->base);
	free(circular_list);
}
		
int ci_getSize(circular_list* circular_list)
{
	return circular_list->size;
}

bool ci_isEmpty(circular_list* circular_list)
{
	return circular_list->head == NULL;
}

int ci_append(circular_list*circular_list,int element)
{
	if(circular_list->size == 0)
	{
		circular_list->head = (cnode*)malloc(sizeof(cnode));
		circular_list->tail = circular_list->head;
		circular_list->head->data = element;
		circular_list->head->next = circular_list->head;
		++circular_list->size;
		return element;
	}
	else
	{
		circular_list->tail->next = (cnode*)malloc(sizeof(cnode));
		circular_list->tail->next->data = element;
		circular_list->tail->next->next = circular_list->head;
		circular_list->tail = circular_list->tail->next;
		++circular_list->size;
		return element;
	}
}

void ci_print(circular_list* circular_list)
{
	int i=0;
	cnode* p = circular_list->head;
	while(i<circular_list->size)
	{
		printf("circular list [%d]:%d.\n",i,p->data);
		p=p->next;
		++i;
	}
}
	
int ci_insertIndex(circular_list* circular_list,int index ,int element)
{
	if(circular_list->size == 0)//index must equal 0, only can insert head.
	{
		if(index!=0)
		{
			printf("current list size is 0,index must equal to 0.\n");
			return -1;
		}
		else
		{
			ci_append(circular_list,element);
		}
	}
	else//size > 0,index belong to 0~size -1.
	{
		if(index <0 || index>=circular_list->size)
		{
			printf("current size is %d,index must in 0 ~ %d!\n",circular_list->size,circular_list->size -1);
			return -1;
		}
		if(index ==0)	//insert head
		{
			circular_list->head = (cnode*)malloc(sizeof(cnode));
			circular_list->head->next = circular_list->tail->next;
			circular_list->head->data = element;
			circular_list->tail->next = circular_list->head;
			++circular_list->size;		
			return element;
		}
		else
		{
			int i=1;
			cnode*q = (cnode*)malloc(sizeof(cnode));
			q->data = element;
			cnode* p = circular_list->head;
			while(i<index)
			{
				p=p->next;
				++i;
			}//p定位到插入节点前一个节点
			q->next = p->next;
			p->next = q;
			++circular_list->size;
			return element;
		}
	}		
}

int ci_deleteIndex(circular_list* circular_list,int index)
{
	if(circular_list->size == 0)
	{
		printf("no elements in list!.\n");
		return -1;
	}
	else
	{
		if(index <0 || index>=circular_list->size)
		{
			printf("current size is %d,index must in 0 ~ %d!\n",circular_list->size,circular_list->size -1);
			return -1;
		}
		if(index ==0)	//delete head
		{
			int value;
			cnode*p = circular_list->head;
			value = p->data;
			circular_list->head = p->next;
			circular_list->tail->next = p->next;
			
			free(p);
			--circular_list->size;		
			return value;
		}
		else if(index == circular_list->size -1)	//delete tail
		{
			int value,i=1;
			cnode* p = circular_list->head;
			cnode* q = circular_list->tail;
			while(i<index)
			{
				p=p->next;
				++i;
			}//p定位到尾节点前一个节点
			value = p->next->data;
			circular_list->tail = p;
			p->next = circular_list->head;
			free(q);
			--circular_list->size;
			return value;
		}
		else
		{
			int value,i=1;
			cnode*q;
			cnode* p = circular_list->head;
			while(i<index)
			{
				p=p->next;
				++i;
			}//p定位到删除节点前一个节点
			
			q = p->next;
			p->next = q->next;
			free(q);
			--circular_list->size;
			return value;
		}
		
	}
}
	