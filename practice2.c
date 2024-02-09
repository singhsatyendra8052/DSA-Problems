#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node *next;
}nd;
nd *head;

struct node *create(int n)
{
    nd *ptr;
    for (int i = 1; i < n; i++)
    {
        if (i==1)
        {
             head=(nd*)malloc(sizeof(nd));
             ptr=head;   
        }
        else
        {
            ptr->next=(nd*)malloc(sizeof(nd));
            ptr=ptr->next;
        }
        printf("enter the data at %d - \n",i);
        scanf("%d",&ptr->data);  
    }
    ptr->next=NULL;
    printf("\n");
    return head;   
}
void display(nd * head,int k)
{
    if (head==NULL)
    {
        return;
    }
    display(head->next,k);
    if (head->data!=k)
    {
        printf("%d\n",head->data);
    }
    
}
int main()
{
    int n;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    head=create(n);
    int k;
    
    scanf("%d",&k);
    display(head,k);
}
