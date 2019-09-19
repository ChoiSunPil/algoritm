#include <iostream>
#include <queue>
using namespace std;


struct node{
    int num;
    int prior;
};
//M은 0부터
int findMax(queue<node>& q)
{
int maxP = 0;
queue<node> tmp = q;
while(!tmp.empty())
{
node n = tmp.front();
if(maxP < n.prior)
    maxP = n.prior;
tmp.pop();
}
return maxP;
}
int main()
{
int total;
int result[100];
cin>>total;


for(int  i = 0 ; i < total ; i++)
{
int N;
int M;
int count = 0;
int maxP = 0;
queue<node> q;
cin>>N>>M;

for(int  j = 0 ; j < N ; j++)
{
node n;
n.num = j;
cin>>n.prior;
if(maxP < n.prior)
    maxP = n.prior;
q.push(n);
}
while(!q.empty())
{  
node n = q.front();
q.pop();
if(n.prior >= maxP)
{
count++;
if(n.num == M)
    break;        
maxP  =findMax(q);
}
else
{
q.push(n);
}
}

result[i] = count;
}

for(int  i = 0 ; i < total ; i++)
{
    cout<<result[i]<<endl;
}





return 0;
}