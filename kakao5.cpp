#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct structure{
    bool pole = false;
    bool beam = false;
    bool start = false;
    bool end = false;
}
structure table[1000][1000];
bool checkPole(int x, int y ,int opt)
{

}
bool checkBeam(int x, int y ,int opt)
{

}


vector<vector<int> > solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int> > answer;
    queue<vector<int> > created;
    queue<vector<int> > destroyed;
    for(int i = 0 ; i < build_frame ; i++)
    {
    vector<int> tmp;
    int x = build_frame[i][0];
    int y = build_frame[i][1]; 
    int a = build_frame[i][2]; //0 pole 1 beam
    int b = build_frame[i][3]; //0 destroy 1 create
    tmp.push_back(x);
    tmp.push_back(y);
    tmp.push_back(a);
    if(a == 0)
    {
        if(b ==0)
        {
            if(checkPole(x,y,0))
            {
                table[x][y].pole = false;
                tabel[x][y].start = false;
                destroyed.push(tmp);
            }
                
        }
        else
        {
           if(checkPole(x,y,1))
            {
                created.push(tmp);
            }
        }
    }
    else
    {
        if(b ==0)
        {
             if(checkBeam(x,y,0))
            {
                destroyed.push(tmp);
            }
        }
        else
        {
            if(checkBeam(x,y,1))
            {
                created.push(tmp);
            }
        }
    }
    
    }

    while(!created.empty())
    {
        int check = 0;
        vector<int> ans;
        queue< vector<int> > tmp = destroyed;
        while(!destroyed.empty())
        {



        }

        if(check == 0)
            answer.push_back(ans);
    }

    



    return answer;
}