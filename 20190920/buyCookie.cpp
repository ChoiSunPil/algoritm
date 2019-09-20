#include <iostream>
#include <vector>
#include <string>


using namespace std;
int maxSize = 0;
int table[2000][2000] = {0,};
int N;
int solution(vector<int> cookie) {
    int answer = -1;
    N = cookie.size();
    for(int i = 0 ; i < N ; i++)
        table[i][i] = cookie[i];

    
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = i+1 ; j<N ; j++)
        {
            table[i][j] =table[i][j-1] + cookie[j];
        }
    }

    for(int  i = 0 ; i < N-1 ; i++)
    {
        for(int j = i ; j <N-1; j++)
        {
            if(table[i][j] > table[j+1][N-1])
                break;

            for(int k = j+1 ; k < N ;k++)
            {
                if(table[i][j]==table[j+1][k])
                {
                    if(maxSize<table[i][j])
                    maxSize= table[i][j];
                }
                else if(table[i][j] <table[j+1][k])
                {
                    break;
                }
            }
        }
    }
        return maxSize;
}
int main()
{
int arr[] = {1,2,4,5};
vector<int> tmp(arr,arr+4);
cout<<solution(tmp);


return 0;
}