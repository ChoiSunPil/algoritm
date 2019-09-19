#include <iostream>
#include <vector>

using namespace std;

void check(vector<vector<int> > &spaceArr , int  i , int j)
{
    if(i < 0 || i >= spaceArr.size())
    {
        return;
    }
    else if(j < 0 || j >= spaceArr.size())
    {
        return ;
    }
    else if(spaceArr[i][j] != 1)
    {
        return;
    }
    else
    {
        spaceArr[i][j] = -1;
        check(spaceArr,i+1,j);
        check(spaceArr,i-1,j);
        check(spaceArr,i,j+1);
        check(spaceArr,i,j-1);
    }
}
int findSpace(vector<vector<int> > &arr , int height)
{
vector<vector<int> > spaceArr;
int count = 0;
for(int i = 0 ; i < arr.size() ; i++)
{
vector<int> tmp;
for(int  j = 0 ; j < arr.size(); j++)
{
    int tm;
    if(arr[i][j] > height)
        tm = 1;
    else
        tm = 0;
    tmp.push_back(tm);
}
spaceArr.push_back(tmp);
}
for(int  i = 0 ; i < arr.size(); i++)
{
    for(int  j = 0 ; j < arr.size(); j++)
    {
        if(spaceArr[i][j] == 1)
        {
            count++;
            check(spaceArr,i,j);

        }
    }
}
return count;
}
int main()
{
int N;
int maxSpace = 0;
int max = 0;
cin>>N;
vector< vector<int> > arr;
for(int i = 0 ; i < N ; i++)
{
vector<int> tmp;
for(int  j = 0 ; j < N; j++)
{
    int tm;
    cin>>tm;
    if(max < tm)
        max = tm;
    tmp.push_back(tm);
}
arr.push_back(tmp);
}

for(int i = 0 ; i <= max ; i++)
{
    int result  =  findSpace(arr,i);
    
    if(maxSpace < result)
         maxSpace = result;
}
cout<<maxSpace;
return 0;
}