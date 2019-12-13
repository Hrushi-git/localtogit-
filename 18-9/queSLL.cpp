#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node * next;
		node(int x)
		{
			data=x;
			next=0;
		}
		
};
class stack//:public node
{
	node* head;
		public:
		stack()
		{
			head=0;
		}	
		int empty()
		{
			if(!head)
			return 1;
			return 0;
		}
		void push(int x)
		{
			if(empty())
			{
				head=new node(x);
			//	cout<<"!  ";
			}
			else
			{
				
				node*p=head;
				while(p->next)
				{
					p=p->next;
				//	cout<<"@  ";
				}
				p->next=new node(x);
			}
		}
		int pop()
		{
			if(empty())
			return -65395;
			node*p=head;
			while(p->next->next)
			{
				p=p->next;
			}
			int x=p->next->data;
			delete p->next;
			p->next=NULL;
			return x;
		}
		void show()
		{
			node*p=head;
			while(p)
			{
				cout<<p->data<<"  ";
				p=p->next;
			}
		}
};
int main()
{
	stack S;
	S.push(4);
	S.push(63);
	S.push(435);
	S.push(54);
	S.show();cout<<endl;
	cout<<S.pop();cout<<endl;
	S.show();	cout<<endl;
}
