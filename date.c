#include <stdio.h>
#include <stdlib.h>
void find(int cur,int start,int count,int i);
int result[88];
int arr[35][35];
int N, K ,M;
int main()
{
int total;
scanf("%d",&total);

for(int i = 0; i < total; i++)
{
scanf("%d %d %d",&N,&K,&M);
for(int j= 0 ; j < N ; j++)
{
    for(int k = 0 ; k < N ; k++)
        {
        char it;   
        scanf(" %c",&it);
        if(it == 'N')
            arr[j][k] = 0;
        else
            arr[j][k] = 1;
        } 
}
for(int j = 0 ; j < N ; j++)
{
int isCycle = 0 ;
for(int k = 0 ; k < N ; k++)
{
    if(arr[j][k] == 0)
        isCycle++;
}
if(isCycle < N)
    find(j,j,1,i);
}
result[i] %= M;
}

for(int i = 0; i < total; i++)
{
printf("#%d %d\n",i+1,result[i]);
}


return 0;
}
// 시작 count 1부터
void find(int cur,int start,int count, int i)
{

if(count > 1 && count < K && cur == start)
{
    result[i]++;
}
else if(count == K && cur == start)
{
    result[i]++;
    return;
}
else if(count > K)
{
    return;
}

for(int j = 0 ; j < N ; j++)
{
    if(arr[cur][j] == 1)
        find(j,start,count+1,i);
}
}
