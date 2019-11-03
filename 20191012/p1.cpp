#include <string>
#include <vector>
#include <iostream>
using namespace std;




int solution(int n, vector<int> P) {
    int answer = 0;
    int count = 1;
    int minOil = P[0];
    answer+=minOil;
    for(int  i = 1 ; i < P.size();i++)
    {
        if(minOil > P[i])
        {
            minOil = P[i];
        }
        answer += minOil;
    }

    return answer;
}

int main()
{
int n = 10;
int arr[]= {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
vector<int> v(arr,arr+10);
cout<<solution(n,v); 

}