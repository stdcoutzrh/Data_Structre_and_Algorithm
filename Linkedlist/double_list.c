#include"double_list.h"

double_list* dou_createList(void)
{
	double_list* list = (double_list*)malloc(sizeof(double_list));
	if(!list)
	{
		perror("malloc:");
		exit(-1);
	}
	list->head = NULL;
	list->size = 0;
	return list;
}
	
int dou_getSize(double_list* double_list)
{
	return double_list->size;
}

bool dou_isEmpty(double_list* double_list)
{
	return double_list->head == NULL ;
}

int dou_append(double_list*double_list,int element)
{
	struct dnode* node = (dnode*)malloc(sizeof(dnode));
	if(!node)
	{
		perror("malloc:");
		exit(-1);
	}
	node->data = element;
	if(dou_isEmpty(double_list))
	{
		double_list->head = node;
		node->prior = node->next = node;
		++double_list->size;
		return element;
	}
	else
	{
		node->prior = double_list->head->prior;
		node->next = double_list->head;
		double_list->head->prior->next =double_list->head->prior = node;
		++double_list->size;
		return element;
	}
}
		
void dou_print(double_list* double_list)
{
	int i =0;
	dnode*p = double_list->head;
	while(i<double_list->size)
	{
		printf("double list [%d]:%d.\n",i,p->data);
		p=p->next;
		++i;
	}
	printf("current size of list:%d.\n",double_list->size);
}
int dou_insertIndex(double_list* double_list,int index ,int element)
{
	if(double_list->size == 0)
	{
		if(index!=0)
		{
			printf("current list size is 0,index must equal to 0.\n");
			return -1;
		}
		else
		{
			dou_append(double_list,element);
		}
	}
	else
	{
		if(index <0 || index>=double_list->size)
		{
			printf("current size is %d,index must in 0 ~ %d!\n",double_list->size,double_list->size -1);
			return -1;
		}
		if(index ==0)	//insert head
		{
			dnode* node = (dnode*)malloc(sizeof(dnode));
			if(!node)
			{
				perror("malloc:");
				exit(-1);
			}
			node->data = element;
			node->next =double_list->head;
			node->prior = double_list->head->prior;
			double_list->head->prior->next = node;
			double_list->head->prior = node;
			double_list->head = node;
			++double_list->size;
			return element;
		}
		else
		{
			int i=1;
			dnode*p = double_list->head;
			dnode* node = (dnode*)malloc(sizeof(dnode));
			if(!node)
			{
				perror("malloc:");
				exit(-1);
			}
			node->data = element;
			while(i<index)
			{
				p=p->next;
				++i;
			}//p定位到插入节点前一个节点
			node->next = p->next;
			node->prior = p->next->prior;
			p->next->prior = node;
			p->next = node;
			++double_list->size;
			return element;
		}
	}	
}

int dou_deleteIndex(double_list* double_list,int index)
{
	if(double_list->size == 0)
	{
		printf("no elements in list!.\n");
		return -1;
	}
	else
	{
		if(index <0 || index>=double_list->size)
		{
			printf("current size is %d,index must in 0 ~ %d!\n",double_list->size,double_list->size -1);
			return -1;
		}
		if(index ==0)	//delete head
		{
			int value;
			struct dnode*p = double_list->head;
			value = p->data;
			
			p->prior->next = p->next;
			p->next->prior = p->prior;
			double_list->head = p->next;
			free(p);
			--double_list->size;		
			return value;
		}
		else if(index == double_list->size -1)	//delete tail
		{
			int value ;
			struct dnode*p = double_list->head->prior;
			value = p->data;
			p->prior->next = double_list->head;
			double_list->head->prior = p->prior;
			free(p);
			--double_list->size;
			return value;
		}
		else
		{
			int value,i=0;
			struct dnode* p = double_list->head;
			while(i<index)
			{
				p=p->next;
				++i;
			}//p定位到删除节点
			value = p->data;
			p->next->prior = p->prior;
			p->prior->next =  p->next;
			free(p);
			--double_list->size;
			return value;
		}	
	}
}

int dou_getIndex(double_list*double_list,int index)
{
	if(index>=double_list->size || index <0)
	{
		printf("current size is %d,index must in 0 ~ %d!\n",double_list->size,double_list->size -1);
			return -1;
	}
	int i =0;
	dnode* p = double_list->head;	
	while(i<index)
	{
		p=p->next;
		++i;
	}
	return p->data;
}

void dou_reverseList(double_list*double_list)
{
	int i =0;
	dnode*q = NULL;
	dnode* p = double_list->head;
	double_list->head = p->prior;
	while(i<double_list->size)
	{
		q=p->prior;
		p->prior = p->next;
		p->next =q;
		p=p->next;
		++i;
	}	
}
