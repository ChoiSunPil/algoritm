#include <stdio.h>
#include <math.h>
unsigned long result[10];
int main()
{
int total;
scanf("%d",&total);
for(int i = 0 ; i < total; i++)
{
int N;
scanf("%d",&N);
for(int j = 1 ; j <= N ;j++)
{
unsigned long long sum = j;
for(int k = 1 ; k < j ; k++)
{
    sum *= j;
}
printf("sum : %lld\n",sum);
result[i] += (sum % 1000000007);
}
}

for(int  i =0 ; i < total ; i++)
{
    printf("#%d %ld\n",i+1,result[i]);
}


}
