#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int posY[] = {-1,1,0,0};
int posX[] = {0,0,1,-1};

//반시계 방향 인덱스
int ccw[4] = { 2, 0, 3, 1 };
//시계 방향 인덱스
int cw[4] = { 2, 1, 3, 0 };

int main()
{
int arr[4][5];
int count = 0;
vector<pair<int,int> > ctr;
int index = 0;
ctr.push_back(pair<int,int>(1,0));
ctr.push_back(pair<int,int>(0,1));
ctr.push_back(pair<int,int>(-1,-0));
ctr.push_back(pair<int,int>(0,-1));
ctr.push_back(pair<int,int>(1,0));
int i = 2;
int j = 2; 
for(int  i = 0 ; i < 4 ; i++)
{
    for(int  j = 0 ; j < 5 ; j++)
    {
        arr[i][j] = count;
        count++; 
    }
}

for(int  i = 0 ; i < 4 ; i++)
{
    for(int  j = 0 ; j < 5 ; j++)
    {
       printf("%3d ",arr[i][j]);
    }
    cout<<endl;
}
cout<<endl;


		//공기청정기
		//위쪽
		int y = 2;
		int x = 0 + 1;
        int tmp = arr[y][x];
		arr[y][x] = -1;
		//반시계 공기청정
		for (int i = 0; i < 4; i++)
		{
			while (1)
			{
				int nextY = y + posY[ccw[i]];
				int nextX = x + posX[ccw[i]];
				
				if (nextY == 2 && nextX == 0)
					break;
				if (!(0 <= nextY && nextY < 4 && 0 <= nextX && nextX < 5))
					break;

                int tmp2 = arr[nextY][nextX]; 
				arr[nextY][nextX] = tmp;
                tmp = tmp2;
				y = nextY;
				x = nextX;
			}
		}









for(int  i = 0 ; i < 4 ; i++)
{
    for(int  j = 0 ; j < 5 ; j++)
    {
       printf("%3d ",arr[i][j]);
    }
    cout<<endl;
}


return 0;
}