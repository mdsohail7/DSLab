#include<stdio.h>
int binary_search(int a[],int num,int n)
{
  int mid, low=0, high=n-1;
  while (low<=high) {
    mid=(low+high)/2;
    if(a[mid]==num)
        return mid;
    else{
        if(num>a[mid])
            low=mid+1;
        else
            high=mid-1;
    }
  }
  return -1;
}

int main() {
  int num,n,searched,i;
  printf("Enter the size of array \n");
  scanf("%d",&n );
  int a[n];
  if(n>100 || n<0)
  {
     printf("Invalid Size \n");
     return 0;
  }
  else{
    printf("Enter the elements of array in a sorted way\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&i );
    }
  /*  for (i=0;i<n;i++) {
      for(j=i,j<n;j++)
      {
        if(a[i]>a[j])
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
    } */
    printf("Enter the number to be searched \n");
    scanf("%d",&num);
    searched =  binary_search(a,num,n);
    printf("The element is found at the index %d",searched);
  }

  return 0;
}
