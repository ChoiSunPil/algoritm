#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > paper(10,vector<int>(10));
struct point{
    int i;
    int j;
};

void print(vector<vector<int> > &tmp)
{
cout<<"result"<<endl;
 for(int  i =0 ; i < 10 ; i++)
 {
     for(int  j = 0; j < 10 ; j++)
        cout<<tmp[i][j]<<" ";
    cout<<endl;
 }
 cout<<endl;
}

bool checkRemain(vector<vector<int> >&tmp)
{
//남은 색종이 있는지 판별
for(int  i = 0 ; i <10 ; i++)
{
    for(int j = 0; j <10 ;j++)
    {
        if(tmp[i][j] ==1)
        {
            return false;
        }
    }
}
return true;
}


//사각형 유효성 검사
bool findSquare(vector<vector<int> >&tmp,const point & p,int n) 
{
    if(p.i +n >10 || p.j +n > 10)
        return false;

    for(int i = p.i ; i < p.i+n ; i++)
    {
        for(int  j = p.j ; j < p.j+n ; j++)
        {
            if(tmp[i][j]== 0 ||tmp[i][j]== 2)
                return false;
        }
    }
    return true;
}
//색종이 덮기
void coverPaper(vector<vector<int> >&tmp,const point & p,int n)
{
     for(int i = p.i ; i < p.i+n ; i++)
    {
        for(int  j = p.j ; j < p.j+n ; j++)
        {
            tmp[i][j] = 2; //덮기
        }
    }
}

int main()
{
vector<point> paint; //1 위치 자징 queue
int result = -1;
vector<int> order;
for(int  i = 0 ; i < 10 ; i++)
{
    for(int j = 0 ; j < 10 ;j++)
    {
        cin>>paper[i][j];
        if(paper[i][j] == 1)
        {
            point p = {i,j};
            paint.push_back(p);
        }
    }
}
for(int  i = 0 ; i <5 ; i++)
    order.push_back(i);


do{
int count = 0;
vector< vector<int> > tmp(10,vector<int>(10));
tmp.assign(paper.begin(),paper.end());
vector<int> v(5,5); 
for(int  i = 0; i < v.size(); i++)
{
     for(int j = 0 ; j < paint.size();j++)
     {  
         point p = paint[j];
         if(tmp[p.i][p.j] == 1)
         {
             if(findSquare(tmp,p,order[i]+1) == true)
            {
                    coverPaper(tmp,p,order[i]+1);
                    v[order[i]]--;
                    count++;
            }
         }
        if(v[order[i]] == 0)
            break;
     }
}


if(checkRemain(tmp) == true)
{
    if(result == -1)
    {
        result = count;
    }
    else if(result > count && count >-1)
        result = count;
}
}while(next_permutation(order.begin(),order.end()));


cout<<result<<endl;;
return 0;
}

