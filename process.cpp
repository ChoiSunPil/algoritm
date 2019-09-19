#include <iostream>
using namespace std;
struct core{
int i;
int j;
};
int ConnectCount =0;
int min = 0;
int N;
core cores[12];
int table[12][12];
int result[50];
void findMin(core co , int count,int result){

if(count == N)
{
if(ConnectCount == N){
    if(result < min)
        {
            min = result;
        }
    }
    else
    {
    ConnectCount = N;
    min =result;
    }
return;
}
else
{
 /**
  *  Case1. 놓을 수 있는 선분 존재*
  * 
  *  Case2. 선분 놓을 수 없을 때
  * 
  * */
    for(int i= 0)



}
}
int main()
{
    int total;
    cin>>total;
    for(int i = 0;  i < total ; i++)
    {
        cin>>N;
        min = 0;
        ConnectCount = 0;
        int coreNum = 0;
        for(int  j = 0 ; j < N ; j++)
        {
            for(int j = 0 ; k < N ; k++)
               {
                   cin>>table[j][k];
                   cores[coreNum].i = j;
                   cores[coreNum].j = k;
                   coreNum++;
               } 
        }
        for(int  j = 0 ; j < N ; j++)
            findMin(cores[j],1);
        
        result[i] = min;
    }
    for(int i = 0;  i < total ; i++)
    {
        cout<<"#"<<i+1<<" "<<result[0]<<endl;
    }

    return 0;
}