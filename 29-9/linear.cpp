#include <iostream>
#include <stdlib.h>
#include <chrono>
#define MAX 100000
using namespace std;
using namespace std::chrono;
int main()
{
	int j,a[MAX],i;
	
	for(i=0;i<MAX;i++)
	{
		a[i]=random()%100000000;
		
	}
	int num;
	num=random()%10000;
	cout<<"Number to be searched :";
	cout<<num<<endl;	
	i=0;
	auto start=high_resolution_clock::now();
	while(i<MAX)
	{
		if(a[i]==num)
		{
			cout<<"found";
			break;
		}
		i++;
	}
	if(i==100000)
	cout<<"Not found ";
	
	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<endl<<"Time required :"<<duration.count();
	return 0;
}
