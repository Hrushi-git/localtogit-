#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int x)
		{
			data=x;
			next=0;
		}
};
class SLL
{
	node *head,*q;
		public:
			SLL()
			{
				head=0;
			}
			void creat()
			{
				int N;	
				cout<<"NUMber of node :";
				cin>>N;
				creat(N,head);
			}
			void creat(int N,node *q)
			{
				if(!N)
				return;
				int x;
				cout<<"Enter value :";
				cin>>x;
				if(!q)
				{
					q=head=new node(x);
					creat(N-1,q);
				}
				else
				{
					q->next=new node(x);
					q=q->next;
					creat(N-1,q);
				}
				
			}
			void show()
			{
				node *p=head;
				while(p)
				{
					cout<<p->data<<"   ";
					p=p->next;
				}
				cout<<endl;		
			}
};
int main()
{
	SLL S;
	S.creat();
	S.show();
	return 0;
}
