#include "stdio.h"
#include "stdlib.h"

struct vote{
    int id;
    int vn;
    vote *next;
};

vote * vhead;

void insert(int id)
{
    vote * p = vhead->next;
    vote * q = vhead;
    while(p && p->id != id)
    {
        q = p;
        p = p->next;
    }
    if(p) p->vn++;
    else
    {
        q->next = (vote *)malloc(sizeof(vote));
        q->next->id = id;
        q->next->vn = 1;
        q->next->next = NULL;
    }
}

void freelist()
{
    vote * p = vhead->next;
    vote *q;
    while(p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    vhead->next = NULL;
}

int main()
{
    int n, vn, id, i;
    vhead = (vote *)malloc(sizeof(vote));
    vhead->id = -1;
    vhead->vn = -1;
    vhead->next = NULL;
    while(scanf("%d%d", &n, &vn) != -1)
    {
        for(i = 0; i < vn; i++)
        {
            scanf("%d", &id);
            insert(id);
        }
        vote *p = vhead->next;
        int half = vn / 2;
        while(p)
        {
            if(p->vn > half)
            {
                printf("%d\n", p->id);
                break;
            }
            p = p->next;
        }
        if(!p) printf("-1\n");
        freelist();
    }
    return 0;
}