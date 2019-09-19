#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int find_viewer(deque<int> &qu);
int result[10];

int main()
{
int total =10 ;
deque<int> qu ;
for(int i = 0 ; i  < total ; i++)
{
int N;
cin>>N;
int count = 0 ;
for(int j = 0 ; j < N ; j++){
    int number;
    cin>>number;    
    if(qu.size() != 5)
        {    
        qu.push_back(number);
        if(qu.size() == 5)
            count += find_viewer(qu);

        }
    else
        {
        qu.pop_front();
        qu.push_back(number);
        count += find_viewer(qu);
        }
}
result[i] = count;
}
for(int  i = 0 ; i < total ; i++)
{
cout<<"#"<<i+1<<" "<<result[i]<<endl;
}

return 0;
}

int find_viewer(deque<int> &qu)
{
if((qu[0]<qu[2]) && (qu[1]<qu[2])&& (qu[3]<qu[2]) && (qu[4]<qu[2]))
{
    int max1 = max(qu[0],qu[1]);
    int max2 = max(qu[3],qu[4]);

    return qu[2] - max(max1,max2);
}
else
{
    return 0;
}


}