#include<stdio.h>
#include<stdlib.h>
int n;
struct node{
    int data;
    struct node *Lnext;
    struct node *Rnext
};
struct node *head;
struct node *create( int n);
int main()
{
    // int n;
    scanf("%d",&n);

}
struct node *create(int n)
{
    struct node *newnode;
    struct node *ptr=head;
    for (int i =1; i <=n; i++)
    {
        if (i==1)
        {
            head=(struct node *)malloc(sizeof(struct node ));
            head->Lnext=NULL;
            ptr=head;
        }
        else
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            ptr->Rnext=newnode;
            newnode->Lnext=ptr;
            ptr=newnode;
        }
        scanf("%d",&ptr->data);
    }
    ptr->Rnext=NULL;
    return head;
}
void display(struct node *head){
    struct node *ptr;
    ptr=head;
    while (ptr->Rnext!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->Rnext;
    }

    
}
void insert(struct node *head)
{
    struct node * ptr;
    ptr=head;
    int a,c;
    scanf("%d",&a);
    int h[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d",&h[i]);
    }
    for (int i = 0; i < a; i++)
    {
        c=(n+1)/2;
        for (int i = 1; i < c; i++)
        {
            
        }
        

    }
    
    

}

