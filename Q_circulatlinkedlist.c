#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;
void enqueue(int value)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=0;
    if (rear==0)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
    printf("the data has bee inserted\n");
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("the queue is empty\n");
    }
    else if (front==rear)
    {
        front=rear=0;
        free(temp);
    }
    
    else
    {
        front = front->next;
        rear->next=front;
        printf("the removed data is %d\n", temp->data);
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("the queue is empty\n");
    }
    else
    {
        printf("the queue elements are \n");

        while (temp->next != front)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}
void topelement()
{
     if (front == NULL)
    {
        printf("the queue is empty\n");
    }
    else
    {
        printf("the top element is %d\n", front->data);
    }
}
int main()
{
    int value;
    printf("1- for enqueue operattion\n");
    printf("2- for dequeue operattion\n");
    printf("3- for display operattion\n");
    printf("4- for top element of the queue1 data structure operattion\n");
    printf("5- for exist operattion\n");
    printf("---------------------------\n");

    int i = 1;
    while (i)
    {
        int ch;
        printf("Enter choice for the operation\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            // int value;
            printf("enter the data to be entered\n");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            // printf("the removed item is %d\n",pop(stack,top));
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            topelement();
            break;
        case 5:
            i = 0;
            break;
        default:
            break;
        }
    }
}