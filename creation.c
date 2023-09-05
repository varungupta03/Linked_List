#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head,*s,*t;
    head=NULL;
    s=NULL;
    t=NULL;
    head = (struct node*)malloc(sizeof(struct node));
    s = (struct node*)malloc(sizeof(struct node));
    t = (struct node*)malloc(sizeof(struct node));
    head->next=s;
    head->data=10;
    s->next=t;
    s->data=9;
    t->next=NULL;
    t->data=19;
}