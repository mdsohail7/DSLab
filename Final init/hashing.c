#include<stdio.h>
#include<math.h>
#define MAX 10

int hash(int k)
{
    return k%MAX;
}

int linear_probe(int l)
{
    return ++l%MAX;
}

int quadratic_probe(int h, int i)
{
    return (int)(h+pow(i,2))%MAX;
}

int double_hash(int h,int i)
{
    return (h+i*linear_probe(h))%MAX;
}

void display(int a[])
{
    int i;
    printf("\n The Element Of Array are:\n");
    for(i=0;i<MAX;i++)
        printf("%d\t",a[i]);
    printf("\n\n");
}

int main()
{
    int a[MAX],i,ch,h,e,count;
    for(i=0;i<MAX;i++)
        a[i]=-1;

    do{
        count=0;
        printf("Enter The Number To Be Stored:");
        scanf("%d",&e);
        h=hash(e);
        if(a[h]==-1)
        {
            a[h]=e;
            display(a);
        }
        else
        {
            while(count<MAX)
            {
                count++;
                printf("\nCollision Occurred At %d ",h);
                printf("Please Enter Your Choice For Resolution:");
                printf("\n 1.Linear probing\n 2.Quadratic probing\n 3.Double Hashing\n");
                printf("Enter Your Choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                        h=linear_probe(h);
                        break;
                    case 2:
                        h=quadratic_probe(h,count);
                        break;
                    case 3:
                        h=double_hash(h,count);
                        break;
                    default:
                        printf("]n INVALID CHOICHE");
                        count--;
                        break;
                }
                if (a[h]==-1)
                {
                    a[h]=e;
                    display(a);
                    break;
                }
            }
            if(count==MAX)
            {
                printf("\n Array is Full or Collision Resolution not Successful");
                return 0;
            }
        }

    }while(1);
return 0;
}
