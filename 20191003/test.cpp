#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
vector<int> v;
vector<int> t(5,5);
int count = 0;
for(int  i = 0 ; i < 5 ; i++)
    v.push_back(i);

 for(int  i = 0 ; i < 5 ; i++)
        cout<<v[i]<<" ";
    cout<<endl;
for(int  i = 0 ; i < 5 ; i++)
     cout<<t[i]<<" ";
// do{
// count++;
//     for(int  i = 0 ; i < 5 ; i++)
//         cout<<v[i]<<" ";
//     cout<<endl;
// }while(next_permutation(v.begin(),v.end()));

// cout<<count;
}