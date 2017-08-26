#include<stdio.h>
#include<stdlib.h>

struct AVLnode
{
    int data, height;
    struct AVLnode* left, *right;
};

int max(int a, int b)
{
    return a > b ? a:b;
}

int getHeight(struct AVLnode* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

struct AVLnode* singleLeftRotate(struct AVLnode* X)
{
    struct AVLnode* W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = 1 + max(getHeight(X->left), getHeight(X->right));
    W->height = 1 + max(getHeight(W->left), getHeight(W->right));
    return W;
}

struct AVLnode* singleRightRotate(struct AVLnode* W)
{
    struct AVLnode* X = W->right;
    W->right = X->left;
    X->left = W;
    X->height = 1 + max (getHeight(X->left), getHeight(X->right));
    W->height = 1 + max (getHeight(W->left), getHeight(W->right));
    return X;
}

struct AVLnode* leftRightDoubleRotate(struct AVLnode* Z)
{
    Z->left = singleRightRotate(Z->left);
    return singleLeftRotate(Z);
}

struct AVLnode* rightLeftDoubleRotate(struct AVLnode* Z)
{
    Z->right = singleLeftRotate(Z->right);
    return singleRightRotate(Z);
}

struct AVLnode* getNewNode(int data)
{
    struct AVLnode* newNode = (struct AVLnode*)malloc(sizeof(struct AVLnode*));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    newNode->height = 0;
    return newNode;
}

struct AVLnode* insert(struct AVLnode* root, int data)
{

    // case 1, first time insertion
    if (!root)
    {
        root = (struct AVLnode*)malloc(sizeof(struct AVLnode*));
        root->left = root->right = NULL;
        root->data = data;
        root->height = 0;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            // tree has got unbalanced
            if (data < root->left->data)
                root = singleLeftRotate(root);
            else
                root = leftRightDoubleRotate(root);
        }
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            if (data > root->right->data)
                root = singleRightRotate(root);
            else
                root = rightLeftDoubleRotate(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

void inorder(struct AVLnode* root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct AVLnode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 45);
    root = insert(root, 30);
    root = insert(root, 25);

    inorder(root);
    return 0;
}
