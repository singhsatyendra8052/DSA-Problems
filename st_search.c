#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node  *head=NULL;
void push(){
    int i=1;
    while (i)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        if (newnode->data>0)
        {
            if (head==NULL )
            {
                newnode->next=NULL;
                head=newnode;
            }
            else
            {
                newnode->next=head;
                head=newnode;
            }
        }
        else
        {
            i=0;
        }
        
    }
    
}
void search(struct node* head)
{
    struct node *ptr=head;
    int flag=0;
    int key;
    scanf("%d",&key);
    for ( ptr = head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data==key)
        {
            flag=1;
        }
        
    }
    if (flag)
    {
        printf("Elemnet found");
    }
    else{
        printf("Element not found");
    }
    
}
int main()
{
    push();
    search(head);
    return 0;
}