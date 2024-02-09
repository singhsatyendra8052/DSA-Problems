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
int main()
{
    struct node* head;
    struct node* first;
    struct node* second;
    struct node* insert;
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    insert=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    second->next=NULL;
    
    traverse(head);

    return 0;
}