#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *Lnext;
    struct node *Rnext;
};
struct node *head;
struct node *create_cdll(int);
void display_cdll(struct node *head);
void search_cdll(struct node *head);                  // 1
struct node *insertfirstCdll(struct node *head);      // 2
struct node *insertendCdll(struct node *head);        // 3
struct node *insert_keyaftercdLL(struct node *head);  // 4
struct node *insert_keybeforecdLL(struct node *head); // 5
struct node *insertlocaftercdLL(struct node *head);   // 6
struct node *insertlocbeforecdLL(struct node *head);  // 7
struct node *delete_loccdLL(struct node *head);       // 8
struct node *delete_begcdLL(struct node *head);       // 9
struct node *delete_endcdLL(struct node *head);       // 10
struct node *delete_keycdLL(struct node *head);       // 11
int main()
{
    int n;
    printf("Enter the number of element to be printed-\n");
    scanf("%d", &n);
    head = create_cdll(n);
    display_cdll(head);
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
        search_cdll(head);
        break;
    case 2:
        head=insertfirstCdll(head);
        printf("New DLL after the insertion of elements at first node\n");
        display_cdll(head);
        break;
    case 3:
        head=insertendCdll(head);
        printf("New DLL after the insertion of elements at last position\n");
        display_cdll(head);
        break;
    // case 4:
    //     head=insert_keyaftercdLL(head);
    //     printf("New DLL after the insertion of new elements after a given key \n");
    //     display_cdll(head);
    //     break;
    // case 5:
    //     head=insert_keybeforecdLL(head);
    //     printf("New DLL before the insertion of new elements before given key\n");
    //     display_cdll(head);
    //     break;
    // case 6:
    //     head=insertlocaftercdLL(head);
    //     display_cdll(head);
    //     break;
    // case 7:
    //     head=insertlocbeforecdLL(head);
    //     display_cdll(head);
    //     break;
    // case 8:
    //     head=delete_begcdLL(head);
    //     display_cdll(head);
    //     break;
    // case 9:
    //     head=delete_endcdLL(head);
    //     display_cdll(head);
    //     break;
    // case 10:
    //     head=delete_loccdLL(head);
    //     display_cdll(head);
    //     break;
    // case 11:
    //     head=delete_keycdLL(head);
    //     display_cdll(head);
    //     break;
    case 12:
        t=1;
        break;
    default:
        break;
    }
    }while(t!=1);
}
struct node *create_cdll(int n)
{
    struct node *newnode, *ptr;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->Lnext = NULL;
            ptr = head;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            ptr->Rnext = newnode;
            newnode->Lnext = ptr;
            ptr = newnode;
        }
        printf("Enter Node_%d - ", i);
        scanf("%d", &ptr->data);
    }
    ptr->Rnext = head;
    head->Lnext = ptr;
    return head;
}
void display_cdll(struct node *head)
{
    printf("CDLL elements are:  ");
    struct node *ptr;
    ptr = head;

    printf("%d ", ptr->data);
    ptr = ptr->Rnext;

    while (ptr != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Rnext;
    }
    printf("\n");
}
void search_cdll(struct node *head)
{
    printf("SEARCHING CLL\n");
    struct node *ptr;
    int value, flag = 0;
    printf("Enter an Element to search - ");
    scanf("%d", &value);
    ptr = head;
    while (ptr->Rnext != head)
    {
        if (ptr->data == value)
        {
            flag = 1;
            break;
        }
        ptr = ptr->Rnext;
    }
    if (ptr->data == value)
        flag = 1;
    if (flag == 1)
        printf("Result - %d Found in the CLL.\n\n", value);
    else
        printf("Result - %d not found in the CLL.\n\n", value);
}
struct node *insertfirstCdll(struct node *head)
{
   struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &newnode->data);
    ptr = head;
    while (ptr->Rnext != head)
    {
        ptr = ptr->Rnext;
    }
    newnode->Lnext = ptr;
    ptr->Rnext = newnode;
    newnode->Rnext = head;
    head->Lnext = newnode;
    head = newnode;
    return (head); 
}
struct node *insertendCdll( struct node *head)
{
    struct node * ptr;
    ptr=head;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element of the new data-\n");
    scanf("%d",&newnode->data);
    while (ptr->Rnext!=head)
    {
        ptr=ptr->Rnext;
    }
    ptr->Rnext=newnode;
    newnode->Lnext=ptr;
    newnode->Rnext=head;
    head->Lnext=newnode;
    return head;
}
struct node *insert_keyaftercdLL(struct node *head)
{
    struct node *ptr;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter tha data of the new element-\n");
    scanf("%d",&newnode->data);
    printf("enter the key after which you want to insert the element-");
}