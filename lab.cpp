#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row_size = 3; //행의 개수
int col_size = 3; //열의 개수
int A[100][100];
struct Num{
    int num;
    int count;
};
int compareNum(Num &Num1 ,Num &Num2)
{
    if(Num1.count < Num2.count)
    {
        return true;
    }
    else if(Num1.count == Num2.count)
    {
        if(Num1.num < Num2.num)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}
void arrange_row()
{    
// 정렬하고 넣기
int max_col = 0;
for(int  i = 0 ; i < row_size; i++)
{
vector<Num> countNum;
for(int  j = 0 ; j < col_size ;j++)
{
int check = 0 ; //중복 여부 판단

for(int k = 0 ; k < countNum.size() ;k++)
{    
    if(countNum[k].num == A[i][j])
       {
           countNum[k].count++;
           check =1;
           break;
       }
}
if(check == 0)
{
    if(A[i][j] != 0){
    Num tmp;
    tmp.num = A[i][j];
    tmp.count = 1;
    countNum.push_back(tmp);
    }
}
}
sort(countNum.begin(),countNum.end(),compareNum);
for(int k = 0 ; k < col_size; k++)
        A[i][k] =0;



for(int k = 0 ; k < countNum.size(); k++)
{
if(k >=50)
    break;    
A[i][k*2] = countNum[k].num;
A[i][k*2+1] = countNum[k].count;

}

if(max_col < (countNum.size()*2))
    max_col = countNum.size()*2;
}

// 늘이난 열만큼 col_size 증가 
    col_size = max_col;
}





void arrange_col()
{
// 정렬하고 넣기
int max_row = 0;
for(int  i = 0 ; i < col_size; i++)
{
vector<Num> countNum;
for(int  j = 0 ; j < row_size ;j++)
{
int check = 0 ; //중복 여부 판단

for(int k = 0 ; k < countNum.size() ;k++)
{    
    if(countNum[k].num == A[j][i])
       {
           countNum[k].count++;
           check =1;
           break;
       }
}
if(check == 0)
{

    if(A[j][i] != 0){
    Num tmp;
    tmp.num = A[j][i];
    tmp.count = 1;
    countNum.push_back(tmp);
    }
}
}
sort(countNum.begin(),countNum.end(),compareNum);
for(int k = 0 ; k < row_size; k++)
        A[k][i] =0;

for(int k = 0 ; k < countNum.size(); k++)
{
if(k >=50)
    break;
A[k*2][i] = countNum[k].num;
A[k*2+1][i] = countNum[k].count; 
}

if(max_row < (countNum.size()*2))
    max_row = countNum.size()*2;
}

// 늘이난 열만큼 col_size 증가 
    row_size = max_row;

}
int main()
{
int r,c,k;
int time = 0;
cin>>r>>c>>k;
r--;
c--;
for(int i = 0 ; i < 3 ; i++)
{
    for(int  j = 0 ; j <3 ; j++)
    {
        cin>>A[i][j];
    }
}
/**********************/
while(1)
{
if(time > 100)
{
    cout<<-1<<endl;
    break;
}
else if(A[r][c] == k)
{
cout<<time<<endl;
    break;
}

if(row_size >= col_size)
{
arrange_row();
}
else
{
arrange_col();
}

// /*** Test ***/
// for(int  i = 0 ; i < row_size ; i++)
// {
//     for(int  j = 0 ; j < col_size ; j++)
//     {
//         cout<<" "<<A[i][j]<<" ";
//     }
//     cout<<endl;
// }
// cout<<endl;
// /***********/

time++;
}
/**********************/
    return 0;
}
