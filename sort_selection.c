#include<stdio.h>
#include<stdlib.h>
void selectionsort(int a[],int n){
    int temp;
    for (int i = 0; i <n-1; i++)
    {
        int minindex=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[minindex])
            {
                minindex=j;
            }
            
        }
        if (minindex!=i)
        {
             temp=a[i];
             a[i]=a[minindex];
             a[minindex]=temp;
        }
    }
    printf("the sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
}
int main()
{
    int n;
    printf ("enter the size of the array\n");
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
}