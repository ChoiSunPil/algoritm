#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int table[12][12];
int answer = 0;
int total;
void check_table(int i , int j , int num)
{
  int k ;   
 for( k = 0 ; k < total ; k++)
 {  
     table[i][k] += num;
     table[k][j] += num;
 }
 k = 1;
 while(1)
 {
    int check = 0;
    if(i-k >-1 && j-k >-1)
    {
        table[i-k][j-k] +=num;
    }
    else
        check++;
    
    if(i-k > -1 && j+k < total)
    {
        table[i-k][j+k] +=num;
    }
    else
        check++;
     
    if(i+k <total && j+k < total)
    {
        table[i+k][j+k] +=num;
    }
    else
        check++;
      
    if(i+k <total && j-k > -1)
    {
        table[i+k][j-k] +=num;
    }
    else
        check++;
     
     
    if(check == 4)
        break;
     k++;
 }

}
void find_queen_place(int depth,int horizontal)
{
 if(depth == total-1 && table[depth][horizontal] == 0)
 { 
    answer++;
    return;
 }
 else if(table[depth][horizontal] > 0)
 {
     return ;
 }


 if(table[depth][horizontal] == 0)
 {
   check_table(depth,horizontal,1);
   
   for(int  i = 0 ; i < total ; i++)
       find_queen_place(depth+1,i);
    
   check_table(depth,horizontal,-1);
 }
 else
     return ;
}
int solution(int n) {
    total = n;
    for(int  i = 0 ; i <  n ; i++)
        find_queen_place(0,i);
    return answer;
}
int main()
{
    printf("%d",solution(4));


    return 0;
}