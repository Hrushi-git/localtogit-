#include <iostream>
#include <cstring>
#define MAX 5
using namespace std;
typedef struct data
{
	
};
class QUEUE
{
	char name[10][20];
	int f,r;
	public:
		QUEUE()
		{
			f=r=-1;
		}
		int full()
		{
			if(f==(r+1)%MAX)
			return 1;
			return 0;
		}
		int empty()
		{
			if(r==-1)
			return 1;
			return 0;
		}
		void enque(char *p)
		{
			if(!full())
			{
				if(empty())
				{
					f=(f+1)%MAX;
				}
				r=(r+1)%MAX;
				strcpy(name[r],p);
			}
			else
				cout<<"Full\n";
		}
		char* deque()
		{
			if(empty())
			{
				cout<<"Empty";
				return 0;
			}
			char *p=name[f];
			if(f==r)
			f=r=-1;
			else
			f=(f+1)%MAX;
			return p;
			
		}
		void show()
		{
			int x=f,i;
			if(r<f)
			{
				for(i=f;i<MAX;i++)
				cout<<name[i]<<"  ";
				for(i=0;i<=r;i++)
				cout<<name[i]<<"  ";
			}
			while(x<=r)
			{
				cout<<name[x]<<"  ";
				x++;
			}
			cout<<endl;
		}
		int islast()
		{
			if(r==f)
			return 1;
			return 0;
		}
		void show(int i)
		{
			cout<<f<<"  "<<r<<endl;
		}
};
int main()
{
		QUEUE Q;
			int N,l,i,j;
	char name[50],*p;
	int y;
	do
	{
		cout<<"choice :";
	cin>>y;
	switch(y)
	{
		case 1:
			cin>>name;
			Q.enque(name);
			Q.show(1);
			break;
		case 2:
			cout<<Q.deque();
			Q.show(1);
			break;
		case 3:
			Q.show();
			Q.show(1);
			break;
	}
	}while(y);
	return 0;


	cout<<"Enter number :";
	cin>>N;
	for(i=0;i<N;i++)
	{
		cout<<"enter name :";
		cin>>name;
		Q.enque(name);
	}
	cout<<"ENTER LUCKY numbet:";
	cin>>l;
	for(i=0;i<N;i++)
	{
			Q.show();
		if(Q.islast())
		strcpy(name,Q.deque());
		else
		for(j=0;j<l-1;j++)
		{
				p=Q.deque();
				Q.enque(p);
				
		}	
		Q.deque();
		
	}
	cout<<"Lucky  winner:"<<name;
	return 0;
}
