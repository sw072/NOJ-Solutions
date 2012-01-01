#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define is_op(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')

struct node
{
    int num;
    char op;
    bool type;        //0 : number ; 1 : operator
    node *next;
};

node *head;
node *optop;


//op1 > op2 ?
bool comp_prop(char op1, char op2)
{
    if(op2 == '@')
        return true;
    if(op1 == '(')
        return true;
    if(op1 == ')')
        if(op2 == '(')
            return true;
    if(op1 == '^')
        if(op2 != '(')
            return true;
    if(op1 == '*' || op1 == '/')
        if(op2 == '+' || op2 == '-' || op2 == '(')
            return true;
    if(op1 == '+' || op1 == '-')
        if(op2 == '(')
            return true;
    return false;
}

void print_express(node *h)
{
    if(!h) return;
    print_express(h->next);
    if(!h->next)
    {
        printf("%d", h->num);
        return;
    }
    if(!h->type) printf(" %d", h->num);
    else if(h->type) printf(" %c", h->op);
}

void calculate(node *h)
{
    int a, b;
    if(!h->next) return;
    calculate(h->next);
    if(h->type)
    {
        a = h->next->next->num;
        b = h->next->num;
        if(h->op == '+') h->num = a + b;
        else if(h->op == '-') h->num = a - b;
        else if(h->op == '*') h->num = a * b;
        else if(h->op == '/') h->num = a / b;
        else if(h->op == '^')
        {
            h->num = 1;
            while(b)
            {
                h->num *= a;
                b--;
            }
        }
        h->type = false;
        node *p1 = h->next->next;
        node *p2 = h->next;
        h->next = p1->next;
        free(p1);
        free(p2);
        print_express(head);
        printf("\n");
    }
}

int main()
{
    char str[100000];
    scanf("%s", str);
    int i, len = strlen(str);
    node * pnew;
    optop = (node *)malloc(sizeof(node));
    optop->op = '@';
    optop->type = true;
    optop->next = NULL;
    for(i = 0; i < len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(!head)
            {
                head = (node *)malloc(sizeof(node));
                head->next = NULL;
            }
            else
            {
                pnew= (node *)malloc(sizeof(node));
                pnew->next = head;
                head = pnew;
            }
            head->num = str[i] - '0';
            head->type = false;
        }
        else if(str[i] == ' ')
        {}
        else if(is_op(str[i]))
        {
            while(!comp_prop(str[i], optop->op))
            {
                pnew = optop;
                optop = optop->next;
                pnew->next = head;
                head = pnew;
            }
            if(optop->op == '(' && str[i] == ')')
            {
                pnew = optop;
                optop = optop->next;
                free(pnew);
            }
            if(str[i] != ')' && comp_prop(str[i], optop->op))        //str[i].op > optop->op
            {
                pnew = (node *)malloc(sizeof(node));
                pnew->next = optop;
                optop = pnew;
                optop->op = str[i];
                optop->type = true;
            }
        }
    }
    while(optop->next)
    {
        pnew = optop;
        optop = optop->next;
        pnew->next = head;
        head = pnew;
    }
    free(optop);

    print_express(head);
    printf("\n");
    
    calculate(head);

    while(head)
    {
        pnew = head;
        head = head->next;
        free(pnew);
    }

    return 0;
}