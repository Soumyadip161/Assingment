#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int data;
    struct stack *next;
}stack;
stack *top=NULL;
int max;
int size=0;
void push(int n)
{
    stack *new_node=(stack *)malloc(sizeof(stack));
    if(size<max){
    new_node->data=n;
    if(top == NULL)
    {
       top=new_node;
       new_node->next=NULL;
    }
    else{
        new_node->next=top;
        top=new_node;
    }
    size++;
    }
    else{
        printf("Stack Overflow\n");
    }
}
int pop()
{
    stack *hr;
    int d;
    if (size>0)
    {
         hr=top;
    d=top->data;
    top=top->next;
    free(hr);
    size--;
    if(size==0){
        top==NULL;
    }
    

    }
    else 
    {
        
        printf("Stack UnderFlow\n");
        return -18999905;
    }
    return d;
}


void peek()
{
  if (size>0)
    {
    int d=top->data;
    printf("Current element at top:%d\n",d);

    }
    else 
    {
        printf("No element in stack\n");
    }
        
}
   
