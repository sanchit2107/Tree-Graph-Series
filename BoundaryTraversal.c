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

void printLeftNode(struct node* root)
{
    if(root)
    {
        if(root->left)
        {
            printf("%d",root->data);
            printLeftNode(root->left);
        }
        else if(root->right)
        {
            printf("%d", root->data);
            printLeftNode(root->right);
        }

    }
}

void printRightNode(struct node* root)
{
    if(root)
    {
        if(root->right)
        {
            printRightNode(root->right);
            printf("%d",root->data);

        }
        else if(root->left)
        {
            printRightNode(root->left);
            printf("%d", root->data);
        }

    }
}

void printLeavesNode(struct node* root)
{
    if(root)
    {
        printLeavesNode(root->left);
        if(!(root->left) && !(root->right))
            printf("%d", root->data);
        printLeavesNode(root->right);
    }
}

/*void printBoundary(struct node* root)
{

}*/
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
    printLeftNode(root);
    printLeavesNode(root->left);
    printLeavesNode(root->right);
    printRightNode(root);
    return 0;
}
