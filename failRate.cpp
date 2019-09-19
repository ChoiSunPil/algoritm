#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stage{
    int stageNum;
    int failUser = 0;
    int playUser = 0;
   long double failRate;
};
stage stageList[501];
bool cmp(stage &p1 , stage &p2)
{
if(p1.failRate > p2.failRate)
{
    return true;
}
else if(p1.failRate == p2.failRate)
{   
    if(p1.stageNum < p2.stageNum)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
else
{
    return false;
}


}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(int i = 0 ; i <= N ; i++)
    {
        stageList[i].stageNum = i+1;
    }
    for(int i = 0 ; i < stages.size() ; i++)
    {
        stageList[stages[i]-1].failUser++;
        for(int  j = 0 ; j <= stages[i]-1;j++)
            stageList[j].playUser++;
    }
    for(int i = 0 ; i < N ; i++)
    {
        if(stageList[i].playUser != 0)
            stageList[i].failRate = (long double)stageList[i].failUser/stageList[i].playUser;
        else
        {
            stageList[i].failRate = 0;
        }
        
        
    }
    sort(stageList,stageList+N,cmp);
    for(int  i = 0 ; i < N ; i++)
    {
        //cout<<"rate :"<<stageList[i].failRate<<" "<<"num : "<<stageList[i].stageNum<<endl;
        answer.push_back(stageList[i].stageNum);
    }
    return answer;
}
int main()
{
    int arr[] ={4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,6};
    vector<int> a(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector <int> result = solution(5,a);
    for(int  i =0 ; i < result.size(); i++)
    {
        cout<<result[i]<<endl;
    }

}