#include <iostream>
#include <string>
#include <algorithm>
#define MAX_SIZE 13
using namespace std;

typedef struct _TreeNode
{
  string data;
}TreeNode;
typedef struct _Tree
{
int cur = 0;
TreeNode array[MAX_SIZE];

}Tree;
Tree tree;
void add_tree(Tree * Target_Tree , string Item);
void control_tree(Tree * Target_Tree,int position);
string pop(Tree* Target_Tree);
void rotate(string &s);
void add_tree(Tree * Target_Tree , string Item)
{

if(Target_Tree->cur ==0)
{
Target_Tree->array[Target_Tree->cur].data = Item;
Target_Tree->cur++;
}
else
{
for(int i = 0 ; i <Target_Tree->cur ; i++)
{
if(Target_Tree->array[i].data.compare(Item)== 0)
    return ;
}

Target_Tree->array[Target_Tree->cur].data = Item;
control_tree(Target_Tree,Target_Tree->cur);
Target_Tree->cur++;
}
}
void control_tree(Tree * Target_Tree,int position)
{
if(Target_Tree->array[(position-1)/2].data.compare(Target_Tree->array[position].data) < 0)
{
    return ;
}
else
{
 swap(Target_Tree->array[(position-1)/2].data,Target_Tree->array[position].data);
 
 if((position-1)/2 == 0)
    return;
 else
    control_tree(Target_Tree,(position-1)/2);
}

}
string pop(Tree* Target_Tree)
{
if(Target_Tree->cur ==0)
{
return NULL;
}
else
{
string result = Target_Tree->array[0].data;
Target_Tree->cur--;
swap(Target_Tree->array[0].data,Target_Tree->array[Target_Tree->cur].data);
control_tree(Target_Tree,Target_Tree->cur-1);
return result;
}
}
int main()
{
int test_num;
cin>>test_num;
for(int  i = 0 ; i < test_num ;i++)
{
int N , K;
cin>>N>>K;
string buffer ;
cin>>buffer;
int str_len = N/4;
/**
 * 
 * index 0 부터 로테이션 돌리면서 우선수위 큐에 넣기
 * 
 * */




/*******/

/***
 * K 번째 POP 한 결과 출력
 * ***/
string result;
for(int j = 0 ; j < K ; j++)
{
    result = pop(tree);
}
cout<<"#"<<i+1<" "<<strtol(result.c_str(),NULL,16)<<endl;
}

return 0;
}
void rotate(string &a) {
  string s;
  s.assign(a,0,3);
  a.assign(a,3,a.length()-3);
  a.append(s);
}