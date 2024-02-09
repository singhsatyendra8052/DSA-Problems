#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void push()
{
    int i = 1;
    while (i)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        if (newnode->data > 0)
        {
        
            if (head == NULL)
            {
                newnode->next = NULL;
                head = newnode;
            }
            else
            {
                newnode->next = head;
                head = newnode;
            }
        }
        else
        {
            i=0;
        }
        
    }
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
int main()
{
    push();
    display(head);
    return 0;
}