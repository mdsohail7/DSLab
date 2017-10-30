#include<stdio.h>
#define MAX_SIZE 100

int split(int arr[],int lower, int upper)
{
    int pivot=lower, a=lower+1, b=upper;
    int temp;
    while(b>=a)
    {
        while(arr[a]<arr[pivot])
            a++;
        while(arr[b]>arr[pivot])
            b--;
        if(b>a)
        {
            temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
        }
    }
    temp=arr[pivot];
    arr[pivot]=arr[b];
    arr[b]=temp;

    return b;

}
void quick_sort(int arr[],int lower,int upper)
{
    int i;
    if(lower<upper)
    {
        i=split(arr,lower,upper);
        quick_sort(arr,lower,i-1);
        quick_sort(arr,i+1,upper);
    }

}

int main()
{
    int b[MAX_SIZE],i,a;
    printf("Enter The No Of Element: ");
    scanf("%d",&a);
    if(a<0 || a>100)
    {
        printf("Enter The No Between 0 To 100");
        return 0 ;
    }

    for(i=0;i<a;i++)
    {
        printf("Enter The No :");
        scanf("%d",&b[i]);
    }
    quick_sort(b,0,a-1);
    printf("\nSorted Array Is:\n");
    for(i=0;i<a;i++)
        printf("\t%d\n",b[i]);
    return 0;
}
