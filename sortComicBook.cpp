#include <stdio.h>
#include <stdlib.h>
int result[100];
int main()
{
int total;
scanf("%d",&total);

for(int  i = 0 ; i < total ; i++)
{
int N;
int count = 0;
int itr = 1;
char* arr;
scanf("%d",&N);
arr =  (char*)malloc(sizeof(char)*N);
for(int j = 0 ; j < N ; j++)
{
    int num;
    scanf("%d",&num);
    if(num == 1)
    {
        count++;
        arr[0] =1;
    }
    else if(arr[num-2] == 0)
    {
        count++;
        arr[num-1] =1;
    }
    else 
    {
        arr[num-1] =1;
    }
}
result[i] = count;
}

for(int i = 0 ; i < total ; i++)
{
printf("#%d %d\n",i+1,result[i]);
}


return 0;
}