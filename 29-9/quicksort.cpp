#include <iostream>
#include <stdlib.h>
#include <chrono>
#define MAX 10000

using namespace std;
using namespace std::chrono;
void swap(int *num1,int *num2)
{ 	int num3;
	num3=*num1;
	*num1=*num2;
	*num2=num3;
}
int partition(int *a,int l,int h)
{
	int pivot=a[l];
	int p=l+1;
	int q=h;
	while(p<=q)
	{
		while(pivot<=a[p] && p<=h)
		p++;
		while(pivot>a[q])
		q--;
		if(p<q)
		swap(&a[p],&a[q]);
	}
	swap(&a[q],&a[l]);
	return q;
}
void quicksort(int *a,int l,int h)
{
	if(l<h)
	{
		cout<<"Processing......\r";
		int k=partition(a,l,h);
		quicksort(a,l,k-1);
		quicksort(a,k+1,h);
		cout<<"\r";
	}
}

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
		a[i]=rand()%1000000000;
		else if(ch==3)
		a[i]=i;
		else
		a[i]=MAX-i;
		
	}
	int num;
	num=random()%10000;
	i=0;
	auto start=high_resolution_clock::now();
	quicksort(a,0,MAX-1);

	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<"\n__________________________________\n";
	cout<<endl<<"Time required :"<<duration.count()<<endl;
	cout<<"__________________________________\n";
	for(i=0;i<10;i++)
	cout<<a[i]<<"  ";
	cout<<endl;
	goto start;
	return 0;
}
