#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int data;
    struct node *next;
}node;
int r=-1,f=-1;
int size;
void Enqueue(node **front,node **rear,int val)
{
   
    if(r==-1&&f==-1)
    {
        node *newnode=(node *)malloc(sizeof(node));
        r=0;
        f=0;
        newnode->data=val;
        *front=newnode;
        *rear=newnode;
        (*front)->next=*front;
    }
    else{
        if((r+1)%size!=f)
        {
            node *newnode=(node *)malloc(sizeof(node));
            r=(r+1)%size;
            newnode->data=val;
           (*rear)->next=newnode;
            newnode->next=*front;
            *rear=newnode;
        }
        else{
            printf("Queue overflow\n");
        }
    }
    printf("Front :%d      rear:%d\n",f,r);
}
void Dequeue(node **front,node **rear)
{
 if(f==-1)
 printf("No Element to dequeue\n");
 else if(r==f){
    printf("Element Dequeued is: %d\n",(*front)->data);
    node *tmp=*front;
    *front=(*front)->next;
    (*rear)->next=*front;
    free(tmp);
    f=-1;
    r=-1;
   }
    else{
    printf("Element Dequeued is: %d\n",(*front)->data);
    node *tmp=*front;
    *front=(*front)->next;
    (*rear)->next=*front;
    free(tmp);
    f=(f+1)%size;
    }
    printf("Front :%d      rear:%d",f,r);
}
int main(){
    printf("Enter size of Queue\n");
    scanf("%d",&size);
     int m,ch,d;
   node *front=NULL;
   node *rear=NULL;
    
    while(1)
    {
        printf("Enter 1------> to enqueue\n");
        printf("Enter 2------> to dequeue\n");
        printf(" Enter -1-----> to exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter the element to insert\n");
                scanf("%d",&d);
                Enqueue(&front,&rear,d);
            break;
        case 2: Dequeue(&front,&rear);
                break;
        case -1: exit(1);
        
        default: printf("wrong choice\n");
            break;
        }
    }
    return 0;
}
