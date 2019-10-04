#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define  IN  987654321
using namespace std;

int result = IN;

struct point{
    int i;
    int j;
};
vector<point> paint;
void print(vector<vector<int> > &tmp)
{
cout<<"result"<<"\n";
 for(int  i =0 ; i < 10 ; i++)
 {
     for(int  j = 0; j < 10 ; j++)
        cout<<tmp[i][j]<<" ";
    cout<<"\n";
 }
 cout<<"\n";
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
//색종이 제거
void removePaper(vector<vector<int> >&tmp,const point & p,int n)
{
     for(int i = p.i ; i < p.i+n ; i++)
    {
        for(int  j = p.j ; j < p.j+n ; j++)
        {
            tmp[i][j] = 1; //덮기
        }
    }
}
/**
 * tmp는 table , index 는 p vecotr index 
 * 
 */

void dfs(vector<vector<int> >&tmp ,int index ,int count, vector<int> sizeOfColor)
{
    // cout<<"index :"<<index<<cout
        for(int  i =5 ; i> 0; i--) //색종이 최대 크기 구하기
        {
            if(findSquare(tmp,paint[index],i) == true)
            {
                for(int  j =0 ; j <= i ;j++) //i 이하의 색종이 크기 보다 작게
                {
                    if(sizeOfColor[j-1] != 0){
                        coverPaper(tmp,paint[index],j);
                        count = count +1;
                        sizeOfColor[j-1]--;
                        // print(tmp);
                        if(checkRemain(tmp) == true)
                        {
                            removePaper(tmp,paint[index],j);
                            if(count < result)
                                result = count;
                                return; 
                        }

                        for(int  k = index+1 ; k  < paint.size(); k++ )
                            {
                                if(tmp[paint[k].i][paint[k].j]==1)
                                    {
                                        dfs(tmp,k,count,sizeOfColor);       
                                        break;
                                    }
                            }
                    removePaper(tmp,paint[index],j);
                    count--;
                    sizeOfColor[j-1]++;
                    }
                }

                break;
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
vector< vector<int> > paper(10, vector<int>(10));
vector<int> sizeOfColor(5,5);
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


if(paint.size() ==0)
{
    cout<<0<<"\n";
    return 0;
}

dfs(paper,0,0,sizeOfColor);

if(result == IN)
    cout<<-1<<"\n";
else
    cout<<result;


return 0;
}
