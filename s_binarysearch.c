#include<stdio.h>
int front;
int rear;
void binarysearch(int *arr,int n)
{
    front =0;
    rear=n;
    int data;
    printf("enter the data to be searched\n");
    scanf("%d",&data);
    int mid;
    int flag=0;
    while (front<rear)
    {
        mid =(front+rear)/2;
        if (arr[mid]==data)
        {
            printf("the %d is present in the array at %d\n",data,mid);
            //flag=1;
            break;
        }
         else if (arr[mid]>data)
        {
            rear=mid-1;
        }
        else
        {
            front=mid+1;
        }
    }
    // if(flag==1)
    // {
    //     printf("element is present\n");

    // }
    // else{
    //     printf("element is not present\n");
    // }
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

    binarysearch(arr,n);
}