#include "stdio.h"
#include "stdlib.h"
int main()
{
    int s;
    printf("Enter the size of array\n");
    scanf("%d",&s);
    int i,j,key,flag;
    int *arr=(int *)malloc(sizeof(int)*s);
    printf("Enter array elements\n");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<s;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for(i=1;i<s;i++)
    {
        key=arr[i];
        flag=0;
        for(j=i-1;j>=0;j--)
        {
            if(key<arr[j])
            {
                arr[j+1]=arr[j];
                flag=1;
            }
            else{
                break;
            }
        }
        if(flag==1)
        arr[j+1]=key;
    }
    printf("Sorted array\n");
     for(i=0;i<s;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;

}
