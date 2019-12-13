#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node(int x)
		{
			data=x;
			next=NULL;
		}
};
class SLL
{
	node *head;
	public:
		SLL(){head=0;}
		void creat()
		{
			int N,i,v;
			cout<<"Enter number of nodes :";
			cin>>N;
			for(i=0;i<N;i++)
			{
				cout<<"Enter node value :";
				cin>>v;
				if(head==0)
				head=new node(v);
				else
				{
					node* p=head;
					while(p->next)
					p=p->next;
					p->next=new node(v);
				}
			}
		}
		void merge(SLL S1,SLL S2)
		{
			int i=1;
			node *p=S1.head;
			node *q=S2.head;
			node *r;
			if(p->data>q->data)
			r=head=new node(p->data);
			else
			r=head=new node(q->data);
			p=p->next;
			q=q->next;
			while(p && q)
			{
				if(p->data>q->data)
				{
					r->next=new node(p->data);
					r=r->next;
					p=p->next;
					q=q->next;
				}
				else
				{
					r->next=new node(q->data);
					r=r->next;
					q=q->next;
					p=p->next;
				}
			}
			while(p)
			{
				r->next=new node(p->data);
				r=r->next;
				p=p->next;
			}
			while(q)
			{
				r->next=new node(q->data);
				r=r->next;
				q=q->next;
			}
			
		}
		void show()
		{
			node*p=head;
			while(p)
			{
				cout<<p->data<<"  ";
				p=p->next;
			}
			cout<<endl;		
		}
		int count()
		{
			node *p=head;
			int c=0;
			while(p)
			{
				p=p->next;
				c++;
			}
			return c;
		}
		void delvalue(int key)
		{
			node *p=head,*q=p->next;
			int tot=count(),i=0;
			if(head->data==key)
			{
				i++;
				if(i==2)
				{
					delete p;
					head=q;
					return;
				}			
			}
			while(q)
			{
				if(q->data==key)
				{
					i++;
					if(i==2)
					{
						p->next=q->next;
						delete q;
						q=p->next;
					}				
				}
				p=q;
				if(!q)
				return;
				q=q->next;
			}
		}
};
int main()
{
	SLL S1,S2,S3;
	S1.creat();
	S2.creat();
	S1.show();
	S2.show();
	S3.merge(S1,S2);
	S3.show();
	return 0;
}
