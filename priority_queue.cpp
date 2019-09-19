#include <iostream>
#include <algorithm>
#define MAX(a,b) a > b ? 1 : 0;
using namespace std;
class priorityQueue{

private :
   int  MAX_SIZE =12;
   int cur;
   int*  heap;

   void arrangeHeapPush(int pos)
   {
    if(heap[pos] < heap[(pos-1)/2])
    {
        return ;
    }
    else
    {
        swap(heap[pos],heap[(pos-1)/2]);
        
        if((pos-1)/2 != 0)
            arrangeHeapPush((pos-1)/2);
    }
   }
    void arrangeHeapPop(int pos)
    {
       
        if(heap[pos] > heap[(pos*2)+1] && heap[pos] > heap[(pos+1)*2])
        {
            return;
        }
        else
        {
         int check = MAX(heap[(pos*2)+1],heap[(pos+1)*2]);
         if(check == 1)
         {
            if(cur > 1)
            swap(heap[pos],heap[(pos*2)+1]);
            
            if(pos != cur-1 && cur >= 0)
            arrangeHeapPop((pos*2)+1);
         }
         else
         {
            if(cur > 1)
            swap(heap[pos],heap[(pos+1)*2]);
            
            if(pos != cur-1 && cur >= 0)
            arrangeHeapPop((pos+1)*2);
         }
        } 
    }
public:
    priorityQueue(){
        heap = new int[MAX_SIZE];
        cur = 0;
    }
    void push(int item)
    {
        if(cur == 0)
        {
            heap[cur] = item;
            cur++;
            return;
        }
        else
        {
            for(int  i = 0 ; i < cur ; i++)
                {
                    if(heap[i] == item)
                        return ;
                }
                heap[cur] = item;
                arrangeHeapPush(cur);
                cur++;
        }
    }
    int pop(){
        int result = heap[0];
        if(cur == 0)
            return -1;
        else if(cur == 1)
        {    
        cur--;
        return result;    
        }
        else{
        heap[0] = heap[cur-1];
        cur--;
        arrangeHeapPop(0);
        return result;
        }
    }

    void print(){
        for(int i = 0 ; i < cur ; i++)
        {
            cout<<heap[i]<<endl;
        }
    }

  ~priorityQueue(){
      delete heap;
  }
};



int main()
{
priorityQueue pq;
pq.push(100);
pq.push(1000);
pq.push(80);
pq.push(30000);
pq.print();
// for(int  i = 0 ; i < 3 ; i++)
// {
//     cout<<"pop"<<endl;
//     cout<<pq.pop()<<endl;
//     cout<<"heap"<<endl;
//     pq.print();
// }




return 0;
}