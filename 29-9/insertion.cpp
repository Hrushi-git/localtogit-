#include <iostream>
#include <stdlib.h>
#include <chrono>
#define MAX 100000
#define swap(a,b) int t;t=a;a=b;b=t
using namespace std;
using namespace std::chrono;
int main()
{
	start:
	int j,a[MAX+1],i;
	int ch;
		random();
		cout<<"1.Random\n";
		cout<<"2.Descending\n";
		cout<<"3.Ascending\n";
		cout<<"Choice :";
		cin>>ch;
	for(i=0;i<MAX;i++)
	{
		
		if(ch==1)
		a[i]=rand()%10000000;
		else if(ch==3)
		a[i]=i;
		else
		a[i]=MAX-i;
		
	}
	int num;
	num=random()%10000;
	i=0;
	auto start=high_resolution_clock::now();
	a[MAX]=num;
	
	for(i=1;i<MAX;i++)
	{
		int temp=a[i];
		for(j=i-1;j>-1 && a[j]>temp;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
		
	}
	for(i=0;i<10;i++)
	cout<<a[i]<<" ";
	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<"\n__________________________________\n";
	cout<<endl<<"Time required :"<<duration.count()<<endl;
	cout<<"__________________________________\n";
	goto start;
	return 0;
}
