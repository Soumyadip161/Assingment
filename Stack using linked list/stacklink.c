#include "stacklink.h"
#include <stdio.h>
int main()
{
    int ch,n,v;
    printf("Enter the maximum capacity of the stack\n");
    scanf("%d",&max);
     while (1)
    {
    printf("Press 1------>to push\n");
    printf("Press 2------>to pop\n");
    printf("Press 3------>to peek\n");
    printf("Press -1------>to exit menu\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to push\n");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: 
             v=pop();
             if (v!=-18999)
            {
                printf("Element:%d\n",v);
            }
             break;
            case 3: peek();
                    break;
            case -1: exit(1);
        }
    }
    return 0;
}