#include<stdio.h>
#include<stdlib.h>
static int i=0;
static int n;
struct node *create_sll();
void display_sll(struct node *head);
void search_sll(struct node *head);
struct node
    {
        int data;
        struct node *next;
        
    };
    struct node *head;
    
    //ptr=(struct node *)malloc(sizeof(struct node));


//struct node* insertend_sll(struct node*);

int main()
{
//head=create_sll();
    struct node *head;
    printf("enter the number of list\n");
    scanf("%d",&n);
    head=create_sll(n);
    display_sll(head);


    return 0;
}

struct node *create_sll()
{
    struct node *ptr;
    for (int i = 0; i <n; i++)
    {
        if(i==1)
        {
             head=(struct node*)malloc(sizeof(struct node));
             ptr=head;
        }
        else
        {
            ptr->next=(struct node*)malloc(sizeof(struct node));
            ptr=ptr->next;
        }
        printf("\nenter the %d the element ",i);
        scanf("%d",&ptr->data);
        
    }
    ptr->next=NULL;
    return(head);

    
}
void display_sll(struct node *head)
{
    struct node *ptr;
    int count=0;
    for (ptr=head;ptr!=NULL;ptr=ptr->next)
    {
      printf("\nnode data=%d",ptr->data);
    }
    count ++;
    
}