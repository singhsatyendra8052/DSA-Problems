#include<stdio.h>
void bubblesort(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j <n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}
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
    bubblesort(arr,n);
    printf("the sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    
}