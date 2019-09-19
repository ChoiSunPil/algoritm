#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{


/****
 *  파일 불러오기
 */
ifstream in("sample_input.txt");
int total_num;
int ***arr;
in>>total_num;
cout<<total_num<<endl;
arr = new int**[total_num];
for(int  i= 0; i < total_num ;i++)
{
int num;
in >> num;
cout<<num<<endl;   
arr[i] = new int*[num];
for(int k =0 ; k < num ; k++)
{
arr[i][k] = new int[num];
for(int a = 0 ; a <num ;a++)
{
    in>>arr[i][k][a];
}
}
}

/**********************************/




}