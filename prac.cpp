#include <iostream>
#include <vector>
using namespace std;
int main()
{
vector <int> v;
v.push_back(1);
vector <int> s;
s = v;
s.push_back(2);
v[0] =3;
cout<<v.size()<<" "<<s.size()<<endl;
cout<<v[0]<<" "<<s[0]<<endl;
return 0;
}