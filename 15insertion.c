#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("element is %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}
struct node *insert(struct node *head,int data)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct node *insertend(struct node *head,int data)
{   
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node*p=head;
    while (p->next !=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL; 
    return head;
}
int main()
{
    struct node* head;
    struct node* first;
    struct node* second;
    
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    
    head->data=1;
    head->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    second->next=NULL;
    printf("traverse list\n");

    traverse(head);
    head= insert(head,4);
    printf("list after insertion\n");
    traverse(head);
    head=insertend(head,14);
    //insertend(head,14);
    printf("list after end insertion\n");
    traverse(head);


    return 0;
}
