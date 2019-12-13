#include <iostream.h>
#include <stdlib.h>
#include <chrono>
#define MAX 100000
using namespace std;
using namespace std::chrono;
int main()
{
	int j,a[MAX],i;
	
	for(i=0;i<MAX;i++)sssss
	{
		a[i]=i;
		
	}
	int num;
	//num=random()%10000;
	cout<<"Number to be searched :";
	cin>>num;
		
	i=0;
	auto start=high_resolution_clock::now();
	int low=0,mid;
	int high =MAX-1;
	for(mid=(low+high)/2;low<=high;mid=(low+high)/2)
	{
		if(num==a[mid])
		{
			cout<<"Found";
			break;
		}
		else if(num>a[mid])
		{
			low=mid+1;
		}
		else 
			high=mid-1;
		
	}
	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<endl<<"Time required :"<<duration.count();
	return 0;
}
