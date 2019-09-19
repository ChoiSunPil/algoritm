#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int row ;
int col ;
int isUnique[8] = {0,};
string table[8][20]; // 한줄에 같은 속성의 값들 저장
vector <vector <int> > candiSet;
int answer;
bool checkUniq(vector<int> &v1 ,vector<int> &v2);


void findUniqueKey(vector<int> &keys){
set< vector <string> > uniqueChecker;


for(int  i =0 ; i < row ; i++)
{
    vector<string> tmp;
    for(int j = 0 ; j < keys.size(); j++)
        tmp.push_back( table[keys[j]][i]);
    uniqueChecker.insert(tmp);
}



if(uniqueChecker.size() == row)
{
    for(int i = 0 ; i < keys.size(); i++)
    {
        if(isUnique[keys[i]] != 0 && isUnique[keys[i]] < keys.size())
            return ;

    }
    for(int i = 0 ; i < keys.size();i++)
    {
        isUnique[keys[i]] = keys.size();
    }

    for(int  i = 0 ; i < keys.size(); i++)
    {
        cout<<keys[i]<<" ";
    }
    cout<<endl;
    candiSet.push_back(keys);
    return ;
}
else
{
    if(keys.size() == col)
       {
        return;
       } 
    for(int i = keys[keys.size()-1]+1 ; i < col ; i++)
    {
        vector<int> tmpKey;
        tmpKey.resize((int)keys.size());
        copy(keys.begin(),keys.end(),tmpKey.begin());
        if(isUnique[i] == 0 || isUnique[i] >= keys.size())
        {
            tmpKey.push_back(i);
            findUniqueKey(tmpKey);
        }
    }
}

}
int solution(vector<vector< string > > relation) {
    row = relation.size(); //튜플
    col = relation[0].size(); //속성
    for(int i = 0  ; i < row;i++)
    {
        for(int j = 0 ; j <col;j++)
        {
            table[j][i] = relation[i][j];
        }
    }

    for(int i = 0 ; i < col ; i++)
    {
        vector<int> keys;
        keys.push_back(i);
        findUniqueKey(keys);
    }

    for(int  i = 0 ; i < candiSet.size();i++)
    {
        bool check = true;
        for(int j = 0; j < candiSet.size();j++)
        {
            if(candiSet[i].size() > candiSet[j].size())
            if(checkUniq(candiSet[i],candiSet[j]) == false)
            {
                check =  false;
                break;
            }
        }
        if(check == true)
            answer++;
    }
    return answer;
}
bool checkUniq(vector<int> &v1 ,vector<int> &v2){

    bool check =true;
    int count = 0;
    for(int i = 0 ; i < v1.size();i++)
    {
        for(int j = 0 ; j < v2.size();j++)
            {
                if(v1[i] == v2[j])
                    count++;

            }
    }
    if(count == v2.size())
        check = false;

    return check;
}
int main()
{
vector<string> test[6];
vector< vector<string> > t;
test[0].push_back("010");
test[0].push_back("9065");
test[0].push_back("4118");


test[1].push_back("011");
test[1].push_back("9065");
test[1].push_back("4118");


test[2].push_back("010");
test[2].push_back("6496");
test[2].push_back("7812");



test[3].push_back("011");
test[3].push_back("6496");
test[3].push_back("7812");

test[4].push_back("010");
test[4].push_back("9065");
test[4].push_back("7812");



for(int i = 0 ; i < 5 ; i++)
    t.push_back(test[i]);

cout<<solution(t);

    return 0;
}