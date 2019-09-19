#include <string>
#include <vector>
#include <iostream>
using namespace std;

int findStrMin(string s,int n)
{
string buffer ="";    
vector<string> v;
int  i = 0;
int count = 0 ;
cout<<"N :"<<n<<endl;
while(i <= s.length())
{
if(i+n <= s.length())
 v.push_back(s.substr(i,n));
else
{
    v.push_back(s.substr(i,n));
    v.push_back(" ");
}

 i+= n;   
}
for(i = 0 ; i < v.size()-1 ; i++)
{
 if(!v[i].compare(v[i+1]))
  {
      count++;
  }
  else
  {
    if(count > 0)
    {
        buffer.append(to_string(count+1));
        buffer.append(v[i]);
    }
    else
    {
      buffer.append(v[i]);   
    }
    count = 0;
  }
}
cout<<"buffer : "<<buffer<<endl;
return buffer.length();
}
int solution(string s) {
    int answer = 0;
    int min = 1000;
    if(s.length() == 1)
      return 1;
    for(int  i = 1 ; i <= s.length()/2 ;i++)
    {
        int tmp =findStrMin(s,i);
        if(min > tmp)
            min = tmp;
    }
    answer = min;
    return answer;
}
int main()
{
string s = "a";
cout << solution(s);
return 0;
}