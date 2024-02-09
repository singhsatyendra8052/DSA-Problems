#include<stdio.h>
#include<stdlib.h>
//static int n;
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *create_sll(int);//1
void search_sll(struct node *head);//2
void display_sll(struct node *head);//3
struct node * insertfirst(struct node *head);//4
struct node * insertlocafter(struct node *head);//5
struct node * insertend(struct node *head);//6
struct node *insert_keyafter(struct node *head);//7
struct node *insert_keybefore(struct node *head);//8
struct node *insert_mid(struct node *head);//9
struct node *delete_loc(struct node *head);//10
struct node *delete_beg(struct node *head);//11
struct node *delete_end(struct node *head);//12
struct node *insertlocbefore(struct node *head);//13
struct node *delete_key(struct node *head);//14
struct node *delete_mid(struct node *head);//15

int main()
{
    int n;
    struct node *head;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    head=create_sll(n);
    display_sll(head);
    //function for searching an elements
    search_sll(head);
    head=insertfirst(head);
    printf("linked list after the insertion of element at first position\n");
    display_sll(head);
    //function for inserting the element at end positions
    head=insertend(head);
    printf("linked list after the insertion of element at end position\n");
    display_sll(head);

    //linked list after the insertion of element at the mid position
    head=insertlocafter(head);
    printf("linked list after the insertion of element at the mid position\n");
    display_sll(head);
    //funtion for inserting the element after a given node
    head=insertlocbefore(head);
    display_sll(head); 
    //inserting element after a given key
    head=insert_keyafter(head);
    display_sll(head);
    //inserting the elements before a given elements
    head=insert_keybefore(head);
    display_sll(head);
    //function for inserting the element at the mid position
    head=insert_mid(head);
    display_sll(head);
    //funtion for deleting an element in gice sll
    head=delete_key(head);
    display_sll(head);
    //Linked list after the deletion of mid elements
    head=delete_loc(head);
    printf("Linked list after the deletion of elements at given node\n");
    display_sll(head);
    //function for deletion at the begining
    head=delete_beg(head);
    display_sll(head);
    //function for deletion of last node
    head=delete_end(head);
    display_sll(head);
    //funtion for deleting mid elements
    head=delete_mid(head);
    printf("linked list list after deletion of mid element\n");
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
struct node * insertfirst(struct node *head)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    int data;
    printf("enter the data to be inserted at first node-\n");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    
    return head;

}
struct node* insertlocafter(struct node *head)
{
    struct node *ptr;
    struct node *pttr;
    ptr=(struct node*)malloc(sizeof(struct node));
    pttr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    int data,n,count=1;
    printf("enter the data inserted after the  node-\n");
    scanf("%d",&data);
    printf("After which node you want to insert your data-\n");
    scanf("%d",&n);
    while (count!=n)
    {
        ptr=ptr->next;
        count++;
    }
    //ptr=pttr->next;
    pttr->data=data;
    pttr->next=ptr->next;
    ptr->next=pttr;
    return head;  
}
struct node * delete_loc(struct node *head)
{
    printf("enter which node you want to delete\n");
    int p,count =1;
    scanf("%d",&p);
    struct node *ptr=head;
    struct node *prev;
    //ptr=(struct node *)malloc(sizeof(struct node));
    //prev=(struct node *)malloc(sizeof(struct node));
    while (count!=p)
    {
        prev=ptr;
        ptr=ptr->next;
        count++;
    }
    
    prev->next=ptr->next;
    free(ptr);
    return head;
}
struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    printf("the new sll after deletion of first element\n");
    return head;

}
struct node *delete_end(struct node *head)
{
    struct node *prev;
    struct node *ptr;
    ptr=head;
    while (ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;

    }
    prev->next=NULL;
    free(ptr);
    printf("The new sll after the deletion of elements at the last node \n");
    return head;
    
}
struct node *insertend(struct node *head)
{
    struct node *ptr;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("The new data to be inserted at the end\n");
    scanf("%d",&newnode->data);
    ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    return head;
}
void search_sll(struct node *head)
{
    struct node *ptr;
    int n,flag=0;
    ptr=head;
    printf("enter the data to be searched\n");
    scanf("%d",&n);
    for ( ptr =head; ptr !=NULL; ptr=ptr->next)
    {
        if (n==ptr->data)
        {
            flag=1;
            
        }
        
    }
    if (flag)
    {
        printf("Element is present \n");
    }
    else
    {
        printf("Elemnet is not present\n");
    }
}
struct node *insert_keyafter(struct node *head)
{
    int key,data;
    printf("enter the element after which you want to insert the new element-\n");
    scanf("%d",&key);
    struct node *ptr;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr=head;
    for (ptr = head; ptr!=NULL; ptr=ptr=ptr->next)
    {
        if (ptr->data==key)
        {
            printf("insert the element-\n");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=ptr->next;
            ptr->next=newnode;
      
            break;
        }
        
    }
    
   return head; 
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
struct node *delete_key(struct node *head)
{
    int data;
    printf("enter the data to be deleted\n");
    scanf("%d",&data);
    struct node *ptr;
    struct node *prev;
    ptr=head;
    while (ptr!=NULL)
    {
        if (ptr->data==data)
        {
            prev->next=ptr->next;
            free(ptr);
            break;
        }
        prev=ptr;
        ptr=ptr->next;
        
    }
    return head;

}
struct node *insertlocbefore(struct node *head)
{
    struct node *ptr;
    struct node *pttr;
    ptr=(struct node*)malloc(sizeof(struct node));
    pttr=(struct node*)malloc(sizeof(struct node));
    
    int data,n,count=1;
    printf("enter the data inserted before the  node-\n");
    scanf("%d",&data);
    printf("before which node you want to insert your data-\n");
    scanf("%d",&n);
   if (n==1)
   {
        ptr->data=data;
        ptr->next=head;
        head=ptr;
   }
   if(n>=2)
   {
    ptr=head;
     while (count!=n-1)
    {
        ptr=ptr->next;
        count++;
    }
    pttr->data=data;
    pttr->next=ptr->next;
    ptr->next=pttr;
   }
   
    //ptr=pttr->next;
    
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
    int n=count;
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
