#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;

int is_full(int top)
{
    if(top == N-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push()
{
    printf("enter the element to be inserted-\n");
    int data;
    scanf("%d",&data);
    if (is_full(top)==1)
    {
        printf("Stack is full\n");

    }
    else{
        top=top+1;
        stack[top]=data;
    }
    
}
int is_empty(int top)
{
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

void pop()
{
    int popped_item;
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        popped_item=stack[top];
        top=top-1;
        printf("the popped item is %d\n",popped_item);
    }
    // return popped_item;
    
}

void display(int top)
{
    printf("the elements of the stack -\n");
    for (int i =top; i >=0; i--)
    {
        printf(" %d \n",stack[i]);
    }
    
}
void topelement()
{
    printf("the top most element of the stack is %d\n",stack[top]);
}
int main()
{
    printf("1- for push operattion\n");
    printf("2- for pop operattion\n");
    printf("3- for display operattion\n");
    printf("4- for top element of the stack data structure operattion\n");
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
        push();
        break;
        case 2:
        //printf("the removed item is %d\n",pop(stack,top));
        pop();
        break;
        case 3:
        display(top);
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
