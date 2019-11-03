#include <stdio.h>

long zero[90];
long not_zero[90];
int main()
{
int n;
scanf("%d",&n);
zero[0] = 0;
not_zero[0] = 1;

for(int i= 1 ; i < n; i++)
{
    zero[i] = zero[i-1] + not_zero[i-1];
    not_zero[i] = zero[i-1];
}

printf("%ld\n",zero[n-1]+not_zero[n-1]);

return 0;
}