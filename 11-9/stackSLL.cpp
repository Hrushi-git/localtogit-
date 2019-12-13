#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    public:
    node(int x)
    {
        data=x;
        next=0;
    }
    node(){}
};
class stack:public node
{
    node* top;
    public:
    stack()
    {
        top=0;
    }
    void push(int x)
    {
        node *q=new node(x);
        q->next=top;
        top=q;
    }
    int pop()
    {
        node *p=top;
        p=p->next;
        int x=top->data;
        delete top;
        top=p;
        return x;        
    }
    void disp(node *p)
    {
        if(!p)
        return;
        disp(p->next);
        cout<<p->data<<"   ";
    }
    void toppass()
    {
        node* p=top;
        disp(p);
    }
};
int main()
{
	stack S;
	S.push(14);
	S.push(17);
	S.push(72);
	S.push(31);
	S.toppass();
	cout<<"Poped out :"<<S.pop()<<S.pop()<<endl;
	S.toppass();
	
	return 0;
}
