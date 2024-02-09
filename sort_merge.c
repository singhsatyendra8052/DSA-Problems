#include<stdio.h>
void merge(int arr[], int mid, int start, int end)
{
    int i, j, k, B[100];
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        B[k] = arr[j];
        k++;
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = B[i];
    }
}

void mergeSort(int arr[], int start, int end){
    int mid; 
    if (start>=end)
    {
        return;
    }
        mid =  (start + end) /2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, mid, start, end);

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

    mergeSort(arr,0,n-1);
    printf("the sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }

}

