#include <iostream>
using namespace std;

int result = 200000;
void solution(int brown , int cony,int time)
{
if(brown == cony)
{
//cout<<"brown : "<<brown<<"cony :"<<cony<<"time"<<time<<endl;
if(result > time)
    result = time;
return;
}
else if(time > result)
{
    return ;
}
else if(cony > 200000 || brown > 200000 ||  brown < 0)
{
    return;
}
else
{
//cout<<"brown : "<<brown<<"cony :"<<cony<<endl;

 if(brown > cony)
 {
     solution(brown-1,cony+time+1,time+1);
 }
 solution(brown+1,cony+time+1,time+1);
 solution(brown*2,cony+time+1,time+1);  
}
}
int main()
{
int brown, cony;
cin>>brown>>cony;
solution(brown,cony,0);
cout<<result<<endl;
return 0;
}