#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}node;
node * add_node(node *root,int n)
{
    if(root==NULL)
    {
        
        root=(node *)malloc(sizeof(node));
       root->data=n;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(n < root->data)
    {
        root->left=add_node(root->left,n);
    }
    else if(n>root->data)
    {
        root->right=add_node(root->right,n);
    }
    return root;
}
void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
int getRightmin(node *root)
{
    node* tmp=root;
    while (tmp->left!=NULL)
    {
        tmp=tmp->left;
    }
    return tmp->data;
}  
node *delete_node(node *root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data>val)
    {
        root->left=delete_node(root->left,val);
    }
    else if(root->data<val)
    {
        root->right=delete_node(root->right,val);
    }
    else{
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->right==NULL)
        {
            node *tmp=root->left;
            free(root);
            return tmp;
        }
        else if(root->left==NULL)
        {
            node *tmp=root->right;
            free(root);
            return tmp;
        }
        else 
        {
            int rightmin=getRightmin(root);
            root->data=rightmin;
            root->right=delete_node(root->right,rightmin);
        }
    }
    return(root);
    
} 
int main()
{
    node *root=NULL;
    printf("Enter values to be stored into the tree; Enter -1 to stop\n");
    int d;
    scanf("%d",&d);
    while(d!=-1)
    {
        root=add_node(root,d);
        scanf("%d",&d);
    }
    preorder(root);
    printf("Enter the value you want to delete\n");
    int val;
    scanf("%d",&val);
    root=delete_node(root,val);
    preorder(root);
    return 0;
}
