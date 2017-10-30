#include<stdio.h>

int binary_search(int a[],int num,int n)
{
    int mid,low=0,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if (a[mid]==num)
            return a[mid];
        else
        {
            if(num>a[mid])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}


int main ()
{
    int i,a,c,number;
    printf("Enter The No Of Element:\t ");
    scanf("%d",&a);

    if(a<0 || a>100)
    {
        printf("Enter The No Between 0 to 100");
        return 0 ;
    }
        int b[a];
    for(i=0;i<a;i++)
    {
        printf("Enter The No In Ascending Order:\t");
        scanf("%d",&b[i]);
    }
    printf("Enter The No To Be Searched:\t");
    scanf("%d",&number);
    c=binary_search(b,number,a);
    if(c==-1)
        printf("The Number %d Does Not Exist",number);
    else
        printf("The Number To Be Searched Is %d\n",c);
    return 0;
}
