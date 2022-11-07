#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int d;
     struct node *next;
}node;
void insert(node ** head,int n)
{
    node *new_node=(node *)malloc(sizeof(node));
    new_node->d=n;
    if(*head==NULL)
    {
       *head=new_node;
       new_node->next=NULL;
    }
    else{
        node *tmp = *head;
        while (tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=new_node;
        new_node->next=NULL;
    }
}
int getSize(node* head){
    int size=1;
    node *hr=head;
    while (hr->next!=NULL)
    {
        size++;
        hr=hr->next;
    }
    return size;
}
void selectionsort(node ** head)
{
    int min;
    node *tmp=*head;
    int size= getS1ize(*head);
    for(int i=1;i<=size-1;i++)
    {
        node *temp=tmp->next;
       node *min=temp;
    for(int j=i+1;j<=size;j++)
    {
        if(min->d>temp->d)
        {
            min=temp;
        }
      temp=temp->next;
    }
    if(tmp->d>min->d)
    {
        int t=tmp->d;
        tmp->d=min->d;
        min->d=t;
    }
    tmp=tmp->next;
    }
}
void display( node* href)
{
     node* hr=href;

    while(hr!=NULL)
    {
        
        printf("%d\t",hr->d);
        hr=hr->next;
    }
}
int main()
{
    node *head=NULL;
    int ch,d;
    while(1)
    {
         printf("\npress\n");
        printf("1--------> to enter an element at end\n");
        printf("2----->To perform selection sort\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert at end\n");
                 scanf("%d",&d);
                 insert(&head,d);
                 display(head);
            break;
            case 2:printf("Performing selection sort\n");
                   selectionsort(&head);
                   display(head);
                   break;
            case 3:exit(1);
        
       
        }
    }
}
