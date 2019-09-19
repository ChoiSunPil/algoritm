#include <stdio.h>
int main()
{
int total;
int result[100000];
scanf("%d",&total);
for(int  i = 0 ; i <  total ; i ++)
{
int N;
int count = 0 ;
scanf("%d",&N);
for(int j= 0 ; j < N ; j++)
{
int num;
scanf("%d",&num);
    if(j == 0)
        count += num;
    else if(num == 0 || num == 1 || count == 1 || count == 0)
        count += num;
    else
        count *= num;
}
result[i] = count;
}

for(int  i = 0 ; i < total ; i++)
    printf("#%d %d\n",i+1,result[i]);


return 0;
}