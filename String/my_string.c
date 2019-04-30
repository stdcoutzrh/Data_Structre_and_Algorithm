/*string.h:This is an implemention of string.h in C language.
 *author:stdcoutzrh
 *emai:stdcoutzrh@gmail.com
 */
 
#ifndef MY_STRING_H
#define MY_STRING_H
 
#include<stdio.h>
 
int my_strLen(char*s)	//get length of s
{
	int i=0;
	if(s==NULL)
		return -1;
	while(*s++!='\0')
	{
		++i;
	}	
	return i;
}
 
//the destination string dest should be large enough to receive the copy
char* my_strCopy(char*dst,char*src)		//copy src to dst
{
	if(my_strLen(dst)<=my_strLen(src))
	{
		printf("length of src is more than dst,this may cause some problems!\n");
	}
	char* p = dst;
	while(*src!='\0')
	{
		*p++=*src++;
	}
	*(++p)='\0';
	return dst;
}

char* my_strnCopy(char*dst,char*src,int n)	//copy n bytes data from src to dst
{
	if(my_strLen(src)<n)
	{
		printf("copy failed,length of %s is less than %d. \n",src,n);
		return NULL;
	}
	esle if(my_strLen(dst)<=n)
	{
		printf("length of src is more than dst,this may cause some problems!\n");
	}
	int i=0;
	while(i<n)
	{
		dst[i]=src[i];
		++i;
	}
	dst[i]='\0';
	return dst;
}



int main(int argc,char**argv)
{
	char a[10]={0};
	char* d ="eeadasdasdsdasdasde";
	printf("%s\n",my_strCopy(a,d));
	return 0;
}
		
#endif //MY_STRING_H		
 
 