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
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
void insert_beg(struct node **head_ref,int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void insert_middle(struct node **head_ref, int data, int after)
{
    struct node *new_node, *temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
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
}
void insert_end(struct node **head_ref, int data)
{
    struct node *new_node, *temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=*head_ref;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
int main()
{
    int n,after,data1,data2,data3;
    struct node *head=NULL;
    printf("Enter the total number of nodes:");
    scanf("%d",&n);
    head=createlist(n);
    printf("\nData in the list \n");
    traverse_list(head);
    printf("\n");
    printf("Enter data of node to be added at beginning:");
    scanf("%d",&data1);
    insert_beg(&head,data1);
    printf("Enter data of node to be added in middle:");
    scanf("%d",&data2);
    printf("Enter data of node after which element is to be added:");
    scanf("%d",&after);
    insert_middle(&head,data2,after);
    printf("Enter data of node to be added at end:");
    scanf("%d",&data3);
    insert_end(&head,data3);
    printf("\nNew Data in the list \n");
    traverse_list(head);
}