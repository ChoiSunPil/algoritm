#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int isVisited[200];
int networkNum = 0;
int solution(int n, vector<vector<int> > computers) {
    int answer = 0;


while(1)
{

    int f = -1;
    queue<int> q;
    for(int i = 0 ; i < n; i++)
    {
           if(isVisited[i] == 0)
           {
               f = i;
               break;
           }
    }
    if(f == -1)
        break;

    q.push(f);

    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();

        isVisited[tmp] =1;
        for(int i = 0 ; i < n ; i++)
        {
            if(computers[tmp][i] ==1 && tmp != i && isVisited[i] == 0)
               {
            
                   q.push(i);
               } 
        }
    }
    networkNum++;
}
answer = networkNum;



    return answer;
}
int main()
{
vector<int> a[3];
vector<vector <int> > b;
a[0].push_back(1);
a[0].push_back(1);
a[0].push_back(0);

a[1].push_back(1);
a[1].push_back(1);
a[1].push_back(1);

a[2].push_back(0);
a[2].push_back(1);
a[2].push_back(1);
for(int i = 0 ; i < 3 ; i++)
    b.push_back(a[i]);

cout<<solution(3,b)<<endl;



return 0;
}
