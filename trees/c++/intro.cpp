/*
 * intro to bst: INCLUDE FUNCTIONS FOR INSERTION DELETION SEARCHING TRAVERSING
 * */
#include<iostream>

struct BSTnode
{
    int data;
    BSTnode *left, *right;
};

BSTnode* get_new_node(int data)
{
    BSTnode* new_node = new BSTnode();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

BSTnode* insert(BSTnode* root, int data)
{
    // case 1 when root is null
    if (!root)
        root = get_new_node(data);
    // case 2 when data is less than root
    else if (data < root->data)
        root->left = get_new_node(data);
    // case 3 when data is greater than root
    else
        root->right = get_new_node(data);
    return root;
}

int main()
{
    BSTnode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root ,30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 10);
}
