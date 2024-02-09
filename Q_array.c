#include<stdio.h>
# define n 100
int queue[n];
int front=-1,rear=-1;

void enqueue(int value)
{
    if(rear==n-1)
    {
        printf("queue is overflow\n");
    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("sucessfully inserted\n");

     }
}
void dequeue()
{
    if (front==-1)
    {
        printf("The queue id underflow\n");
    }
    else
    {
        printf("the deleted element is %d\n",queue[front]);
        front++;
        if (front==n)
        {
            front=rear=-1;
        }
        
    }
    
    
}
void display()
{
    if(rear==-1)
    {
        printf("the queue is empty\n");
    }
    else{
        printf("the queue elements are-\n");
        for (int i = front; i <=rear; i++)
        {
            printf("%d\n",queue[i]);
        }
        
    }

}
void topelement()
{
    if (rear==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("%d\n",queue[front]);
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
    
    
    int i=1;
    while (i)
    {
        int ch;
        printf("Enter choice for the operation\n");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:
        //int value;
        printf("enter the data to be entered\n");
        scanf("%d",&value);
        enqueue(value);
        break;
        case 2:
        //printf("the removed item is %d\n",pop(stack,top));
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        topelement();
        break;
        case 5:
        i=0;
        break;
        default:
        break;
        
    }
    }
}
