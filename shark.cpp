#include <iostream>
#include <vector>
using namespace std;
int sea[20][20];
int N;
int fishCount = 0;

int main()
{
for(int  i = 0 ; i < N ;i++)
{
    for(int  j = 0 ; j < N; j++)
      {  
          cin>>sea[i][j];
          if(sea[i][j]> 0 && sea[i][j] < 9)
            fishCount++;
      }
}







    return 0;
}