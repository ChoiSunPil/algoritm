#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int row ;
int col ;
int isUnique[8] = {0,};
string table[8][20]; // 한줄에 같은 속성의 값들 저장
int answer = 0;
void findCondidate(int depth)
{
set<vector<string>> checker;
queue <int> q;
for(int i = 0; i< col ;i++)
{
    if()
    q.push()
}
if(checker.size() == row)
{

}

if(depth < col)
    findCondidate(depth+1);
}
int solution(vector<vector< string > > relation) {
      for(int i = 0  ; i < row;i++)
    {
        for(int j = 0 ; j <col;j++)
        {
            table[j][i] = relation[i][j];
        }
    }

    
    return answer;
}
int main()
{
vector<string> test[6];
vector< vector<string> > t;
test[0].push_back("100");
test[0].push_back("ryan");
test[0].push_back("music");
test[0].push_back("1");


test[1].push_back("200");
test[1].push_back("apeach");
test[1].push_back("math");
test[1].push_back("2");

test[2].push_back("300");
test[2].push_back("tube");
test[2].push_back("computer");
test[2].push_back("3");

test[3].push_back("400");
test[3].push_back("con");
test[3].push_back("computer");
test[3].push_back("4");

test[4].push_back("500");
test[4].push_back("muzi");
test[4].push_back("music");
test[4].push_back("5");

test[5].push_back("600");
test[5].push_back("apeach");
test[5].push_back("music");
test[5].push_back("6");



for(int i = 0 ; i < 6 ; i++)
    t.push_back(test[i]);

cout<<solution(t);

    return 0;
}