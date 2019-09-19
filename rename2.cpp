#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
struct user{
    string userId;
    string nickname;
};
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
    vector<user> userList;
    queue< pair<int,int> > op;
    for(int  i = 0 ; i < record.size();i++)
    {
        vector<string> tmp = split(record[i],' ');
        if(tmp[0].compare("Enter") == 0)
        {
            int check =0;
            int userIdx = 0;
            user tmpUser = {tmp[1],tmp[2]};
             for(int j = 0 ; j < userList.size(); j++)
            {
                if(tmp[1].compare(userList[j].userId)==0)
                {
                    pair<int,int> tmpOp(0,j);
                    userList[j].nickname =tmp[2];
                    check = 1;
                    op.push(tmpOp);
                    break;
                }
            }
            if(check == 0)
            {
                pair<int,int> tmpOp(0,userList.size());
                userList.push_back(tmpUser);
                op.push(tmpOp);
            }

        }
        else if(tmp[0].compare("Leave") ==0)
        {
             for(int j = 0 ; j < userList.size(); j++)
            {
                if(tmp[1].compare(userList[j].userId)==0)
                {
                 pair<int,int> tmpOp(1,j);
                 op.push(tmpOp);
                }
            }
        }
        else
        {
            for(int j = 0 ; j < userList.size(); j++)
            {
                if(tmp[1].compare(userList[j].userId)==0)
                {
                    userList[j].nickname =tmp[2];
                    break;
                }
            }
        }
    }
    while(op.empty() == 0)
    {
        string tmp;
        pair<int ,int> tmpOp = op.front();
        tmp.append(userList[tmpOp.second].nickname);
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