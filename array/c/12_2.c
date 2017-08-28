// using balanced bst (avl)
#include<stdio.h>
#include<stdlib.h>

struct AVLnode
{
    int data, height, count;
    struct AVLnode* left, *right;
};

int max(int a, int b)
{
    return a > b ? a:b;
}

int getCount(struct AVLnode* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)// leaf node
        return 0;
    return 1 + getCount(root->left);
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
    X->count = 1 + getCount(X->left);
    W->count = 1 + getCount(W->left);
    return W;
}

struct AVLnode* singleRightRotate(struct AVLnode* W)
{
    struct AVLnode* X = W->right;
    W->right = X->left;
    X->left = W;
    X->height = 1 + max (getHeight(X->left), getHeight(X->right));
    W->height = 1 + max (getHeight(W->left), getHeight(W->right));
    X->count = 1 + getCount(X->left);
    W->count = 1 + getCount(W->left);
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

struct AVLnode* insert(struct AVLnode* root, int data)
{
    // case 1, first time insertion
    if (!root)
    {
        root = (struct AVLnode*)malloc(sizeof(struct AVLnode*));
        root->left = root->right = NULL;
        root->data = data;
        root->height = 0;
        root->count = 0;
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
    root->count = getCount(root->left) + 1;
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

struct AVLnode* getInorderSuccessor(struct AVLnode* root)
{
    if (!root) return root;
    while (root->left)
        root = root->left;
    return root;
}

struct AVLnode* remove_node(struct AVLnode* root, int data)
{
    if (!root)
        return root;
    // search for element
    if (data < root->data)
        root->left = remove_node(root->left, data);
    else if (data > root->data)
        root->right = remove_node(root->right, data);
    else
    {
        // data is found
        // node to be deleted is leaf
        if (!root->left && !root->right)
        {
            free(root);
            root = NULL;
        }
        // node to be deleted has one child
        else if (!root->right)// has left child
        {
            struct AVLnode* temp = root;
            root = root->left;
            free(temp);
        }
        else if (!root->left)// has right child
        {
            struct AVLnode* temp = root;
            root = root->right;
            free(temp);
        }
        else
        {
            // node has two children
            struct AVLnode* inorderSuccessor = getInorderSuccessor(root->right);
            root->data = inorderSuccessor->data;
            root->right = remove_node(root->right, inorderSuccessor->data);
        }
    }
    return root;
}

int countLeftNodes(struct AVLnode* root)
{
    int cnt = 0;
    while (root->left)
    {
        cnt++;
        root = root->left;
    }
    return cnt;
}

void printCountInorder(struct AVLnode* root)
{
    if (root)
    {
        printCountInorder(root->left);
        printf("%d ", root->count);
        printCountInorder(root->right);
    }
}

/*
void processElementOfArr(int *arr, int n)
{
    struct AVLnode* root = NULL;
    root = insert(root, arr[n-1]);
    int i;
    for (i = n-2; i >= 0; --i)
    {
        root = insert(root, arr[i]);
    }
    printCountInorder(root);
    printf("\n");
}
*/

int main()
{
    /*
    int n, i, k;
    printf("Enter n\n");
    scanf("%d", &n);
    int arr[1000];
    printf("Enter elements\n");
    for (i = 0; i < n; ++i)
       scanf("%d", &arr[i]);
    processElementOfArr(arr, n);
    */
    struct AVLnode* root = NULL;
    root = insert(root, 2);
    root = insert(root, 3);
    /*
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 0);
    root = insert(root, 10);
    */

    //inorder(root);

    //printCountInorder(root);
    return 0;
}
