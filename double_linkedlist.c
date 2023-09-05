#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev,*next;
}node;
node* createlist(int n)
{
    struct node *head,*temp;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if (head==NULL)
    {
        printf("Mo memory is allocated");
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
        struct node *new_node=NULL;
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("No memory is allocated");
            return NULL;
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
void traverse(struct node *head_ref)
{
    struct node *temp;
    int i=1;
    if(head_ref==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=head_ref;
    printf("Data in the list:\n");
    while(temp!=NULL)
    {
        printf("Data of node %d:%d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}
int main()
{
    int n;
    struct node *head=NULL;
    printf("Enter the total number of nodes:");
    scanf("%d",&n);
    head=createlist(n);
    traverse(head);
}