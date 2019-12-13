#include<iostream>
#define MAX 50
using namespace std;
typedef struct job
{
	int jno,jtime;
}job;
class Queue
{

	job T[MAX];
	int r,f;
		public:
			Queue()
	{
		f=r=-1;
	}
	int full()
	{
		if(r==MAX-1)
		return 1;
		return 0;
	}
	int empty()
	{
		if(r==-1)
		return 1;
		return 0;
	}
	void enque(job x)
	{
		if(!full())
		{
			if(empty())
			{
				f++;
			}
			r++;
			T[r]=x;
		}
		else
		cout<<"Queue Overflow\n";
	}
	job deque()
	{
		if(!empty())
		{
			job x=T[f];
			if(f==r)
			f=r=-1;
			else
			f++;
			return x;		
		}
		else
		{
			cout<<"Queue underflow\n";
			
		}
	}
		void input()
		{
			int N;
			job T;
			cout<<"Enter number of jobs :";
			cin>>N;
			int i;
			for(i=0;i<N;i++)
			{
				cout<<"Enter jNO :";
				cin>>T.jno;
				cout<<"Enter Jtime :";
				cin>>T.jtime;
				enque(T);
				cout<<"---------------------\n";
			}
	}
};
int main()
{
	Queue Q;
	job T;
	Q.input();
	cout<<"Enter time for job :";
	int cq;
	cin>>cq;
	while(!Q.empty())
	{
		T=Q.deque();
		T.jtime-=cq;
		if(T.jtime>0)
		{
			Q.enque(T);
		}
		else
		{
			cout<<"Task "<<T.jno<<" completed \n";
		}
	}
}
