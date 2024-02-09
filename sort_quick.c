#include<stdio.h>
int partition(int arr[],int start,int end)
{
    int pivot=arr[end];
    int i=start;
    for (int j = start; j <end; j++)
    {
        if (arr[j]<pivot)   
        {
            
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
        
    }
    int temp=arr[i];
    arr[i]=arr[end];
    arr[end]=temp;
    return i;
}
void quicksort(int arr[],int start,int end)
{
    if(start<end)
    {
        int loc=partition(arr,start,end);
        quicksort(arr,start,loc-1);
        quicksort(arr,loc+1,end);
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
    //int i=0;
    quicksort(arr,0,n-1);
    printf("the sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
}