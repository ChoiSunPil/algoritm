#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
bool cmpDE(int &a , int &b)
{
if(a >= b)
   return true;
else
{
    return false;
}
}


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> q;

    for(int  i = 0 ; i <operations.size();i++)
    {
        if(operations[i][0] == 'I')
        {
        string tmp = operations[i].substr(2,operations[i].length()-2);
        int num = atoi(tmp.c_str());    
        q.push_back(num);
        }
        else
        {
            sort(q.begin(),q.end(),cmpDE);
            if(operations[i][2] =='1') //최대
            {
                if(!q.empty())
                {
                   q.pop_front();
                }
            }
            else
            {
                if(!q.empty())
                {
                    q.pop_back();
                }
            }
        }
    }
    if(!q.empty()){
    sort(q.begin(),q.end(),cmpDE);
    answer.push_back(q.front());
    answer.push_back(q.back());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
int main()
{
string arr[] ={"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
vector<string> s(arr,arr+7);
vector<int> answer = solution(s);
cout<<"0 :"<<answer[0]<<"1 :"<<answer[1]<<endl;

}