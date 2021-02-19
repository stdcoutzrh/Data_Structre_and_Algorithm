#include"single_list.h"

single_list* si_createSingleList(void)
{
	single_list* list = (single_list*)malloc(sizeof(single_list));
	if(!list)
	{
		perror("malloc:");
		exit(-1);
	}
	list -> head = NULL;
	list -> size =0;
	return list;
}

void si_destoryList(single_list*single_list)
{
	if(single_list->head!=NULL)
		free(single_list->head);
	free(single_list);
}
	
bool si_isEmpty(single_list*single_list)
{
	return single_list->head == NULL ;
}

int si_getSize(single_list*single_list)
{
	return single_list->size;
}

void si_print(single_list*single_list)
{
	if(single_list->size == 0)
		printf("empty single list!\n");
	else
	{
		int i = 0;
		snode* p = single_list->head;
		while(p!=NULL)
		{
			printf("single list[%d]:%d\n",i,p->data);
			p=p->next;
			++i;
		}
	}
}
			
int si_appendEnd(single_list*single_list,int element)
{
	//去掉node节省一个指针的内存 OVO~
	//snode * node = (snode*)malloc(sizeof(snode));	
	//node ->data = element;
	//node ->next =NULL;
	
	if(single_list->size == 0)
	{
		single_list->head = (snode*)malloc(sizeof(snode));
		if(!single_list->head)
		{
			perror("malloc:");
			exit(-1);
		}
		single_list->head->data = element;
		single_list->head->next =NULL;
	}
	else
	{	
		snode* p = single_list->head;
		while(p->next!=NULL)
		p=p->next;
		p->next = (snode*)malloc(sizeof(snode));
		if(!p->next)
		{
			perror("malloc:");
			exit(-1);
		}
		
		p->next->data = element;
		p->next->next =NULL;		
	}
	++single_list->size;
	return element;
}
	
int si_insertIndex(single_list*single_list,int index,int element)
{
	if(si_getSize(single_list)!=0)//current list is not empty,index is in 0 ~ size -1.
	{
		if((index<0 ||index >= single_list->size))
		{
			printf("current size is %d,legal index is in %d ~ %d! \n",
					si_getSize(single_list),0,si_getSize(single_list)-1);
			return -1;
		}
		else if(index == 0)	//insert head
		{
			snode*node = (snode*)malloc(sizeof(snode));
			if(!node)
			{
				perror("malloc:");
				exit(-1);
			}
			node -> data = element;
			node ->next = single_list->head;
			single_list->head = node;
			++single_list->size;
			return element;
		}
		else
		{
			int i = 0;
			snode* p = single_list->head;
			while(i<index-1)
			{	
				p=p->next;
				++i;
			}		
			snode*node = (snode*)malloc(sizeof(snode));
			if(!node)
			{
				perror("malloc:");
				exit(-1);
			}
			node -> data = element;
			node ->next = p->next;
			p->next = node;
			++single_list->size;
			return element;
		}
	}
	else//current list is empty ,lindex must equal to 0,insert head
	{
		if(index!=0)
		{
			printf("current list is empty ,lindex must equal to 0!\n");
			return -1;
		}
		else
		{
			snode*node = (snode*)malloc(sizeof(snode));
			if(!node)
			{
				perror("malloc:");
				exit(-1);
			}
			node -> data = element;
			node ->next = NULL;
			single_list->head = node;
			++single_list->size;
			return element;
		}			
	}
}

int si_deleteIndex(single_list*single_list,int index)
{
	if(index<0 ||index >single_list->size)
	{
		printf("current size is %d,legal index is in %d ~ %d! \n",
				si_getSize(single_list),0,si_getSize(single_list)-1);
		return -1;
	}
	else if(index == 0)	//delete first node
	{
		int value = single_list->head->data;
		snode* node = single_list->head;
		single_list->head = single_list->head->next;
		free(node);
		--single_list->size;
		return value;
	}
	else
	{
		int i = 0;
		snode* p = single_list->head;
		while(i<index-1)
		{	
			p=p->next;
			++i;
		}	
		int value = p->next->data;
		snode* node = p->next;
		p->next = p->next->next;
		free(node);
		--single_list->size;
		return value;
	}				
}

void si_reverse(single_list**d_single_list)
{
	single_list* nlist=(single_list* )malloc(sizeof(single_list));
	nlist->head = NULL;
	nlist->size = 0;
	
	snode*p = (*d_single_list)->head;	
	int value = 0;
		
	while(p!=NULL)
	{
		value = p->data;
		si_insertIndex(nlist,0,value);			
		p=p->next;
		si_deleteIndex(*d_single_list,0);
	}
	*d_single_list = nlist;
}

bool si_isCyclic(single_list*single_list)
{
	//fast slow pointer
	struct snode* t1,*t2;
	t1=t2=single_list->head;
	
	while(t1&&t2)
	{
		//slow pointer
		t1=t1->next;
		//fast pointer
		t2= t2->next?t2->next->next:t2->next;
		if(t1 == t2)
			return true;
	}
	return false;
}
