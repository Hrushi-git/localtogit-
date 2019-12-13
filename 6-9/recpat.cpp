#include <iostream>

using namespace std;
void recpat(int c,int i);
int main()
{
    int num;
    cout<<"Enter number :";
    cin>>num;
   	recpat(1,2);
	cout<<endl;
}
void recpat(int c,int i,int num)
{
    if(c==10)
    return;
    if(c==i)
    {
        cout<<"\n";
        
         recpat(1,i+1);   
         
    }
    else
    {
        cout<<c;
        recpat(c+1,i);
        cout<<endl;
        
    }
    
}
