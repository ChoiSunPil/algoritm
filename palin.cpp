#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char palin[2500];
int max = 0;
char* str;
void findPalin(int index,int count)
{ 
if(count > strlen(str))
{
    return ;
}
else 
{   
    char a[1500] ={0,};
    char b[1500] = {0.};//짝
    char c[1500] = {0.};//홀
    int check = 0;
    strncpy(a,str+index ,count);
    strncpy(b,str+index+count,count);
    strncpy(b,str+index+count,count-1);
    for(int i = 0 ; i < count ; i++)
    {
        if(a[i] != b[count-1-i])
        {
            check =1;
            break;
        }   
    }
    
    
    if(check ==1)
    {
        int ch =0;
        for(int  i = 0 ;i < count-1 ;i++)
        {
        if(a[i] != b[count-1-i])
            {
            ch =1;
            break;
            }       
        }
        if(ch == 0)
        {
        int len = strlen(b)+strlen(c);
        if(max < len)
            max =len;  
        }
        
    }
    else
    {
        int len = strlen(b)+strlen(a);
        if(max < len)
            max =len;
    }
    findPalin(index,count+1);
}    
}
int solution(char* s) {
    int answer = 0;
    int n = strlen(s);
    str = s;
    for(int  i = 0 ; i < n ; i++)
    {
        findPalin(i,1);
    }

    return answer;
}