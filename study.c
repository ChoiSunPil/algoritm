#include <stdio.h>
#include <stdlib.h>

typedef  struct _info{

int start;
int end;
}info;
int road[500][500];
info class[500];
int result[500];
int main()
{
int total;
scanf("%d",&total);
for(int i = 0 ; i  < total ; i++)
{
int N,s;
int count = 0;
scanf("%d %d",&N,&s);
for(int j = 0; j < N ; j++)
{
   scanf("%d %d",&class[j].start,&class[j].end);  
}
for(int j = 0; j < N ; j++)
    for(int j = 0 ; k < N ; k++)
        {
            scanf("%d",&road[j][k]);
        }
/*
 * 여기서 부터 구현  
 */






}


for(int i = 0 ; i < total ; i++)
    printf("#%d %d\n",i+1,result[i]);

return 0;
}
