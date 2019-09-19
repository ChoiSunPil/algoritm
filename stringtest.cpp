#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
string a = "123456789";
cout<<a.length()-1 <<endl;

string s;
s.assign(a,0,1);

cout<<a.length()-1 <<endl;
cout<<a.assign(a,1,a.length()-1)<<endl;
cout<<a<<endl;
a.append(s);
cout<<a<<endl;

s = a;
for (int i = 1; i < s.size(); i++)
    swap(s[i-1], s[i]);

cout<<s<<endl;
cout<<a<<endl;
printf("%p\n",s.c_str());
printf("%p",a.c_str());





return 0;

}