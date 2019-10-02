#include<iostream>
using namespace std;

class lst{
public:
lst *next;
int info;
public:
   lst* makelist(lst* start)
  {
   lst *temp = new lst;
   cin>>temp->info;
   temp->next = NULL;
   if(start==NULL)
   {
       start=temp;
       return start;
   }
   lst *cur =start;
   while(cur->next!=NULL)
   cur=cur->next;

   cur->next=temp;
   return start;
    }


    lst* insertbefore(lst *start)
    {
    lst *temp = new lst;
    cin>>temp->info;
    temp->next = NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    cout<<"Insert element to be inserted before"<<endl;
    int ele;
    cin>>ele;

    lst *cur=start;
    while((cur->next)->info!=ele)
    {
        cur=cur->next;
    }
    temp->next=cur->next;
    cur->next=temp;
    if(cur==start)
    {
        temp->next=cur;
        start = temp;
    }
    if(cur==NULL)
        cout<<"Element not found"<<endl;
    return start;

  }
lst* display(lst* start)
{
    lst *cur=start;
    while(cur!=NULL)
    {
        cout<<cur->info<<"\t";
        cur=cur->next;
    }
    cout<<endl;
}
lst* insertafter(lst* start)
{
    lst *temp = new lst;
    cin>>temp->info;
    temp->next = NULL;
    lst *t =start;
    cout<<"Insert element to be inserted after"<<endl;
    int ele;
    cin>>ele;

    while(t->info!=ele)
    {
        t=t->next;
    }

    temp->next = t->next;
    t->next = temp;
    return start;
}
lst* deletefunc(lst* start)
{
    lst* t =start;
    cout<<"Insert element to be deleted"<<endl;
    int ele;
    cin>>ele;
    lst *prev;
    while((t->info!=ele)&&(t!=NULL))
    {
        prev=t;
        t=t->next;
    }
    if(t==start)
    {
        start=start->next;
        delete t;
    }
    else if(t==NULL){
        cout<<"Element Not present"<<endl;
    }
    else{
        prev->next= t->next;
        delete t;
    }
}
lst* reversal(lst *start)
{
    lst *p, *q, *r;
    p=r=NULL;
    q=start;
    while(q!=NULL)
    {
       r=p;
       p=q;
       q=q->next;
       p->next=r;

    }
    start=p;
    return start;
}
lst* sorting(lst *start)
{
    lst *p,*q;
    p=start;
    int temp;
    while(p->next!=NULL){
        q=p->next;
        while(q!=NULL)
        {
            if((p->info)>(q->info)){
             temp=p->info;
             p->info=q->info;
             q->info=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
    display(start);
}
lst* deletealternate(lst *start)
{
    lst *c=start;
    lst* c1;
    while((c!=NULL)&&(c->next!=NULL))
    {
        c1=c->next;
        c->next=c1->next;
        if(c!=NULL)
            c=c->next;
        delete c1;
    }
    display(start);

}
lst* insertinsorted(lst *start)
{
    cout<<"Insert element"<<endl;
    lst *temp= new lst;
    temp->next=NULL;
    cin>>temp->info;
    lst *cur;
    if(start==NULL)
    {
        start= temp;
        return start;
    }
    if((temp->info)<(start->info))
    {
        temp->next= start;
        start=temp;
        return start;
    }
cur =start;
while(cur!=NULL)
{
    lst *t =cur->next;
    if((temp->info)>=(cur->info)&&(temp->info)<=(t->info))
    {
        cur->next=temp;
        temp->next =t;
        break;
    }
    cur=cur->next;
    if(cur->next==NULL)
     {
         cur->next=temp;
         temp->next=NULL;
     }

}

}
};

int main()
{
    lst *start=NULL;
    lst s;
    int ch,ch1;
    while(1)
    {
    cout<<"1.Insert 2.Insert Before or After\ 3.Display \t 4.Delete \t 5.Reversal \t 6.Sort \t 7.Alternate Node deletion \t 8.sorted insertion \t 9.exit  "<<endl;
    cin>>ch;
    switch(ch){
    case 1:start=s.makelist(start);break;
    case 2:cout<<"1.Insertion Before \t 2.Insertion After"<<endl;
            cin>>ch1;
            switch(ch1)
            {
            case 1: start=s.insertbefore(start);break;
            case 2: start = s.insertafter(start);break;
            }
            break;
    case 3:s.display(start);break;
    case 4:s.deletefunc(start);break;
    case 5:start=s.reversal(start);
            s.display(start);
            break;
    case 6:s.sorting(start);break;
    case 7:s.deletealternate(start);break;
    case 8:s.insertinsorted(start);break;
    default: ch=9;
            break;
    }
if(ch==9)
    break;
}

}
