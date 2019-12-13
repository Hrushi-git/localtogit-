#include <iostream>
#include<iomanip>
using namespace std;

void TOH(int n,char S,char D,char I);
int main()
{	
	int n;
	cin>>n;
	TOH(n,'S','I','D');
	return 0;
}
void TOH(int n,char S,char D,char I)
{
	if(n==0)
	return;
	static int i=1;
	
	TOH(n-1,S,I,D);
	cout<<setw(3)<<i++<<"  ";
	cout<<S<<"---->"<<D<<endl;
	TOH(n-1,I,D,S);
}
