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
    else if(root->right!=NULL)
    {
        root->left=add_node(root->left,n);
    }
    else if(root->left!= NULL)
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

void postorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
    
}
void Inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    
    Inorder(root->left);
    printf("%d\t",root->data);
    Inorder(root->right);
    
    
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
