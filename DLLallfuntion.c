#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *Lnext;
    int data;
    struct node *Rnext;
};
struct node *head;
struct node *create_dll(int);
void display_dll(struct node *head);
void search_dll(struct node *head);//1
struct node * insertfirstDLL(struct node *head);//2
struct node * insertendDLL(struct node *head);//3
struct node *insert_keyafterDLL(struct node *head);//4
struct node *insert_keybeforeDLL(struct node *head);//5
struct node * insertlocafterDLL(struct node *head);//5
struct node *insertlocbeforeDLL(struct node *head);//13
struct node *insert_midDLL(struct node *head);//9
struct node *delete_locDLL(struct node *head);//10
struct node *delete_begDLL(struct node *head);//11
struct node *delete_endDLL(struct node *head);//12
struct node *delete_keyDLL(struct node *head);//14
struct node *delete_midDLL(struct node *head);//15

int main()
{
    int n;
    printf("Enter the number of element to be printed-\n");
    scanf("%d",&n);
    head=create_dll(n);
    display_dll(head);
    printf("\t\t\t\t Enter 1. for Searching the elements\n");
    printf("\t\t\t\t Enter 2. for inserting the element at head positions\n");
    printf("\t\t\t\t Enter 3. for inserting the element at end positions\n");
    printf("\t\t\t\t Enter 4. for inserting the element after key given key positions\n");
    printf("\t\t\t\t Enter 5. for inserting the element before key given key key positions\n");
    printf("\t\t\t\t Enter 6. for inserting the element after key given key node positions\n");
    printf("\t\t\t\t Enter 7. for inserting the element before given key node positions\n");
    printf("\t\t\t\t Enter 8. for inserting the element at mid position positions\n");
    printf("\t\t\t\t Enter 9. for deleting the elements at head position\n");
    printf("\t\t\t\t Enter 10. for deleting the elements at end position\n");
    printf("\t\t\t\t Enter 11. for deleting the elements at given node position\n");
    printf("\t\t\t\t Enter 12. for deleting the elements at given key position\n");
    printf("\t\t\t\t Enter 13. for deleting the elements at mid position\n");
    int choice;
    printf("enter the case no.for the function which you want to execute\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        search_dll(head);
        break;
    case 2:
        head=insertfirstDLL(head);
        printf("New DLL after the insertion of elements at first node\n");
        display_dll(head);
        break;
    case 3:
        head=insertendDLL(head);
        printf("New DLL after the insertion of elements at last position\n");
        display_dll(head);
        break;
    case 4:
        head=insert_keyafterDLL(head);
        printf("New DLL after the insertion of new elements after a given key \n");
        display_dll(head);
        break;
    case 5:
        head=insert_keybeforeDLL(head);
        printf("New DLL before the insertion of new elements before given key\n");
        display_dll(head);
        break;
    case 6:
        head=insertlocafterDLL(head);
        display_dll(head);
        break;
    case 7:
        head=insertlocbeforeDLL(head);
        display_dll(head);
        break;
    // case 8:
    //     head=insert_midDLL(head);
    //     display_dll(head);
    //     break;
    case 9:
        head=delete_begDLL(head);
        display_dll(head);
        break;
    case 10:
        head=delete_endDLL(head);
        display_dll(head);
        break;
    case 11:
        head=delete_locDLL(head);
        display_dll(head);
        break;
    case 12:
        head=delete_keyDLL(head);
        display_dll(head);
        break;
    case 13:
        head=delete_midDLL(head);
        display_dll(head);
        break;
    default:
        break;
    }
    

}
struct node * create_dll(int n)
{
    struct node *ptr;
    struct node *newnode;
    for (int i = 1; i <=n; i++)
    {
        if (i==1)
        {
            head=(struct node *)malloc(sizeof(struct node));
            head->Lnext=NULL;
            ptr=head;
        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node ));
            newnode->Lnext=ptr;
            ptr->Rnext=newnode;
            ptr=newnode;
            
        }
        printf("%d element - ",i);
        scanf("%d",&ptr->data);
        
    }
    ptr->Rnext=NULL;
    return head;
}
void display_dll(struct node *head)
{
    struct node *ptr;
    int i=1;
    for ( ptr =head; ptr!=NULL; ptr=ptr->Rnext)
    {
        printf("%d node - %d",i,ptr->data);
        printf("\n");
        i++;
    }
    
}
void search_dll(struct node *head)
{
    struct node *ptr;
    int search,count=0;
    printf("enter the elemnet which you want to traverse\n");
    scanf("%d",&search);
    ptr=head;
    while (ptr!=NULL)
    {
        if (ptr->data==search)
        {
            printf("Element is present\n");
            count=1;
        }
        ptr=ptr->Rnext;
    }
    if (count==0)
    {
        printf("Element is absent\n");
    }

}
struct node *insertfirstDLL(struct node *head)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data of new elements-\n");
    scanf("%d",&newnode->data);
    head->Lnext=newnode;
    newnode->Rnext=head;
    newnode->Lnext=NULL;
    head=newnode;
    return head;
}
struct node *insertendDLL(struct node *head)
{
    struct node *newnode;
    struct node *ptr;
    ptr=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    while (ptr->Rnext!=NULL)
    {
        ptr=ptr->Rnext;
    }
    printf("enter the elements of new data\n");
    scanf("%d",&newnode->data);
    ptr->Rnext=newnode;
    newnode->Lnext=ptr;
    newnode->Rnext=NULL;
    return head;
    
}
struct node *insert_keyafterDLL(struct node *head)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    struct node * ptr,*after;
    ptr=head;
    int key;
    printf("Enter the key after which you want to insert the data\n");
    scanf("%d",&key);
    while (ptr->data!=key)
    {
        ptr=ptr->Rnext;
        after=ptr->Rnext;   
    }
    printf("Enter the elements of new data \n");
    scanf("%d",&newnode->data);
    ptr->Rnext=newnode;
    newnode->Lnext=ptr;
    newnode->Rnext=after;
    after->Lnext=newnode;
    return head;    
}
struct node *insert_keybeforeDLL(struct node * head)
{
    struct node *ptr;
    struct node *before;
    int key;
    printf("enter the key before  which you want to insert the data\n");
    scanf("%d",&key);
    ptr=head;
    
