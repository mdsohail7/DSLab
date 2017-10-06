#include<stdio.h>
int split(int arr[],int lower, int upper)
{
  int pivot=lower, a=lower+1, b=upper;
  int temp;
  while (b>=a) {
    while(arr[a]<arr[pivot])
      a++;
    while (arr[b]>arr[pivot])
      b--;
    if(b>a)
    {
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
   }
    temp = arr[b];
    arr[b] =arr[pivot];
    arr[pivot] = temp;
    return b;
}


void quick_sort(int a[], int lower, int upper)
{
  int i;
  if(lower<upper){
    i=split(a,lower,upper);
    quick_sort(a,lower,i-1);
    quick_sort(a,i+1,upper);
  }
}

int main() {
  int n,i;
  printf("Enter the size of array \n");
  scanf("%d",&n );
  int a[n];
  if(n>100 || n<0)
  {
     printf("Invalid Size \n");
     return 0;
  }
  else{
    printf("Enter the elements of array \n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i ]);
    }
    quick_sort(a,0,n-1);
    printf("Sorted elements are :");
    for(i=0;i<n;i++)
    {
      printf("%d ",a[i]);
    }

 return 0;
}
}
