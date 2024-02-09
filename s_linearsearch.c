#include<stdio.h>
int main()
{
    int n;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int data;
    printf("enter the data to be searched\n");
    scanf("%d",&data);
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==data)
        {
            flag=1;
        }
        
    }
    if (flag)
    {
        printf("the data is present\n");

    }
    else
    {
        printf("the data is not present\n");
    }
    
    
}