#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev,*next;
}node;
node* createlist(int n)
{
    struct node *temp, *head;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("No memory is allocated");
        return NULL;
    }
    printf("Enter the data of node 1:");
    scanf("%d",&data);
    head->data=data;
    head->prev=NULL;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
        struct node *new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("No memory is allocated");
            break;
        }
        printf("Enter the data of node %d:",i);
        scanf("%d",&data);
        new_node->data=data;
        new_node->next=NULL;
        new_node->prev=NULL;
        temp->next=new_node;
        new_node->prev=temp;
        temp=temp->next;
    }
    return head;
}
void traverse(struct node **head_ref)
{
    struct node *temp;
    int i=1;
    if(*head_ref==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=*head_ref;
    printf("Data in the list:\n");
    while(temp!=NULL)
    {
        printf("Data of node %d:%d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}
void insert_beg(struct node **head_ref,int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void insert_middle(struct node **head_ref,int data,int after)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    struct node *temp;
    if(*head_ref==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=*head_ref;
    while(temp->data!=after)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    new_node->prev=temp;
}
void insert_end(struct node **head_ref,int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    struct node *temp;
    if(*head_ref==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=*head_ref;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}
int main()
{
    int n,data1,data2,data3,after;
    struct node *head=NULL;
    printf("Enter the total number of nodes:");
    scanf("%d",&n);
    head=createlist(n);
    printf("\n");
    traverse(&head);
    printf("\n");
    printf("Enter the data of node to be insertd in beginning:");
    scanf("%d",data1);
    insert_beg(&head,data1);
    printf("Enter data of node to be added in middle:");
    scanf("%d",&data2);
    printf("Enter data of node after which element is to be added:");
    scanf("%d",&after);
    insert_middle(&head,data2,after);
    printf("Enter data of node to be added at end:");
    scanf("%d",&data3);
    insert_end(&head,data3);
    printf("\n");
    printf("\nNew Data in the list \n");
    traverse(&head);
} 