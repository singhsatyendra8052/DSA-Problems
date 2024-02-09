#include<stdio.h>
#include<stdlib.h>
#define n 5
int queue[n];
int front =-1;
int rear =-1;
void insert()
{
    int data;
    printf("enter the data to be inserted -\n");
    scanf("%d",&data);
    if (rear==n-1)
    {
        printf("the queue is full\n");
    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=data;
        printf("sucessfully inserted\n");

     }   
}
void reverse()
{
    
}
