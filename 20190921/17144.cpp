#include <iostream>
#include <vector>
using namespace std;
int posX[] = {-1,0,1,0};
int posY[] = {0,1,0,-1};
int calSum(vector< vector<int> > &table)
{
int result = 0;
    for(int  i= 0 ; i < table.size();i++)
    {
        for(int j = 0 ; j < table[0].size();j++)
        {
            if(table[i][j]!=-1)
                result += table[i][j];
        }
    }

    return result;
}



void timeForTable(vector< vector<int> > &table,int time)
{

while(time > 0)
{
vector< vector<int> > tmp(table.size());
for(int  i = 0 ; i < table.size() ;i++)
    tmp[i].resize(table[0].size());

/**미세먼지 확장 구간**/
for(int i = 0 ; i < table.size();i++)
{

for(int  j = 0 ; j < table[0].s

ize();j++)
{

    for(int  k = 0 ; k < 4 ; k++)
    {
        if((i+posX[k] >0 && i+posX[k] <table[0].size()) &&(j+posY[k] >0 && j+posY[k] <table.size()))
        {
            if(table[i+posX[k]][j+posY[k]]!= -1)
            {
                tmp[i+posX[k]][j+posY[k]]+=table[i][j]/5;
            }
        } 
    }
}
}


for(int i = 0 ; i < table.size();i++)
{
for(int  j = 0 ; j < table[0].size();j++)
{
    if(table[i][j] > 0){
    for(int  k = 0 ; k < 4 ; k++)
    {
        if((i+posX[k] >0 && i+posX[k] <table[0].size()) &&(j+posY[k] >0 && j+posY[k] <table.size()))
        {
            if(table[i+posX[k]][j+posY[k]]!= -1)
            {
               table[i][j] -=table[i][j]/5;
            }
        } 
    }
    tmp[i][j] = table[i][j];
    }
}
}
table = tmp;
for(int i = 0 ; i < table.size();i++)
{
for(int  j = 0 ; j < table[0].size();j++)
{
cout<<table[i][j]<<" ";
}
cout<<endl;
}
cout<<endl;





/***공기 청정기 구간***/





time--;     
}

}
int main()
{
int R,C,T;
vector< vector<int> > table;
cin>>R>>C>>T;
for(int i = 0 ; i <R ; i++ )
{
    vector<int> tmp;
    for(int  j = 0 ; j < C ;j++)
    {
        int num;
        cin>>num;
        tmp.push_back(num);
    }
    table.push_back(tmp);
}
timeForTable(table,T);
cout<<calSum(table)<<endl;
return 0;
}
