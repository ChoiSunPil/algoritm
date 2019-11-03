#include <string>
#include <vector>

using namespace std;
struct point{
    int  i;
    int  j;
};
vector<vector<point> > alpha (26);
point findCenter(vector<vector<int> > &visited)
{
    point p = {-1,-1};

    for(int  i = 0 ; i < visited.size(); i++)
    {


    }

    return p;
}
bool findStar(vector<point>& p ,int size,int boardSize)
{
    vector<vector<int> > visited(boardSize , vector<int>(boardSize));
    for(int i = 0 ; i < p.size() ;i++)
    {
        visited[p[i].i][p[i].j]= 1;
    }
    point center = findCenter(visited);
    if(center.i == -1)
        return false;
    
    



}
int solution(vector<string> board) {
    int answer = 0;
    for(int  i = 0 ;i < board.size(); i++)
    {
        for(int  j = 0 ; j <board[i].size();j++)
        {
            alpha[board[i][j]-'A'].push_back(point(i,j));
        }
    }

    for(int i =0 ; i<alpha.size() ;i++)
    {
        if(alpha[i].size()> 0 && alpha[i].size()%2 ==1)
        {
            point p = findCenter(alpha[i]);
            for(int j =  board.size()-1 ; j >=0 ;j++)
            {
                if(j%2 ==0)
                    continue;
                if(findStar(p,j,board.size()))
                { 
                    answer++;
                    break;
                }
            }
        }
    }
    return answer;
}
int main()
{


}