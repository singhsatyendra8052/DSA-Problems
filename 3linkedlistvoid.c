#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *head;
struct node *createsll(int );
void display(struct node *head);
int main()
{
    int n;
    // creating the new node
    head=createsll(n);
    display(head);
}
struct node *createsll(int n)
{
    int n;
    scanf("%d",&n);
    for (int i =1; i <=n; i++)
    {
        
    }
    
}