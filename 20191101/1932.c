#include <stdio.h>
#define MAX(a,b) a>b?a:b
long table[500][500];
long result[500][500];
int N;
void dp(int i, int j)
{
    if(result[i][j] == -1)
    {
        int tmp1 = -1;
        int tmp2 = -1;
        int res;
            tmp1 = result[i-1][j];
            tmp2 = result[i-1][j-1];
        res = MAX(tmp1,tmp2);
        result[i][j] = res + table[i][j];

    }
}
int main()
{
long max =0;
scanf("%d",&N);
for(int  i = 0 ; i < N ;i++)
{
    for(int j = 0 ; j <i+1 ;j++)
    {
        scanf("%d", &table[i][j]);

        if(i == 0 && j == 0)
            result[i][j] = table[i][j];
        else
            result[i][j] = -1;
    }
}

for(int  i = 1 ; i < N ; i++)
{
    for(int j = 0 ; j < i+1 ; j++)
    {
        dp(i,j);
    }
}



for(int i = 0 ; i < N; i++)
{
    if(max < result[N-1][i])
        max = result[N-1][i];
}
printf("%d\n",max);

return 0;
}