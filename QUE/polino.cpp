#include <iostream>
#include <iomanip>
using namespace std;
class node
{
	public:
	union
	{
		int pow;
		char var;
	}pv;
	int flag;
	union
	{
		int coef;
		node *down;
	}cd;
	node *next;
	
	node(char c)
	{
		pv.var=c;
		flag=0;
		next=0;
	}
	node (int coef,int pow)
	{
		flag=1;
		cd.coef=coef;
		pv.pow=pow;
		next=0;
	}
};
class GLL
{

	node *head;
	public:
	
	void creat()
	{
		char x;
		int coef,pow;
		cout<<"Enter the variable :";
		cin>>x;
		node* p=head=new node(x);
		int y;
		do
		{
			cout<<"Enter power       :";
			cin>>pow;
			cout<<"Enter coefficient :";
			cin>>coef;
			p->next=new node(coef,pow);
			p=p->next;
			cout<<"Wanna add more  :";
			cin>>y;
		}while(y);
	}
	void disp()
	{
		node *p=head->next,*b;
		while(p)
		{
			if(p->pv.pow)
			cout<<(p->cd.coef)<<"("<<head->pv.var<<"^"<<noshowpos<<p->pv.pow<<")";
			 cout<<showpos;
			b=p;
			p=p->next;		
		}
		cout<<showpos<<(b->cd.coef)<<endl;
		
	}
	void add(GLL G1,GLL G2)
	{
		int coef,pow;
		node *r=head=new node(G1.head->pv.var);
		node *p=G1.head->next;
		node *q=(G2.head)->next;
		while(p && q)
		{
			coef=p->cd.coef+q->cd.coef;
			if(p->pv.pow>q->pv.pow)
			{
				r->next=new node(p->cd.coef,p->pv.pow);
				r=r->next;
				p=p->next;
			}
			else if(p->pv.pow<q->pv.pow)
			{
				r->next=new node(q->cd.coef,q->pv.pow);
				r=r->next;
				q=q->next;
			}
			else
			{
				r->next=new node(coef,p->pv.pow);
				r=r->next;
				p=p->next;
				q=q->next;
			}
		}
		while(p)
		{
			r->next=new node(p->cd.coef,p->pv.pow);
			r=r->next;
			p=p->next;
		}
		while(q)
		{
			r->next=new node(q->cd.coef,q->pv.pow);
			r=r->next;
			q=q->next;
		}
	}
		void sub(GLL G1,GLL G2)
	{
		int coef,pow;
		node *r=head=new node(G1.head->pv.var);
		node *p=G1.head->next;
		node *q=(G2.head)->next;
		while(p && q)
		{
			coef=p->cd.coef-q->cd.coef;
			if(p->pv.pow>q->pv.pow)
			{
				r->next=new node(p->cd.coef,p->pv.pow);
				r=r->next;
				p=p->next;
			}
			else if(p->pv.pow<q->pv.pow)
			{
				r->next=new node(q->cd.coef,q->pv.pow);
				r=r->next;
				q=q->next;
			}
			else
			{
				r->next=new node(coef,p->pv.pow);
				r=r->next;
				p=p->next;
				q=q->next;
			}
		}
		while(p)
		{
			r->next=new node(p->cd.coef,p->pv.pow);
			r=r->next;
			p=p->next;
		}
		while(q)
		{
			r->next=new node(q->cd.coef,q->pv.pow);
			r=r->next;
			q=q->next;
		}
	}
};
int main()
{
	GLL G1,G2,G3,G4;
	G1.creat();
	G2.creat();
	G1.disp();
	G2.disp();
	G3.add(G1,G2);
	G4.sub(G1,G2);
	cout<<"Addition is :";
	G3.disp();
	cout<<"Subtraction is :";
	G4.disp();
	return 0;
}
