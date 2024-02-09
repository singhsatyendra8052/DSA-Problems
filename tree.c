#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *left;
    int data;
    struct node *right;
    
};
struct node *root=NULL;
struct node *newnode(int item)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
 void insert_bst(struct node *root,int item)
 {
    struct node *current,*parent;
    if (root==NULL)
    {
        root=newnode(item);
    }
    else
    {
        current=root;
        parent=NULL;
        while(1)
        {
            parent=current;
            if(item<parent->data)
            {
                current=current->left;
                if (current==NULL)
                {
                    parent->left=newnode(item);
                    return;
                }
                
            }
            else
            {
                current=current->right;
                if (current==NULL)
                {
                    parent->right=newnode(item);
                    return;
                }
                
            }
            
        }
    }    
 }
 void displaybst(struct node *root)
 {
    printf("BST elemnts are : \n");
    if (root!=NULL)
    {
        displaybst(root->left);
        printf("%d\n",root->data);
        displaybst(root->right);
    }
    
 }



int main()
{
    int n;
    printf("enter the no. of element to be inserted - \n");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&arr[i]);
        //insert_bst(root,arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        insert_bst(root,arr[i]);
    }
    
    displaybst(root);
    
}