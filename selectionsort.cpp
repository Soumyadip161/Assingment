#include <stdlib.h>
#include <stdio.h>
int * arr;
int size;
void selectionsort()
{
    int min,mini,i,j,temp;
    for(i=0;i< size;i++)
    {
        min=arr[i];
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<min)
            {
                mini=j;
                min=arr[j];
            }
        }
        if(arr[i]>min)
        {
         temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
        }
    }
}
int main()
{
    printf("Enter size of array\n");
    scanf("%d",&size);
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the array elements\n");
     for(int i=0;i<size;i++)
    {
      scanf("%d",&arr[i]);
    }
     for(int i=0;i<size;i++)
    {
      printf("%d\t",arr[i]);
    }
    printf("\n");
    selectionsort();
    for(int i=0;i<size;i++)
    {
      printf("%d\t",arr[i]);
    }

    return 0;
}
