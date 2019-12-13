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
			node *H=head=new node(p->data);
			p=p->next;
			while(p && q)
			{
				if(i%2)
				{
					H->next=new node(q->data);
					H=H->next;
					q=q->next;
				}
				else
				{
					H->next=new node(p->data);
					H=H->next;
					p=p->next;
				}
				i++;
			}
			while(p)
			{
				H->next=new node(p->data);
				H=H->next;
				p=p->next;
			}
			while(q)
			{
				H->next=new node(q->data);
				H=H->next;
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
		void delrepeat()
		{
			int pos=2,i=2,j;
			node *p=head,*q,*r;
			while(p)
			{
				pos=i++;
				q=p->next;
				while(q)
				{
					r=q;
					if(p->data==q->data)
					{
						delvalue(q->data);
						q=p->next;
						//q=r->next;
						continue;
					}
					q=q->next;
				}
				p=p->next;
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
	cout<<"After deleting repeated element :\n";
	S3.delrepeat();
	S3.show();
	return 0;
}
