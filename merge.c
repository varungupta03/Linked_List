#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* createlist(int n)
{
    struct node *head, *newnode, *temp;
    int data, i;
    head=(struct node*)malloc(sizeof(int));
    if(head==NULL)
    {
        printf("No memory is allocated");
        return NULL;
    }
    printf("Enter the data of node 1:");
    scanf("%d",&data);
    head->next=NULL;
    head->data=data;
    temp=head;
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(int));
        if(newnode==NULL)
        {
            printf("No memory is allocated");
            break;
        }
        printf("Enter the data of node %d:",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}

void traverselist(struct node **head_ref)
{
    struct node *temp;
    if(*head_ref==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=*head_ref;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

node* mergelist(struct node **head_ref1, struct node **head_ref2)
{
    struct node *temp;
    
        temp=*head_ref1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=*head_ref2;
        return *head_ref1;
}

int main()
{
    int n1,n2;
    struct node *head1, *head2, *head;
    printf("Enter the number of nodes in list 1:");
    scanf("%d",&n1);
    head1=createlist(n1);
    printf("\n");
    printf("Data in list 1:\n");
    traverselist(&head1);
    printf("\n");
    printf("Enter the number of nodes in list 2:");
    scanf("%d",&n2);
    head2=createlist(n2);
    printf("\n");
    printf("Data in list 2:\n");
    traverselist(&head2);
    printf("\n");
    head=mergelist(&head1,&head2);
    printf("Merged Data:\n");
    traverselist(&head);    
}