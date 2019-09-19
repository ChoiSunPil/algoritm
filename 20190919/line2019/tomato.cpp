#include <iostream>
#include <queue>
using namespace std;
int posX[] = {0,0,1,-1};
int posY[] = {1,-1,0,0};

int table[1000][1000];

int main()
{
int N, M;
queue< pair<int,int> > matureTomato;
int time = 0;
int none = 0;
cin>>M>>N;
for(int i = 0 ; i < N ; i++)
{
    for(int j = 0 ; j < M ; j++)
        {
            cin>>table[i][j];
            if(table[i][j] ==1)
            {
                
                matureTomato.push(pair<int,int>(i,j));
            }
            else if(table[i][j] == -1)
            {
                none++;
            }
        }
}
while(!matureTomato.empty())
{
queue <pair<int,int> > tmpQ;
    while(!matureTomato.empty())
    {
        pair<int,int> tmpP = matureTomato.front(); 
        matureTomato.pop();

        for(int  i = 0 ; i < 4 ;i++)
        {
            if((tmpP.first+posX[i]>= 0 && tmpP.first+posX[i] < N) &&(tmpP.second+posY[i] >=0)&&(tmpP.second+posY[i] <M))
            {            
                if(table[tmpP.first+posX[i]][tmpP.second+posY[i]] == 0)
            {
            table[tmpP.first+posX[i]][tmpP.second+posY[i]] = 1;
            tmpQ.push(pair<int,int>(tmpP.first+posX[i],tmpP.second+posY[i]));
            }
            }
        }
    }
// for(int i = 0 ; i < N ; i++)
// {
//     for(int j = 0 ; j < M ; j++)
//         {
//             cout<<table[i][j]<<" ";
//         }
//         cout<<endl;
// }
// cout<<endl;;
matureTomato = tmpQ;
time++;
}

for(int i = 0 ; i < N ; i++)
{
    for(int j = 0 ; j < M ; j++)
        {
            if(table[i][j] == 0)
                {
                    cout<<-1<<endl;
                    return 0;
                }
        }
}
cout<<time-1<<endl;
return 0;
}