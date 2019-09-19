#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Point{
int x;
int y;
}Point;
typedef struct _Line{
Point s;
Point e;
}Line;
Line lines[500];
int lineSize =0;
void sort_asc(Point * s, Point * e)
{
    if(s->x < e->x)
    {
     return;
    }
    else if(s->x == e->x)
    {
       if(s->y < e->y)
       {
           return;
       }
       else
       {
        Point tmp = {s->x,s->y};
        s->x =e->x;
        s->y =e->y;
        e->x = tmp.x;
        e->y = tmp.y;
        return ;
       }
    }
    else
    {
       Point tmp = {s->x,s->y};
        s->x =e->x;
        s->y =e->y;
        e->x = tmp.x;
        e->y = tmp.y; 
    }
}
int check_duplicated_line(Point s ,Point e){
//Line 저장은 x ,y 오름차순
sort_asc(&s,&e);
for(int  i = 0 ; i < lineSize ; i++)
{
if(lines[i].s.x ==s.x && lines[i].s.y == s.y &&lines[i].e.x == e.x &&lines[i].e.y == e.y)
        return 0;
}

lines[lineSize].s.x = s.x;
lines[lineSize].s.y = s.y;
lines[lineSize].e.x = e.x;
lines[lineSize].e.y = e.y;
lineSize++;
return 1;
}
int solution(char* dirs)
{
    int  i= 0;
    int answer = 0;
    Point cur = {0,0};
    //평면계 크기는 5,5,-5,-5
    while(dirs[i] != '\0')
    {
        Point tmp;
        if(dirs[i] == 'U' && ((cur.y+1) <= 5))
        {
        tmp.x = cur.x;
        tmp.y = cur.y+1;
        if(check_duplicated_line(cur,tmp) == 1)
            answer++;
        cur.y++;
        }
        else if(dirs[i] == 'D'&& ((cur.y-1) >= -5))
        {
        tmp.x = cur.x;
        tmp.y = cur.y-1;
        if(check_duplicated_line(cur,tmp)== 1)
            answer++;             
        cur.y--;
        }
        else if(dirs[i] == 'R'&& ((cur.x+1) <= 5))
        {
        tmp.x = cur.x+1;
        tmp.y = cur.y;
        if(check_duplicated_line(cur,tmp) ==1)
            answer++;      
        cur.x++;
        }
        else if(dirs[i] == 'L'&& ((cur.x-1) >= -5))
        {
        tmp.x = cur.x-1;
        tmp.y = cur.y;
        if(check_duplicated_line(cur,tmp)==1)
            answer++; 
        cur.x--; 
        }
    i++;    
    }
    


	return answer;
}
int main()
{
printf("%d",solution("LLLLLLLLLLLLLLLLLLLLLL"));
}