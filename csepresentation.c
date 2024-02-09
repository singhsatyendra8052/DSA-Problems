// #include<stdio.h>
// #include<stdlib.h>
// struct node 
// {
//     int regno;
//     char name[100];
//     char branch[100];
//     float cgpa;
//     struct node *next;
// };
// struct node *head;

// struct node *create_sll(int n)
// {
//     struct node *ptr;
//     for (int i = 1; i <=n; i++)
//     {
//         if(i==1)
//         {
//              head=(struct node*)malloc(sizeof(struct node));
//              ptr=head;
//         }
//         else
//         {
//             ptr->next=(struct node*)malloc(sizeof(struct node));
//             ptr=ptr->next;
//         }
//         printf("\nenter the %d the regno. ",i);
//         scanf("%d",&ptr->regno);
//         printf("enter the name-\n");
//         scanf("%s",&ptr->name);
//         printf("enter the cgpa-\n");
//         scanf("%d",&ptr->cgpa);
//         printf("enter the branch-\n");
//         scanf("%s",&ptr->branch);

        
//     }
//     ptr->next=NULL;
//     return(head);
    
// }
// void display_sll(struct node *head)
// {
//     struct node *ptr;
//     int i=1;
//     ptr=head;
//     for ( ptr =head; ptr !=NULL; ptr=ptr->next)
//     {
//         printf(" student registration no,  - %d\n",i,ptr->regno);
//         printf(" %d name of the student is - %s\n",i,ptr->name);
//         printf(" cgpa of the student is - %f\n",i,ptr->cgpa);
//         printf(" name of the branch - %s\n",i,ptr->branch);
//         i++;
//     }
    
// }
// int main()
// {
//     int n;
//     printf("enter the no. of the student\n");
//     scanf("%d",&n);
//     head=create_sll(n);
//     display_sll(head);
// }
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    int regno;
    char name[100];
    char branch[100];
    float cgpa;
    struct node *next;
};

struct node *head;

struct node *create_sll(int n)
{
    struct node *ptr;
    for (int i = 1; i <=n; i++)
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
        printf("\nEnter the %dth regno: ", i);
        scanf("%d", &ptr->regno);
        printf("Enter the name: ");
        scanf("%s", ptr->name);
        printf("Enter the cgpa: ");
        scanf("%f", &ptr->cgpa);
        printf("Enter the branch: ");
        scanf("%s", ptr->branch); 
    }
    ptr->next=NULL;
    return head;  
}

void display_sll(struct node *head)
{
    struct node *ptr;
    int i=1;
    ptr=head;
    for (ptr = head; ptr != NULL; ptr=ptr->next)
    {
        printf("\nStudent %d:\n", i);
        printf("Registration no.: %d\n", ptr->regno);
        printf("Name: %s\n", ptr->name);
        printf("CGPA: %f\n", ptr->cgpa);
        printf("Branch: %s\n", ptr->branch);
        i++;
    }
}
void display_student_by_regno(struct node *head, int regno)
{
    struct node *ptr;
    int found = 0;
    ptr = head;

    while (ptr != NULL) {
        if (ptr->regno == regno) {
            printf("\nStudent Found:\n");
            printf("Registration no.: %d\n", ptr->regno);
            printf("Name: %s\n", ptr->name);
            printf("CGPA: %f\n", ptr->cgpa);
            printf("Branch: %s\n", ptr->branch);

            found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (!found) {
        printf("\nStudent with registration number %d not found.\n", regno);
    }
}
void bubble_sort(struct node *head)
{
    struct node *ptr;
    int swapped;
    
    if (head == NULL || head->next == NULL)
        return;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != NULL) {
            if (ptr->regno > ptr->next->regno) {
                // Swap the nodes
                struct node *temp = ptr->next;
                ptr->next = ptr->next->next;
                temp->next = ptr;

                if (ptr == head)
                    head = temp;
                else {
                    struct node *prev = head;
                    while (prev->next != ptr)
                        prev = prev->next;
                    prev->next = temp;
                }

                ptr = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}


int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    head=create_sll(n);
    //display_sll(head);
    int reg;
    printf("enter the regno. of the student\n");
    scanf("%d",&reg);
    display_student_by_regno(head,reg);

    //bubble_sort(head);
    //printf("\nStudents sorted by registration number:\n");s
    //display_sll(head);
    return 0;
}
