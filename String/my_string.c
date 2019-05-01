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
	else if(my_strLen(dst)<=n)
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

char* my_strCat(char*dst,char*src)
{
	char*p =dst;
	while(*p!='\0')
		++p;
	while(*src!='\0')
		*p++=*src++;
	*(p)='\0';
	return dst;
}

char* my_strnCat(char*dst,char*src,int n)
{
	if(my_strLen(src)<n)
	{
		printf("cat failed,length of %s is less than %d. \n",src,n);
		return NULL;
	}
	int i=0;
	char*p =dst;
	while(*p!='\0')
		++p;
	while(i<n)
	{
		*p++=*src++;
		++i;
	}
	*(p)='\0';
	return dst;
}

int my_strCmp(char*s1,char*s2)
{
	for(;(*s1 == *s2) && (*s1 != '\0');s1++,s2++)
        ;
    return *s1-*s2;
}

void* my_memcpy(void*dst,void*src,int count)
{
    void*ret = dst;
 
    while (count--) {
        *(char*)dst = *(char*)src;
        dst = (char*)dst + 1;
        src = (char*)src + 1;
    }
 
    return(ret);
}

void* my_memmove(void*dst, const void*src, int count)
{
    void * ret = dst;
    if (dst <= src || dst >= (src + count)) 
	{
        while (count--)
            *(char*)dst++ = *(char*)src++;
    }
    else 
	{
        dst = (char*)dst+count - 1;
        src = (char*)src+count - 1; 
        while (count--)
            *(char*)dst-- = *(char*)src--;
    }
    return(ret);
}

void* my_memset(void *s, int c, int n)
{
	char * tmp = (char *)s;
	while(n--> 0)
		*tmp++ = c;
	return s; 
}

int BruteForce(char*T,char*S,int tlength,int slength)
{
    int j=0,i=0;
    while(i<tlength && j<slength)
    {
        if(T[i]==S[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    return j==slength?i-slength:-1;
}

void get_next(char*S,int*next)
{
	int slen = my_strLen(S);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < slen - 1)
	{
		if (k == -1 || S[j] == S[k])
		{
			++j;
			++k;
			if (S[j] != S[k])
				next[j] = k;   
			else
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}
 
int kmp(char*T, char*S,int*next)
{
	int i=0,j=0;
	int tlen = my_strLen(T);
	int slen = my_strLen(S);
	while (i < tlen && j < slen)
	{  
		if (j == -1 || T[i] == S[j])
		{
			++i;
			++j;
		}
		else
		{    
			j = next[j];
		}
	}
	if (j == slen)
		return i - j;
	else
		return -1;
}

#endif //MY_STRING_H