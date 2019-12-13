#include <iostream>
using namespace std;
#define MAX 50
class Queue
{
	int A[MAX];
	int f,r;
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
	void enque(int x)
	{
		if(!full())
		{
			if(empty())
			{
				f++;
			}
			r++;
			A[r]=x;
		}
		else
		cout<<"Queue Overflow\n";
	}
	int deque()
	{
		if(!empty())
		{
			int x=A[f];
			if(f==r)
			f=r=-1;
			else
			f++;
			return x;		
		}
		else
		{
			cout<<"Queue underflow\n";
			return -32655;
		}
	}
	
};

int main()
{
	Queue Q;
	Q.deque();
	Q.enque(10);
	Q.enque(52);
	cout<<Q.deque();
	return 0;
}
