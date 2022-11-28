#include <stdio.h>
#include <stdlib.h>
int main()
{
    int key,i,j,size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int *arr;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    for(int gap=size/2;gap>0;gap=gap/2)
    {
    for(i=gap;i<size;i++)
    {
        key=arr[i];
        for(j=i-gap;j>=0;j-=gap)
        {
            if(arr[j]>key)
            {
                arr[j+gap]=arr[j];

            }
            else{
                break;
            }
        }
        arr[j+gap]=key;
    }
    }

printf("Sorted array\n");
 for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
