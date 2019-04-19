/*dynamic_array.h:This is an implemention of static array in C language.
 *Characteristic:
 *	1.Give an initial size when defining an array
 *	2.Not support for dynamic expansion
 *  3.Support for adding and deleting operations
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */

#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
	int length;	//length of sta_array
	int size;	//the size of space already uesed in sta_array
	int *arr;	//the memory address of sta_array
}sta_array;

int st_length(sta_array *sta_array);	//get length of sta_array
int st_size(sta_array *sta_array);		//get size of sta_array
bool st_isEmpty(sta_array *sta_array);		//judge if array is empty

int st_getValueAt(sta_array *sta_array,int index);	//return the value of loc index element	
void st_print(sta_array *sta_array);	//print sta_array

void st_initArr(sta_array *sta_array);	//malloc space for sta_array

int st_insert(sta_array *sta_array,int index,int element);	//insert element
int st_delete(sta_array *sta_array, int index);	//delete index location element

int st_search(sta_array *sta_array, int element);	//search for element
int st_nextElem(sta_array *sta_array,int element);	//return the next value of element

#endif //STATIC_ARRAY_H