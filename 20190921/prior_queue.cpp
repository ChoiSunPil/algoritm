 #include <queue>
#include <iostream>
#include <vector>
using namespace std;

struct point{
    int first;
    int second;
};
bool compare(point & a, point &b) //first 내림 차순, second 오름 차순 , 내림은 < true , 오름은 > true
  {  
    if(a.first < b.first)
      	return true;
    else if(a.first == b.first)
    {
      if(a.second>b.second)
        return true;
      else
        return false;
    }
    else
      return false;
  }



struct cmp{
  bool operator()(point & a, point &b) //first 내림 차순, second 오름 차순 , 내림은 < true , 오름은 > true
  {  
    if(a.first < b.first)
      	return true;
    else if(a.first == b.first)
    {
      if(a.second>b.second)
        return true;
      else
        return false;
    }
    else
      return false;
  }
};
int main(){
  priority_queue<point,vector<point >,cmp> pq;
  vector<point> a;
  point p = {1,3};
  pq.push(p);
  a.push_back(p);
  p.first =2;
  p.second =4;
  pq.push(p);
  a.push_back(p);
  p.first =1;
  p.second =4;
  pq.push(p);
  a.push_back(p);

  



  while(!pq.empty())
  {
      cout<<pq.top().first<<" "<<pq.top().second<<endl;
      pq.pop();
  }

    sort(a.begin(),a.end(),compare);
    for(int i = 0 ; i < a.size();i++)
    {
        cout<<"vector :"<<a[i].first<<" "<<a[i].second<<endl;
    }
}