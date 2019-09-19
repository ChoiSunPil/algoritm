#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool isPossible(string str)
{
	stack<char> s;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
		{
			s.push(str[i]);
		}
		else if(str[i]==')')
		{
			if(s.empty())
			{
				return false;
			}
			else{
				s.pop();
			}
		}
	}
	if(s.empty())
		return true;
	return false;
}
void makeUV(string&u ,string &v,string p)
{
    int l = 0;
    int r = 0;
    for(int i = 0 ; i < p.length(); i++)
    {
        if(p[i] == '(')
        {
            l++;
        }
        else
        {
            r++;
        }
        
        if(l == r && l != 0)
        {
            u.append(p.substr(0,i+1));
            v.append(p.substr(i+1));
            break;
        }
    }
}
void reverseU(string & u)
{
    string buffer ="";
    for(int  i = 0 ; i < u.length();i++)
    {
        if(u[i] == '(')
            buffer.append(")");
        else
            buffer.append("(");
    }
    u = buffer;



}
string makeRightBracket(string u,string v)
{
    string buffer = "";
    string tmpU = "";
    string tmpV = "";
    if(isPossible(u))
    {
        buffer.append(u);

    if(v == "")
    {
        return buffer;
    }
    else
    {
    makeUV(tmpU,tmpV,v);
    return buffer.append(makeRightBracket(tmpU,tmpV));
    }
    }
    else
    {
        makeUV(tmpU,tmpV,v);
        buffer.append("(");
        buffer.append(makeRightBracket(tmpU,tmpV));
        buffer.append(")");
        for(int i = 1 ; i< u.length()-1 ;i++)
        {
        if(u[i] == '(')
            buffer.append(")");
        else
            buffer.append("(");
        }
        return buffer;
    }
}
string solution(string p) {
    string answer = "";
    string u ="";
    string v ="";
    makeUV(u,v,p);
    answer = makeRightBracket(u,v);
    return answer;
}
int main()
{
    string s = "123";

    cout<<solution("))()((");
    return 0;
}