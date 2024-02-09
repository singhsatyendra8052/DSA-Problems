#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *create_csll(int);
void display_csll(struct node *head);
void search_csll(struct node *head);                  // 1
struct node *insertfirstCsll(struct node *head);      // 2
struct node *insertendCsll(struct node *head);        // 3
struct node *insert_keyaftercsLL(struct node *head);  // 4
struct node *insert_keybeforecsLL(struct node *head); // 5
struct node *insertlocaftercsLL(struct node *head);   // 6
struct node *insertlocbeforecsLL(struct node *head);  // 7
struct node *delete_loccsLL(struct node *head);       // 8
struct node *delete_begcsLL(struct node *head);       // 9
struct node *delete_endcsLL(struct node *head);       // 10
struct node *delete_keycsLL(struct node *head);       // 11
int main()
{
    int n;
    printf("Enter the number of element to be printed-\n");
    scanf("%d", &n);
    head = create_csll(n);
    display_csll(head);
    printf("\t\t\t\t Enter 1. for Searching the elements\n");
    printf("\t\t\t\t Enter 2. for inserting the element at head positions\n");
    printf("\t\t\t\t Enter 3. for inserting the element at end positions\n");
    printf("\t\t\t\t Enter 4. for inserting the element after key given key positions\n");
    printf("\t\t\t\t Enter 5. for inserting the element before key given key key positions\n");
    printf("\t\t\t\t Enter 6. for inserting the element after key given key node positions\n");
    printf("\t\t\t\t Enter 7. for inserting the element before given key node positions\n");
    printf("\t\t\t\t Enter 8. for deleting the elements at head position\n");
    printf("\t\t\t\t Enter 9. for deleting the elements at end position\n");
    printf("\t\t\t\t Enter 10. for deleting the elements at given node position\n");
    printf("\t\t\t\t Enter 11. for deleting the elements at given key position\n");
    printf("\t\t\t\t Enter 12. TO END the PROGRAM\n");
    int t=0;
    do{
    int choice;
    printf("enter the case no.for the function which you want to execute\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        search_csll(head);
        break;
    case 2:
        head=insertfirstCsll(head);
        printf("New DLL after the insertion of elements at first node\n");
        display_csll(head);
        break;
    case 3:
        head=insertendCsll(head);
        printf("New DLL after the insertion of elements at last position\n");
        display_csll(head);
        break;
    case 4:
        head=insert_keyaftercsLL(head);
        printf("New DLL after the insertion of new elements after a given key \n");
        display_csll(head);
        break;
    case 5:
        head=insert_keybeforecsLL(head);
        printf("New DLL before the insertion of new elements before given key\n");
        display_csll(head);
        break;
    case 6:
        head=insertlocaftercsLL(head);
        display_csll(head);
        break;
    // case 7:
    //     head=insertlocbeforecsLL(head);
    //     display_csll(head);
    //     break;
    // case 8:
    //     head=delete_begcsLL(head);
    //     display_csll(head);
    //     break;
    // case 9:
    //     head=delete_endcsLL(head);
    //     display_csll(head);
    //     break;
    // case 10:
    //     head=delete_loccsLL(head);
    //     display_csll(head);
    //     break;
    // case 11:
    //     head=delete_keycsLL(head);
    //     display_csll(head);
    //     break;
    case 12:
        
        t=1;
        exit;
        break;
    default:
        break;
    }
    }while(t!=1);
}
// #include<stdio.h>

struct node *create_csll(int n)
{
    struct node *ptr;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr->next;
        }
        printf("the %d element of the list = ", i);
        scanf("%d", &ptr->data);
    }
    ptr->next = head;
    printf("\n");
    return head;
}
void display_csll(struct node *head)
{
    struct node *ptr;
    int i = 1;
    ptr = head;
    printf(" %d node - %d\n", i, ptr->data);
    i = i + 1;
    for (ptr = ptr->next; ptr != head; ptr = ptr->next)
    {
        printf(" %d node - %d\n", i, ptr->data);
        i++;
    }
}
void search_csll(struct node *head)
{
    struct node *ptr;
    ptr = head;
    int a;
    int flag = 0;
    printf("enter the data to be searched-\n");
    scanf("%d", &a);
    if (ptr->data == a)
    {
        printf("%d is present in the csll.\n", a);
    }
    else
    {
        ptr = ptr->next;
        while (ptr!=head)
        {
            if (ptr->data == a)
            {
                flag = 1;
            }
            ptr = ptr->next;
        }
        if (flag)
        {
            printf("%d is present in csll.\n", a);
        }
        else
        {
            printf("%d is not present in csll.\n", a);
        }
    }
}
struct node *insertfirstCsll(struct node *head)
{
    struct node *newnode;
    struct node *ptr;
    newnode=(struct node *)malloc(sizeof(struct node ));
    printf("enter the data of the newnode -\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    head=newnode;
    return head;
}
struct node *insertendCsll(struct node *head)
{
    struct node *ptr;
    ptr=head;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the elements to be inserted at the end-\n");
    scanf("%d",&newnode->data);
    while (ptr->next!=head) 
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=head;
    return head;
}
struct node *insert_keyaftercsLL(struct node *head)
{
    int a;
    printf("Enter the key after which you want to insert the data\n");
    scanf("%d",&a);
    struct node *ptr;
    ptr=head;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data of the new elements-\n");
    scanf("%d",&newnode->data);
    while (ptr->data!=a&&ptr->next!=head)
    {
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    return head;
}
struct node *insert_keybeforecsLL(struct node *head)
{
     int a;
    printf("Enter the key before which you want to insert the data\n");
    scanf("%d",&a);
    struct node *ptr;
    struct node *pttr;
    ptr=head;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data of the new elements-\n");
    scanf("%d",&newnode->data);
    while (ptr->data!=a&&ptr->next!=head)
    {
        pttr=ptr;
        ptr=ptr->next;
    }
    newnode->next=pttr;
    pttr->next=newnode;
    return head;
}
struct node *insertlocaftercsLL(struct node * head)
{
    printf("INSERTING ELEMENT AFTER A LOCATION\n");
    int loc, count = 1;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);

    printf("Enter after which location it should be inserted: ");
    scanf("%d", &loc);

    while (ptr->next != head && count != loc)
    {
        ptr = ptr->next;
        count += 1;
    }

    if (loc > count)
    {
        printf("\nInvalid location entered by the user\n\n");
        return head;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
}
struct node *insertlocbeforecsLL(struct node *head)
{
    printf("INSERTING ELEMENT BEFORE A LOCATION\n");
    int loc, count = 1;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    ptr = head;

    printf("Enter before which location it should be inserted: ");
    scanf("%d", &loc);
    if (loc == 1)
    {
        newnode->next = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        head = newnode;
        return head;
    }
    else
    {
        while (ptr->next != head && count != (loc - 1))
        {
            ptr = ptr->next;
            count += 1;
        }
        if (count != (loc - 1))
        {
            printf("Location not found\n");
            return head;
        }

        newnode->next = ptr->next;
        ptr->next = newnode;
        return head;
    }
}
