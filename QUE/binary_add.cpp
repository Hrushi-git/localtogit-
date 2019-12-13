#include<iostream>
#include<math.h>
using namespace std;
class node
{
   public:
        int bit;
        node* next,*prev;
    public:
        node(int x)
        {
            bit=!!x;
            next=NULL;
            prev=0;
        }
        node(){}
};
class DLL:public node
{
    node* head,*last;
    public:
        DLL()
        {
            head=NULL;
        }
        void getnum()
        {
            int i=0;int bin[100],num;           
            cout<<"Enter number :";
            cin>>num;
  				makeDLL(num&32768);
  				num=num<<1;
            for(i=1;i<16;i++)
				{
       	   	makeDLL(num&32768);
            	num=num<<1;
        		}
        }
        void makeDLL(int bit)
        {
            node*p=head;
            node*q=new node(bit);
            if(head==0)
            last=head=q;
            else
            {
                while(p->next!=0)
                p=p->next;
                p->next=q;
                p->next->prev=p;
                last=p=p->next;
            }
        }
        void addatbeg(int bit)
        {
            node*p=head;
            node*q=new node(bit);
            if(head==0)
            last=head=q;
            else
            {
                q->next=p;
                p->prev=q;
            }
            head=q;
        }
        void disp()
        {
            node*p=head;
            while(p)
            {
                cout<<p->bit;
                p=p->next;
            }
        }
        int count()
        {
            node*p=head;
            int i=0;
            while(p)
            {
                i++;
                p=p->next;
            }
            return i;
        }
        void disprev()
        {
            node*p=last;
            
            while(p)
            {
                cout<<p->bit;
                p=p->prev;
            }
        }
        void getadd(DLL D1,DLL D2)
        {
            int s,c=0;
            node* p=D1.last;
            node* q=D2.last;
            while(p && q)
            {
                s=(p->bit)+(q->bit)+c;
                if(s==3)
                {
                    c=1;
                    addatbeg(!!s);
                }
                else if(s==2)
                {
                    c=1;
                    addatbeg(!s);
                }
                else
                {
                    addatbeg(!!s);
                    c=0;
                }
                p=p->prev;
                q=q->prev;
            }
            if(c)
           addatbeg(!!c);
            while(!p && q)
            {
                addatbeg(q->bit);
                q=q->next;
            }
            while(p && !q)
            {
                addatbeg(p->bit);
                p=p->next;
            }
        } 
        void Decimal()
        {
        		node *p=head;
            int pw=count()-1,i,sum=0;
				
				while(p)
				{
					sum+=(p->bit)*pow(2,pw--);
					p=p->next;
				}
				cout<<sum;
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
   void getsub(DLL D1,DLL D2)
   {
   	D2
   }
     void getsub(DLL D1,DLL D2,int f)
        {
            int s,c=0;
            node* p=D1.last;
            node* q=D2.last;
            while(p && q)
            {
                s=(p->bit)+(q->bit)+c;
                if(s==3)
                {
                    c=1;
                    addatbeg(!!s);
                }
                else if(s==2)
                {
                    c=1;
                    addatbeg(!s);
                }
                else
                {
                    addatbeg(!!s);
                    c=0;
                }
                p=p->prev;
                q=q->prev;
            }
            if(c)
           addatbeg(!!c);
            while(!p && q)
            {
                addatbeg(q->bit);
                q=q->next;
            }
            while(p && !q)
            {
                addatbeg(p->bit);
                p=p->next;
            }
        } 
};
int main()
{
    DLL D1,D2,D3,D4;
    D1.getnum();
    cout<<"Binary :";
    D1.disp();cout<<endl;
    D2.getnum();
    cout<<"Binary :";
    D2.disp();cout<<endl;
    D3.getadd(D1,D2);
    cout<<">>>Addition :";
    D3.disp();cout<<endl;
	 cout<<"IN decimal :";D3.Decimal();   
	 D4.getsub(D1,D2);
    cout<<">>>Subtraction :";
    D4.disp();cout<<endl;
	 cout<<"IN decimal :";D4.Decimal();     
    return 0;
}   
