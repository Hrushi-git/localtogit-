#include<iostream>
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
        void getbin()
        {
            int i=0;char bin[100];           
            cout<<"Enter binary :";
            cin.getline(bin,98);
  
            while(bin[i])
            {
                makeDLL(bin[i++]-48);
            }       
        }
        void makeDLL(char bit)
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
        void addatbeg(char bit)
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
            int pow=count();
                         
        }
};
int main()
{
    DLL D1,D2,D3;
    D1.getbin();
    D2.getbin();cout<<endl;
    D3.getadd(D1,D2);
    D3.disp();
}   
