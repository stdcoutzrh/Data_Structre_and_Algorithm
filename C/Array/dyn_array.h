/*dynamic_array.h:This is an implemention of dynamic array in C language.
 *Characteristic:
 *	1.Give an initial size when defining an array
 *	2.Support for dynamic expansion
 *	3.Support for adding and deleting operations
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct 
{
	int cur_length;//current length of array
    int size;	//the number of elements in array
    int *arr;	//the memeory address of arr
}dyn_array;

dyn_array* dy_createArr(int x);		//create a dynamic array
void dy_destroyArr(dyn_array* dyn_array);	//destory a dynamic array

int dy_curLength(dyn_array* dyn_array);	//return the current length of elements in array
int dy_size(dyn_array* dyn_array);	//return the number of elements in array
bool dy_isEmpty(dyn_array* dyn_array);	//judge if the array is empty
void dy_print(dyn_array* dyn_array);	//print dyn_array

int dy_getValueAt(dyn_array* dyn_array,int index);	//return the value of loc index element
int dy_search(dyn_array *dyn_array, int element);	//search for element

int dy_pushBack(dyn_array* dyn_array,int element);	//push back
int dy_popBack(dyn_array* dyn_array);	//pop back

int dy_insert(dyn_array* dyn_array,int index,int element);
int dy_delete(dyn_array* dyn_array,int index);

#endif //DYNAMIC_ARRAY_H
