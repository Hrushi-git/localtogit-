#include <iostream>
using namespace std;
#define MAX 3
class Queue
{
	int A[MAX];
	int r;
		public:
	Queue()
	{
		r=-1;
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
	void enque(int x)
	{
		if(!full())
		{
			A[++r]=x;
		}
		else
		cout<<"Queue Overflow\n";
	}
	int deque()
	{
		int i,x;
		if(!empty())
		{
			x=A[0];
			for(i=0;i<r;i++)
			{
				A[i]=A[i+1];
			}
			r--;
			return x;		
		}
		else
		{
			cout<<"Queue underflow\n";
			return -32655;
		}
	}
	void show()
	{
		int i;
		for(i=0;i<=r;i++)
		{
			cout<<A[i]<<"  ";
		}
		if(!i)
		cout<<"EM";
	}
	
};

int main()
{
	Queue Q;
	Q.deque();
	Q.enque(10);
	Q.enque(16);
	Q.enque(73);
Q.show();
	cout<<"\n";
	cout<<Q.deque();
	cout<<"\n";
	Q.show();
	cout<<"\n";
	
	
	cout<<"\n";
	return 0;
}
