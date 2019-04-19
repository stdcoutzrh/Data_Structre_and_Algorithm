#include"sta_array.h"

int st_length(sta_array *sta_array)
{
	return sta_array->length;
}

int st_size(sta_array *sta_array)
{
	return sta_array->size;
}

bool st_isEmpty(sta_array *sta_array)
{
	if(sta_array->size == 0)
		return true;
	return false;
}

int st_getValueAt(sta_array *sta_array,int index)
{
	if(index>sta_array->size || index<0)
		return -1;
	return sta_array->arr[index];
}


void st_print(sta_array *sta_array)	
{
	for(int i=0;i<sta_array->size;++i)
	{
		printf("sta_array[%d] : %d\n",i,sta_array->arr[i]);
	}
}

void st_initArr(sta_array *sta_array)
{
	sta_array->arr = (int*)malloc(sta_array->length*sizeof(int));
	if(!sta_array->arr)
	{
		perror("malloc:");
		exit(-1);
	}
}

int st_insert(sta_array *sta_array,int index,int element)
{
	if(sta_array->size >= sta_array->length ||index < 0)
	{
		return -1;
	}
	else
	{
		memmove(&sta_array->arr[index+1], &sta_array->arr[index],(sta_array->size - index) * sizeof(int));
		sta_array->arr[index] = element;
		++sta_array->size;
		return index;
	}
}

int st_delete(sta_array *sta_array, int index)
{
	int element = sta_array->arr[index];
	if(sta_array->size <= index || index < 0)
	{
		return -1;
	}
	else
	{
		memmove(&sta_array->arr[index], &sta_array->arr[index+1],(sta_array->size - index-1) * sizeof(int));
		--sta_array->size;
		return element;
	}	
}

int st_search(sta_array *sta_array, int element)
{
	for(int i=0;i<sta_array->size;++i)
	{
		if(sta_array->arr[i] == element)
			return i;
	}
	return -1;
}

int st_nextElem(sta_array *sta_array,int element)
{
	for(int i=0;i<sta_array->size-1;++i)
	{
		if(sta_array->arr[i] == element)
			return sta_array->arr[i+1];
	}
	return -1;	
}

/* test code*/

#if 1

int main(int argc,char**argv)
{
	printf("======static_array test=====\n");
	
	int loc = 0;
	sta_array my_array={20,0,NULL};
	st_initArr(&my_array);
	
	for(int i=0;i<10;i++)
	{
		st_insert(&my_array,i,i);
	}
	
	st_insert(&my_array,5,666);
	st_delete(&my_array,5);
	
	st_print(&my_array);
	printf("\n");
	
	loc=st_search(&my_array,6);
	printf("element 6 is at:%d\n",loc);
	
	printf("===static_array test finished===\n\n");
			
	return 0;
}

#endif
		