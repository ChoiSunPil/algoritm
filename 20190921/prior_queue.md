# c++ 우선순위 큐 다루기

####  template <class T, class Container = vector<T> ,class Compare = less<typename Container::value_type> > class priority_queue;
1. primitive type 오름차순

   ```c++
   #include <queue>
   #include <vector>
   #inclue <functional>
   using namespace std;
   int main()
   {
     //구현
     priority_queue<int> pq();
     //또는
     //priority_queue<int,vector<int>,less<int>> pq; 
   }
   ```

   

2. primitive type 내림 차순

  ```c++
   #include <queue>
   #include <vector>
#inclue <functional>
  using namespace std;
  int main()
  {
    //구현
    priority_queue<int,vector<int>,greater<int>> pq; 
  }
  ```
  
3. 구조체 정렬 커스텀
  
  ```c++
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
   ```
   
   ### 결론
   
   vector sort 할때랑, pq 정렬 할때랑 순서가 반대이다. 주의 필요
