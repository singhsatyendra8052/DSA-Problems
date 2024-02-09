#include <stdio.h>
#include <stdlib.h>
 
void merge(int arr[], int s,int m, int e)
{
    int i, j, k;
    int n1 = m - s + 1;
    int n2 = e - m;
 
    
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[s + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = s;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[],
               int s, int e)
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
 
        
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
 
        merge(arr, s, m, e);
    }
}
 
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
    printf("Enter the size of the array :\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
 
    printf("Given array is \n");
    printArray(arr, n);
 
    mergeSort(arr, 0, n - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}