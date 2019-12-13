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
	cout<<"1.Random\n";
		cout<<"2.Descending\n";
		cout<<"3.Ascending\n";
		cout<<"Choice :";
		cin>>ch;
	for(i=0;i<MAX;i++)
	{
		
		if(ch==1)
		a[i]=random()%100000000;
		else if(ch==3)
		a[i]=i;
		else
		a[i]=MAX-i;
		
	}
	int num;
	num=random()%10000;
	cout<<"Number to be searched :";
	cin>>num;
	cout<<num<<endl;	
	i=0;
	auto start=high_resolution_clock::now();
	a[MAX]=num;
	
	while(num!=a[i])
	{
		i++;
	}
	if(i==100000)
	cout<<"Not found ";
	else 
		cout<<"Found \n";
	
	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<endl<<"Time required :"<<duration.count();
	return 0;
}
