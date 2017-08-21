/*
 * find lca
 * tree used is normal binary tree
 * approach used:
 * we parallel search for both the nodes
 * we return the node to parent whenever we find value of that node, explanation is in code itself
 * */
#include<iostream>
#include<stack>
#include<stdlib.h>

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
    if (!root) return root;

    if (root->data == val1 || root->data == val2)
        return root; // returning the root because it is either equal to one of them

    node* left_lca = get_lca(root->left, val1, val2);
    node* right_lca = get_lca(root->right, val1, val2);

    if (left_lca && right_lca)
        return root;// we check if we get some node from left side as well as from right side and this is the first time we are getting such node thus we return root saying that root is lca

    return (left_lca?left_lca:right_lca); // we are getting only one node, then depending on which node we are getting we are returning that node to the parent.
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

    std::cout<<std::endl;

    node* ret_node = get_lca(root, 65, 75);
    std::cout<<ret_node->data;
    std::cout<<std::endl;
    return 0;
}

// T.C = O(n) since we are going to traverse the entire tree in worst case
// S.C = O(n) since we are apply kind of preorder traversal, thus the space would be the space required by the stack, therefore the stack would
// depend on height of tree which in worst case is going to be order of n.
