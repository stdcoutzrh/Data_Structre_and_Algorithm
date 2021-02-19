#include"dyn_array.h"

dyn_array* dy_createArr(int x)
{
	const int min_size_of_dynamic_array = 1;
	if(x<min_size_of_dynamic_array)
	{
		x=min_size_of_dynamic_array;
	}
	dyn_array* array = (dyn_array*)malloc(sizeof(dyn_array));
	if(!array)
	{
		perror("malloc:");
		exit(-1);
	}
	array->cur_length = x;
	array->size = 0;
	array->arr = (int*)malloc(sizeof(int)*array->cur_length);
	if(!array->arr)
	{
		perror("malloc:");
		exit(-1);
	}
	return array;
}

void dy_destroyArr(dyn_array* dyn_array)
{
	free(dyn_array->arr);
	free(dyn_array);
}

int dy_size(dyn_array* dyn_array)
{
	return dyn_array->size;
}

int dy_curLength(dyn_array* dyn_array)
{
	return dyn_array->cur_length;
}

bool dy_isEmpty(dyn_array* dyn_array)
{
	if(dyn_array->size == 0)
		return true;
	return false;
}

void dy_print(dyn_array* dyn_array)
{
	if(dyn_array->size ==0)
	{
		printf("no elements in this array!\n");
	}
	else
	{
		for(int i=0;i<dyn_array->size;++i)
		{
			printf("array[%d]:%d\n",i,dyn_array->arr[i]);
		}
	}
}
	
int dy_getValueAt(dyn_array* dyn_array,int index)
{
	if(index>dyn_array->size || index<0)
		return -1;
	return dyn_array->arr[index];
}
	
int dy_search(dyn_array *dyn_array, int element)
{
	for(int i=0;i<dyn_array->size;++i)
	{
		if(dyn_array->arr[i] == element)
			return i;
	}
	return -1;
}

int dy_pushBack(dyn_array* dyn_array,int element)
{
	if(dyn_array->size >= dyn_array->cur_length)
	{
		
		int *p = dyn_array->arr;
		dyn_array->cur_length*=2;
		dyn_array->arr = (int*)malloc(sizeof(int)*dyn_array->cur_length);
		if(!dyn_array->arr)
		{
			perror("malloc:");
			exit(-1);
		}
		memmove(dyn_array->arr,p,dyn_array->size*(sizeof(int)));
		dyn_array->arr[dyn_array->size++]=element;
		free(p);
		return element;
	}
	else
	{
		dyn_array->arr[dyn_array->size++]=element;
		return element;
	}
}
		
				
int dy_popBack(dyn_array* dyn_array)
{
	if(dyn_array->size == 0)
	{
		printf("no elements in this array!\n");
		return -1;
	}
	else
	{
		return dyn_array->arr[--dyn_array->size];
	}		
}

int dy_insert(dyn_array* dyn_array,int index,int element)
{
	if(index<0||index>dyn_array->size)
	{
		printf("index > size!\n");
		return -1;
	}
	if(dyn_array->size >= dyn_array->cur_length)
	{
		int *p = dyn_array->arr;
		dyn_array->cur_length*=2;
		dyn_array->arr = (int*)malloc(sizeof(int)*dyn_array->cur_length);
		if(!dyn_array->arr)
		{
			perror("malloc:");
			exit(-1);
		}
		memmove(dyn_array->arr,p,index*(sizeof(int)));
		dyn_array->arr[index]=element;
		memmove(&dyn_array->arr[index+1],&p[index],(dyn_array->size-index)*(sizeof(int)));
		++dyn_array->size;
		free(p);
		return element;
	}
	else
	{
		memmove(&dyn_array->arr[index+1],&dyn_array->arr[index],(dyn_array->size-index)*(sizeof(int)));
		dyn_array->arr[index]=element;
		++dyn_array->size;
		return element;
	}	
}

int dy_delete(dyn_array* dyn_array,int index)
{
	if(index<0||index>dyn_array->size)
	{
		printf("index > size!\n");
		return -1;
	}
	int value = dyn_array->arr[index];
	memmove(&dyn_array->arr[index],&dyn_array->arr[index+1],(dyn_array->size-index)*(sizeof(int)));
	--dyn_array->size;
	return value;
}
