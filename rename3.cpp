#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
using namespace std;
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
    return internal;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userList;
    map<string,string>::iterator it;
    queue< pair<int,string> > op;
    for(int  i = 0 ; i < record.size();i++)
    {
        vector<string> tmp = split(record[i],' ');
        if(tmp[0].compare("Enter") == 0)
        {
            pair<int,string> tmpOp(0,tmp[1]);
            it =userList.find(tmp[1]);
            if(it != userList.end())
            {
                it->second = tmp[2];
            }
            else
            {
                userList.insert(pair<string,string>(tmp[1],tmp[2]));
            }
            op.push(tmpOp);
        }
        else if(tmp[0].compare("Leave") ==0)
        {
            it =userList.find(tmp[1]);
            if(it != userList.end())
            {
                pair<int,string> tmpOp(1,tmp[1]);
                op.push(tmpOp);
            }
        }
        else
        {
            it =userList.find(tmp[1]);
            if(it != userList.end())
            {
                it ->second  = tmp[2];
            }
        }
    }
    while(op.empty() == 0)
    {
        string tmp;
        pair<int ,string> tmpOp = op.front();
        tmp.append(userList.find(tmpOp.second)->second);
        if(tmpOp.first == 0)
        {
            tmp.append("님이 들어왔습니다.");
        }
        else
        {
            tmp.append("님이 나갔습니다.");
        }
    answer.push_back(tmp);
    op.pop();
    }
    return answer;
}
int main()
{  
    string arr[] ={"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> a(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector <string> b = solution(a);
    for(int  i = 0 ; i < b.size(); i++)
    {
        cout<<b[i]<<endl;
    }
    
    return 0;
}