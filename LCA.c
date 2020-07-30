#include<stdio.h>

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

struct node* LCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    else if(root->data == n1 || root->data == n2)
        return (root);
    struct node* l = LCA(root->left,n1,n2);
    struct node* r = LCA(root->right,n1,n2);

    if(l && r)
        return root;
    else if(l)
        return l;
    else
        return r;
}
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("LCA of 4 and 5 : %d\n",LCA(root,4,5)->data);
    printf("LCA of 4 and 7 : %d\n",LCA(root,4,7)->data);
    printf("LCA of 6 and 7 : %d\n",LCA(root,6,7)->data);
    printf("LCA of 4 and 2 : %d\n",LCA(root,4,2)->data);
    printf("LCA of 2 and 1 : %d\n",LCA(root,2,1)->data);
    return 0;
}
