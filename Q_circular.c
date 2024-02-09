#include<stdio.h>
#include<stdlib.h>
#define n 5
int queue[n];
int front =-1, rear=-1;
void enqueue(int value)
{
    if (front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=value;

    }
    else if ((rear+1)%n==front)
    {
        printf("queue is full\n");
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=value;
    }
    
    
}
void dequeue()
{
    if (front==-1&&rear==-1)
    {
        printf("queue is empty\n");
    }
    else if(front==rear)
    {
        front=rear =-1;
    }
    else{
        printf("the removed element is %d\n",queue[front]);
        front=(front+1)%n;
    }
    
}
void display()
{
    int i=front;
    if (front==-1&&rear==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("the elements are queue are-\n");
        while (i!=rear)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%n;
        }
        printf("%d\n",queue[rear]);
    }  
}
void topelement()
{
    if (front==-1&&rear==-1)
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
