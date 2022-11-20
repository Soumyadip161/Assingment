#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;

void insert(struct node** href,int n)
{
    
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data=n;
    new_node->link=NULL;
    if (*href==NULL)
    {
        *href=new_node;
    }
    else{
    node* hr=*href;

    while(hr->link!=NULL)
    {
        hr=hr->link;
        
    }
   
    hr->link=new_node;
}
}
void insert_at_begining(node** href,int n)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=n;
    if(*href==NULL)
    {
        *href=new_node;
        new_node->link=NULL;
    }
    else{
        new_node->link=*href;
        *href=new_node;
    }

}
void delete_begining_element(node** href)
{
    node * hr;
    hr=*href;
    *href=hr->link;
    printf("Element dequeued is %d\n",hr->data);
    free(hr);
}
void delete_at_end(node** href)
{
    node* hr;
    hr=*href;
    while(hr->link->link!=NULL)
    {
        hr=hr->link;
    }
    node *temp=hr->link;
    hr->link=NULL;
    printf("Element dequeued is %d\n",temp->data);
    free(temp);
}

void display( node* href)
{
     node* hr=href;

    while(hr!=NULL)
    {
        
        printf("%d\t",hr->data);
        hr=hr->link;
    }
}
int main()
{
    node* head;
    head=NULL;
    int ch,d,pos;
    while(1)
    {
        printf("\npress\n");
        printf("1--------> to enqueue at end\n");
        printf("2--------> to enqueue at begining\n");
       
        printf("3--------> to dequeue at head\n");
        printf("4--------> to dequeue at end\n");
        printf("5---------> to exit from menu\n");
        scanf("%d",&ch);
        
       switch(ch)
       {
          case 1:printf("Enter the element to insert at end\n");
                 scanf("%d",&d);
                 insert(&head,d);
                 display(head);
                 break;
          case 2:printf("Enter the element to insert\n");
                 scanf("%d",&d);
                 insert_at_begining(&head,d);
                 display(head);
                 break;
          
        case 3:
               if(head==NULL)
               {
                printf("Head is already NULL\n");
               }
               else{
                delete_begining_element(&head);
               }
               display(head);
               break;
        case 4:
               if(head==NULL)
               {
                printf("Head is already NULL\n");
               }
               else{
                delete_at_end(&head);
               }
               display(head);
               break;
          case 5:printf("Thanks for using:)");
                 exit(1);
                 break;
        default:printf("Wrong input enter again");
        }
    }
    return 0;
}
