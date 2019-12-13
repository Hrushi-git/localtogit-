#include <iostream>
using namespace std;
class stack
{
    int sign[40];
    int top;
    
    public:
    stack()
    {
        top=-1;
    }
    void push(char p)
    {
       sign[++top]=p;         
    }
    int pop()
    {
        return sign[top--];   
    }
    int prio(char ch)
    {
        switch(ch)
        {
            case '*':
            case '/':return 1;
            case '+':
            case '-':return 0;
        }
        return 0;
    }
    int gettop()
    {  
        return sign[top];
    }
    int empty()
    {
        if(top==-1)
        return 1;
        return 0;
    }
    void comp(char ch,char fin[],int *j)
    {
       if(empty())
        push(ch);
        else
        {
            hell:
            if(prio(gettop())>=prio(ch))
            {
                fin[(*j)++]=pop();
               
                  if(empty())
                   push(ch);
                  else
                  {
                        goto hell;
                  }
            }
            else
            push(ch);
        }
    }
    int eval(char *f)
    {
        int a,b;
        int i=0;
        while(f[i])
        {
            //cout<<"^"<<f[i];
            if(f[i]=='+')
            {
                a=pop();
                b=pop();
                push(a+b);
            }
				else if(f[i]=='-')
            {
                a=pop();
                b=pop();
                push(a-b);
            }
				else if(f[i]=='*')
            {
                a=pop();
                b=pop();
                push(a*b);
            }
				else if(f[i]=='/')
            {
                a=pop();
                b=pop();
                push(a/b);
            }
            else
				
            push(f[i]-48);
          i++; 
        }
        return pop();
    }
};
int main()
{
	stack S,I;
	char exp[50],fin[50];
	cout<<"Enter exp :";
	cin.getline(exp,48);
	int i=0,j=0,f;
	while(exp[i]!=0)
	{
	    if(exp[i]=='+' ||exp[i]=='-' ||exp[i]=='*' ||exp[i]=='/')
	   { 
	        S.comp(exp[i],fin,&j);
	   }
	   else
	    {
	        fin[j++]=exp[i];  
	    }
	    i++;
	}
	while(!S.empty())
	{
	     fin[j++]=S.pop();
	}
	fin[j++]=0;
	cout<<fin<<endl;
	cout<<I.eval(fin)<<endl<<endl;
	
	
	
	return 0;
}
