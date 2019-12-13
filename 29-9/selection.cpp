#include <iostream>
#include <stdlib.h>
#include <chrono>
#define MAX 100000
using namespace std;
using namespace std::chrono;
int main()
{
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
	int swap=0;
	for(i=0;i<MAX;i++)
	{
		swap=0;
		for(j=i+1;j<MAX;j++)
		{
			if(a[i]>a[j])
			{
				swap++;
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		if(swap==1)
		break;
	}
	for(i=0;i<10;i++)
	cout<<a[i]<<" ";
	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<endl<<"Time required :"<<duration.count();
	return 0;
}
