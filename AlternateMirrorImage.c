#include<stdio.h>
#include<math.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int max(int h1,int h2)
{
    if(h1>h2)
        return h1;
    else
        return h2;
}
struct node* height(struct node* root)
{
    if(root == NULL)
        return 0;
    else if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return (1+ max(height(root->left),height(root->right)));
}

struct node* alternateMirror(struct node* root,int i)
{
        if(root == NULL)
            return 0;
        if(i==1)
        {
            printf("%d ",root->data);
            return 0;
        }
        else
        {
            alternateMirror(root->right,i-1);
            alternateMirror(root->left,i-1);
        }
}


int main()
{
    int i;
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    struct node* h = height(root);
    for(i=1; i<=h; i=i+2)
    {
            alternateMirror(root,i);
    }
    return 0;
}
