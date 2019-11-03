#include <string>
#include <vector>
#include <iostream>
int posX[] ={0,0,1,-1};
int posY[] = {1,-1,0,0};
using namespace std;
int globalT;
int answer;
void dfs(int i , int j , int depth)
{
    if(globalT == depth)
    {
        if(i == 1 && j ==6)
        {
            answer++;
        }
    }
    else if( depth > globalT)
    { 
        
        return;
    }
    else
    {
    for(int  k = 0 ; k < 4 ;k++)
    {

        if(i+posX[k] == 0)
        {
            if(j+posY[k] >0 && j+posY[k]< 10)
                dfs(i+posX[k],j+posY[k],depth+1);
        }
        else if(i+posX[k]== 1)
        {
            if(j+posY[k] > 0 && j+posY[k]< 9)
                dfs(i+posX[k],j+posY[k],depth+1);
        }
        else if(i+posX[k] ==2)
        {
            if(j+posY[k] >0 && j+posY[k]< 7)
                dfs(i+posX[k],j+posY[k],depth+1);
        }   
    }
    }
}
int solution(int T) {
    globalT = T;
    if(T <= 1)
        return answer;


    dfs(1,6,0);

    return answer;
}
int main()
{
   cout<< solution(2);   
}