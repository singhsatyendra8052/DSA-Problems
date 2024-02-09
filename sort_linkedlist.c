#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
int main()
{
    int n;
    scanf("%d",&n);
    head=create_sll(n);

}
void sort(struct node *head,int n)
{
    struct node *next=head;
    struct node *ptr=head;
    struct node *ptr1=head;
    struct node *next1;
    for (ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        next1=next->next;
        for (ptr1=head;ptr1!=NULL;ptr1=ptr1->next)
        {
            if (next->data>next1->data)
            {
                int temp=next->data;
                next->data=next1->data;
                next1->data=temp;
            }
            
        }
        
    }
    
}
struct node* create_sll(int n)
{
    struct node* ptr;
    for (int i = 1; i <=n; i++)
    {
        if (i==1)
        {
            head=(struct node*)malloc(sizeof(struct node));
            ptr=head;
        }
        else
        {
            ptr->next=(struct node*)malloc(sizeof(struct node));
            ptr=ptr->next;
        }
        printf("the %d element of the list = ",i);
        scanf("%d",&ptr->data);
        
        
    }
    ptr->next=NULL;
    printf("\n");
    return head;
    
}