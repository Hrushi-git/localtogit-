#include <iostream>
#define MAX 4
using namespace std;

class stack
{
   int arr[MAX];
   int top;
   public:
   stack()
   {
        top=-1;
   }
   void push(int x)
   {
        if(!full())
        arr[++top]=x; 
        else
        cout<<"FILL";
   }
   int pop()
   {
        if(!empty())
        {
            return  arr[top--];
        }
        
   }
   int empty()
   {
       if(top==-1)
        {
            cout<<"\nEmpty stack\n";
            return 1;
        }
        return 0;
   }
   int full()
   {
        if(top==MAX)
        {
            cout<<"Stack full\n";
            return 1;
        }
            
        return 0; 
   }
   void disp()
   {
        int i=-1;
        while(++i<=top)
        cout<<arr[i]<<"  ";
   }
    
};
int main()
{
	stack S;
	S.push(5);
	S.push(12);
	S.push(25);
	S.push(62);
	S.push(50);
	S.disp();
	cout<<"Poped out :"<<S.pop()<<"  "<<S.pop()<<endl;
	S.disp();
	
	
	return 0;
}
