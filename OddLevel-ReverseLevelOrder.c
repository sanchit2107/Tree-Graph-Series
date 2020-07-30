#include<stdio.h>
#include<math.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
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

struct node* levelOrder(struct node* root, int i)
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
            levelOrder(root->right,i-1);
            levelOrder(root->left,i-1);
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
    for(i=1; i<=h; i++)
    {
        if(i%2)
        {
            levelOrder(root,i);
        }
    }
    return 0;
}
