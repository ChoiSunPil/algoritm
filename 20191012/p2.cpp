#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct car{
string plate;
int odo;
};
struct cmp{
  bool operator()(car & a, car &b) //first 내림 차순, second 오름 차순 , 내림은 < true , 오름은 > true
  {  
    if(a.odo > b.odo)
      	return true;
    else if(a.odo == b.odo)
    {
        if(a.plate > b.plate)
            return true;
        else
            return false; 
    }
    else
      return false;
  }
};
string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
    string answer = "";
    priority_queue<car , vector<car>,cmp > pq;
    for(int  i = 0 ; i < n ; i++)
    {
        car cars;
        cars.plate = plates[i];
        cars.odo = odo[i];
        pq.push(cars);
    }
    for(int i = 0 ; i < k ; i++ )
    {
        car c;
        c.plate = pq.top().plate;
        c.odo =pq.top().odo;
        c.odo += drives[i];
        pq.pop();
        pq.push(c);
    }
    answer = pq.top().plate;
    return answer;
}
int main()
{
    int n = 6;
    int plate[] ={};
    int odo[] ={};
    int k =8;
    int drives


}
