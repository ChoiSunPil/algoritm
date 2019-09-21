#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
string str = "@.org";
regex pattern("^[a-z*.]+@[a-z]+.(org|com|net)$");
cout<<regex_match(str,pattern)<<endl;


}