    if (ptr->data==key)
    {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data of new elements-\n");
        scanf("%d",&newnode->data);
        head->Lnext=newnode;
        newnode->Rnext=head;
        newnode->Lnext=NULL;
         head=newnode;
        
    }
           
     else
     {
        while (ptr->data!=key)
    {
        
        ptr=ptr->Rnext;
        before=ptr->Lnext;   
        
    }
    struct node *newnode;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter the data of new elements-\n");
            scanf("%d",&newnode->data);
            ptr->Lnext=newnode;
            newnode->Rnext=ptr;
            newnode->Lnext=before;
            before->Rnext=newnode;
     }
    return head;
}
struct node *insertlocafterDLL(struct node *head)
{
    struct node *ptr;
    struct node *after;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    int loc,count=1;
    printf("Enter the node after which you want to insert the data-\n");
    scanf("%d",&loc);
    ptr=head;
    while (count!=loc)
    {
        
        ptr=ptr->Rnext;
        after=ptr->Rnext;
        count=count+1;
    }
    
    printf("Enter the elements of new data \n");
    scanf("%d",&newnode->data);
    ptr->Rnext=newnode;
    newnode->Lnext=ptr;
    newnode->Rnext=after;
    after->Lnext=newnode;
    return head;   
}
struct node *insertlocbeforeDLL(struct node *head)
{
    struct node *ptr;
    struct node *before;
    printf("Enter the node before you wnat to insert the data\n");
    int n,loc=1;
    scanf("%d",&n);
    ptr=head;
    
    if (n==1)
    {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data of new elements-\n");
        scanf("%d",&newnode->data);
        head->Lnext=newnode;
        newnode->Rnext=head;
        newnode->Lnext=NULL;
         head=newnode;
        
    }
           
     else
     {
        while (n!=loc)
    {
        
        ptr=ptr->Rnext;
        before=ptr->Lnext;   
        loc++;
    }
    struct node *newnode;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter the data of new elements-\n");
            scanf("%d",&newnode->data);
            ptr->Lnext=newnode;
            newnode->Rnext=ptr;
            newnode->Lnext=before;
            before->Rnext=newnode;
     }
    return head;
}
struct node *delete_begDLL(struct node *head)
{
    struct node *ptr;
    ptr=head;
    head=head->Rnext;
    head->Lnext=NULL;
    free (ptr);
    return head;
}

struct node *delete_endDLL(struct node *head)
{
    struct node *ptr;
    struct node *temp;
    ptr=head;
    while (ptr->Rnext!=NULL)
    {
        temp=ptr;
        ptr=ptr->Rnext;
    }
    temp->Rnext=NULL;
    free(ptr);
    return head;
}
struct node *delete_locDLL(struct node *head)
{
    struct node *ptr;
    struct node *after;
    struct node *before;

    printf("enter the given node which you want to delete\n");
    int n,loc=1;
    scanf("%d",&n);
    ptr=head;
    while (loc!=n)
    {
        before=ptr;
        ptr=ptr->Rnext;
        after=ptr->Rnext;
        loc++;
    }
    before->Rnext=after;
    after->Lnext=before;
    free(ptr);
    return head;
}
struct node *delete_keyDLL(struct node *head)
{
    struct node *ptr;
    struct node *before;
    struct node *after;
    ptr=head;
    printf("enter the element which you want to delete\n");
    int key;
    scanf("%d",&key);
    ptr=head;
    while (ptr->data!=key)
    {  
        before=ptr;
        ptr=ptr->Rnext;
        after=ptr->Rnext;
    }
    before->Rnext=after;
    after->Lnext=before;
    free(ptr);
    return head;
}
struct node *delete_midDLL(struct node *head)
{
    struct node *ptr;
    struct node *after;
    struct node *before;
    int count=1;
    int loc=1;
    //ptr=head;
    for ( ptr = head; ptr->Rnext!=NULL; ptr=ptr->Rnext)
    {
        count++;
    }
    
    printf("%d",count);
    ptr=head;
    while (loc>=(count/2))
    {
        before=ptr;
        ptr=ptr->Rnext;
        after=ptr->Rnext;
        loc++;
    }
    before->Rnext=after;
    after->Lnext=before;
    free(ptr);
    return head;
}