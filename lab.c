#include <stdio.h>
#include <mem.h>
void find_min();
void arrange_col();
void arrange_col();;
int A[100][100];

int row_num[101][101]; // 1~100까지 행별로 카운트
int col_num[101][101]; // 1~100까지 열 별로 카운트
int row_size = 3;
int col_size = 3;
int r,c, k;
int time = 0;

void arrange_row()
{
int buffer[100];
int max_row_size =0;
for(int  i = 0 ; i < col ;i++)
{
    for(int j =1 ; j <= 100 ; j++)
    {
        if(row_num[i] == j)
        {
        buffer[max_row_size] = i;
        buffer[max_row_size] =
        }
    }
}
if(max_row_size)

}
void arrange_col()
{
int buffer[200];


}
void find_min()
{
if(A[r][c] == k)
{
    printf("%d",time);
    return ;
}
if(time > 100)
{
    printf("%d",-1);
    return ;
}
if(row_size >= col_size)
{
arrange_row();
time++;
find_min();
}
else
{
arrange_col();
time++;
find_min();
}
}
int main()
{
scanf("%d %d %d",&r,&c,&k);
r -= 1;
c -= 2;
for(int  i =0 ; i < 3 ;i++)
{
    for(int j = 0 ; j <3 ; j++)
    {
        scanf("%d", &A[i][j]);
        row_num[i][A[i][j]]++;
        row_num[A[i][j]][j]++;
    }
}
/**********************/
find_min();

return 0;
}