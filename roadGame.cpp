#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{    
int x;
int y;
};
struct Tree{
int index;
int left;
int right;   
}
int NodeList[100000];


vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    Node * root = new Node;
    Node * tmp = root;
    vector<vector<int> > answer;
    vector<node
    for(int i = 0 ;i < nodeinfo.size(); i++ )
    {
        NodeList[i].x = nodeinfo[i][0];
        NodeList[i].y = nodeinfo[i][1];
    }

    return answer;
}
int main()
{  
    int tmp[][2] = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    vector < vector<int> > answer;
    for(int  i = 0 ; i <9 ; i++)
    {
        vector<int> tmpArr(tmp[i], tmp[i] + sizeof(tmp[i]) / sizeof(int));
        answer.push_back(tmpArr);
    }
    sort(answer.begin(),answer.end(),cmp );
    for(int  i = 0 ; i < answer.size() ;i++)
    {
        
        cout<<"i : "<<i<<", "<< answer[i][0] <<", "<<answer[i][1]<<endl; 
    }


    return 0;
}