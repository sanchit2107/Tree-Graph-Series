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
    for(i=1;i<=h;i++)
    {
    levelOrder(root,i);
    printf("\n");
    }
    return 0;
}
