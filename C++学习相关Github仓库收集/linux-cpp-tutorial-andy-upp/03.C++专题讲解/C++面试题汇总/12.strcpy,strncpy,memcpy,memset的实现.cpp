//https://blog.csdn.net/cszhangchao/article/details/24327747
#include <stdio.h>
#include <assert.h>
char* mystrcpy(char* dest, const char* src)
{
    assert(dest != NULL && src != NULL);
    char* temp = dest;
    while((*temp++ = *src++) != '\0')
    {}
    return dest;
}

char* mystrncpy(char* dest, const char* src, int len)  
{  
    assert(dest!=NULL && src!=NULL);  
  
    char* temp=dest;  
    int i=0;  
  
    while(i++ < len  && (*temp++ = *src++)!='\0')  
    {}  
  
    if(*(--temp)!='\0')  
        *temp='\0';  
  
    return dest;  
}

void* mymemcpy(void* dest, void* src, int len)  
{  
    int i=0;  
    char* tempdest=(char*)dest;  
    char* tempsrc=(char*)src;  
  
    if(tempdest<tempsrc || tempdest>(tempsrc+len-1))  
    {  
        while(i<len)  
        {  
            *tempdest++ = *tempsrc++;  
            i++;  
        }  
    }  
    else  
    {  
        tempdest+=len;  
        tempsrc+=len;  
        i=len;  
        while(i>0)  
        {  
            *tempdest-- = *tempsrc--;  
            i--;  
        }  
    }  
    return dest;  
}  



int main()
{

    char* a = "hello workd";
    char* b = (char*)malloc(sizeof(12));
    
    b = mystrcpy(b,a);
    printf("b:%s", b);

    return 0;
}