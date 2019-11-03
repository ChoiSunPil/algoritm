#include <string>
#include <vector>
#include <iostream>
int posX[] ={0,0,1,-1};
int posY[] = {1,-1,0,0};
using namespace std;
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