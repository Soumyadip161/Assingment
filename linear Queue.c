#include <stdio.h>
#include <stdlib.h>
int* queue;
int size;
int front= -1;
int rear= -1;
void Enqueue(int n)
{
    if (front==rear && front==-1)
    {
        front+=1;
        rear+=1;
        queue[rear]=n;
    }
    else{
        if(rear<size-1)
        {
            rear+=1;
            queue[rear]=n;
        }
        else{
            printf("The Queue is full\n");
        }
    }
}
int dequeue()
{
    int y;
    if(front>rear || front==-1)
    {
        printf("Queue is empty\n");
        return -9999;
    }
    else{
        if(front==rear)
        {
            y=queue[front];
            front=rear=-1;
        }
        else{
            y=queue[front];
            front+=1;
        }
        return y;
    }
}
int main()
{
    int m;
    printf("Enter the size of the queue\n");
    scanf("%d",&size);
    queue=(int *)malloc(sizeof(int)*size);
    printf("Enter the elements of the queue\n");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&m);
        Enqueue(m);
    }
    printf("Now dequeue is being executed\n");
    for(int i=1;i<=size;i++)
    {
        printf("The element dequed is:%d\n",dequeue());
    }
    return 0;
}
