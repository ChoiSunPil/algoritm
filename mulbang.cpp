#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
struct food{
    int num;
    int times;
};

// int solution(vector<int> food_times, long long k) {
//     int answer = 0;
//     long long count = 0;
//     long long i = 0;
//     long long endCount = 0;
//     while(1)
//     {
//     cout<<"i :"<<i<<endl;
//     if(food_times[i%food_times.size()] != 0)
//      {  
//         count++;
//         food_times[i%food_times.size()]--;
//         if(food_times[i%food_times.size()]==0)
//             endCount++;

//         if(count == k+1)
//         {
//             answer = (i%food_times.size()) +1;
//             break;
//         }

//      }
//     if(endCount == food_times.size())
//         {
//             answer = -1;
//             break;
//         }    
//     i++;
//     }

//     return answer;
// }
int solution(vector<int> food_times, long long k){
    int answer = 0;
    long long i = 0;
    long long count = 0;
    queue<food> q;
    for(int i = 0 ; i <food_times.size();i++)
    {
        food f = {i+1,food_times[i]};
        q.push(f);
    }
    while(!q.empty())
    {
        food tmp;
        count++;
        tmp = q.front();
        q.pop();
        if(count == k +1)
        {
            return tmp.num;
        }
        else
        {
            tmp.times--;
            if(tmp.times >0)
                q.push(tmp);
        }
    }
    
    return -1;
}
int main(){
    int arr[] = {3,1,2};
    vector<int> test(arr,arr+3);
    cout<<solution(test,5);
return 0;
}
