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
void delete_beg(struct node **head_ref)
{
    struct node *temp;
    temp=*head_ref;
    if(head_ref==NULL)
    {
        printf("Memory is not allocated");
    }
    *head_ref=temp->next;
    free(temp);
    printf("\nNew Data in the list \n");
    traverse_list(*head_ref);
}
void delete_end(struct node **head_ref)
{
    struct node *temp,*prev;
    if(*head_ref==NULL)
    {
        printf("Memory is not allocated");
    }
    temp=*head_ref;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("\nNew Data in the list \n");
    traverse_list(*head_ref);
}
void delete_middle(struct node **head_ref,int after)
{
    struct node *temp,*ptr;
    temp=*head_ref;
    ptr=NULL;
    if(*head_ref==NULL)
    {
        printf("Memory is not allocated");
    }
    while(temp->data!=after)
    
    { 
        temp=temp->next;
    }
    if(temp==NULL) printf("Data after which the node is to be deleted is not available");
    ptr=temp->next;
    if(ptr==NULL) printf("No node is available to delete");
    temp->next=ptr->next;
    free(ptr);
    printf("\nNew Data in the list \n");
    traverse_list(*head_ref);
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
    delete_beg(&head);
    delete_end(&head);
    printf("Enter data of node after which element is to be deleted:");
    scanf("%d",&after);
    delete_middle(&head,after);
    printf("\n New Data in the list \n");
    traverse_list(head);
}