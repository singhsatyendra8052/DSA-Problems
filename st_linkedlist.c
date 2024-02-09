#include<stdio.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
void push()
{
    
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    if (head==NULL)
    {
        printf("Enter the first value of the stack\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        printf("Enter the value in the stack\n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
    }
    
}
void pop()
    {
        if (head==NULL)
        {
            printf("stack underflow\n");
            return;
        }
        else
        {
            struct node *ptr;
            ptr=head;
            head=ptr->next;
            printf("popped item is %d\n",ptr->data);
            free(ptr);
        }
        //return head;
}
void display(struct node *head)
{
    struct node *ptr=head;
    if (head==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
    
}
void topelement(struct node *head)
{
    struct node *ptr=head;
    if (head==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("the top element is %d\n",ptr->data);
    }
    
    
}
void search(struct node *head)
{
    printf("enter the element to be searched\n");
    int key;
    int flag=0;
    scanf("%d",&key);
    struct node *ptr=head;
    for ( ptr =head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data==key)
        {
            flag=1;
            break;
        }
        
    }
    if (flag)
    {
        printf("element is present in the stack\n");
    }
    else
    {
        printf("element is not present\n");
    }
    
    

}
int main()
{
    printf("1- for push operattion\n");
    printf("2- for pop operattion\n");
    printf("3- for display operattion\n");
    printf("4- for top element of the stack data structure operattion\n");
    printf("5- for searching the element in the stack\n");
    printf("6- for exist operattion\n");
    printf("---------------------------\n");
    
    
    int i=1;
    while (i)
    {
        int ch;
        printf("Enter choice for the operation\n");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:
        push();
        break;
        case 2:
        //printf("the removed item is %d\n",pop(stack,top));
        pop();
        break;
        case 3:
        display(head);
        break;
        case 4:
        topelement(head);
        break;
        case 5:
        search(head);
        break;
        case 6:
        i=0;
        break;
        default:
        break;
        
    }
    }
    
    return 0;
}