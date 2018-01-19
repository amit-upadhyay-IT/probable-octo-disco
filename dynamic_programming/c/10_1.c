#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, lis;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->lis = 0;
    temp->left = temp->right = NULL;
    return temp;
}

int max(int a, int b)
{
    return a > b ? a: b;
}

int LargestIndependentSet(struct node *root)
{
    if(!root)
        return 0;

    if(root->lis)
        return root->lis;

    if(!root->left && !root->right)
        return (root->lis = 1);

    int lisExclCurr = LargestIndependentSet(root->left) + LargestIndependentSet(root->right);
    int lisInclCurr = 1;

    if(root->left)
        lisInclCurr += LargestIndependentSet(root->left->left) + LargestIndependentSet(root->left);

    if(root->left)
        lisInclCurr += LargestIndependentSet(root->left->left) + LargestIndependentSet(root->left->right);

    if(root->right)
        lisInclCurr += LargestIndependentSet(root->right->left) + LargestIndependentSet(root->right->right);

    root->lis = max(lisInclCurr, lisExclCurr);
    return root->lis;
}

int main()
{
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    printf("The size of largest independent set is = %d", LargestIndependentSet(root));
    return 0;
}
