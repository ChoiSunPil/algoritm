#include <string>
#include <vector>
#include <iostream>

using namespace std;
int posX[] ={0,0,1,-1};
int posY[] ={1,-1,0,0};
int diagonalX[] ={1,1,-1,-1};
int diagonalY[] = {1,-1,1,-1};

bool checklocation(int  i , int j, int n,vector<string> & board)
{
    for(int  k = 0 ; k < 4 ; k++)
    {
        int tmpX = i + n*diagonalX[k];
        int tmpY = j + n*diagonalY[k];
        if(board[tmpX][tmpY] != board[i][j])
            return false;
    }
    return true;
}

bool findCenter(int i, int j, vector<string> & board)
{
    char tmp = board[i][j];
    for(int k = 0 ; k < 4 ;k++)
    {
        if(i+posX[k] < 0 || i+posX[k] >= board.size() || j+posY[k] < 0  || j+ posY[k] >= board.size())
        {   
            return false;
        }

        if(i+diagonalX[k] < 0 || i+diagonalX[k] >= board.size() || j+diagonalY[k] < 0  || j+ diagonalY[k] >= board.size())
        {   
            return false;
        }
        
        if(board[i+posX[k]][j+posY[k]]==1)
            return false;

        if(board[i+diagonalX[k]][j+diagonalY[k]]==0)
            return false;
    }

    return true;

}






int solution(vector<string> board) {
    int answer = 0;
    for(int  i = 0 ; i <board.size(); i++)
    {
        for(int j  = 0 ; j < board.size();j++)
        {
            if(findCenter(i,j,board) == true)
            {
                int k =1;
                while(1)
                {
                    cout<<1<<endl;
                    if(!checklocation(i,j,k,board))
                    {
                       if(k-1 > answer)
                            answer = k-1;
                        break;
                    }
                }

            }
        }
    }
    return 2*answer+1;
}

int main()
{
    string arr[] ={"ABCBA","DABAG","EBABH","FAJAI","AKLMA"};
    vector<string> a(arr,arr+5);
    cout<<solution(a);
    return 0;
}