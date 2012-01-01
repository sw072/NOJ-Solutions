#include "iostream"
using namespace std;

struct node
{
    int num;
    node *next;
};
int n,k;
node *h;
void Creat()
{
    int i;
    node *p,*q;
    h=new node;
    h->num=1;
    p=h;
    for(i=1;i<n;i++)
    {
        q=new node;
        q->num=i+1;
        p->next=q;
        p=q;
    }
    q->next=h;
}

void Move(node *p)
{
    node *q;
    q=p->next;
    p->next=q->next;
    delete q;
    h=p->next;
}

node *Count()
{
    int i;
    node *p;
    for(i=0;i<k;i++)
    {
        p=h;
        h=h->next;
    }
    return p;
}

int main()
{
    int i=0;
    node *p;
    while(scanf("%d%d",&n,&k)!=-1)
    {
        k--;
        i=0;
        Creat();
        while(i<n-1)
        {
            p=Count();
            Move(p);            //????p????????????
            i++;
        }
        printf("%d\n",h->num);
        delete h;
    }
    return 0;
}