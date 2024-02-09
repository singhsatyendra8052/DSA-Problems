#include<stdio.h>
void insertionsort(int arr[],int n)
{
    int j;
    for (int i = 1; i <=n-1; i++)
    {
        j=i;
        while (j>0&&arr[j-1]>arr[j])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
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
    insertionsort(arr,n);
    printf("the sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}