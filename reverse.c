#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
   
}node;
node* createlist(int n)
{
    struct node *newNode, *temp, *head;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory");
        return NULL;
    }
    printf("Enter data of node 1:");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL)
        {
            printf("No memory is allocated");
            break;
        }
        printf("Enter the data of node %d:",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}
void traverse_list(node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("Data: %d", temp->data);
        printf("\n");
        temp=temp->next;
    }
}
node* reverse(struct node **head_ref)
{
    struct node *temp,*next,*prev;
    temp=*head_ref;
    prev=NULL;
    next=NULL;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    *head_ref=prev;
}
int main()
{
    int n,after;
    struct node *head=NULL;
    printf("Enter the total number of nodes:");
    scanf("%d",&n);
    head=createlist(n);
    printf("\nData in the list \n");
    traverse_list(head);
    reverse(&head);
    printf("\nReversed list \n");
    traverse_list(head);
}