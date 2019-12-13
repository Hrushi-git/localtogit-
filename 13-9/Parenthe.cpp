#include <iostream>
using namespace std;
class stack
{
    int par[40];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    void push(char p)
    {
        par[++top]=p;         
    }
    int pop()
    {
        return par[top--];
    }
    void comp()
    {
        if(top==0)
        return;
        else if((par[top]==41 &&  par[top-1]==40)||(par[top]==93 &&  par[top-1]==91)||(par[top]==125 &&  par[top-1]==123))
        {
            pop();
            pop();
        }       
    }
    int empty()
    {
        if(top==-1)
        return 1;
        return 0;
    }
};
int main()
{
    char equ[50];
    stack S;
    cout<<"Enter eqution :";
    cin.getline(equ,48);
    int i=0;
    while(equ[i]!=0)
    {
       {
            if(equ[i]==123 || equ[i]==91 || equ[i]==93|| equ[i]==125|| equ[i]==41 ||equ[i]==40)
            {
                S.push(equ[i]);
                S.comp();              
            }
       }
        i++;
    }
   if(S.empty())
   {
        cout<<"Correctly";
   }
   else
   cout<<"Incorrect";
	return 0;
}
