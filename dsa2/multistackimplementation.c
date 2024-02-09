#include<stdio.h>
#define n 9
int stack[n];
int topA=-1;
int topB=n;

void PUSH_A()
{
    int data;
    printf("Enter the number to be inserted in stack a; \n");
    scanf("%d",&data);
    if (topA == (topB-1))
    {
        printf("stack is full \n");
    }
     else
     {
        topA++;
        stack[topA]=data;
     }
       
}
void PUSH_B()
{
    printf("enter the number to be inserted in stack B: \n");
    int data;
    scanf("%d",&data);
    if (topB==topA+1)
    {
        printf("stack is full \n");
    }
     else
     {
        topB--;
        stack[topB]=data;
     }
       
}
void POP_A()
{
    int poppeditem;
    if (topA==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        poppeditem=stack[topA];
        topA--;
        printf("popped item is - %d \n",poppeditem);
    }  
}
void POP_B()
{
    int poppeditem;
    if (topB==n)
    {
        printf("stack is empty\n");
    }
    else
    {
        poppeditem=stack[topB];
        topB++;
        printf("popped item is - %d \n",poppeditem);
    }  
}
void display(int topA,int topB)
{
    printf("the elements of the stackA-\n");
    for (int i =topA; i >=0; i--)
    {
        printf(" %d \n",stack[i]);
    }
    printf("the elements of the stackB-\n");
    for (int i=topB;i<n;i++)
    {
        printf(" %d \n",stack[i]);
    }
}
int main()
{
    printf("1- for push operattion in stack A\n");
    printf("2- for push operation in stack B\n");
    printf("3- for pop operation in stackA\n");
    printf("4- for pop operation in stackB\n");
    printf("5- for exist operattion\n");
    printf("6- for display operation\n");
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
            PUSH_A();
            break;
            case 2:
            PUSH_B();
            break;
            case 3:
            POP_A();
            break;
            case 4:
            POP_B();
            break;
            case 5:
            i=0;
            break;
            case 6:
            display(topA,topB);
            default:
            break;

        }
    }
    
    return 0;
}
