#include<iostream>
#include<math.h>
using namespace std;
class node
{
    int bit;
    node*next;
    public:
    node(int b)
    {
        if(b)
        bit=1;
        else
        bit=0;
        next=0;
    }
    friend class SLL;
};//65536
class SLL
{
    node* head[3];
    public:
    node* binary(int num)
    {
        node* q=head[0]=new node(num&1);
        num=num>>1;
        int i;
        for(i=1;i<16;i++)
        {
            q->next=new node(num&1);
            num=num>>1;
            q=q->next;
        }
        return head[0];
    }
    void call(int i)
    {
        disp(head[i]);
    }
    void disp( node* p)
    {   
        if(p==NULL)
        {          
            return;
        }
        disp(p->next); 
        cout<<p->bit;      
    }
    void onescom()
    {
        node *p=head[0];
        node *q=head[1]=new node(!(p->bit));
        while(p->next)
        {
            p=p->next;
            q->next=new node(!(p->bit));
            q=q->next;
        }     
	}   
    void twoscom()
    {         
        node *p=head[1];
        node *q=head[2]=new node(!(p->bit)); 
       int b=p->bit;         
        p=p->next;
        if(b==1)
        {           
            do
            {
                q->next=new node(!(p->bit));               
                q=q->next;
                b=(p->bit);
                p=p->next;
            }while(b!=0);    
        }  
        while(p!=NULL)
        {           
           q->next=new node(p->bit);          
           q=q->next;
           p=p->next;            
        }
   }  
};
int main()
{
    SLL S1;
    int num;
    cout<<"Enter num :";
    cin>>num;
    S1.binary(num);
    S1.onescom();
    S1.twoscom();
    cout<<"Binary of number   :";S1.call(0);cout<<"\n";
    cout<<"1's comp of number :";S1.call(1);cout<<"\n";   
    cout<<"2's comp of number :";S1.call(2);cout<<"\n";
}		
