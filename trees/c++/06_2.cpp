/*
 * find lca
 * tree used is BST
 * approach used:
 * search for the val1 and val2 simultaneously and in the process of searching
 * note the pointer where we are get split into two different directions.
 * */
#include<iostream>
#include<queue>

struct node
{
    int data;
    node* left, *right;
};

node* get_new_node(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data)
{
    // case 1, when root is empty
    if (!root)
        root = get_new_node(data);

    // case 2, when data is less
    else if (root->data > data)
        root->left = insert(root->left, data);

    // case 3, when data is greater than parent
    else if (root->data < data)
        root->right = insert(root->right, data);

    return root;
}


node* get_lca(node* root, int val1, int val2)
{
    while (root)
    {
        bool b1 = val1 < root->data && val2 < root->data;
        bool b2 = val1 > root->data && val2 > root->data;
        if (b1 || b2)
        {
            b1 ? root = root->left : root = root->right;
        }
        else
        {
            break;
        }
    }
    return root;
}

int main ()
{
    node* root = NULL;
    root = insert(root, 100);
    root = insert(root, 70);
    root = insert(root, 75);
    root = insert(root, 130);
    root = insert(root, 115);
    root = insert(root, 150);
    root = insert(root, 60);
    root = insert(root, 65);

    node* lca_node = get_lca(root, 65, 150);
    std::cout<<lca_node->data;

    std::cout<<std::endl;
    return 0;
}

