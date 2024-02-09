#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *create_sll();
void display_sll(struct node *head);

struct node *insert_mid(struct node *head);
struct node *delete_mid(struct node *head);
struct node *insert_keybefore(struct node *head);
int main()
{
    int n;
    scanf("%d",&n);
    head=create_sll(n);
    display_sll(head);
    printf("\n");
    head=insert_keybefore(head);
    display_sll(head);
    head=insert_mid(head);
    display_sll(head);
    head=delete_mid(head);
    printf("Linked list after the deletion of mid element\n");
    display_sll(head);
    return 0;

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
void display_sll(struct node *head)
{
    struct node *ptr;
    int i=1;
    ptr=head;
    for ( ptr =head; ptr !=NULL; ptr=ptr->next)
    {
        printf(" %d node - %d\n",i,ptr->data);
        i++;
    }
    
}
struct node * insert_keybefore(struct node *head)
{
    int key,data,count=0;
    printf("insert the element before which you want to insert the element-\n");
    scanf("%d",&key);
    struct node *ptr;
    struct node *prev;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    ptr=(struct node *)malloc(sizeof(struct node ));
    //prev=(struct node *)malloc(sizeof(struct node ));
    ptr=head;
    for (ptr = head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data==key)
        {
            printf("insert the element-\n");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=prev->next;
            prev->next=newnode;
            count=0;
            break;
        }
        else
        {
            count=1;
        }
        prev=ptr;
        
    }
    if (count!=0)
        {
            printf("the element is not present\n");
        }
   return head; 
}   
struct node *insert_mid(struct node *head)
{
    struct node *ptr;
    struct node *prev;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    
    int count=0;
    for ( ptr =head; ptr!=NULL; ptr=ptr->next)
    {
        count++;
    }
    int n=count,a=0;
    if (count%2==0)
    {
            ptr=head;
            for (int i =1; i <=count/2; i++)
            {
                prev=ptr;
               ptr=ptr->next; 
            }
            printf("enter the data of new element\n");
            scanf("%d",&newnode->data);
            prev->next=newnode;
            newnode->next=ptr;
            return head;
    }
    else
    {
        ptr=head;
            for (int i =1; i <=count/2; i++)
            {
                prev=ptr;
               ptr=ptr->next; 
            }
            printf("enter the data of new element\n");
            scanf("%d",&newnode->data);
            prev->next=newnode;
            newnode->next=ptr;
            return head;
    }
}
struct node * delete_mid(struct node *head)
{
    int count=0;
    struct node *ptr;
    
    struct node *prev;
    for ( ptr =head; ptr!=NULL; ptr=ptr->next)
    {
        count++;
    }
    int n=count;
    if (count%2==0)
    {
        ptr=head;
        for (int i =1; i <=count/2; i++)
            {
                prev=ptr;
               ptr=ptr->next; 
            }
    
    prev->next=ptr->next;
    free(ptr);
    return head;
    }
    else
    {
        ptr=head;
      for (int i =1; i <=count/2; i++)
            {
                prev=ptr;
               ptr=ptr->next; 
            }
    
    prev->next=ptr->next;
    free(ptr);
    return head;
    }
}
