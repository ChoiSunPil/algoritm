#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;
struct pos{
    int r;
    int c;
};
int city[51][51];
vector<pos> house;
vector<pos> chicken;
int minChicken;
int N, M;
int visited[13] ={0,};
int distance(pos& a,pos& b)
{
    return abs(a.r - b.r) + abs(a.c - b.c);
}
int findMinDistance(vector<pos>& house,deque<pos>& chicken)
{
int res = 0;
vector<int> result(house.size(),50*50);  
for(int  j = 0 ; j < house.size(); j++)
    for(int  i = 0 ; i < chicken.size(); i++)
    {
        if(result[j] == 0)
        {
            result[i] = distance(house[j],chicken[i]);
        }
        else
        {
            int tmp = distance(house[j],chicken[i]);
            if(result[j] > tmp)
                result[j] = tmp;
        }
    }

for(int  i = 0; i < house.size(); i++)
    {
        res += result[i];
    }
return res;
}

void combination(deque<pos> v,int i)
{
    v.push_back(chicken[i]);
    visited[i] = 1;
    if(v.size() == M)
    {
        if(minChicken == 0)
        {
           minChicken = findMinDistance(house,v);
        }
        else
        {
            int tmp = findMinDistance(house,v);
            if(tmp < minChicken)
                minChicken =tmp;
        }
        
    }
    else
    {
        for(int  j =  i +1 ; j < chicken.size();j++)
        {
            if(visited[j] == 0)
            {
                combination(v,j);
            }
        }
    }
    v.pop_back();
    visited[i] = 0;
}

int main(){
deque<pos> d;
cin>>N>>M;
for(int  i = 1 ; i <= N ; i++)
{
    for(int  j = 1 ; j<=N ;j++)
    {
        pos tmp = {i,j};
        cin>>city[i][j];
        if(city[i][j] ==1)
        {
        
            house.push_back(tmp);
        }
        else if(city[i][j] == 2)
        {
            chicken.push_back(tmp);
        }
    }
}
for(int  i = 0 ; i < chicken.size() ; i++)
    combination(d,i);
cout<<minChicken;

return 0;
}