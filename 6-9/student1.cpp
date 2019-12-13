#include<iostream>
using namespace std;
class node
{
    char na[50];
    int prn,mon;
    node* next;
    node()
    {
          cout<<"Enter name :";cin.getline(na,48);
          cout<<"Enter prn  :";cin>>prn;
          
          next=0;
    }
    friend class SLL;
};
class SLL
{
    node *head;
    public:
        SLL()
        {
            head=0;
        }
        void addatbeg()
        {
            node* q;
            q=new node ();
            head->mon=0;
            q->mon=1;
            if(head==0)
            {
                head=q;
            }
            else
            {
                q->next=head;
                head=q;
            }
        }
        node* creat()
        {
            int y;
           
             node* q=head=new node();
                head->mon=1;
                cout<<"Do you want to continue(1/0) :";
                cin>>y;
                cin.ignore();
                
                if(!y)
                return head;
                
            do
            {
               q->next=new node();
               q=q->next;
               cout<<"Do you want to continue(1/0) :";
               cin>>y;
               cin.ignore();
            }while(y);
            return head;
        }
        void deleteatbeg()
        {
            if(head==0)
            cout<<"List empty";
            else
            {
                node *p=head;
                head=head->next;
                head->mon=1;
                delete p;
            }
        }
        void disp()
        {
            node*p=head;
            while(p)
            {
                cout<<"Name is ";cout<<p->na<<endl;
                cout<<"PRN  is ";cout<<p->prn<<endl;
                if(p->mon)
                cout<<"MONitor"<<endl;
                cout<<"----------------------------\n";
                p=p->next;
        
            }
        }
        int count()
        {
            node*p=head;
            int c=0;
            while(p)
            {
                c++;
                p=p->next;
        
            }
            return c;
        }
        void delbypos(int pos)
        {
            cout<<"HI"<<endl;
            node* p=head;int i;
            if(pos<1 || pos>count())
            cout<<"Invalid pos";
            else if(pos==1)
            {
                cout<<"HI1"<<endl;
                deleteatbeg();
            }
            else
            {
                cout<<"HI2"<<endl;
                for(i=0;i<pos-1;i++)
                p=p->next;
                node *q=p->next;
                p->next=p->next->next;
                delete q;
                
            }
        }
        
};
int main()
{
    SLL S1;
    node* head=S1.creat();
    int y;
    do
    {
        cout<<"1.Disp\n";
             cout<<"2.count\n";
        cout<<"3.delete\n";
        cout<<"0.EXIT\n";
        cin>>y;
        switch(y)
        {
            case 1:S1.disp();break;
            case 2:cout<<S1.count();break;
            case 3:int pos;
            cin>>pos;
            S1.delbypos(pos);break;
            case 0:break;
            cout<<"continue ";
            cin>>y;
        }
    }while(y);
}
